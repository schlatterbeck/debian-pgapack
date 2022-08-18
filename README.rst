Debian Package builder for PGApack
==================================

PGAPack_ is a general-purpose, data-structure-neutral, parallel genetic
algorithm library originally developed by David Levine at Argonne
National Laboratory. The parallel implementation uses the Message
Passing Interface standard MPI_. This package is intended to build
Debian packages for all supported MPI backends (currently one of
`mpich`, `openmpi`, or `lam`) and in addition a package for the serial
(non-parallel) version of PGApack.

This module used to have the original sources on the master branch and
maintain the debianized version in the debian/sid branch. This is now
history. Instead we maintain the original sources in a git submodule.
Everything to build the latest version is now on the master branch.

After cloning this module, get the PGAPack_ code which is in a submodule::

  git submodule init
  git submodule update

and then build with::

  dpkg-buildpackage -rfakeroot

This will yield a PGAPack_ library package for each MPI backend and a
generic pgapack Debian package. Note that for me the lam MPI backend
does not work, there is a `Debian bug report`_ for it.

This package was adapted from the effort of Dirk Eddelbuettel who
maintained a pgapack debian package for several years after having
negotiated a free license for PGApack with Argonne National Laboratory.

.. _PGAPack: https://github.com/schlatterbeck/pgapack 
.. _MPI: http://mpi-forum.org/ 
.. _`Debian bug report`:
    https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=1000446

