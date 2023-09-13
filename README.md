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

\[
\text{Distance} = \frac{\text{Speed of Sound} \times \text{Time}}{2}
\]
​
This formula accounts for the round-trip travel time of the ultrasonic pulse.

The Arduino collects data from the UltraSonic sensors, processes the information to determine the distance to obstacles, and communicates this data to the Pixhawk flight controller. The Pixhawk then makes real-time adjustments to the drone's flight path to avoid collisions.