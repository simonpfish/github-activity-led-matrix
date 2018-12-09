from gpiozero import OutputDevice
from time import sleep

address_pins = [18, 23, 24, 25, 8, 7, 12, 16, 20, 21]
rgb_pins = [6, 13, 19]
we_pin = 26


class Matrix():

  def __init__(self):

    self.adr_out = [OutputDevice(pin) for pin in address_pins]
    self.rgb_out = [OutputDevice(pin) for pin in rgb_pins]
    self.we_out = OutputDevice(26)

    for out in self.adr_out + self.rgb_out + [self.we_out]:
      out.off()

  def setPixel(self, adr, rgb):
    adr_bits = bin(adr)[2:].zfill(10)

    for i in range(len(adr_bits)):
      if adr_bits[i] == '1': self.adr_out[i].on()
      else: self.adr_out[i].off()

    for i in range(len(rgb)):
      if rgb[i]: self.rgb_out[i].on()
      else: self.rgb_out[i].off()

    self.we_out.on()
    self.we_out.off()


if __name__ == "__main__":
  m = Matrix()

  for i in range(32 * 32):
    m.setPixel(i, [1 if x == '1' else 0 for x in bin(i)[-3:]])

  sleep(0.5)

  for i in range(32 * 32):
    m.setPixel(i, [0, 0, 0])
    sleep(0.1)

  while True:
    pass