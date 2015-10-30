/*
  Arduino Starter Kit example
 Project 3  - Love-O-Meter
 
 This sketch is written to accompany Project 3 in the
 Arduino Starter Kit
 
 Parts required:
 1 TMP36 temperature sensor 
 3 red LEDs
 3 220 ohm resistors
 
 Created 13 September 2012
 by Scott Fitzgerald
 
 http://arduino.cc/starterKit
 
 This example code is part of the public domain 
 */

// named constant for the pin the sensor is connected to
const int sensorPin = A0;
// room temperature in Celcius
float baselineTemp = 20.0;

void setup(){
  // open a serial connection to display values
  Serial.begin(9600);
  // set the LED pins as outputs
  // the for() loop saves some extra coding
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
 
  baselineTemp = getTemperature();
}


void loop(){

  float temperature = getTemperature();
  Serial.println(temperature);

  // if the temperature rises 3 degrees, turn an LED on 
 if(temperature >= baselineTemp+3 && temperature < baselineTemp+5){
    setLights(HIGH, LOW, LOW);
    Serial.println("A little!");
  } // if the temperature rises 5-8 degrees, turn a second LED on  
  else if(temperature >= baselineTemp+5 && temperature < baselineTemp+8){
    setLights(HIGH, HIGH, LOW);
    Serial.println("You're hot!");
  } // if the temperature rises more than 8 degrees, turn all LEDs on
  else if(temperature >= baselineTemp+8){
    setLights(HIGH, HIGH, HIGH);
    Serial.println("In love!");
  }
  else{ // if the current temperature is lower than the baseline
    setLights(LOW, LOW,LOW);
    Serial.println("Cold!");
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