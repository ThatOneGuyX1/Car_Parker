
const int trigPin = 2;
const int echoPin = 3;

const int blue = 13;
const int red =11; 
const int yellow = 9;
const int green = 7;


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
  distance = (duration * 0.034 / 2)*.393;
  Serial.print("Distance: ");
  Serial.println(distance);

  outputLED();




  /*
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration * 0.034 / 2)*.393;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  */
}

void RunTrigPin()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
}

void outputLED()
{
  if (distance <= 12 && distance > 9)
  {
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
  }
  else if (distance <=9 && distance > 4)
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
  }
  else if (distance <= 4 && distance > 2)
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
  }
  else if (distance <= 2)
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