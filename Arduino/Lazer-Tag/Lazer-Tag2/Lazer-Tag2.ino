int photocellPin = 2;       //define photocellsh=2, read the value of voltage. 
int buzzerPin = 13;
int val = 0;       //define original of val.   

const int MINLIGHT = 900; 

void setup() 
{     
	Serial.begin(9600); // for debugging through serial monitor
	pinMode(buzzerPin, OUTPUT);
}    

void loop() 
{     
	val = analogRead(photocellPin);    //get the value from sensor     
	Serial.println(val);
	if (val>MINLIGHT){
		beep(buzzerPin);
		delay(2000);
	}

	delay(100);
}

void beep(int buzzerPin)
{    
  for(int i=0;i<60;i++)// Output a frequency of sound 
  {
    digitalWrite(buzzerPin,HIGH);//sound
    delay(1); //delay 1ms 
    digitalWrite(buzzerPin,LOW); //mute
    delay(1); //delay 1ms  
  }

  for(int i=0;i<75;i++)// Output the other frequency of sound
  {
    digitalWrite(buzzerPin,HIGH);//sound 
    delay(2);//delay 2ms 
    digitalWrite(buzzerPin,LOW);//mute
    delay(2);//delay 2ms 
  }       
}