---
layout: page
title: FAQ: General information
tagline: 
---
{% include JB/setup %}

##### 1. What is PMIx?

PMIx consists of the following:

* a standardized set of APIs, as defined in a set of four header files
* a convenience library that resource managers can use to provide PMIx services
* a community dedicated to defining and maintaining the PMIx standard

##### 2. What is the objective of PMIx?

PMIx is focused on creating a standardized set of APIs for interactions between applications and the system management software stack (SMS) that:

* enables portability of applications across environments. SMS providers are free to return "not supported" on any request, but the API itself must at least be present and consistent with the PMIx definition
* shifts the point of competition between SMS providers from the API definitions to the breadth and quality of their backend support

##### 3. What is the history of the PMIx project?

PMIx has its roots in launch performance studies done on the RoadRunner system at Los Alamos National Laboratory in the mid-2000s. Several key results were uncovered by that work:

  * Application startup times were primarily dominated by the time spent exchanging information between processes. Programming models based on inter-process communication (e.g., MPI) require that each process know how to address messages to their peers. At startup, each process would therefore discover its address information and "publish" it to a local daemon, which would in turn exchange the information with the daemons on all other nodes hosting that application. This exchange, commonly known as the "modex", was the source of the delay.

  Subsequent analysis of the contents of the modex revealed that the majority of information being exchanged (e.g., where each process was located) was actually already known by the local resource manager daemon supporting each node. Only the specifics of the network endpoint were missing - in TCP terms, it was the socket number each process was listening to that was not known at time of process start. Thus, if network addressing could be pre-assigned by the resource manager, or be statically calculated, and the resource manager given a mechanism for sharing its knowledge of the application's environment, then the modex operation could be completely eliminated.

  * The second largest delay was caused by repeated calls to load dynamic libraries due to a bottleneck at the IO nodes. This was resolved for the RoadRunner system by forcing applications to be built statically, or at least with dlopen disabled, thus eliminating the bottleneck. However, this proved to be an unsatisfactory long-term solution as it:

    * precludes the use of inherently dynamic programming languages (e.g., scripting languages such as Python)
    * results in a larger memory footprint per process due to the loss of shared library support
    * still was bound by the time required to download and position each application on its host node
  
Each of these issues becomes amplified as the scale of the system increases, thus making it imperative that the problems be addressed as we move towards exascale systems. Discussions between individuals and various groups ensued over the years, but it wasn't until mid-2014 that an initial core group formed to establish the "Instant-On" initiative that germinated into the PMIx project.

Achieving Instant-On requires that the system management software stack (SMS) both pre-position applications and their attendant libraries, and provide all required information for communication at process start. This necessitated negotiations with the resource management (RM) providers as much of the information and staging during startup occurs in that software. By the end of 2015, multiple RM providers had joined the community as active participants in defining PMIx operations related to Instant-On.

However, during the course of working on Instant-On, it became apparent that additional interactions might also be desirable. For example, applications might want to dynamically request changes in their allocations, perhaps expanding or even contracting their size. These operations required interfaces essentially identical to those already being developed, and so it seemed natural to extend PMIx to support them. In addition, the RM providers were seeing an increasing level of requests from users for broadened interactions between applications and the SMS. If pursued piecemeal, these requests would all result in different protocols for exchanging communications between the application and the SMS, representing a major burden on the RM providers.

Therefore, the PMIx project agreed to expand its scope from Instant-On to cover the general application-SMS interface. The project now provides standardized interfaces for a variety of query and request operations, including notification of system events, requests for allocations and queue status, and logging of data for retrieval by tools.

##### 4. Is the PMIx project a specific implementation, or a standard?

  PMIx is a set of standardized APIs, expressed as C-based header files. In addition, the PMIx community provides a convenience library to ease and encourage widespread support for the standard. System providers are welcome to use the library, but there is no requirement that anyone do so. Indeed, some providers have already stated their intention to provide their own implementation of the standard for various reasons.

##### 5. Why isn't PMIx part of the MPI Forum or another standards body?

The [MPI Forum](http://mpi-forum.org/) is the forum governing the Message Passing Interface (MPI). It deals specifically with standardizing interfaces for the MPI programming model. While PMIx is used to support startup of an MPI implementation, it does not itself have any knowledge or understanding of MPI - e.g., PMIx has no concept of a "communicator", which is a core element of MPI.

Organizing PMIx under the MPI Forum is therefore problematic. While we have no philosophical issue with doing so, it isn't clear how a set of non-MPI interface definitions would fit within the Forum's purview. Similarly related topics (e.g., debugger interfaces) have been discussed within the Forum as addenda to the standard, with the discussions occurring in related working groups. However, these definitions have not been classed as "standards" and are not controlled in that manner. Likewise, the prior PMI definitions were never organized under a standards body nor considered as part of the Forum.

A review of alternative standards bodies resulted in similar findings. Relevant organizations are focused on specific programming models, or on topical areas (e.g., network protocols) that don't comfortably encompass the objectives of the PMIx members.

The PMIx community would prefer to be covered via some standards process as a means of facilitating broader adoption. Accordingly, the community adopted its own standards-based procedure for controlling the PMIx specification. As the community is relatively small at this time, a full formal process based on physical meetings was considered overly burdensome. Thus, the community adopted a lighter weight process:

* All modifications and additions to the PMIx standard must be formally proposed as a Request For Comment (RFC). These are put forward in the form of a Github Pull Request (PR) against the [PMIx RFC repository](https://github.com/pmix/RFCs) using the provided [RFC template](https://github.com/pmix/RFCs/blob/master/Template.md).

* The proposed modification or addition must include a prototype implementation against the PMIx convenience library's [master repository](https://github.com/pmix/master). This ensures that the change has been subjected to some degree of functional validation, and gives reviewers an example of how it might be implemented.

* An email is sent to the PMIx developer's mailing list alerting members to the RFC and prototype implementation. This includes links to the RFC and the accompanying pull request, along with a very brief statement of the RFC's purpose (e.g., a copy of the abstract section). Both the email and the PR shall include a proposed timetable within which the author(s) would like to have the RFC reviewed. This is not intended to form a hard deadline, but rather to inform the community as to the anticipated pace of the proposal.

* Review comments and requests for changes are made on the RFC pull request, and modifications to the proposed implementation can be suggested. This continues until a consensus emerges over the proposed change to the standard, or agreement is reached to retract the proposal.

* The RFC is then scheduled for review at the next available PMIx developer teleconference. At that time, any remaining objections or concerns are discussed and a final decision is made. If approved, the RFC is marked to that affect and committed to the RFC repository, and the prototype implementation is subsequently added to the convenience library. If rejected, the RFC is marked accordingly and the PR closed.

Attributes included in the PMIx definition (as provided in the "pmix_common.h" header) can be added without RFC since SMS providers are not required to support them. Proposed additions are discussed during one or more of the developer teleconferences prior to adoption.

##### 6. How stable/mature is the PMIx standard definition?
  
The PMIx community has committed to providing a stable and portable set of API definitions. Accordingly, the community avoids as much as possible changes to existing APIs, and each API is defined to provide maximum flexibility. The v1.0 definitions were considered an "early offering" intended solely to generate initial feedback - thus, these APIs were subject to adjustment based on response from early adopters.

With release of v1.1.5, however, the base APIs governing support of launch, wireup, and event notification were considered complete. This version constituted the first production PMIx release and was included in both the SLURM 16.05 and Open MPI 2.0 releases. Experience gained in completing these definitions have aided the community in establishing guidelines for future APIs that will enable us to avoid future modifications to released APIs. In particular, this includes minimizing the number of fixed parameters in function signatures, and the generous use of "info key" arrays to allow flexible specification of behaviors (both optional and required). Thus, extended definitions of behaviors can be achieved thru the simple addition of new key-value definitions without modifying the API's signature.

These two design principles have been validated as we worked thru development of the v2.x series, and into the addition of new APIs for the upcoming v3.0 series releases. Thus, no further modifications of existing APIs are anticipated. Addition of new APIs is expected to continue in bursts as members and users identify new desired areas for application-SMS interaction.

Development of the PMIx convenience library remains active. All functional APIs are covered, and we continue to strive to provide complete coverage of all defined "info keys".
