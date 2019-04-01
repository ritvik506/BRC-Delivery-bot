//This is the edited file
#include<SoftwareSerial.h>

int sr2 = 2;
int sr4 = 7;


long duration, distance;
int ENB= 5;//Controls left wheel
int IN1=8;
int IN2=9;
int IN3=10;
int IN4=11;
int ENA=3;//controls right wheel,functioning fully


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
  analogWrite(ENA,50);
  analogWrite(ENB,150);
  Serial.println("for_right");
  
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




void setup() {

  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(sr2,INPUT);
  pinMode(sr4,INPUT);
 }






void loop() {
 while(digitalRead(sr4) == 0){
    FOR_LEFT();
 }
 while(digitalRead(sr2) == 0){
    FOR_RIGHT();
 }

 forward();
 
}
