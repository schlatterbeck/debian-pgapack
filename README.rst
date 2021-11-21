Debian Package builder for PGApack
==================================

PGAPack_ is a general-purpose, data-structure-neutral, parallel genetic
algorithm library originally developed by David Levine at Argonne
National Laboratory. The parallel implementation uses the Message
Passing Interface standard MPI_. This package is intended to build
Debian packages for all supported MPI backends (currently one of
`mpich`, `openmpi`, or `lam`) and in addition a package for the serial
(non-parallel) version of PGApack.

After cloning this module, check out the `debian/sid` branch, get the
PGAPack_ code which is in a submodule::

  git submodule init
  git submodule update

and then build with::

  dpkg-buildpackage -rfakeroot

This will yield a PGAPack_ library package for each MPI backend and a
generic pgapack Debian package.

This package was adapted from the effort of Dirk Eddelbuettel who
maintained a pgapack debian package for several years after having
negotiated a free license for PGApack with Argonne National Laboratory.
