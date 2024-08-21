int left=12,right=13;
int md1d = 2 ;
 int md1g = 3 ;
 int md2d = 5 ;
 int md2g = 4 ;
int a=1;
int inLeft , inRight ;
void setup() {
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  Serial.begin(9600);
  
  pinMode(md1d, OUTPUT);
  pinMode(md1g, OUTPUT);
  pinMode(md2d, OUTPUT);
  pinMode(md2g, OUTPUT);

}

void loop() {

 inLeft = digitalRead(left);
 inRight =digitalRead(right) ;
  
    if (inLeft==1 && inRight==1){
    move_forward();
    
    }
 if (inLeft==0 && inRight==1){
  Serial.println("left");
 turn_left();
    
   
  }
   if (inLeft==1 && inRight==0){
  Serial.println("right");
    
    turn_right();
    
    
  }
      if (inLeft== 0&& inRight==0 ){
stop();
    
    }


  

}

void move_forward() {
  digitalWrite(md1d, HIGH);
  digitalWrite(md1g, LOW);
  digitalWrite(md2d, HIGH);
  digitalWrite(md2g, LOW);
}
void move_backwards() {
  digitalWrite(md1d, LOW);
  digitalWrite(md1g, HIGH);
  digitalWrite(md2d, HIGH);
  digitalWrite(md2g, LOW);
}
void turn_right() {
  digitalWrite(md1d, LOW);
  digitalWrite(md1g, HIGH);
  digitalWrite(md2d, HIGH);
  digitalWrite(md2g, LOW);
}
void turn_left() {
  digitalWrite(md1d, HIGH);
  digitalWrite(md1g, LOW);
  digitalWrite(md2d, LOW);
  digitalWrite(md2g, HIGH);
}
void stop() {
  digitalWrite(md1d, LOW);
  digitalWrite(md1g, LOW);
  digitalWrite(md2d, LOW);
  digitalWrite(md2g, LOW);
}