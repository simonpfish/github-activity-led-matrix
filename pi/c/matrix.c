#include "EasyPIO.h"
#include "frames/Simon.c"
#include "frames/firework.c"
#include "frames/meteors.c"
#include "frames/snow_angel.c"
#include <stdio.h>

const int ADR_PINS[] = {21, 20, 16, 12, 7, 8, 25, 24, 23, 18};
const int RGB_PINS[] = {6, 13, 19};
const int WE_PIN = 26;

void matrixInit() {
  pinMode(WE_PIN, OUTPUT);
  digitalWrite(WE_PIN, 0);

  for (int i = 0; i < 10; i++)
    pinMode(ADR_PINS[i], OUTPUT);
  for (int i = 0; i < 3; i++)
    pinMode(RGB_PINS[i], OUTPUT);
}

void writeAdr(int adr) {
  for (int i = 0; i < 10; i++) {
    if (adr & (1 << i))
      digitalWrite(ADR_PINS[i], 1);
    else
      digitalWrite(ADR_PINS[i], 0);
  }
}

void writeRGB(int rgb) {
  for (int i = 0; i < 3; i++) {
    if (rgb & (1 << i))
      digitalWrite(RGB_PINS[i], 1);
    else
      digitalWrite(RGB_PINS[i], 0);
  }
}

void setPixel(int adr, int rgb) {
  writeAdr(adr);
  writeRGB(rgb);

  digitalWrite(WE_PIN, 1);
  digitalWrite(WE_PIN, 0);
}

void displayFrame(const uint32_t frame_data[]) {
  // All frames must be 32x32
  for (int i = 0; i < 1024; i++) {
    uint32_t raw_rgb = frame_data[i];

    uint32_t r = !!(raw_rgb & 0xFF);
    uint32_t g = !!(raw_rgb & (0xFF << 8)) << 1;
    uint32_t b = !!(raw_rgb & (0xFF << 16)) << 2;

    setPixel(i, r | g | b);
  }
}

void displayAnim(const uint32_t frames[][1024], int length, int framerate) {
  for (int i = 0; i < length; i++) {
    displayFrame(frames[i]);
    delayMillis(1000 / framerate);
  }
}

int main(int argc, char const *argv[]) {
  pioInit();
  matrixInit();

  // displayAnimation(meteors_data, METEORS_FRAME_COUNT, 0);
  displayAnim(firework_data, FIREWORK_FRAME_COUNT, 6);
}
