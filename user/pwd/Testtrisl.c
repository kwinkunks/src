#include <stdio.h>

#include <rsf.h>

#include "trisl.h"

int main(void) {
    double dot1[2], dot2[2];
/*    static int n1=100, n2=100, rect1=10, rect2=5; */
    static int n1=7, n2=7, rect1=3, rect2=3; 
    int i1, i2;
    float **p;

    p = sf_floatalloc2(n1,n2);

    for (i2=0; i2 < n2; i2++) {
	for (i1=0; i1 < n1; i1++) {
	    p[i2][i1] = (i1-n1/2)*(i2-n2/2)/((n1-1.)*(n2-1.));
	}
    }

    trisl_init(n1, n2, rect1, rect2);
    trisl_set(p);
    sf_dot_test(trisl_lop, n1*n2, n1*n2, dot1, dot2);
    trisl_close();

    printf ("%12.8f ? %12.8f\n",dot1[0],dot1[1]);
    printf ("%12.8f ? %12.8f\n",dot2[0],dot2[1]);

    exit(0);
}
