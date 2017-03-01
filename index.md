---
layout: page
title: PMI-Exascale
tagline:
---
{% include JB/setup %}

<img align="left" src="images/PMIxSimple.png" width="48">The Process Management Interface (PMI) has been used for quite some time as a means of exchanging wireup information needed for interprocess communication. Two versions (PMI-1 and PMI-2) have been released as part of the MPICH effort. While PMI-2 demonstrates better scaling properties than its PMI-1 predecessor, attaining rapid launch and wireup of the roughly 1M processes executing across 100k nodes expected for exascale operations remains challenging.

PMI Exascale (PMIx) represents an attempt to resolve these questions by providing an extended version of the PMI definitions specifically designed to support clusters up to and including exascale sizes. The overall objective of the project is not to branch the existing definitions - in fact, PMIx fully supports both of the existing PMI-1 and PMI-2 APIs - but rather to (a) augment and extend those APIs to eliminate some current restrictions that impact scalability, (b) establish a standards-like body for maintaining the definitions, and (c) provide a reference implementation of the PMIx standard that demonstrates the desired level of scalability.

Charter
=====================

The charter of the PMIx community is to:

* __Define__ a set of agnostic APIs (not affiliated with any specific programming model code base) to support interactions between application processes and the system management software stack (SMS)

* __Develop__ an open source (non-copy-left licensed) standalone "convenience" library to facilitate adoption of the PMIx standard

* __Retain__ transparent backward compatibility with the existing PMI-1 and PMI-2 definitions, any future PMI releases, and across all PMIx versions

* __Support__ the _Instant On_ initiative for rapid startup of applications at exascale and beyond

* __Work__ with the HPC community to define and implement new APIs that support evolving programming model requirements for application-RM interactions.

Note that the definition of the PMIx standard is not contingent upon use of the convenience library. Any implementation that supports the defined APIs is perfectly acceptable, and some environments have chosen to pursue that route. The convenience library is provided solely for the following purposes:

* Validation of the standard. No proposed change and/or extension to the standard is accepted without an accompanying prototype implementation in the convenience library. This ensures that the proposal has undergone at least some minimal level of scrutiny and testing before being considered.

* Ease of adoption. The PMIx convenience library is designed to be particularly easy for resource managers (and the SMS in general) to adopt, thus facilitating a rapid uptake into that community for application portability. Both client and server libraries are included, along with reference examples of client usage and server-side integration. A list of supported environments and versions is provided [here](etc) - please check regularly as the list is changing!

The convenience library targets support for the Linux operating system.  A reasonable effort is made to support all major, modern Linux distributions; however, validation is limited to the most recent 2-3 releases of RedHat Enterprise Linux (RHEL), Fedora, CentOS, and SUSE Linux Enterprise Server (SLES). In addition, development support is maintained for Mac OSX. Production support for vendor-specific operating systems is included as provided by the vendor.

Participation in the PMIx community is open to anyone, and not restricted to only code contributors to the convenience library. Current community members are listed [here](community).

Overview of PMIx
=====================

The following publications (with accompanying citation info) may help provide some background on PMIx and a perspective on its role in future HPC resource management:

* PMIx: Storage Integration [[pdf]](https://github.com/pmix/publications/blob/master/PMIx-TieredStorage.pdf) [[ppt]](https://github.com/pmix/publications/blob/master/PMIx-TieredStorage.pptx)
    * **PMIx: Storage Integration** Ralph H Castain. Presented at _DOE Tiered Storage Working Group meeting_, Feb 2017.

* PMIx Birds-of-a-Feather at SC'16 [[pdf]](https://github.com/pmix/publications/blob/master/PMIxBoF-2016.pdf) [[ppt]](https://github.com/pmix/publications/blob/master/PMIxBoF-2016.pptx)
    * **Charting the PMIx Roadmap.** Ralph H Castain, David Solt, and Artem Polyakov. Presented at _Birds-of-a-Feather Meeting, Supercomputing 2016_, November 2016.

* PMIx: Scalable Debugger Support [[pdf]](https://github.com/pmix/publications/blob/master/PMIxDebugger.pdf) [[ppt]](https://github.com/pmix/publications/blob/master/PMIxDebugger.pptx)
    * Ralph H. Castain, Presented to MPI Forum Debugger Working Group, July 28, 2016

* PMIx State-of-the-Union at SIAM'16 [[pdf]](https://github.com/pmix/publications/blob/master/PMIx-SoU-Mar2016.pdf) [[ppt]](https://github.com/pmix/publications/blob/master/PMIx-SoU-Mar2016.pptx)
    * **Process Management Interface-Exascale** David Solt and Ralph H Castain, Presented at SIAM'16, April 12-18 2016

* PMIx Birds-of-a-Feather at SC'15 [[pdf]](https://github.com/pmix/publications/blob/master/PMIx-BoF-SC15.pdf) [[ppt]](https://github.com/pmix/publications/blob/master/PMIx-BoF-SC15.pptx)
    * **Charting the PMIx Roadmap.** Ralph H Castain, Joshua Ladd, David Solt, and Gary Brown. Presented at _Birds-of-a-Feather Meeting, Supercomputing 2015_, November 2015.

* Exascale Process Management Interface (SLURM User's Group 2015) [[pdf]](https://github.com/pmix/publications/blob/master/slug2015.pdf) [[ppt]](https://github.com/pmix/publications/blob/master/slug2015.pptx)
    * **Exascale Process Management Interface.** Ralph H Castain, Joshua Ladd, Artem Polyakov, David Bigagli, and Gary Brown. Presented at _SLURM User's Group Meeting_, Sept 2015, Washington DC

* HPC Resource Management: View to the Future [[pdf]](https://github.com/pmix/publications/blob/master/RMFutures.pdf) [[ppt]](https://github.com/pmix/publications/blob/master/RMFutures.pptx)
    * **HPC Resource Management: View to the Future.** Ralph H Castain. Presented at _Open MPI Developer's Meeting_, Feb 2016, Dallas TX


How do I get involved?
=====================

1. Read the documentation. The [header](https://github.com/pmix/master/tree/master/include) files contain the "official" definition of the standard, and the comments in them are intended to provide explanation and guidance. In addition, a set of man pages are being written to describe their implementation in the convenience library (not much is there just yet, but we are working on it):

  * [Man pages for current head of development](man)

 In addition, a [set of example applications](https://github.com/pmix/master/tree/master/examples) have been developed to highlight how an application might use various aspects of PMIx.

1. Review the [wiki](https://github.com/pmix/master/wiki) for an explanation of the standard definitions and an overview of the convenience library

1. Scan the [FAQs](faq).

1. Download the latest release or the master:

  * The PMIx library itself (including documentation):
    * [Production releases](downloads)
    * [Nightly](http://www.open-mpi.org/software/pmix/nightly/master/)

  * The PMIx code base is being developed in [the PMIx GitHub repository](https://github.com/pmix/master).

1. Become part of the conversation

  * [Join the mailing list](https://groups.google.com/forum/#!forum/pmix). The list sees a fairly low rate of posting as most discussion occurs in Github "issues" and in the teleconferences. However, broad-ranging issues and announcement of releases are among the topics handled on the mailing list.

  * [Follow the repositories](https:://github.com/pmix). Pull requests and issues are heavily used to discuss proposed changes in both [implementation](https://github.com/pmix/master) and the [standard](https://github.com/pmix/RFCs). 

  * Participate in the [teleconferences](https://github.com/pmix/master/wiki/4-Meetings). PMIx developers meet every Tues and Thurs to discuss the project, review and approve pending RFCs, and talk about their ongoing efforts. Anyone can join the calls to listen and participate in the design of PMIx.
