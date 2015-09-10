---
layout: page
title: PMIx
tagline: PMI-exascale
---
{% include JB/setup %}

The Process Management Interface (PMI) has been used for quite some time as a means of exchanging wireup information needed for interprocess communication. Two versions (PMI-1 and PMI-2) have been released as part of the MPICH effort. While PMI-2 demonstrates better scaling properties than its PMI-1 predecessor, attaining rapid launch and wireup of the roughly 1M processes executing across 100k nodes expected for exascale operations remains challenging.

PMI Exascale (PMIx) represents an attempt to resolve these questions by providing an extended version of the PMI standard specifically designed to support clusters up to and including exascale sizes. The overall objective of the project is not to branch the existing pseudo-standard definitions - in fact, PMIx fully supports both of the existing PMI-1 and PMI-2 APIs - but rather to (a) augment and extend those APIs to eliminate some current restrictions that impact scalability, and (b) provide a reference implementation of the PMI-server that demonstrates the desired level of scalability.

The charter of the PMIx community is to:

> Develop an open source, independent (i.e., not affiliated with any specific programming model code base) library to support applications.



PMIx is designed to .

PMIx targets support for the Linux operating system.  A reasonable effort is made to support all major, modern Linux distributions; however, validation is limited to the most recent 2-3 releases of RedHat Enterprise Linux (RHEL), Fedora, CentOS, and SUSE Linux Enterprise Server (SLES). Support for vendor-specific operating systems is included as provided by the vendor.

Overview of PMIx
=====================

The following presentation describes some of the motivation for PMIx.

<div align="center">
<iframe src="//www.slideshare.net/slideshow/embed_code/key/46z5El9n7kE7Zy" width="425" height="355" frameborder="0" marginwidth="0" marginheight="0" scrolling="no" style="border:1px solid #CCC; border-width:1px; margin-bottom:5px; max-width: 100%;" allowfullscreen> </iframe> <div style="margin-bottom:5px"> <strong> <a href="//www.slideshare.net/rcastain/hpc-controls-future" title="HPC Controls Future" target="_blank">HPC Controls Future</a> </strong> from <strong><a href="//www.slideshare.net/rcastain" target="_blank">rcastain</a></strong> </div>


How do I get involved?
======================

First, read the documentation:

* [Man pages for current head of development](master/man/)

A set of Linux man pages have been carefully written to specify the PMIx API.  Read through these man pages to get a sense of it.  A [set of example applications](https://github.com/ofiwg/fabtests) have been developed to highlight how an application might use various aspects of PMIx.

Second, download the latest release or the master:

* The libfabric library itself (including documentation): [libfabric-1.1.0.tar.bz2](http://downloads.openfabrics.org/downloads/ofi/libfabric-1.1.0.tar.bz2) (or [see all prior releases](http://downloads.openfabrics.org/downloads/ofi/))
* Examples and unit tests: [fabtests-1.1.0.tar.bz2](http://downloads.openfabrics.org/downloads/ofi/fabtests-1.1.0.tar.bz2) (or [see all prior releases](http://downloads.openfabrics.org/downloads/ofi/))

The bulk of the libfabric code base is being developed in [the main OFIWG libfabric GitHub repository](https://github.com/ofiwg/libfabric).

Third: [become part of the conversation](http://www.open-mpi.org/community/lists/pmix-devel/)

[Join the PMIx mailing lists](http://www.open-mpi.org/community/lists/pmix.php).  Notices of the every-Tuesday PMIx Webexes are sent on the devel list; anyone can join the calls to listen and participate in the design of PMIx.

Although PMIx targets Linux as its primary operating system, portability for non-Linux platforms is provided as a convenience to our development community.  Currently, PMIx has been ported to OS X.
