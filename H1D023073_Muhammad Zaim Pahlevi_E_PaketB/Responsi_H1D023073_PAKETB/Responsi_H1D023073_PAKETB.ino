#include <Servo.h>

Servo myservo;

const int servoPin = 9;
int pos = 0;
int val = 0;
const int btnUp = 3;
const int ledPin = 13;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(btnUp, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("DRS: CLOSED");
  bool upState = digitalRead(btnUp);
  val = digitalRead(btnUp);
  pos = map(val,0, 1023, 0, 90);
  if (upState ==HIGH){
    digitalWrite(ledPin, HIGH);
    myservo.write(pos);
    Serial.print("DRS: ACTIVE");
  }
}
