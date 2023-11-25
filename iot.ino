#include<Servo.h>
#include <dht.h>
#define DATApin 9
dht DHT;      
#define trigPin 7
#define echoPin 5
int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int led = 6;

int ir;


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
  
  pinMode(2,INPUT);
  pinMode(4,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(A0,INPUT);
  digitalWrite(2,LOW);
  digitalWrite(11,HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {

  //ldr.........................

  sensorValue = analogRead(sensorPin);
Serial.println("ldr =");
  Serial.println(sensorValue);

  if (sensorValue < 280)

  {

  Serial.println("LED light on");

  digitalWrite(led,HIGH);

  delay(10000);

  }

  digitalWrite(led,LOW);

  delay(sensorValue);
 ////////////////////////////////////////////////////ldr

 ///////////////////////ultrasonic///////////////////////////
  
  long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
 distance =duration * 0.034/2;
  Serial.print("distance:");
Serial.print(distance);

Serial.println(" cm");
  
  
  
  if(distance < 40)
  {
    digitalWrite(8,HIGH);
    delay(2000);
  }
  else
  {
    digitalWrite(8,LOW);
  }
  
  ///////////////////// PIR with LED starts//////////////////////////
  int pir = digitalRead(2);
  
  if(pir == HIGH)
  {
    digitalWrite(4,HIGH);
    Serial.println("motion detected....");
    delay(1000);
  }
  else if(pir == LOW)
  {
    digitalWrite(4,LOW);
  }
  
  //temp with fan
  // Read data from Sensor
  int readData = DHT.read11(DATApin);
  float t = DHT.temperature;  // Read Temperature in Degree Celsius unit
  //Print Tempareture Value on Serial Monitor Window
  Serial.print("Temperature = ");
  Serial.print(t);  // Temperature value in Degree Celsius
  

  
  if(t > 30)
  {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else
  {
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  }
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
