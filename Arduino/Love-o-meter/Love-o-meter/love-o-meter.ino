/*
  Arduino Starter Kit example
 Project 2  - Love-O-Meter
 
 This sketch is written to accompany Project 2 
 
 Parts required:
 1 TMP36 temperature sensor 
 3 red LEDs
 3 220 ohm resistors
 
 Created 31 October 2015
 by Geoffrey Vandiest
 
  
 This example code is part of the public domain 
 */

// named constant for the pin the sensor is connected to
const int sensorPin = A0;
// room temperature in Celcius
float baselineTemp = 0.0;

void setup(){
  // open a serial connection to display values
  Serial.begin(9600);

  // set the LED pins as outputs
  // the for() loop saves some extra coding
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
  // retrieve the base temperature
  baselineTemp = getTemperature();
  Serial.println("Base Temperature:");
  Serial.print(baselineTemp);
}


void loop(){

  // retrieve current temperature
  float temperature = getTemperature();
  Serial.println("Temperature:");
  Serial.print(temperature);

  // if the temperature rises 3 degrees, turn an LED on 
 if(temperature >= baselineTemp+3 && temperature < baselineTemp+5){
    setLights(HIGH, LOW, LOW);  
  } // if the temperature rises 5-8 degrees, turn a second LED on  
  else if(temperature >= baselineTemp+5 && temperature < baselineTemp+8){
    setLights(HIGH, HIGH, LOW);
  } // if the temperature rises more than 8 degrees, turn all LEDs on
  else if(temperature >= baselineTemp+8){
    setLights(HIGH, HIGH, HIGH);
  }
  else { // if the current temperature is lower than the baseline
    setLights(LOW, LOW,LOW);
  }

  delay(1);
}

float getTemperature()
{
  // read the value on AnalogIn pin 0 
  // and store it in a variable
  int sensorVal = analogRead(sensorPin);

  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

   // convert the voltage to temperature in degrees C
  return (voltage - 0.06 ) * 130;
}

void setLights(bool light1, bool light2, bool light3)
{
  digitalWrite(2, light1);
  digitalWrite(3, light2);
  digitalWrite(4, light3);
}