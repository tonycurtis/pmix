---
layout: page
title: PMIx-Enabled Environments
tagline: 
---
{% include JB/setup %}

##### 1. What environments include PMIx support?

The following systems currently support PMIx:

* SLURM: starting in release 16.05 with PMIx v1.1.5
* Fujitsu:

This list will be updated as vendors release their support

##### 2. What environments plan to include PMIx support?

Resource managers that have indicated plans to include PMIx support in upcoming releases include:

* IBM
* Adaptive Solutions
* Altair

##### 3. What do I do if my vendor hasn't yet released PMIx support?

The PMIx community has a prototype PMIx reference server that will soon be released to help with the transition period. Users on systems that do not yet support PMIx can, if they choose, launch the reference server across their allocated nodes. The server will establish a network of PMIx daemons (one per node) that will provide support for launch, wireup, event notification, and all other PMIx services. More details will be provided as the server becomes generally available.

The main drawback to use of the PMIx reference server is the lack of integration to the native system management software stack (SMS). This manifests itself in the lack of support for obtaining new allocations, the ability to obtain notification of system-level events, and other areas that lie outside the purview of the immediate allocation. 
