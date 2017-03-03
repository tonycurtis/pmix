---
layout: page
title: Source Code Access
tagline: 
---
{% include JB/setup %}

Because the PMIx Team tries very hard to release stable and
as-bug-free-as-possible distributions, we tend to take a long time
between major releases.  However, there are many useful new features
(and bug fixes) in our internal Git tree that some users have
asked for access to.  Additionally, for those who are actually develop with the internals of PMIx, Git access gives the most
up-to-date versions rather than the periodic tarball access.  As such,
the PMIx Team provides public read-only access to the PMIx Git tree.</p>

Be aware, however, that the head of the development code tree is
*not* guaranteed to be stable.  For the most part, we try very
hard to not commit things that are broken, but this is an active
development tree -- bugs happen.  This is actually another major
reason that this tree has been made available: peer review.  If you
find any bugs, _please_ report them on the [issues](https://github.com/pmix/pmix/issues) list.

The Git "master" branch is the current development version of
PMIx.  It is generally where new PMIx work is done.

There are multiple ways to get access to Open MPI's source code:

* [Clone the main PMIx repo at GitHub](https://github.com/pmix/pmix)</a>.  The main development work occurs on the "master" branch in this repo.

    * Advantage: You'll easily be able to keep up with the latest source code using normal Git commands (e.g., '<code>git pull --rebase</code>').
    * Disadvantage: You need to have [several tools installed](source/building)to compile PMIx from a developer checkout.

* Clone the [releases](https://github.com/pmix/releases) repo at GitHub.  This repo holds the release branches for PMIx (i.e., the branches that are used to
make official distribution tarballs).

    * Advantage: You'll easily be able to keep up with the latest source code using normal Git commands (e.g., '<code>git pull --rebase</code>').
    * Disadvantage: You need to have [several tools installed](source/building)to compile PMIx from a developer checkout.

* Download a [nightly snapshot tarball](https://www.open-mpi.org/software/pmix/nightly/master). In this case, no special tools are required, and a simple configure and make will install PMIx.

    * Advantage: You need no extra tools to compile and install PMIx.
    * Disdvantage: You cannot easily keep up with the latest source code; you'll need to download a new tarball each time you want to update.
