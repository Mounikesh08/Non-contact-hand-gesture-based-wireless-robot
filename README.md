# Non Contact Hand Gesture Based Wireless Robot

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
