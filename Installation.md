Installation Instructions
=========================

Hardware Requirements
---------------------

*   Arduino UNO control board
*   Arduino expansion board
*   Power supply board
*   4 Mecanum wheels
*   2 motor driver boards
*   4 JGB37-520 DC motors
*   3D printed main body model
*   Bluetooth module (optional)
*   12V battery or other suitable power supply
*   Dupont wires, screws, and other small accessories

Software Requirements
---------------------

*   Arduino IDE

Installation Steps
------------------

1. **Download the code**

   Download the Mecanum wheel intelligent small car code from [main.ino](https://github.com/CassiusXiang/OmniRob/tree/main/Software/main).

2. **Connect the hardware**

   Insert the Arduino UNO control board into the computer and use Dupont wires to connect the DC motors and other expansion modules.

3. **Open Arduino IDE**

   Open the Arduino IDE software and open the code file. Click "Tools"->"Board" and select "Arduino Uno" as the board.

4. **Upload the code**

   Click "Sketch"->"Upload" to upload the code.

5. **Control**

   Open the Bluetooth serial debugging assistant, find and connect to the Bluetooth module in the device list. Enter commands in the debugging assistant to control the small car to move forward, backward, turn left, turn right, and other actions.

Physical Sample
---------------

Picture of the assembled physical sample:

![](image/2.jpg)

Wiring diagram:

![](image/3.jpg)

Precautions
-----------

*   During the installation process, please read the comments in the code carefully and connect the hardware correctly.
*   When using the Bluetooth serial debugging assistant, please make sure that the Bluetooth module has been found and connected successfully in the device list.
*   When controlling the small car, please pay attention to safety. Do not place the small car on an unbalanced or easily tilted surface to avoid accidents.
*   Please refer to the physical sample for installation and pay attention to the direction of the Mecanum wheels.
*   Please refer to the wiring diagram for wiring.
