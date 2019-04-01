int s2 = 2;
int s4 = 4;

void setup(){
  Serial.begin(9600);
  pinMode(s2,INPUT);
  pinMode(s4,INPUT);
}

void loop(){
  Serial.println(digitalRead(s2));
  Serial.println(digitalRead(s4));
  Serial.println(' ');
}
