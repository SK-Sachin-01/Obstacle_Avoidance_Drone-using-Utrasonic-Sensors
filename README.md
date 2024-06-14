# Obstacle Avoidance Drone using UltraSonic Sensors


## Overview

This project focuses on building an obstacle avoidance drone equipped with UltraSonic sensors and controlled by a Pixhawk flight controller. The drone uses an Arduino for serial communication to process sensor data and make real-time decisions to avoid obstacles. This repository contains all the necessary files, code, and documentation required to set up and operate the drone.

## UltraSonic Sensors
### Components
- **Transmitter**: The transmitter emits ultrasonic waves at a frequency typically around 40 kHz.
- **Receiver**: The receiver detects the reflected ultrasonic waves (echo) that bounce back from obstacles.
- **Control Circuit**: Manages the timing and processing of the ultrasonic pulses and echoes.
- **Power Supply**: Provides the necessary voltage and current to operate the sensor.

### Working
1. **Emission of Ultrasonic Pulse**:
The transmitter generates a short ultrasonic pulse that travels through the air.

2. **Propagation**:
The ultrasonic pulse propagates away from the sensor. If there are no obstacles, it continues until it dissipates.

3. **Reflection**:
When the ultrasonic pulse encounters an obstacle, it reflects back toward the sensor.

4. **Reception**:
The receiver detects the reflected pulse and converts it into an electrical signal.

5. **Distance Calculation**:
The control circuit measures the time interval between the emission of the pulse and the reception of the echo. The distance to the obstacle is calculated using the formula:

                    Distance = ((Speed of Sound) X (Time))/2
​
This formula accounts for the round-trip travel time of the ultrasonic pulse.

The Arduino collects data from the UltraSonic sensors, processes the information to determine the distance to obstacles, and communicates this data to the Pixhawk flight controller. The Pixhawk then makes real-time adjustments to the drone's flight path to avoid collisions.

## Basic Drone Parts
### 1. Propellers
Propellers are crucial components that generate the thrust needed for the drone to lift off the ground and maneuver. Drones typically have two types of propellers: clockwise (CW) and counterclockwise (CCW), which help in stabilizing and controlling the drone's flight.

### 2. Motors
Brushless motors are used to spin the propellers at high speeds. Each propeller is connected to a motor, and the motors are controlled by electronic speed controllers (ESCs).

### 3. Electronic Speed Controllers (ESCs)
ESCs regulate the speed of the motors by varying the power supplied to them. They receive signals from the flight controller and adjust the motor speeds accordingly to control the drone's movement and stability.

### 4. Battery
The battery provides the necessary power for all the drone's components, including the motors, flight controller, and sensors. Lithium Polymer (LiPo) batteries are commonly used due to their high energy density and lightweight properties.

### 5. Power Distribution Board (PDB)
The PDB distributes power from the battery to the various components of the drone, such as the ESCs and flight controller. It ensures that each component receives the appropriate voltage and current.

### 6. Receiver
The receiver is connected to the flight controller and receives control signals from the transmitter (remote control). It allows the pilot to control the drone remotely by sending commands to the flight controller.

### 7. Transmitter
The transmitter is a handheld device used by the pilot to control the drone. It sends control signals to the receiver, which are then passed on to the flight controller to execute the pilot's commands.

### 8. Frame
The drone frame provides the structural support for all the components. It is typically made of lightweight materials such as carbon fiber or plastic to minimize weight while ensuring durability.

## Software Used
### Arduino IDE
The Arduino Integrated Development Environment (IDE) is used to write, compile, and upload code to the Arduino board. It provides a user-friendly interface and a robust set of libraries for interfacing with various sensors and components.

#### Key Features:
**Sketches**: Arduino programs are called sketches. These are written in a simple, C++ based language.
**Libraries**: The IDE includes numerous libraries for working with different hardware components, including UltraSonic sensors.
**Serial Monitor**: Allows real-time monitoring and debugging of the Arduino’s outputs and inputs.
**Code Upload**: Facilitates uploading the written code to the Arduino board via a USB connection.

### Mission Planner
Mission Planner is a ground control station software used for configuring and controlling drones with the Pixhawk flight controller. It provides comprehensive tools for mission planning, real-time monitoring, and parameter adjustment.

#### Key Features:
**Flight Planning**: Create and upload waypoint missions to the drone.
**Real-time Telemetry**: Monitor the drone’s status, including GPS location, altitude, speed, and battery levels.
**Parameter Configuration**: Adjust various flight parameters and settings for optimal drone performance.
**Firmware Updates**: Easily update the firmware of the Pixhawk flight controller.


## Working of the Drone
The drone is equipped with three UltraSonic sensors placed at the front, left, and right sides. These sensors continuously monitor the surroundings to detect obstacles. The working process is as follows:

### Sensor Placement
- **Front Sensor**: Detects obstacles in front of the drone.
- **Left Sensor**: Detects obstacles to the left of the drone.
- **Right Sensor**: Detects obstacles to the right of the drone.

### Obstacle Detection and Avoidance Logic
1. **Distance Calculation**:
The Arduino calculates the distance to obstacles using the UltraSonic sensors. It sends out an ultrasonic pulse and measures the time it takes for the echo to return. This time is used to calculate the distance.

2. **Obstacle Avoidance**:

- The Arduino processes the distances from all three sensors.
- If an obstacle is detected within a predefined maximum distance (100 cm) in front of the drone, it checks the right and left sensors to determine the best avoidance maneuver.
- If obstacles are detected on both sides also, the drone performs a rotation.
- If only the right side is clear, the drone moves right.
- If only the left side is clear, the drone moves left.
- If no obstacles are detected, the drone continues to move forward.

---

Happy flying! 🚁
