# Heart Rate and SpO2 Measurement

The Heart Rate and SpO2 Measurements Project is a software application that allows users to monitor and track their heart rate and blood oxygen saturation levels. It aims to provide a convenient and accessible solution for individuals who want to keep a close eye on their vital signs for health and wellness purposes.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Configuration](#configuration)
- [Acknowledgments](#acknowledgments)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Installation

To get started with the Heart Rate and SpO2 Measurements Project, follow these steps:

1. Assemble the components together as shown in the circuit diagram:
![Circuit Diagram](circuit.jpg)
2. Components:
	- 1 * Arduino Nano
	- 1 * MAX30102
	- 1 * LCD 16*2
	- 1 * Potentiometer 10K
3. Clone or Download the repository to your local machine using the following command:
```
git clone https://github.com/kershrita/Heart-Rate-and-SpO2-measurement.git
```
4. Open your Arduino IDE.
5. Make sure that you have been installed [SparkFun MAX3010x Pulse and Proximity](SparkFun_MAX3010x_Pulse_and_Proximity_Sensor_Library.rar) Library in your IDE.
6. Select board, in our case Arduino Nano.
7. Connect Arduino Nano to the computer then upload the code.

## Usage

Once the Heart Rate and SpO2 Measurements application is up and running:

1. Put your finger on the sensor, wait some seconds then the measurments will appear.
2. Users can take advantage of the real-time monitoring. View your heart rate and SpO2 readings in real-time on the LCD screen.

## Features

- **Real-time Heart Rate Monitoring**: The project enables users to monitor their heart rate in real-time, providing immediate feedback on their cardiovascular health status.
- **SpO2 Measurement**: The application also measures the blood oxygen saturation level (SpO2), which indicates the oxygen levels in the bloodstream. This feature helps users assess their respiratory well-being.
- **Heart Rate Monitoring**: Heart rate measurement determines the number of heartbeats per minute. It helps track heart rate variations during rest, exercise, or sleep, providing insights into overall cardiovascular health and fitness levels.

## Configuration

The Heart Rate and SpO2 Measurements Project provides configuration options for users to personalize their experience. These options may include:

- **Threshold Customization**: Adjust the heart rate and SpO2 thresholds according to individual preferences or medical recommendations.
- **Measurement Interval**: Set the frequency of heart rate and SpO2 measurements, determining how often the application records readings.
- **Sensor Calibration**: Calibrate the heart rate and SpO2 sensor for accurate measurements based on personal factors or environmental conditions.

## Acknowledgments

We would like to acknowledge the following resources and libraries that have been instrumental in developing Heart Rate and SpO2 Measurement:

- **[Arduino IDE](https://www.arduino.cc/en/software)**:  An open-source integrated development environment (IDE) used for programming Arduino boards.
- **[SparkFun MAX3010x Pulse and Proximity](SparkFun_MAX3010x_Pulse_and_Proximity_Sensor_Library.rar)**: are compact, low-power sensors capable of measuring heart rate, blood oxygen saturation (SpO2), and proximity detection. These modules are commonly used in wearable health monitoring devices and fitness trackers.

## Contributing

Contributions to the Heart Rate and SpO2 Measurement are welcome! If you have any ideas, improvements, or bug fixes, feel free to open an issue or submit a pull request. Your contributions can help enhance the project and make it more accessible and reliable for others.


## License

Heart Rate and SpO2 Measurement is released under the [MIT License](LICENSE).

## Contact

- Mail: ashrafabdulkhaliq80@gmail.com
- LinkedIn: https://www.linkedin.com/in/ashraf-abdulkhaliq
- GitHub: https://github.com/kershrita