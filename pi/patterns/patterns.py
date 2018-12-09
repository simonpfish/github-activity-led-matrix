import argparse
import imageio
import numpy as numpy
import os


def load_frames(dirname):
  frames = []

  files = os.listdir(dirname)
  files.sort()

  for filename in files:
    print(dirname + '/' + filename)
    frame = imageio.imread(dirname + '/' + filename)
    frames.append(frame)

  return frames


def get_pixels(frame, conditional=lambda r, c: True):
  pixel_queue = []
  for row in range(len(frame)):
    for col in range(len(frame[row])):
      pixel = frame[row][col]
      r, g, b = [1 if bool(p) else 0 for p in pixel[0:3]]
      address = row * 32 + col
      if conditional(row, col):
        pixel_queue.append((address, int('{}{}{}'.format(r, g, b), 2)))

  return pixel_queue


def queue_directory(dirname):
  frame_queue = []

  frames = load_frames(dirname)
  # First frame
  frame_queue.append(get_pixels(frames[0]))

  # Rest of frames
  for i in range(1, len(frames)):
    frame_queue.append(
        get_pixels(
            frames[i],
            lambda row, col: any(frames[i][row][col] != frames[i - 1][row][col])
        ))

  return frame_queue


def print_frame_queue(frame_queue):
  for frame in frame_queue:
    for pixel in frame:
      print(pixel[0], pixel[1])

    print('')


if __name__ == '__main__':
  parser = argparse.ArgumentParser(
      description='Generate frame queue from png files in a directory')
  parser.add_argument(
      'directory',
      metavar='DIRECTORY',
      type=str,
      help='an integer for the accumulator')

  args = parser.parse_args()
  q = queue_directory(args.directory)
  print_frame_queue(q)