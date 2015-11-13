---
layout: page
title: Source Code Access: Obtaining a Git Clone
tagline: 
---
{% include JB/setup %}

The PMIx Git repository is hosted at [GitHub](https://github.com/).

First, you will need a Git client.  We recommend getting the
latest version available.  If you do not have the command
_git_ in your path, you will likely need to download and
install Git.

PMIx has three repositories at GitHub:

* [master](https://github.com/pmix/master): This is the main PMIx repository where most active development is done. There are Git tags on the
branches in this repo that indicate where release branches were started
(e.g., "v1.1.0" is the tag corresponding to the branching of the PMIx v1.1
release series).
* [releases](https://github.com/pmix/releases): This
repo contains all the PMIx releases branches (i.e., from which
official distribution tarballs are made).  There are Git tags on the
branches in this repo that indicate where official tarballs were made
(e.g., "v1.8.3" is the tag corresponding to the Open MPI v1.8.3
release).
* [tarballs](https://github.com/pmix/tarballs): This repo contains the official release tarballs.

Clone either the master or releases repository.  For example (as of Nov 2015), to clone the main development repository via HTTPS:

```
shell$ git clone https://github.com/pmix/master.git
Cloning into 'master'...
remote: Counting objects: 5319, done.
remote: Compressing objects: 100% (27/27), done.
remote: Total 5319 (delta 5), reused 0 (delta 0), pack-reused 5291
Receiving objects: 100% (5319/5319), 2.03 MiB | 600.00 KiB/s, done.
Resolving deltas: 100% (3958/3958), done.
Checking connectivity... done.
shell$
```

The web interface available by clicking on the above URL shows a
nice summary of recent activity and allows navigating into individual
commits.

Once you have successfully cloned the repository,
continue on to the [building](source/building) instructions on how to build
from a developer checkout.

Note that Git is natively capable of using many forms of web
proxies.  If your network setup requires the user of a web proxy,
[consult the Git documentation for more details](http://git-scm.com/)
