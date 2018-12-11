#include "EasyPIO.h"
#include "matrix.c"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  pioInit();
  matrixInit();

  if (argc == 1) {
    printf("You must enter the text to display \n");
    return 1;
  }

  scrollString((char *)argv[1], 1, 12);
}