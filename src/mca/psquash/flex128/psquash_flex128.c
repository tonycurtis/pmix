/*
 * Copyright (c) 2019      IBM Corporation.  All rights reserved.
 * Copyright (c) 2019      Mellanox Technologies, Inc.
 *                         All rights reserved.
 *
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include <src/include/pmix_config.h>

#include <pmix_common.h>

#include "src/include/pmix_socket_errno.h"
#include "src/include/pmix_globals.h"
#include "src/util/argv.h"
#include "src/util/error.h"
#include "src/util/output.h"

#include <unistd.h>
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#include "src/mca/psquash/psquash.h"
#include "psquash_flex128.h"

#include "src/mca/bfrops/base/base.h"

#define FLEX_BASE7_MAX_BUF_SIZE (SIZEOF_SIZE_T+1)
#define FLEX_BASE7_MASK ((1<<7) - 1)
#define FLEX_BASE7_SHIFT 7
#define FLEX_BASE7_CONT_FLAG (1<<7)

// Move to bfrops framework
#define PMIX_BFROPS_TYPE_SIZEOF(r, t, s)                    \
    do {                                                    \
        (r) = PMIX_SUCCESS;                                 \
        switch (t) {                                        \
            case PMIX_INT16:                                \
            case PMIX_UINT16:                               \
                (s) = SIZEOF_SHORT;                         \
                break;                                      \
            case PMIX_INT:                                  \
            case PMIX_INT32:                                \
            case PMIX_UINT:                                 \
            case PMIX_UINT32:                               \
                (s) = SIZEOF_INT;                           \
                break;                                      \
            case PMIX_INT64:                                \
 case PMIX_UINT64:                                          \
 (s) = SIZEOF_LONG;                                         \
 break;                                                     \
        case PMIX_SIZE:                                     \
            (s) = SIZEOF_SIZE_T;                            \
            break;                                          \
        default:                                            \
            (r) = PMIX_ERR_BAD_PARAM;                       \
        }                                                   \
    } while (0)

static pmix_status_t flex128_init(void);

static void flex128_finalize(void);

static pmix_status_t flex128_encode_int(pmix_data_type_t type,
                                        void *src,
                                        uint8_t dest[PMIX_PSQUASH_INT_MAX_BUF_SIZE],
                                        uint8_t *dest_len);

static pmix_status_t flex128_decode_int(pmix_data_type_t type,
                                        uint8_t src[PMIX_PSQUASH_INT_MAX_BUF_SIZE],
                                        uint8_t src_len,
                                        void *dest);

pmix_psquash_base_module_t pmix_flex128_module = {
    .name = "flex128",
    .init = flex128_init,
    .finalize = flex128_finalize,
    .encode_int = flex128_encode_int,
    .decode_int = flex128_decode_int
};


static pmix_status_t flex128_init(void)
{
    pmix_output_verbose(2, pmix_globals.debug_output,
                        "psquash: flex128 init");
    return PMIX_SUCCESS;
}

static void flex128_finalize(void)
{
    pmix_output_verbose(2, pmix_globals.debug_output,
                        "psquash: flex128 finalize");
}

static pmix_status_t flex128_encode_int(pmix_data_type_t type,
                                        void *src,
                                        uint8_t dest[PMIX_PSQUASH_INT_MAX_BUF_SIZE],
                                        uint8_t *dest_len)
{
    pmix_status_t rc;
    
    PMIX_BFROPS_TYPE_SIZEOF(rc, type, *dest_len);
    if (PMIX_SUCCESS != rc) {
        PMIX_ERROR_LOG(rc);
        return rc;
    }

    memcpy(&dest, src, *dest_len);

    return PMIX_SUCCESS;
}

static pmix_status_t flex128_decode_int(pmix_data_type_t type,
                                        uint8_t src[PMIX_PSQUASH_INT_MAX_BUF_SIZE],
                                        uint8_t src_len,
                                        void *dest)
{
    pmix_status_t rc;
    size_t exp_len;

    PMIX_BFROPS_TYPE_SIZEOF(rc, type, exp_len);
    if (PMIX_SUCCESS != rc) {
        PMIX_ERROR_LOG(rc);
        return rc;
    }

    if( exp_len != src_len ) { // sanity check
        PMIX_ERROR_LOG(rc);
        return rc;
    }

    memcpy(&dest, src, src_len);

    return PMIX_SUCCESS;
}

static int flex_pack_integer(uint64_t size, uint8_t out_buf[FLEX_BASE7_MAX_BUF_SIZE])
{
    uint64_t tmp = size;
    int idx = 0;

    do {
        uint8_t val = tmp & FLEX_BASE7_MASK;
        tmp >>= FLEX_BASE7_SHIFT;
        if (PMIX_UNLIKELY(tmp)) {
            val |= FLEX_BASE7_CONT_FLAG;
        }
        out_buf[idx++] = val;
    } while(tmp && idx < 8);

    /* If we have leftover (VERY unlikely) */
    if (PMIX_UNLIKELY(8 == idx && tmp)) {
        out_buf[idx++] = tmp;
    }
    return idx;
}

static uint64_t flex_unpack_integer(uint8_t in_buf[])
{
    uint64_t size = 0, shift = 0;
    int idx = 0;
    uint8_t val = 0;

    do {
        val = in_buf[idx++];
        size = size + (((uint64_t)val & FLEX_BASE7_MASK) << shift);
        shift += FLEX_BASE7_SHIFT;
    } while(PMIX_UNLIKELY((val & FLEX_BASE7_CONT_FLAG) && (idx < 8)));

    /* If we have leftover (VERY unlikely) */
    if (PMIX_UNLIKELY(8 == idx && (val & FLEX_BASE7_CONT_FLAG))) {
        val = in_buf[idx++];
        size = size + ((uint64_t)val << shift);
    }
    return size;
}
