# SABER: Strandbeest Autonomous Bot for Efficient Roving

This project is an autonomous bot inspired by Theo Jansen's Strandbeest walking mechanism. The project involved modifying an existing mechanical chassis (sourced online) by adding electronics and programming it for autonomous terrain navigation.

## Table of Contents
- [Overview](#overview)
- [Objective](#objective)
- [Hardware Components](#hardware-components)
- [Software Implementation](#software-implementation)
- [Results](#results)
- [Future Enhancements](#future-enhancements)
- [Installation](#installation)
- [Usage](#usage)
- [Credits](#credits)

## Overview
SABER is designed to efficiently navigate different terrains by leveraging the unique walking mechanism of Strandbeests. The original mechanical chassis, sourced from [this guide](https://www.nablu.com/2020/05/building-strandbeest.html?m=1), was modified with hardware components such as Arduino, motors and sensors.

## Objective
The main goal of this project is to transform the existing Strandbeest chassis into an autonomous bot that can:
- To demonstrate successful integration of Jansen's mechanism and motorize it innovatively.
- Avoid obstacles
- Autonomously navigate without user intervention

## Hardware Components
The hardware components used in the project are:
- **Arduino Uno**: The microcontroller unit controlling the bot.
- **BO Motors**: Used for driving the Strandbeest walking mechanism.
- **L298D Motor Driver**: Controls the BO motors.
- **Ultrasonic Sensor**: Provides obstacle detection.
- **Power Supply**: Provides the necessary power for all components.
- **3D-Printed Strandbeest Linkages**: Custom linkages designed in AutoCAD Fusion 360.

Refer to the [detailed report](https://github.com/manojkumarks8/SABER-Strandbeest-Autonomous-Bot/SABERProjectReport.pdf) for a full description of the components and assembly process.

## Software Implementation
The bot's autonomy is driven by a program written in C for the Arduino Uno, which handles motor control, obstacle detection, and communication. The code logic ensures the bot can:
- Detect and avoid obstacles using the ultrasonic sensor.
- Adjust walking patterns based on terrain feedback.

The main code can be found in `src/saberlogic.c`.

## Results
The bot was successfully tested on different terrains, showing efficient maneuvering and obstacle avoidance. See the [Video](./saber.mp4) of SABER in action.

## Future Enhancements
Potential future improvements include:
- Upgrading to LiDAR sensors for better obstacle detection.
- Using LoRa for long-range communication instead of the NRF module.
- Further optimizing power management for extended operation.

## Installation
To recreate the project:
1. Download and install [Arduino IDE](https://www.arduino.cc/en/software).
2. Clone this repository:
    ```
    [git clone https://github.com/manojkumarks8/SABER-Strandbeest-Autonomous-Bot.git]
    ```
3. Make connections according to the circuit diagram available in [circuit_image](./circuit_image.png) annd refer to [CircuitDocumentation](./CircuitDocumentation.pdf) file
4. Open the [saberlogic.c](./saberlogic.c) file in the Arduino IDE and upload it to your Arduino Uno.

## Usage
Once the code is uploaded to the Arduino, power on the bot and place it in an environment for testing. The bot will autonomously start navigating and avoiding obstacles.

## Credits
- **Theo Jansen**: For the original Strandbeest design that inspired the walking mechanism.
- **[Nablu's Guide](https://www.nablu.com/2020/05/building-strandbeest.html?m=1)**: For the mechanical Strandbeest chassis guide used in this project.
- **Team**: Contributors to the hardware and software integration for SABER.

## License
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.
