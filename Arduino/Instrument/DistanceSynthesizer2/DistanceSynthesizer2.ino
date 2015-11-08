/*
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note   frequency   period  timeHigh
 * c          261 Hz          3830  1915  
 * d          294 Hz          3400  1700  
 * e          329 Hz          3038  1519  
 * f          349 Hz          2864  1432  
 * g          392 Hz          2550  1275  
 * a          440 Hz          2272  1136  
 * b          493 Hz          2028  1014  
 * C          523 Hz          1912  956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */

int trigPin = 2;
int echoPin = 3;
int speakerPin = 13;
int val = 0;
int potPin = A0;

int length = 1; // the number of notes
char notes[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' }; // a space represents a rest
int beats[] = { 1 };
int tempo = 300;

float maxDistance = 2.0;
int playDuration = 200;

void setup() {
  
  Serial.begin(9600); // for debugging through serial monitor

  // set pins mode
  pinMode(speakerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  // detect distance to object
  float distance;
  distance = getDistance();
  playDuration = getPlayDuration();

   // for debugging
  Serial.println("playDuration:");
  Serial.print(playDuration);

  // for debugging
  Serial.println("distance:");
  Serial.print(distance);

  // transform distance into sound
  play(distance);

  // needed for smooth experience
  delay(5);
}

void playTone(int tone, int duration) {

  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void ping() // radar: send a short signal 
{
  digitalWrite(trigPin, LOW); //Low high and low level take a short time to TrigPin pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}

float getDistance() // calculate the distance based on echo time of the radar
{
  ping();
  float cm;
  cm = pulseIn(echoPin, HIGH) / 58.0; //Echo time conversion into cm
  cm = (int(cm * 100.0)) / 100.0; //Keep two decimal places
  return cm;
}

// play a note based on detected distance
void play(float distance){ 
  
  float lowLimit;
  lowLimit = maxDistance;

  // if object is too far away do nothing
  if (maxDistance < distance){
    return;
  }

  // divide the maxdistance in 8 areas => 1 area = 1 note
  float areaLenth = maxDistance/8;

  // loop over each area 
  for (int i = 0; i < 8; i++) {
    lowLimit = lowLimit - areaLenth;

    // play the note if the object is in the area
    if (distance < maxDistance && distance >= lowLimit){ 
      Serial.print(notes[i]);
      playNote(notes[i], playDuration);
      Serial.println("playnote:"); // for debugging
      Serial.print(notes[i]); // for debugging
      return;
    }
  }
}

int getPlayDuration(){
    int potVal = analogRead(potPin); // read the value from the sensor
    return potVal;
  }
