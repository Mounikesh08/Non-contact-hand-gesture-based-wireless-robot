# Non contact Hand Gesture Based Wireless Robot

A wireless gesture-controlled robotic arm using Arduino, MPU6050 accelerometer, RF communication, and servo motors. This project enables users to control a robotic arm and navigation platform using hand gestures, suitable for applications like pick-and-place tasks, hazardous material handling, and more.

## Table of Contents
- [Project Overview](#project-overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Limitations](#limitations)
- [Applications](#applications)
- [License](#license)

## Project Overview
This project implements a wireless gesture-controlled robotic arm with a navigation platform. The system uses an Arduino Nano for gesture detection via an MPU6050 accelerometer and push buttons, transmitting commands wirelessly using an RF module (nRF24L01). The receiver, also an Arduino-based system, controls DC motors (via L293D driver) for navigation and servo motors for the robotic arm's movements.

Key features:
- Gesture-based control for forward, backward, left, right, pick, place, up, and down movements.
- Wireless communication up to 1 km (line-of-sight).
- Low-cost and recyclable materials for sustainability.

## Hardware Requirements
- Arduino Nano (2 units: one for transmitter, one for receiver)
- MPU6050 accelerometer/gyroscope module
- nRF24L01 RF module (2 units)
- L293D motor driver
- DC motors (4 units for navigation platform)
- Servo motors (4 units: MG995 for arm and gripper)
- Push buttons (4 units)
- 9V battery (for transmitter)
- 12V battery (for receiver motors)
- Acrylic sheet and aluminum 2020 for structural components
- Breadboard, jumper wires, and other connectors

## Software Requirements
- Arduino IDE (version 1.8.19 or later)
- Libraries:
  - `Wire` (included with Arduino IDE)
  - `MPU6050` (by Electronic Cats)
  - `RF24` (by TMRh20)
  - `Servo` (included with Arduino IDE)

## Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/Gesture-Controlled-Robotic-Arm.git
   cd Gesture-Controlled-Robotic-Arm


Install Arduino Libraries:

Open Arduino IDE.
Go to Sketch > Include Library > Manage Libraries.
Search and install MPU6050 and RF24.


Upload Code:

Connect the transmitter Arduino Nano to your computer.
Open src/transmitter.ino in Arduino IDE, select the correct board and port, and upload.
Connect the receiver Arduino Nano, open src/receiver.ino, and upload.


Hardware Setup:

Assemble the hand glove with MPU6050, push buttons, and RF module connected to the transmitter Arduino.
Assemble the robotic arm and navigation platform with DC motors, servo motors, L293D driver, and RF module connected to the receiver Arduino.
Power the transmitter with a 9V battery and the receiver with a 12V battery.



Usage

Power on both the transmitter and receiver.
Perform hand gestures to control the robot:
Tilt hand right/left for right/left turns.
Tilt hand forward/backward for forward/backward movement.
Press buttons for pick, place, up, or down actions.


Monitor Serial output (9600 baud) for debugging gesture detection and command reception.
Ensure the RF modules are within 1 km range (line-of-sight) for reliable communication.

File Structure
Gesture-Controlled-Robotic-Arm/
├── src/
│   ├── transmitter.ino    # Code for gesture detection and RF transmission
│   └── receiver.ino       # Code for motor and servo control
├── docs/
│   └── MAJOR_PROJECT_BASE.docx  # Project documentation (optional)
├── README.md              # Project overview and instructions
├── LICENSE                # MIT License
└── .gitignore             # Git ignore file

Limitations

Limited RF range (up to 1 km outdoors, reduced indoors with obstacles).
Gyro drift in MPU6050 after prolonged use; consider upgrading to a module with feedback.
Requires stable power supply for motors and servos.
Camera streaming (if implemented) depends on Wi-Fi, causing potential delays.

Applications

Pick-and-place tasks in industrial settings.
Handling hazardous materials or chemicals.
Military applications (e.g., bomb disposal).
Environmental tasks (e.g., garbage removal in lakes).

License
This project is licensed under the MIT License. See the LICENSE file for details.```
