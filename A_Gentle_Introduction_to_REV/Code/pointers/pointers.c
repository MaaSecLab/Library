#include <stddef.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  int x[4] = { 1,2,3,4 };
  int *pointer = x;

  size_t length = sizeof(x) / sizeof(x[0]);
  int sum = 0;
  for (int i = 0; i < length; i++){
    sum += *pointer;
    pointer += 1;
  }

  printf("%d", sum);

  

  return 0;
}
