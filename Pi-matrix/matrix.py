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
      if rgb[i] == '1': self.rgb_out[i].on()
      else: self.rgb_out[i].off()

    self.we_out.on()
    sleep(0.5)
    self.we_out.off()


if __name__ == "__main__":
  m = Matrix()

  sleep(0.5)
  m.setPixel(1, '111')
  sleep(0.5)
  m.setPixel(2, '011')
  sleep(0.5)
  m.setPixel(3, '111')
  while True:
    pass