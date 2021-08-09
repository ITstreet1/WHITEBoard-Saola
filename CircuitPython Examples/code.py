# Code for reading button state on digital pin 40 (IO40)
import time
import board
from digitalio import DigitalInOut, Direction, Pull

btn = DigitalInOut(board.IO40)
btn.direction = Direction.INPUT
btn.pull = Pull.UP

while True:
    if not btn.value:
        print("BTN is down")
    else:
        print("BTN is up")
        pass

    time.sleep(0.1) # sleep for debounce
