---
layout: page
title: Building PMIx from the repo
tagline: 
---
{% include JB/setup %}

After obtaining a successful [Git clone](git), the
following tools are required for developers to compile PMIx from
its repository sources (users who download PMIx tarballs *do
not* need these tools - they are _only_ required for
developers working on the internals of PMIx itself):

Software Package | Notes | URL 
:-----------------|:------|:----
 Git client       | Version 1.8.0 or above | [http://git-scm.org/](http://git-scm.org/) 
 GNU m4           | See version chart below | [ftp://ftp.gnu.org/gnu/m4](ftp://ftp.gnu.org/gnu/m4) 
 GNU autoconf     | See version chart below | [ftp://ftp.gnu.org/gnu/autoconf](ftp://ftp.gnu.org/gnu/autoconf) 
 GNU automake     | See version chart below | [ftp://ftp.gnu.org/gnu/automake](ftp://ftp.gnu.org/gnu/automake) 
 GNU libtool      | See version chart below | [ftp://ftp.gnu.org/gnu/libtool](ftp://ftp.gnu.org/gnu/libtool) 
 Flex             | See version chart below | [ftp://ftp.gnu.org/non-gnu/flex](ftp://ftp.gnu.org/non-gnu/flex) 

The following table lists the versions that are used to make
nightly PMIx tarballs.  Other versions may work, but these are the
versions that we _know_ work.

| PMIx Release  | M4 Version | Autoconf Version | Automake Version | Libtool Version | Flex Version |
| :-------------: | :-----------: | :----------------: | :----------------: | :----------------: | :------------: |
| v1.0 | 1.4.17 | 2.69 | 1.15 | 2.4.6 | 2.5.35 |
| v1.1 | 1.4.17 | 2.69 | 1.15 | 2.4.6 | 2.5.35 |
| master | 1.4.17 | 2.69 | 1.15 | 2.4.6 | 2.5.35 |

Autotools notes:

* Other version combinations <em>may</em> work, but are untested and unsupported.  In particular, developers tend to use higher versions of Autotools for master/development work, and they usually work fine.

Although it should probably be assumed, you'll also need a C/C++
compiler.

The [HACKING](https://github.com/pmix/master/blob/master/HACKING) file in the top-level directory of the PMIx checkout details how to install the tools listed above and the steps required to build a developer checkout of PMIx. It always contains the most current information on how to build a developer's copy of PMIx.

NOTE: by default, when configuring and building PMIx from a developer checkout, *all* debugging code is enabled. This results in a
significant run-time performance penalty.  There are several options for building an optimzed Open MPI; see the HACKING
file for more details.

NOTE: Most Linux distributions and OS X install Flex by default (and this is sufficient).  Other operating systems may provide "lex", but this is *not* sufficient -- flex is required.

