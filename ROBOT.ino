#include <NewPing.h>

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int  motor2pin2 = 5;

#define TRIGGER_PIN 9
#define ECHO_PIN 8
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,  OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
 int uS = sonar.ping();
 if (uS/US_ROUNDTRIP_CM <= 10){
    digitalWrite(motor1pin1,  LOW);
    digitalWrite(motor1pin2, LOW);
  
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW); 
  }
  else {
    digitalWrite(motor1pin1,  LOW);
    digitalWrite(motor1pin2, HIGH);
  
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW); 
  }
  delay(3000);
}
