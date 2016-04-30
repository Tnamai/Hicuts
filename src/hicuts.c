#include "hicuts.h"

int main(int argc, char *argv[])
{
  rule a;
  char *s = "hoge";
  a.field = &(s);
  printf("%s\n", *(a.field));
  return 0;
}


