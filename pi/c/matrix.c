#include "EasyPIO.h"
#include "frames/firework.c"
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

void setFrame(int adr, int rgb) {
  writeAdr(adr);
  writeRGB(rgb);

  digitalWrite(WE_PIN, 1);
  digitalWrite(WE_PIN, 0);
}

int main(int argc, char const *argv[]) {
  pioInit();
  matrixInit();

  int adr, rgb;
  while (scanf("%d %d", &adr, &rgb) != EOF) {
    setPixel(adr, rgb);
  }

  return 0;
}
