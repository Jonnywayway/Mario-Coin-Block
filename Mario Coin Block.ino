#include <AccelStepper.h>
int ledPin = 13;
int EP =9;
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  2     // IN1 on the ULN2003 driver 1
#define motorPin2  3     // IN2 on the ULN2003 driver 1
#define motorPin3  4     // IN3 on the ULN2003 driver 1
#define motorPin4  5     // IN4 on the ULN2003 driver 1
bool a=false;
// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(EP, INPUT); //set EP input for measurment
  stepper1.setMaxSpeed(3000.0);
  stepper1.setAcceleration(1000.0);
  stepper1.setSpeed(3000);
  delay(1000);
}
void loop(){
  long measurement =TP_init();
  delay(50);
  Serial.println(measurement);
  if (measurement > 1000){
    digitalWrite(ledPin, HIGH);
    shoot();
  }
  else{
    digitalWrite(ledPin, LOW); 
  }
}
long TP_init(){
  delay(10);
  long measurement=pulseIn (EP, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
void shoot(){
  stepper1.move(-4096);
  stepper1.runToPosition();
  delay(1000);
  
}

