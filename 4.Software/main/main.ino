//by @Xiang Chang
const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A2;
const int sensor4 = A3;

const int en1 = 6; const int D1 = 4;
const int en2 = 9; const int D2 = 7;
const int en3 = 10; const int D3 = 8; 
const int en4 = 11; const int D4 = 12;

int sensor[4] = {0, 0, 0, 0};
const float Kp_2 = 58, Ki_2 = 0.008, Kd_2 = 15;
const float vc = 90;
float PID_2 = 0;
float error = 0;
float P = 0, I = 0, D = 0, p_error = 0;
float v1 = 0, v2 = 0, v3 = 0, v4 = 0;

void setup(){
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(D1, OUTPUT);  pinMode(D2, OUTPUT);  pinMode(D3, OUTPUT);  pinMode(D4, OUTPUT);
  pinMode(en1, OUTPUT);  pinMode(en2, OUTPUT);  pinMode(en3, OUTPUT);  pinMode(en4, OUTPUT);
}

void L1_f(float v) {
  digitalWrite(D1, HIGH); 
  analogWrite(en1, v);
}
void L1_b(float v) {
  digitalWrite(D1, LOW); 
  analogWrite(en1, v);
}
void L2_f(float v) {
  digitalWrite(D2, LOW); 
  analogWrite(9, v);
}
void L2_b(float v) {
  digitalWrite(D2, HIGH); 
  analogWrite(9, v);
}
void L3_f(float v) {
  digitalWrite(D3, LOW); 
  analogWrite(en3, v);
}
void L3_b(float v) {
  digitalWrite(D3, HIGH); 
  analogWrite(en3, v);
}
void L4_f(float v) {
  digitalWrite(D4, HIGH); 
  analogWrite(en4, v);
}
void L4_b(float v) {
  digitalWrite(D4, LOW); 
  analogWrite(en4, v);
}

void L1(float v) {
  if(v > 0) 
    L1_f(255-v);
  else 
    L1_b(-v);
}
void L2(float v) {
  if(v > 0) 
    L2_f(v);
  else 
    L2_b(225+v);
}
void L3(float v) {
  if(v > 0) 
    L3_f(v);
  else 
    L3_b(255+v);
}
void L4(float v) {
  if(v > 0) 
    L4_f(255-v);
  else 
    L4_b(-v);
}

void loop(){

  sensor[0] = digitalRead(sensor1);
  sensor[1] = digitalRead(sensor2);
  sensor[2] = digitalRead(sensor3);
  sensor[3] = digitalRead(sensor4);

  if(sensor[1] != 0 && sensor[0] == 0 && sensor[2] == 0 && sensor[3] != 0)
    error = 0;
  else if(sensor[1] == 0 && sensor[0] != 0 && sensor[2] != 0 && sensor[3] != 0)
    error = -1.3;
  else if(sensor[1] != 0 && sensor[0] == 0 && sensor[2] != 0 && sensor[3] != 0)
    error = -1;
  else if(sensor[1] != 0 && sensor[0] != 0 && sensor[2] == 0 && sensor[3] != 0)
    error = 1;
  else if(sensor[1] != 0 && sensor[0] != 0 && sensor[2] != 0 && sensor[3] == 0)
    error = 1.3;

//PID Control
  P = error;
  I = I + error;
  D = error - p_error;
  PID_2 = Kp_2 * P + Ki_2 * I + Kd_2 * D;
  p_error = error;

//change v
  v1 = vc + PID_2;
  v2 = vc - PID_2;
  v3 = vc + PID_2;
  v4 = vc - PID_2;
//constrain
  constrain(v1, -255, 255);
  constrain(v2, -255, 255);
  constrain(v3, -255, 255);
  constrain(v4, -255, 255);

  L1(v1);L2(v2);L3(v3);L4(v4);
}
