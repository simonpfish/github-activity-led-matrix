import imageio
import numpy as numpy
import string

LETTER_WIDTH = 6
NUM_LETTERS = 32//6

frame_queue = []
pixel_queue = []

def load_letter_frames():
  letters = list(string.ascii_lowercase)
  letter_frames = {}
  for i in range(26):
    frame = imageio.imread('frames/alphabet/alphabet' + str(i) + '.png')
    letter_frames[letters[i]] = frame

def create_word_frame(word, start_address):
  frame_queue = []
  pixel_queue = []
  for n in range(len(word)-NUM_LETTERS+1):
    truncated_word = word[n:n+NUM_LETTERS]
    for i in range(NUM_LETTERS):
      letter = truncated_word[i]
      top_left_address = start_address+(i*6)
      queue_letter_pixels(letter, top_left_address)
    frame_queue.append(pixel_queue)


def queue_letter_pixels(letter, top_left_address):
  frame = letter_frames[letter]
  for row in range(len(frame)):
    for col in range(len(frame[row])):
      pixel = frame[row][col]
      r, g, b = [1 if bool(p) else 0 for p in pixel[0:3]]
      address = top_left_address + (row * 32) + col
      pixel_queue.append((address, r, g, b))
  # Padding for the 6th column
  for row in range(0, len(frame)+1):
    address = top_left_address + (row * 32) + len(frame[0])
    pixel_queue.append((address, 0, 0, 0))
  # Padding for the 8th row
  for col in range(0, len(frame[0])+1):
    address = top_left_address + (len(frame) * 32) + col
    pixel_queue.append((address, 0, 0, 0))






