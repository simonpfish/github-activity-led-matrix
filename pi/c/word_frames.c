#include "frames/alphabet.c"
#include "matrix.c"
#include <stdio.h>
#include <string.h>

void create_word_frame(char word[], int start_address,
                       uint32_t word_frames[1][1024]) {
  int word_length = strlen(word);
  printf("%d\n", word_length);

  // For now truncate to 5 characters
  for (int i = 0; i < 5; i++) {
    int letter_index = word[i] - 65;
    printf("%d\n", letter_index);
    int top_left_address = start_address + (6 * i);

    // Copy
    for (int r = 0; r <= ALPHABET_FRAME_HEIGHT; r++) {
      for (int c = 0; c <= ALPHABET_FRAME_WIDTH; c++) {
        int address = top_left_address + r * 32 + c;
        // Padding to make it 6x8
        if (r == ALPHABET_FRAME_HEIGHT || c == ALPHABET_FRAME_WIDTH) {
          word_frames[0][address] = 0x00000000;
        }
        // Copy value from the letter frame to the 32x32 frame
        else {
          word_frames[0][address] = alphabet_data[letter_index][r * 5 + c];
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  uint32_t word_frames[1][1024] = {0x00000000};
  create_word_frame("MADDIE", 0, word_frames);
  displayFrame(word_frames[0]);
  return 0;
}