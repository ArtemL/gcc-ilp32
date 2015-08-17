/* Functional tests for the function hotpatching feature.  */

/* { dg-do compile } */
/* { dg-options "-O3 -mzarch -mhotpatch=0,4 --save-temps" } */

#include <stdio.h>

void hp1(void)
{
  printf("hello, world!\n");
}

/* Check number of occurences of certain instructions.  */
/* { dg-final { scan-assembler-times "nopr\t%r7" 1 } } */
/* { dg-final { scan-assembler-not "nop\t0" } } */
/* { dg-final { scan-assembler-times "brcl\t\t0,0" 1 } } */