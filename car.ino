#include <Servo.h>
Servo srv ;
int M1_d = 2;
int M1_g = 3;
int M2_d = 4;
int M2_g = 5;
int Trig=10,Echo=9;
int servo =6;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}


void loop() {
  long distanceInit;
  
  distanceInit=distance ();
  delay(100);
  
  
  if (distanceInit>50)
    Demmarer (); 
    else {
      stop ();
      servoLeft ();
      delay(3000);
     long  distanceleft=distance ();
      delay(100);
      
      servoRight ();
      delay(3000);
     long  distanceRight=distance ();
      delay(100);
      
      if (distanceleft>distanceRight)
        goLeft (5000);
        else 
        goRight (5000);
    }
 
}
void servoInit (){
  int i;
  for (i=0;i<=90;i++){
  srv.write(i);
    delay(10);}
    
}
 
void servoLeft (){
  int i;
  for (i=90;i<=180;i++){
  srv.write(i);
    delay(10);}
    
} 

void servoRight (){  
for (int i=180;i>=0;i--){
    srv.write(i);
    delay(10);}
  
}
long distance (){
 digitalWrite(Trig,LOW);
 delayMicroseconds(10);
 digitalWrite(Trig,HIGH);
 delayMicroseconds(2);
 digitalWrite(Trig,LOW);

 long time = pulseIn(Echo,HIGH);
 return (0.03457*time)/2; 

}
void Demmarer(int d) {
  digitalWrite(M1_d, HIGH);
  digitalWrite(M1_g, HIGH);
  digitalWrite(M2_d, LOW);
  digitalWrite(M2_g, LOW);
  delay(d);
}
void Reculler(int d) {
  digitalWrite(M1_d, LOW);
  digitalWrite(M1_g, LOW);
  digitalWrite(M2_d, HIGH);
  digitalWrite(M2_g, HIGH);
  delay(d);
}
void goLeft (int d){
  digitalWrite(M1_d, HIGH);
  digitalWrite(M1_g, LOW);
  digitalWrite(M2_d, LOW);
  digitalWrite(M2_g, HIGH);
  delay(d);
}
void goRight (int d){
  digitalWrite(M1_d, LOW);
  digitalWrite(M1_g, HIGH);
  digitalWrite(M2_d, HIGH);
  digitalWrite(M2_g, LOW);
  delay(d);
}
void stop (int d){
  digitalWrite(M1_d, LOW);
  digitalWrite(M1_g, LOW);
  digitalWrite(M2_d, LOW);
  digitalWrite(M2_g, LOW);
  delay(d);
}





