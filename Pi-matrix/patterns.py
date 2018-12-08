import imageio
import numpy as numpy
from matrix import Matrix

frame_queue = []

frames = []
for i in range(1, 36):
  frame = imageio.imread('firework_pattern/firework-' + str(i) + '.png.png')
  frames.append(frame)
print(frames)


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


# First frame
queue_frame(frames[0])

# Rest of frames
for i in range(1, len(frames)):
  queue_frame(
      frames[i],
      lambda row, col: any(frames[i][row][col] != frames[i - 1][row][col]))


if __name__ == '__main__':
  m = Matrix()
  while(not empty(frame_queue)):
    new_frame = frame_queue.pop(0)
    for pixel in new_frame:
      m.setPixel(pixel[0],''.join(pixel[1:]))

