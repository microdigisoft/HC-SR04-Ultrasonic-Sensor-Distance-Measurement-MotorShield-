#include <Servo.h>
Servo servo1;//Initialize Servo
int pos = 0;
#define trigPin 9 //initialize pin9 for HC-SR04 trigger pin
#define echoPin 8 //initialize pin9 for HC-SR04 Echo pin
#define led 12  //initialize pin12 for HC-SR04 LED pin
void setup() {
  Serial.begin (9600);
  servo1.attach(10);
  pinMode(trigPin, OUTPUT);// Define trigger pin as output
  pinMode(echoPin, INPUT);// Define echo pin as input
  pinMode(led, OUTPUT);// Define led pin as input
}
void loop()
{

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Calculate distance in CM
  if (distance <= 10)
  {
    Serial.print(distance);
    digitalWrite(led, HIGH);
    for (pos = 180; pos > 1; pos -= 1)// goes from 180 degrees to 0 degrees
    {
      servo1.write (pos); // tell servo to go to position in variable 'pos'
      delay (5); // waits 5ms for the servo to reach the position
    }
    digitalWrite(led, HIGH);
    Serial.println("cm : LED is on ");
    delay(500);
    for (pos = 0; pos < 180; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      servo1.write(pos);
      delay(5); // waits 5ms for the servo to reach the position

    }
  }
  else {
    Serial.print(distance);
    digitalWrite(led, LOW);
    Serial.println(" cm : LED is off ");
    delay(500);
    servo1.write(0); // waits 15ms for the servo to reach the position
  }
}
