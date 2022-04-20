# Logitech Driving Force Shifter USB Adapter

## Prerequisites

* Logitech Driving Force Shifter (Used with G29, G920, and G923 steering wheels)
* Arduino Leonardo or Arduino Micro
* [Arduino IDE](https://www.arduino.cc/en/software)
* [Arduino Joystick Library](https://github.com/MHeironimus/ArduinoJoystickLibrary)

## Wiring

![Shifter to Arduino wiring](/logitech_shifter_usb/images/wiring.png)
The pinout is the same for the Arduino Micro.

## Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software)
2. Plug the Arduino into the PC
3. Open `logitech_shifter_usb.ino`
4. Follow the installation instructions for the [Arduino Joystick Library](https://github.com/MHeironimus/ArduinoJoystickLibrary)
5. In the Arduino IDE, select `Tools`-> `Board` -> `Arduino Leonardo` or `Arduino Micro` depending on the board you are using.
6. In the Arduino IDE, select `Tools`-> `Port` -> Select the device to put the code on, it should look something like `COM3 (Arduino Leonardo)`.
7. Press the upload button.

## Testing

### Windows:

1. Open Control Panel from the Start Menu
2. Under "Hardware and sound", click on "View devices and printers"
3. The Arduino should show up as a gamepad. Right-click the Arduino and click on "Properties"
4. Go to the "Test" tab and push the shifter into each gear. If buttons 1, 2, 3, 4, 5, 6 and 8 can all be seen as pressed (not at the same time), everything is working as it should.

If the shifter reports being in 3rd/4th when it is in 5th/6th or 1st/2nd, adjust the values in `X_LEFT` or `X_RIGHT` and reupload the code to the arduino.
