/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-loop2_unroll -fno-peel-loops -fno-tree-vrp -fdisable-tree-cunroll -fdisable-tree-cunrolli -fenable-rtl-loop2_unroll=foo" } */

unsigned a[100], b[100];
inline void bar()
{
 a[10] = b[10];
}

int foo(void)
{
  int i;
  bar();
  for (i = 0; i < 2; i++)
  {
     a[i]= b[i] + 1;
  }
  return 1;
}

int foo2(void)
{
  int i;
  for (i = 0; i < 2; i++)
  {
     a[i]= b[i] + 1;
  }
  return 1;
}

/* { dg-final { scan-rtl-dump-times "loop turned into non-loop; it never loops" 1 "loop2_unroll" } } */
/* { dg-final { cleanup-rtl-dump "loop2_unroll" } } */
