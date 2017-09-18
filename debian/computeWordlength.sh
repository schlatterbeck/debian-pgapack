#!/bin/sh

tmpfile=$(tempfile)
ctmpfile="${tmpfile}.c"
cat <<EOF > ${ctmpfile}
#include <stdio.h>
int main(void) {
    if (8 == sizeof(long))
	printf("-DWL=64");
    else
	printf("-DWL=32");
    return(0);
}
EOF
gcc -o ${tmpfile} ${ctmpfile}
wordlength=$(${tmpfile})
echo "${wordlength}"
rm -f ${tmpfile} ${ctmpfile}
exit 0
