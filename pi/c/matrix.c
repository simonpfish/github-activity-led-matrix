#include "EasyPIO.h"
#include "frames/Simon.c"
#include "frames/alphabet.c"
#include "frames/firework.c"
#include "frames/meteors.c"
#include "frames/rainbow_explosion.c"
#include "frames/snow_angel.c"
#include "frames/storm.c"
#include <stdio.h>
#include <string.h>

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

void addCharacter(uint32_t frame[1024], char character, int offset) {

  int char_index;
  if(character > 64){ //Capital alphabetic character
    char_index = character - 55;
  }else{ //Digit
    char_index = character -48;
  }

  for (int i = 0; i < 5 * 7; i++) {
    int row = (i / 5);
    int col = (i % 5) + offset;

    if (-1 < col && col < 32)
      frame[32 * row + col] = alphabet_data[char_index][i];
  }
}

void addString(uint32_t frame[1024], char string[], int scroll) {
  int word_length = strlen(string);

  for (int i = 0; i < word_length; i++) {
    int offset = 6 * i - scroll;
    if (offset > 31)
      continue;

    addCharacter(frame, string[i], offset);
  }
}

void scrollString(char string[], int loops) {
  int length = strlen(string) * 6;

  for (int loop = 0; loop < loops; loop++) {
    for (int i = -32; i < length; i++) {
      uint32_t frame[1024] = {0x00000000};
      addString(frame, string, i);
      displayFrame(frame);
      delayMillis(200);
    }
  }
}

uint32_t *overlayFrames(uint32_t frame_a[1024], uint32_t frame_b[1024]) {
  uint32_t frame[1024] = {0x00000000};

  for (int i = 0; i < 1024; i++) {
    frame[i] = frame_a[i];
    frame[i] = frame_b[i];
  }

  return frame;
}

void displayAnimWithString(const uint32_t frames[][1024], int length,
                           int framerate, char string[], int loops) {
  int length = strlen(string) * 6;

  for (int loop = 0; loop < loops; loop++) {
    for (int i = -32; i < length; i++) {
      uint32_t string_frame[1024] = {0x00000000};
      addString(string_frame, string, i);
      displayFrame(overlayFrames(string_frame, frames[i % length]));
      delayMillis(1000 / framerate);
    }
  }
}

int main(int argc, char const *argv[]) {
  pioInit();
  matrixInit();

  if (argc == 1) {
    printf("You must enter the name of an animation to display \n");
    return 1;
  }

  int framecount = 0;
  uint32_t *frames[1024] = {};

  if (argc >= 2) {
    if (strcmp(argv[1], "firework") == 0) {
      const frames = firework_data;
      framecount = FIREWORK_FRAME_COUNT;
    } else if (strcmp(argv[1], "meteors") == 0) {
      const frames = meteors_data;
      framecount = METEORS_FRAME_COUNT;
    } else if (strcmp(argv[1], "storm") == 0) {
      const frames = storm_data;
      framecount = STORM_FRAME_COUNT;
    } else if (strcmp(argv[1], "rainbow-explosion") == 0) {
      const frames = rainbow_explosion_data;
      framecount = RAINBOW_EXPLOSION_FRAME_COUNT;
    }
  }

  if (argc == 2) {
    displayAnim(frames, framecount, 6);
  } else if (argc == 3) {
    displayAnimWithString(frames, framecount, 6, argv[2], 2);
  }
}
