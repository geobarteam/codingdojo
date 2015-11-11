int photocellPin = 2;       //define photocellsh=2, read the value of voltage. 
int val = 0;       //define original of val.    

void setup() 
{     
	Serial.begin(9600); // for debugging through serial monitor
}    

void loop() 
{     
	val = analogRead(photocellPin);    //get the value from sensor     
	Serial.println(val);
	delay(1000);
}
