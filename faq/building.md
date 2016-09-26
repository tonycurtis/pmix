---
layout: page
title: Building the PMIx convenience library
tagline: 
---
{% include JB/setup %}

### 1. What do I need in order to build the PMIx convenience library?

  The following tools are required for developers to compile PMIx from its repository sources (users who download PMIx tarballs do not need these tools - they are only required for developers working on the internals of PMIx itself):

  * Git client: version 1.8.0 or above
  * GNU m4: version 1.4.17 or above
  * GNU autoconf: version 2.69 or above
  * GNU automake: version 1.15 or above
  * GNU libtool: version 2.4.6 or above
  * Flex: version version 2.5.35 or above

  Other version combinations _may_ work, but are untested
  and unsupported.  In particular, developers tend to use higher
  versions of Autotools for master/development work, and they
  usually work fine.

  Although it should probably be assumed, you'll also need a C compiler.

  The [HACKING](https://github.com/pmix/master/blob/master/HACKING) file in the top-level directory of the PMIx checkout
  details how to install the tools listed above and the steps required
  to build a developer checkout of PMIx.  It always contains the
  most current information on how to build a developer's copy of PMIx.

  NOTE: by default, when configuring and building
  PMIx from a developer checkout, _all debugging code is enabled_. This results in a
  _significant_ run-time performance penalty.  There are
  several options for building an optimized PMIx; see the HACKING
  file for more details.

  NOTE: Most Linux distributions and OS X install
  Flex by default (and this is sufficient).  Other operating systems may
  provide "lex", but this is _not_ sufficient -- flex is
  required.

### 2. How do I build the PMIx convenience library?

  If you have obtained a developer's checkout from Git, you need to start by running the _autogen.pl_ command. This does not require any options, but will discover available plugins and generate the necessary configure support.

  For everyone else, in general, all you need to do is expand the
  tarball, run the provided _configure_ script, and then run "make all
  install".  For example:

  ```
  <geshi bash>
  shell$ tar xf pmix-2.0.0.tar.gz
  shell$ cd pmix-2.0.0
  shell$ ./configure --prefix=/usr/local
  <...lots of output...>
  shell$ make all install
  </geshi>
  ```

  Note that the _configure_ script supports a lot of different command
  line options.  For example, the "--prefix" option in the above example
  tells Open MPI to install under the directory "/usr/local/".

  PMIx requires only one external dependency - it must be built against libevent as it relies upon that library for handling of asynchronous events (e.g., from communications). Libevent is typically included in standard Linux distributions, and the PMIx configure script will locate and use it from the usual locations. If libevent was installed in an unexpected location, or if you want to use a different installation of libevent, then you can point PMIx to that libevent installation using the "--with-libevent=<foo>" option.

  Another frequently used PMIx configure option allows inclusion of support for the HardWare Locality (HWLOC) library.

  Consult the _README_ file in the PMIx tarball and the output of
  "configure --help" for specific instructions regarding PMIx's
  configure command line options.";

