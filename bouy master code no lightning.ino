#define sensorPin A3
#include <OneWire.h>
#include <DallasTemperature.h>
#include <MapFloat.h>
#include <ArduinoLowPower.h>
#include "RTCZero.h"
// Data wire is plugged into port D0 on the Arduino
#define ONE_WIRE_BUS 0
#define SLEEP_TIME 200
#define READ_TIME  10

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

int numberOfDevices; // Number of temperature devices found
DeviceAddress tempDeviceAddress; 
const int NUM_READINGS = 60;  // Number of readings to take for each sensor
const int DELAY_BETWEEN_READINGS = 1000;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  // Start up the library
  sensors.begin();
  
  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();
}

void loop() {
  // put your main code here, to run repeatedly:


  Serial.print("Analog output: ");

  Serial.println(readSensor());


float sensorValue = analogRead(A1);
  //Serial.print("Analog Value =");
 // Serial.println(sensorValue);
 
  float voltage = (sensorValue / 1023) * 5;
  //Serial.print("Voltage =");
  //Serial.print(voltage);
 // Serial.println(" V");

//  float wind_speed = mapFloat(voltage, 0.65, 2, 0, 32.4);
 // float speed_mph = ((wind_speed *3600)/1609.344);
 // Serial.print("Wind Speed =");
 // Serial.print(wind_speed);
  //Serial.println("m/s");
//  Serial.print(speed_mph);
 // Serial.println("mph");
  
}

//  This function returns the analog data to calling function
//int readSensor() {
  int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor
  int outputValue = map(sensorValue, 0, 1023, 255, 0); // 
  //return outputValue;             // Return analog rain value
  
//LowPower.sleep(SLEEP_TIME);
}