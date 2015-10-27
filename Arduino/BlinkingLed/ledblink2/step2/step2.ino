 const int buttonPin = 2;     // the number of the pushbutton pin
 const int ledPin =  13;      // the number of the LED pin

// variables will change:
int ledState = LOW;

void setup() {
   // initialize the LED pin as an output:
   pinMode(ledPin, OUTPUT);
   // initialize the pushbutton pin as an input:
   pinMode(buttonPin, INPUT);
}

void loop() {
   // read the state of the pushbutton value:
   int buttonState = digitalRead(buttonPin);
   
   if (buttonState==HIGH){
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
   }

   delay(400);
}
