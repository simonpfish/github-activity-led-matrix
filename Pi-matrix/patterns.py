import imageio
import numpy as numpy
from matrix import Matrix

frame_queue = []

frames = []
for i in range(1, 7):
  frame = imageio.imread('simon_pattern/Simon-' + str(i) + '.png.png')
  frames.append(frame)


def queue_frame(frame, conditional=lambda r, c: True):
  pixel_queue = []
  for row in range(len(frame)):
    for col in range(len(frame[row])):
      pixel = frame[row][col]
      r, g, b = [1 if bool(p) else 0 for p in pixel[0:3]]
      address = row * 32 + col
      if conditional(row, col):
        pixel_queue.append((address, r, g, b))

  frame_queue.append(pixel_queue)


print('start q')

# First frame
queue_frame(frames[0])

# Rest of frames
for i in range(1, len(frames)):
  queue_frame(
      frames[i],
      lambda row, col: any(frames[i][row][col] != frames[i - 1][row][col]))

print('end q')

if __name__ == '__main__':
  m = Matrix()
  from time import sleep
  while True:
    for frame in frame_queue:
      for pixel in frame:
        m.setPixel(pixel[0], pixel[1:])
      sleep(0.5)
