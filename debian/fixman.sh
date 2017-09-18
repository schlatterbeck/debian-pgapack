#!/bin/sh
#
# krs@debian.org  4 Nov 96
# edits all man pages to put them in man3
#
SECS='1 2 4 5 6 7 8 l'
srcdir=$PWD
test -d tmpman || mkdir tmpman
for s in $SECS; do
	cd $srcdir/man/man$s;
	for f in *.$s; do
		base=`basename $f .$s`;
		cp $f $srcdir/tmpman/$base.3;
	done;
done;
cp $srcdir/man/man3/* $srcdir/tmpman
