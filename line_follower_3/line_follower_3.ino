//define pins from Arduino Nano
// like 9 is labeled D9 in the hardware
// as well as 6 as D6
#define in1 3
#define in2 5
#define in3 6
#define in4 9
#define EEP 4

int sensor[5] = {A0, A1, A2, A3, A4};

bool white[5];

int border = 280;

int minus = 3;
int Tdelay = 300;
int MSpeed = 255;
int SSpeed = 200;
int Speed = 160;
int TSpeed = 120;
int SSTSpeed = 80;
int STSpeed = 75;
int BSpeed = 50;
int BBSpeed = 40;
int BBBSpeed = 30;
void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(EEP, OUTPUT);
  for(int i=0;i<6;i++){
    pinMode(sensor[i],INPUT);
  }
  digitalWrite(EEP, HIGH);
}


void loop() {
  for (int i=0;i<5;i++){
    int sens = analogRead(sensor[i]);
    white[i] = (sens < border);
  }
  if(white[3] && white[1] && !white[2]){
    forward();
  //}else if(white[2] && !white[3] && white[4]){
  //  soft_left();
  //}else if(white[1] && !white[2] && white[3]){
  //  soft_right();
  //}else if(!white[1] && white[5]){
  //  right();
  //}else if(!white[4] && white[0]){
  //  left();
  }else if(!white[1]){
    hstop();
    delayMicroseconds(Tdelay);
    soft_right();
    //right();
  }else if(!white[3]){
    hstop();
    delayMicroseconds(Tdelay);
    soft_left();
    //left();
  }else if(!white[0]){
    hard_right();
  }else if(!white[4]){
    hard_left();
  //}else if(white[0] && white[1] && white[2] && white[3] && white[4] && white[5]){
  //  stop();
  }
  //200 below is white
}

/*in1 and in2 is the RIGHT side of the motor and in1 is forward, in2 is backward
  in3 and in4 is the LEFT side if the motor and in4 is forward, in3 is backward*/
void soft_right(){
  analogWrite(in1, MSpeed-minus);
  //digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  analogWrite(in4, MSpeed);
}
void soft_left(){
  analogWrite(in1, MSpeed);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);
  analogWrite(in4, MSpeed-minus);
}
void right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  analogWrite(in4, BBSpeed);
}
void left(){
  analogWrite(in1, BBSpeed);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void hard_right(){
  digitalWrite(in1, LOW);
  analogWrite(in2, STSpeed);
  digitalWrite(in3, LOW);
  analogWrite(in4, STSpeed);
}
void hard_left(){
  analogWrite(in1, STSpeed);
  digitalWrite(in2, LOW);
  analogWrite(in3, STSpeed);
  digitalWrite(in4, LOW);
}
void soft_hard_right(){
  digitalWrite(in1, LOW);
  analogWrite(in2, STSpeed);
  digitalWrite(in3, LOW);
  analogWrite(in4, TSpeed);
}
void soft_hard_left(){
  analogWrite(in1, TSpeed);
  digitalWrite(in2, LOW);
  analogWrite(in3, TSpeed);
  digitalWrite(in4, LOW);
}
//void slow_right(){
//  digitalWrite(in1, HIGH);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, LOW);
//  analogWrite(in4, BSpeed);
//}
//void fast_right(){
//  digitalWrite(in1, HIGH);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, LOW);
//  analogWrite(in4, TSpeed);
//}
//void slow_left(){
//  analogWrite(in1, BSpeed);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, HIGH);
//}
//void fast_left(){
//  analogWrite(in1, TSpeed);
//  digitalWrite(in2, LOW);
//  digitalWrite(in4, HIGH);
//  digitalWrite(in3, HIGH);
//}
//
//
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void hstop(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}
//void back(){
//  digitalWrite(in1, LOW);
//  analogWrite(in2, BSpeed);
//  analogWrite(in3, BSpeed);
//  digitalWrite(in4, LOW);
//}
void forward(){
  //RIGHT SIDE
  analogWrite(in1, MSpeed);
  digitalWrite(in2, LOW);
  //LEFT SIDE
  digitalWrite(in3, LOW);
  analogWrite(in4, MSpeed);
}
//void slow_forward(){
//  //RIGHT SIDE
//  analogWrite(in1, TSpeed);
//  digitalWrite(in2, LOW);
//  //LEFT SIDE
//  digitalWrite(in3, LOW);
//  analogWrite(in4, TSpeed);
//}
//void soft_forward(){
//  //RIGHT SIDE
//  analogWrite(in1, STSpeed);
//  digitalWrite(in2, LOW);
//  //LEFT SIDE
//  digitalWrite(in3, LOW);
//  analogWrite(in4, STSpeed);
//}
//void brake_forward(){
//  analogWrite(in1, BSpeed);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);
//  analogWrite(in4, BSpeed);
//  delay(50);
//  digitalWrite(in1, HIGH);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, HIGH);
//  delay(90);
//}

