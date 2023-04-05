// Defineing Global constant
const int trigPin = 2;
const int echoPin = 3;
const int blue = 13;
const int red =11; 
const int yellow = 9;
const int green = 7;
// This determines the units, .393 is to convert to inches.
const int multiplier =  .393;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  pinMode(red, OUTPUT); 
  pinMode(blue, OUTPUT); 
  pinMode(yellow, OUTPUT); 
  pinMode(red, OUTPUT); 
}
void loop() {

  RunTrigPin();

  duration = pulseIn(echoPin,HIGH);
  distance = (duration * 0.034 / 2)* multiplier; // This converts the time traveled into a distance we can use.
  Serial.print("Distance: ");
  Serial.println(distance);

  outputLED();
}

void RunTrigPin()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
}

void outputLED()
{ /*
  This block of code is designed to change the LED based off of distance, if the distance is greater than a set max distance now lights will be turned on. 
  Each LED stage represent a quarter of the distance. The Ideal state is the last quarter. This could be changed based of needs.
*/
  int maxDistance = 12;

  if (distance <= maxDistance && distance > maxDistance*.75)
  {
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
  }
  else if (distance <= maxDistance *.75 && distance > maxDistance * .5)
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
  }
  else if (distance <= maxDistance*.5  && distance > maxDistance * .25)
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
  }
  else if (distance <= maxDistance * .25)
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
  }

  else
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
  }
}