//This is the edited file
//a professional delivery bot that delivers from any restaurant to your doorstep in less than .5 hrs. order now on Bhoswiggy.
#include<SoftwareSerial.h>
#include<Servo.h>

//Servo
Servo myservo; 
int pos = 0;   


//Ultrasonic Sensor
#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10


long duration, distance;
int ENB= 5;//Controls left wheel
int IN1=8;
int IN2=9;
int IN3=10;
int IN4=11;
int ENA=3;//controls right wheel,functioning fully
//int pinHorn = 6;
char input;


void forward()
{
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);//LEFT WHEEL
  digitalWrite(IN4,LOW);
  analogWrite(ENA,180);
  analogWrite(ENB,175);
  Serial.println("forward");

}

void reverse()
{

  digitalWrite(IN1,HIGH);//RIGHT
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);//LEFT WHEEL
  digitalWrite(IN4,HIGH);//LEFT WHEEL
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  Serial.println("REverse");

}

void STOP() 
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}




void FOR_LEFT()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,150);
  analogWrite(ENB,50);
  Serial.println("for_left");
  
}


void FOR_RIGHT()
{
   digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,100);
  analogWrite(ENB,255);
  
}
void LEFT()
{
  
  digitalWrite(IN1,LOW);//IN1 AND IN2 COMPLIMENTARY
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,200);
  analogWrite(ENB,120);
  Serial.println("left");
}
  
long check_Distance()
{
  
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  return distance;
     
}
  



void setup() {

  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
   
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

  myservo.attach(6); 
 }

 void control()// to Determine motion of bot
 {
  
 
    while(check_Distance() < 25){
      
      if(check_Distance()<10)
      reverse();
      else
      LEFT();
    }
  
  forward();
 }




void loop() {
  forward();
  for (pos = 40; pos <= 110; pos += 15) {// g oes from 40 degrees to 120 degrees 
    
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);   // waits 150ms for the servo to reach the position
    control();
    
  }
  
  for (pos = 110; pos >= 40; pos -= 15) { // goes from 120 degrees to 40 degrees
    myservo.write(pos);            
    delay(100); 
    control();
                       
    }
}
