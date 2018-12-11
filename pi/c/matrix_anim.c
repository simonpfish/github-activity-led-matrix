#include "EasyPIO.h"
#include "frames/Simon.c"
#include "frames/firework.c"
#include "frames/flowers.c"
#include "frames/meteors.c"
#include "frames/rainbow_explosion.c"
#include "frames/snow_angel.c"
#include "frames/storm.c"
#include "matrix.c"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  pioInit();
  matrixInit();

  if (argc == 1) {
    printf("You must enter the name of an animation to display \n");
    return 1;
  }

  if (strcmp(argv[1], "firework") == 0)
    displayAnim(firework_data, FIREWORK_FRAME_COUNT, 6);
  else if (strcmp(argv[1], "meteors") == 0)
    displayAnim(meteors_data, METEORS_FRAME_COUNT, 6);
  else if (strcmp(argv[1], "storm") == 0)
    displayAnim(storm_data, STORM_FRAME_COUNT, 6);
  else if (strcmp(argv[1], "rainbow-explosion") == 0)
    displayAnim(rainbow_explosion_data, RAINBOW_EXPLOSION_FRAME_COUNT, 6);
  else if (strcmp(argv[1], "flowers") == 0)
    displayAnim(flowers_data, FLOWERS_FRAME_COUNT, 6);
  else
    scrollString((char *)argv[1], 1, 12);
}