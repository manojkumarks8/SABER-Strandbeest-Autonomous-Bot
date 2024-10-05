#include <Servo.h>
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 2;
const int motor1PinA = 3;
const int motor1PinB = 5;
const int motor2PinA = 6;
const int motor2PinB = 11;

Servo myservo;
int duration, distance, servoAngle;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1PinA, OUTPUT);
  pinMode(motor1PinB, OUTPUT);
  pinMode(motor2PinA, OUTPUT);
  pinMode(motor2PinB, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(0); // Initialize servo to 0 degrees
}

void loop() {
  distance = getDistance();

  if (distance <= 20) {
    avoidObstacle();
  } else {
    moveForward();
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void moveForward() {
  digitalWrite(motor1PinA, HIGH);
  digitalWrite(motor1PinB, LOW);
  digitalWrite(motor2PinA, HIGH);
  digitalWrite(motor2PinB, LOW);
}

void stopMotors() {
  digitalWrite(motor1PinA, LOW);
  digitalWrite(motor1PinB, LOW);
  digitalWrite(motor2PinA, LOW);
  digitalWrite(motor2PinB, LOW);
}

void avoidObstacle() {
  stopMotors();
  moveBackward();
  delay(500);
  stopMotors();
  
  if (scanForClearPath()) {
    turnRover();
  }
}

void moveBackward() {
  digitalWrite(motor1PinA, HIGH);
  digitalWrite(motor1PinB, LOW);
  digitalWrite(motor2PinA, HIGH);
  digitalWrite(motor2PinB, LOW);
}

bool scanForClearPath() {
  for (servoAngle = 0; servoAngle <= 90; servoAngle += 10) {
    myservo.write(servoAngle);
    delay(100);
    if (getDistance() <= 20) {
      return false;
    }
  }
  for (servoAngle = 90; servoAngle >= 0; servoAngle -= 10) {
    myservo.write(servoAngle);
    delay(100);
    if (getDistance() <= 20) {
      return false;
    }
  }
  return true;
}

void turnRover() {
  if (servoAngle > 45) {
    // Turn right
    digitalWrite(motor1PinA, HIGH);
    digitalWrite(motor1PinB, LOW);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, HIGH);
  } else {
    // Turn left
    digitalWrite(motor1PinA, LOW);
    digitalWrite(motor1PinB, HIGH);
    digitalWrite(motor2PinA, HIGH);
    digitalWrite(motor2PinB, LOW);
  }
  delay(500);
  stopMotors();
}
