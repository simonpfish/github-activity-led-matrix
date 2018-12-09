import imageio
import numpy as numpy
import string

LETTER_WIDTH = 6
NUM_LETTERS = 32/6

letters = list(string.ascii_lowercase)

frame_queue = []

letter_frames = {}
for i in range(26):
  frame = imageio.imread('alphabet/alphabet' + str(i) + '.png')
  letter_frames[letters[i]] = frame
print(letter_frames)

def queue_username(username, start_address):
  truncated_username = username[:5]
  for i in range(5):
    queue_letter_frame(truncated_username[i], start_address+(i*6))




def queue_letter_frame(letter, top_left_address):
  frame = letter_frames[letter]
  pixel_queue = []
  for row in range(len(frame)):
    for col in range(len(frame[row])):
      pixel = frame[row][col]
      r, g, b = [1 if bool(p) else 0 for p in pixel[0:3]]
      address = row * 32 + col
      pixel_queue.append((address, r, g, b))

  frame_queue.append(pixel_queue)






