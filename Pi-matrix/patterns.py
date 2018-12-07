import imageio
import numpy as numpy

frames = []
for i in range (1,36):
  frame = imageio.imread('firework_pattern/firework-'+str(i)+'.png.png')
  frames.append(frame)
print(frames)

pixel_queue = []



