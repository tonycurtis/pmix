---
layout: page
title: PMI-Exascale
tagline:
---
{% include JB/setup %}

The Process Management Interface (PMI) has been used for quite some time as a means of exchanging wireup information needed for interprocess communication. Two versions (PMI-1 and PMI-2) have been released as part of the MPICH effort. While PMI-2 demonstrates better scaling properties than its PMI-1 predecessor, attaining rapid launch and wireup of the roughly 1M processes executing across 100k nodes expected for exascale operations remains challenging.

PMI Exascale (PMIx) represents an attempt to resolve these questions by providing an extended version of the PMI standard specifically designed to support clusters up to and including exascale sizes. The overall objective of the project is not to branch the existing pseudo-standard definitions - in fact, PMIx fully supports both of the existing PMI-1 and PMI-2 APIs - but rather to (a) augment and extend those APIs to eliminate some current restrictions that impact scalability, and (b) provide a reference implementation of the PMI-server that demonstrates the desired level of scalability.

The charter of the PMIx community is to:

> Develop an open source (non-copy-left licensed) and independent (i.e., not affiliated with any specific programming model code base) standalone library to support application interactions with Resource Managers (RMs)

> Retain transparent compatibility with the existing PMI-1 and PMI-2 definitions, and any future PMI releases

> Support the _Instant On_ initiative for rapid startup of applications at exascale and beyond

> Work with the HPC community to define and implement new APIs that support evolving programming model requirements for application-RM interactions.

PMIx is designed to be particularly easy for resource managers to adopt, thus facilitating a rapid uptake into that community for application portability. Both client and server libraries are included, along with reference examples of client usage and server-side integration. A list of supported environments and versions is provided [here](etc) - please check regularly as the list is changing!

PMIx targets support for the Linux operating system.  A reasonable effort is made to support all major, modern Linux distributions; however, validation is limited to the most recent 2-3 releases of RedHat Enterprise Linux (RHEL), Fedora, CentOS, and SUSE Linux Enterprise Server (SLES). Support for vendor-specific operating systems is included as provided by the vendor.

Overview of PMIx
=====================

This provides an overview of the project:

<div align="center">
<iframe src="//www.slideshare.net/slideshow/embed_code/key/g2GcY4dHJc83CN" width="425" height="355" frameborder="0" marginwidth="0" marginheight="0" scrolling="no" style="border:1px solid #CCC; border-width:1px; margin-bottom:5px; max-width: 100%;" allowfullscreen> </iframe> <div style="margin-bottom:5px"> <strong> <a href="//www.slideshare.net/rcastain/exascale-process-management-interface" title="Exascale Process Management Interface" target="_blank">Exascale Process Management Interface</a> </strong> from <strong><a href="//www.slideshare.net/rcastain" target="_blank">rcastain</a></strong>
</div>
</div>

The following presentation includes some of the motivation behind PMIx.

<div align="center">
<iframe src="//www.slideshare.net/slideshow/embed_code/key/46z5El9n7kE7Zy" width="425" height="355" frameborder="0" marginwidth="0" marginheight="0" scrolling="no" style="border:1px solid #CCC; border-width:1px; margin-bottom:5px; max-width: 100%;" allowfullscreen> </iframe> <div style="margin-bottom:5px"> <strong> <a href="//www.slideshare.net/rcastain/hpc-controls-future" title="HPC Controls Future" target="_blank">HPC Controls Future</a> </strong> from <strong><a href="//www.slideshare.net/rcastain" target="_blank">rcastain</a></strong>
</div>
</div>


How do I get involved?
=====================

First, read the documentation. A set of man pages are being written to specify the PMIx API (not much is there just yet, but we are working on it):

* [Man pages for current head of development](master/man/)

 In addition, a [set of example applications](https://github.com/open-mpi/pmix/tree/master/examples) have been developed to highlight how an application might use various aspects of PMIx.

Second, download the latest release or the master:

* The PMIx library itself (including documentation):
    * [PMIx 1.0.0](http://www.open-mpi.org/software/pmix/v1.0/)
    * [Nightly](http://www.open-mpi.org/software/pmix/nightly/master/)

* The PMIx code base is being developed in [the PMIx GitHub repository](https://github.com/open-mpi/pmix).

Third: [become part of the conversation](http://www.open-mpi.org/community/lists/pmix-devel/)

[Join the PMIx mailing lists](http://www.open-mpi.org/community/lists/pmix.php).  Notices of the every-Tuesday PMIx Webexes are sent on the devel list; anyone can join the calls to listen and participate in the design of PMIx.

Although PMIx targets Linux as its primary operating system, portability for non-Linux platforms is provided as a convenience to our development community.  Currently, PMIx has been ported to OS X.
