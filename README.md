# WHITEBoard-Saola

![20210630_140946](https://user-images.githubusercontent.com/30090189/123960235-5b591100-d9af-11eb-99df-d8d80138b1d2.jpg)

WHITEBoard Saola is a development board based on ESP32 S2 module. It has all features that ESP32 S2 offers, plus some aditional. In this repo you will find all the data you need to make this board, that include schematic, gerber files, etc. In adition, there are examples for all features that this Saola variant offers.

## Features

* ESP32-S2-WROOM
  * MCU
    * 128 KB RAM
    * 320 KB SRAM
    * 16 KB SRAM in RTC
  * Wi-Fi
    * 802.11b/g/n
    * Bit rate: 802.11n up to 150 Mbps
    * A-MPDU and A-MSDU aggregation
    * 0.4μs guard interval support
    * Center frequency range of operating channel:2412~2484 MHz
  * Hardware
    * Interfaces: GPIO, SPI, LCD, UART, I2C, I2S,Camera interface, IR, pulse counter, LED PWM,TWAITM(compatible with ISO 11898-1), USBOTG 1.1, ADC, DAC, touch sensor, temperaturesensor
    * 40 MHz crystal oscillator
    * 4 MB SPI flash
    * Operating voltage/Power supply: 3.0~3.6 V
    * Operating temperature range: –40~85 °C
    * Dimensions: (18 × 31 × 3.3) mm
  * Certification
    * Green certification: RoHS/REACH
    * RF certification: FCC/CE-RED/SRRC
  * Test
    * HTOL/HTSL/uHAST/TCT/ESD
* All GPIO pins breaks into two header rows
* UART CP2102N chip with auto reset circuit
* User Buttons
  * BOOT
  * RST
  * BTN
* WS2812C LED
  * WS2812C is fully compatible with WS2812B
  * Operating Currentof 5 mA
  * Built-in signal reshaping circuit
  * Built-in electric reset circuit and power lost reset circuit
  * Send data at speeds of 800 Kbps
  * Scan frequency 2 KHz
  * 256 brightness display
  * 16777216 color
* MPU-6050
  * I2C digital output
  * 6 or 9 axis MotoFusion data in rotation matrix
  * Selectable solder jumps on CLK, FSYNC and AD0
  * Tri-Axis angular sensor (gyro) with a sensitivity up to 131 LSBs/dps
  * Tri-Axis accelerometer with a programmable full scale range of ±2g, ±4g, ±8g and ±16g
  * Digital Motion Processing™ (DMP™) engine offloads complex MotionFusion, sensor timing synchronization and gesture detection
  * Digital-output temperature sensor
* Li-Po JST connector with MCP73831 charging circuit
* Micro USB UART port
* Micro USB OTG port
* Power switch

![20210630_141002](https://user-images.githubusercontent.com/30090189/123966230-82b2dc80-d9b5-11eb-950c-f5ba528b895e.jpg)

## Getting started

WHITEBoard Saola is a development board that can be programmed through Arduino IDE, or CircuitPython and MicroPython. 

### Arduino IDE C/C++

#### PROG PORT

For Arduino IDE, first you have to add ESP32-S2 support. This can be done by adding V2.0 Boards support:
-https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
in File->Preferences->URL and then install through board manager. When done, just select ESP32S2 Dev Module in Boards, proper port and you are good to go. Here you can find some example sketches that will work with hardware on-board. They are not in a form of a library. By plugging into a computer through a PROG micro USB port, the upload will be done without the need to press BOOT or RST buttons.

#### OTG PORT

To use this port to upload the sketch, first you need to install a driver for ESP32-S2. Then, you need to connect the WHITEBoard to a PC in BOOT mode. That can be done by holding the BOOT button while connecting to a PC. If your PC does not recognize a board, you need to install drivers. For that please install Zadig Software, and install the recommended driver (ESP32-S2 (Interface_2)). After that, Saola will show up in Device Manager, and can be selected in IDE while choosing a port. Upload goes the same as in the first method. As there is no reset method, you need to press RST so Saola can leave BOOT mode and start working as programmed.

### CircuitPython

If your choice is a CircuitPython, you need to have installed the latest version of Python. To check what version you have, open Command Prompt and type in:

*python --version*

For erasing and uploading a firmware on ESP32-S2 you need Development mode Esptool, download it by typing:

*git clone https://github.com/espressif/esptool.git*
*cd esptool*
*pip install -e .*

If no problem you should get a massage everything is ok. To check if everything is ok, type in:

*esptool.py*

You should get a list of commands with list of supported chips, in our case esp32s2. The next step is to download a BIN fajl of CircuiPython. Go to https://circuitpython.org and search Wroom as that is the modul of ESP32-S2 we use here. Select Saola1 w/WROOM, that will get you to the download page. Download BIN fajl on some location on your PC.
The next step is to erease Flash of Esp32-S2. To do connect WHITEBoard Saola to a PC with PROG port, and type in:

*esptool.py --chip esp32s2 erase_flash*

Now it is time to upload the CircuitPython firmware to the WHITEBoard Saola. To do so check on which COM port i Saola (say it is COM7). In prompt type:

*esptool.py --chip esp32s2 --port COM7 --baud 921600 write_flash -z 0x000 C:\{location}adafruit-circuitpython-espressif_saola1_wroom-en_US-6.3.0.bin*

Here you should use appropriate COM port and appropriate path to a downloaded file. The name of the file might not be as one here. Version of the software will change in time to come. After successefully uploaded CircuitPython unplug Saola and plug it again, this time through OTG port. Saola will mount as a drive CIRCUITPYTHON.

### MicroPython

-- under construction section --

![20210630_141012](https://user-images.githubusercontent.com/30090189/123969673-bba08080-d9b8-11eb-8d52-94eccd9d4cb3.jpg)

## Features

### User button BTN

WHITEBoard Saola offers a selection of usage its features at its bottom. As the user button BTN is tied to a GPIO40, there is a solder jumper if you need GPIO40 on a header pinout instead of a button. By default, it is open for both sides. Button BTN has a 10K resistor in the pull-down, so when pressed, it will have HIGH logic.

### RGB LED

RGB LED is tied to a GPIO18. Same as for BTN, there is an open solder jumper which you can close in the way of your need. Of course, you can not have both.

### LiPo charging meter

There are two resistors, 22K and 5.6K as a voltage divider. They are tied to a GPIO01, which is Analog pin A0. As for RGB and BTN, under WHITEBoard Saola, there is a solder jumper. You can choose if you want to use GPIO01 on the header, or to measure battery voltage level.

## Power

For power management, this board uses two ICs. MCP73831 For battery management check the LiPo charging section below.
WHITEBoard Saola can be powered up by any of the micro USB connectors. 5V rail is going to the SE5218 voltage regulator. This is an LDO that provides 3.3V@500mA. While testing, I had ZERO issues with stability. But it also means that Saola can not directly power up some power-hungry sensors or modules. In such a case, use an external power supply.
There is no dedicated VIN pin to power WHITEBoard Saola through pinout. However, pin 5V can be used to power Saola with REGULATED 5V DC. Do not use pin 3V3 in a similar manner. However, you CAN NOT charge battery through 5V pin.
The switch under the board is manipulating with the EN pin of the LDO. This way powers up the board. There is a MOSFET for switching the power supply. Saola will cut the battery when there is 5V power on micro USBs or 5V pin. Charging the battery remains all the time when there is 5V. The same goes for the power switch position.

## LiPo charging

For Li-Po charging there is the MCP73831 IC. With a resistor R16 of 2K, charging is set to 500mA charging current. By replacing this resistor you can change the charging current. Here is the table:
* 10K - 100mA
* 5K  - 200mA 
* 2K  - 500mA
* 1K  - 1000mA

Onboard there is a JST 2.00mm pitch connector. As JST is NOT standardized, please check the battery polarity. Wrong polarity can destroy the board and/or battery. Supported batteries are standard Li-Ion/Li-Po with 3.7V nominal voltage. You can use a battery of any capacity.

If the project is for use with a battery, there is a switch on the right side that basically switch from VCC to GND on the EN pin of a voltage regulator. This way you can enable or disable power to the BOARD. In case you can not upload the sketch to a WHITEBoard Saola, please check the position of this switch. While turned OFF by this switch, you can still charge the battery by any of the micro USB ports.

![20210630_141027](https://user-images.githubusercontent.com/30090189/123978647-52bd0680-d9c0-11eb-8733-6fbeafa35515.jpg)

## Pinout

WHITEBoard Saola has a two-row header with 42 pins in total. Depending on the purpose, pins are in a different color. Red for power, black as GND, blue GPIO, and white are special pins. Here you can find the boards diagram so check it out. As I mention, WHITEBoard Saola has all ESP32-S2 pins break out. That is the reason for the size of the board, besides 0805 components and soldering on one side only. To power additional sensors and modules, there are two GND pins and two power pins (5V and 3.3V). There is no VIN pin (check the Power part above). As for white pins, special ones are considered GPIO0 as BOOT pin, GPIO1 (ADC1_0) where voltage divider for battery measurement is tied. There is a jumper selection under the board. I2C pins(GPIO8 and GPIO9), R for Reset, TX and RX for obvious reasons, and GPIO40 and GPIO18. These last two are used for user BTN and RGB LED. The same goes as for GPIO1. GPIO pins are NOT 5V TOLERANT!!! Use some logic shifter, voltage divider, or OP-AMP when interfacing 5V devices.

* First Row
  * 3V3
  * GPIO0 (BOOT)
  * GPIO1 (Battery meter)
  * GPIO2
  * GPIO3
  * GPIO4
  * GPIO5
  * GPIO6
  * GPIO7
  * GPIO8 (SDA)
  * GPIO9 (SCL)
  * GPIO10
  * GPIO11
  * GPIO12
  * GPIO13
  * GPIO14
  * GPIO15
  * GPIO16
  * GPIO17
  * 5V
  * G
* Second Row
  * G
  * R
  * GPIO46
  * GPIO45
  * RX
  * TX
  * GPIO42
  * GPIO41
  * GPIO40 (usr BTN)
  * GPIO39
  * GPIO38
  * GPIO37 (MISO)
  * GPIO36 (SCK)
  * GPIO35 (MOSI)
  * GPIO34 (SS)
  * GPIO33
  * GPIO26
  * GPIO21
  * GPIO20
  * GPIO19
  * GPIO18 (RGB LED)

## PROS

* LiPo battery
* RGB LED
* WiFi
* Gyro
* User button
* OTG and UART micro USB
* Complete GPIO pinout

## CONS

* No Bluetooth
* One Core

## Dimensions

Dimensions of this board are 28x90mm. The hight is 7mm (without headers).

## Disclaimer

WHITEBoard Saola is an open-source development board. My small contribution to the community, that gave me so much. Feel free to use and modify as you want. It would be nice to add some credits if you do.
