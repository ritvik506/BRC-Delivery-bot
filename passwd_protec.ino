int a[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1}
};
int pin[7] = {3,4,5,6,7,2,12};

int trigPin = 8;
int echoPin = A0;

int passwd = 2365;
int entry = 0;

int checkDistance(){
  digitalWrite(trigPin,LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  int distance = pulseIn(echoPin,HIGH) / 29/2; 
  return distance;
}

void setup() {
  pinMode(12,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  Serial.begin(9600);
  
}

void loop() {
  if(checkDistance() < 15){
    for(int i=0; i<10; i++){
      for(int j=0; j<7; j++){
        digitalWrite(pin[j],a[i][j]);
      }
      delay(1500);
      if(checkDistance() > 15){
        entry *= 10;
        entry += i;
        break;
      }
    }
  }

  if(entry > 1000){
    if(entry == passwd){
      Serial.println("Correct passwd");
      entry = 0;
    }
    else{
      Serial.println("Wrong passwd");
      entry = 0;
    }
    for(int j=0; j<7; j++){
        digitalWrite(pin[j],LOW);
    }
    delay(10000);
    
  }
}
