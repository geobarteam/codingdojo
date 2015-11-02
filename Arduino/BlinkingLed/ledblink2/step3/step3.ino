const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int ledState = LOW;
int numberOfPushes = 0;

void setup() {
   // open a serial connection to display values
   Serial.begin(9600);
      // initialize the LED pin as an output:
   pinMode(ledPin, OUTPUT);
   // initialize the pushbutton pin as an input:
   pinMode(buttonPin, INPUT);
}

void loop() {

   // read the state of the pushbutton value:
   int buttonState = digitalRead(buttonPin);
   
   if (buttonState==HIGH) 
   {
        numberOfPushes = numberOfPushes + 1;   
   }

   if (numberOfPushes == 3) 
   {
      numberOfPushes = 0;
   }
   
   if (numberOfPushes == 0)
   {
      off();
   }
   else if (numberOfPushes == 1)
   {
      blink();
   }
   else if (numberOfPushes == 2)
   {
      on();
   }
}

void on(){
  ledState = HIGH;
  digitalWrite(ledPin,ledState);
  delay(400);
}

void off()
{
  ledState = LOW;
  digitalWrite(ledPin,ledState);
  delay(400); 
}

void blink(){
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(200);
}
