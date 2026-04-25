# Train Accident Prevention using Arduino

A railway obstacle detection system using HC-SR04 ultrasonic sensor and Arduino Uno.

## Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 7 LEDs
- Buzzer

## How it Works
1. Ultrasonic sensor measures distance of obstacle
2. LEDs turn ON progressively as obstacle gets closer (every 7cm)
3. Buzzer activates when obstacle is within 49cm
4. Real-time distance displayed on Serial Monitor

## How to Run
1. Connect components as per circuit diagram
2. Upload TrainAccidentPrevention.ino to Arduino Uno
3. Open Serial Monitor at 9600 baud rate
