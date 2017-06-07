#include <stdio.h>
#include "include/add.h"
#include "include/minus.h"

int main(int argc, char **argv) {
  int sum = add(1, 2);
  int difference = minus(1, 2);
  printf("Sum: %d. Difference: %d.\n", sum, difference);
  return 0;
}
