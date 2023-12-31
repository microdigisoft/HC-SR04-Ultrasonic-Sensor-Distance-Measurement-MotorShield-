#include <AFMotor.h >    //Adafruit Motor Driver Shield library
long duration;         //duration of ultrasonic pulse
int distanceCm;        //distance in cm
void setup() {
  Serial.begin (9600);
  pinMode(A1, OUTPUT);    //Analog pin A1 connected to TRIG
  pinMode(A0, INPUT);     //Analog pin A0 connected to ECHO
}
void loop()
{
  digitalWrite(A1, LOW);
  delayMicroseconds(2);
  digitalWrite(A1, HIGH);    //give a pulse of 10us on TRIG
  delayMicroseconds(10);
  digitalWrite(A1, LOW);
  duration = pulseIn(A0, HIGH);     //check time elasped in receiving back the pulse on ECHO
  distanceCm = duration * 0.034 / 2; //convert to distance in cm
  if (distanceCm <= 20)          //if distance less than 20cm display on monitor
  {
    Serial.println(distanceCm);
    delay(1000);
  }
  else
  {}
}
