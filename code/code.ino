#include <Wire.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"
#include <LiquidCrystal.h>

// LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);

MAX30105 MAX;
long IR_val;
const int bufferLength = 100;
uint16_t irBuffer[bufferLength];
uint16_t redBuffer[bufferLength];

int32_t spo2;
int8_t validSPO2;
int32_t heartRate;
int8_t validHeartRate;

void setup(){
  LCD.begin(16, 2);  // Initialize the LCD display with 16 columns and 2 rows
  LCD.setCursor(0, 0);  // Set the cursor to the first column of the first row
  LCD.print("SPO2 : ");  // Print "SPO2 : " on the LCD
  LCD.setCursor(0, 1);  // Set the cursor to the first column of the second row
  LCD.print("HR   : ");  // Print "HR   : " on the LCD

  MAX.begin(Wire, I2C_SPEED_FAST);  // Initialize the MAX30105 sensor

  // Setup sensor parameters for data acquisition
  byte ledBrightness = 0x2A;  // LED brightness: 0 = Off to 255 = 50mA
  byte sampleAverage = 8;  // Number of samples to average: 1, 2, 4, 8, 16, 32
  byte ledMode = 2;  // LED mode: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
  int sampleRate = 1600;  // Sampling rate in Hz: 50, 100, 200, 400, 800, 1000, 1600, 3200
  int pulseWidth = 411;  // LED pulse width in microseconds: 69, 118, 215, 411
  int adcRange = 16384;  // ADC range: 2048, 4096, 8192, 16384

  MAX.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange);  // Configure the MAX30105 with the specified parameters
}

void loop(){
  IR_val = MAX.getIR();  // Read the IR value from the MAX30105 sensor

  // Check if a finger is not detected
  if (IR_val < 10000) {
    LCD.setCursor(0, 0);  // Set the cursor to the first column of the first row
    LCD.print("                ");  // Clear the previous content on the LCD
    LCD.setCursor(0, 1);  // Set the cursor to the first column of the second row
    LCD.print("                ");  // Clear the previous content on the LCD
    LCD.setCursor(2, 0);  // Set the cursor to the third column of the first row
    LCD.print(" No Finger!");  // Print " No Finger!" on the LCD
  }

  // Read red and IR values into the buffers
  for (byte i = 0; i < bufferLength; i++) {
    redBuffer[i] = MAX.getRed();  // Read the red value from the MAX30105 sensor
    irBuffer[i] = MAX.getIR();  // Read the IR value from the MAX30105 sensor
    MAX.nextSample();  // Advance to the next sample
  }

  // Calculate heart rate and oxygen saturation using the spo2_algorithm
  maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);

  // Check if valid heart rate and spo2 values are obtained
  if (validHeartRate && validSPO2) {
    LCD.setCursor(2, 0);  // Set the cursor to the third column of the first row
    LCD.print("                ");  // Clear the previous content on the LCD
    LCD.setCursor(8, 1);  // Set the cursor to the ninth column of the second row
    LCD.print("               ");  // Clear the previous content on the LCD
    LCD.setCursor(0, 0);  // Set the cursor to the first column of the first row
    LCD.print("SPO2 : ");  // Print "SPO2 : " on the LCD
    LCD.setCursor(0, 1);  // Set the cursor to the first column of the second row
    LCD.print("HR   : ");  // Print "HR   : " on the LCD
    LCD.setCursor(8, 1);  // Set the cursor to the ninth column of the second row
    LCD.print(heartRate);  // Print the heart rate value on the LCD
    LCD.setCursor(8, 0);  // Set the cursor to the ninth column of the first row
    LCD.print(spo2);  // Print the spo2 value on the LCD
  }
}
