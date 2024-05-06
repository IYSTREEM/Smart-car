#include <Servo.h>
#include <AFMotor.h>
char value;
boolean lightFront = false;
boolean lightBack = false;
boolean S_light = false;
int speedCar=255;
int distance;
int Left;
int Right;
int L = 0;
int R = 0;
int L1 = 0;
int R1 = 0;
int servoAngle = 90;
#define Echo A0
#define Trig A1
#define S_motor 10
#define relaypin A4
#define B_LED A5
#define SL_LED A2
#define SR_LED A3
#define spoint 90
Servo servo;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


void setup() {
  Serial.begin(9600);
  servo.attach(S_motor);
  pinMode(Trig,OUTPUT);//Trig A1
  pinMode(Echo,INPUT);//Echo A0
  pinMode(relaypin,OUTPUT);//F_LED A4 pin
  pinMode(B_LED,OUTPUT);//B_LED A5 pin
  pinMode(SL_LED,OUTPUT);//SL_LED A2 pin
  pinMode(SR_LED,OUTPUT);//SR_LED A3 pin

}

void loop() {
  
  blutooth_mode();  

}

void blutooth_mode(){

if (Serial.available() > 0) {
  value = Serial.read();
  Stop();       //Initialize with motors stopped.
//
//if (lightFront) {digitalWrite(F_LED, HIGH);
//}
//if (!lightFront) {digitalWrite(F_LED, LOW);
//}
//if (lightBack) {digitalWrite(B_LED, HIGH);
//}
//if (!lightBack) {digitalWrite(B_LED, LOW);
//}
//if (S_light) {digitalWrite(SL_LED, HIGH);
//               digitalWrite(SR_LED, HIGH);
//}
//if (!S_light) {digitalWrite(SL_LED, LOW);
//               digitalWrite(SR_LED, LOW);
//}


switch (value) {
case 'w':forward();break;
case 's':backward();break;
case 'd':left();break;
case 'a':right();break;
case 'x':forwardRight();break;
case 'b':forwardLeft();break;
case 'v':backwardRight();break;
case 'c':backwardLeft();break;
case 'p':relaypin_high();break;
case 'k':servo_decrease();break;
case 'o':servo_increase();break;
case 'n':speedCar = 75;break;
case 'l':relaypin_low();break;
case '2':speedCar = 125;break;
case '3':speedCar = 150;break;
case '4':speedCar = 175;break;
case '5':speedCar = 200;break;
case '6':speedCar = 220;break;
case '7':speedCar = 230;break;
case '8':speedCar = 240;break;
case '9':speedCar = 250;break;
case 'm':speedCar = 255;break;
case 'I':lightFront = true;break;
case 'O':lightFront = false;break;
case 'P':lightBack = true;break;
case 'L':lightBack = false;break;
case 'K':S_light = true;break;
case 'M':S_light = false;break;
}}  


  
}

void relaypin_high() {
  pinMode(relaypin, HIGH);
  delay(60);
  }

void relaypin_low() {
  pinMode(relaypin, LOW);
  delay(60);
  }
void servo_decrease() {
  servoAngle -= 5;
  servo.write(servoAngle);
}
void servo_increase() {
  servoAngle += 5;
  servo.write(servoAngle);
}
void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);


}
void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);

  digitalWrite(B_LED,HIGH);

}
void left()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);

  digitalWrite(SL_LED, HIGH);
    
}
void O_left()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);

  digitalWrite(SL_LED, HIGH);
    
}

void right()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);

  digitalWrite(SR_LED, HIGH);



}
void O_right()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);

  digitalWrite(SR_LED, HIGH);
}

void forwardRight()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
  
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
}

void forwardLeft()
{
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}
void backwardRight()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor4.setSpeed(speedCar);

  digitalWrite(B_LED,HIGH);

}
void backwardLeft()
{
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);

  digitalWrite(B_LED,HIGH);

}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
