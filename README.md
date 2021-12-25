# Logitech Driving Force Shifter USB Adapter

This project will allow you to use a Logitech G29/G920 shifter as a standalone USB device.

## Prerequisites

* Logitech Driving Force Shifter (Used with G29, G920, and G923 steering wheels)
* Arduino Leonardo
* [Arduino IDE](https://www.arduino.cc/en/software)
* [Arduino Joystick Library](https://github.com/MHeironimus/ArduinoJoystickLibrary)

## Wiring

![Shifter to Arduino wiring](/images/wiring.png)

## Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software)
2. Plug the Arduino into the PC
3. Open `logitech_shifter_usb.ino`
4. Follow the installation instructions for the [Arduino Joystick Library](https://github.com/MHeironimus/ArduinoJoystickLibrary)
5. In the Arduino IDE, select `Tools`-> `Board` -> `Arduino Leonardo`
6. In the Arduino IDE, select `Tools`-> `Port` -> `COM3 (Arduino Leonardo)` (The actual port number may be different)
7. Press the upload button

## Testing

### Windows:

1. Open Control Panel from the Start Menu
2. Under "Hardware and sound", click on "View devices and printers"
3. The Arduino should show up as a gamepad. Right-click the Arduino and click on "Properties"
4. Go to the "Test" tab and push the shifter into each gear. If buttons 1, 2, 3, 4, 5, 6 and 8 can all be seen as pressed (not at the same time), everything is working as it should
