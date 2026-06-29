#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

char a;
String readString;

void setup() {
  pinMode(13, OUTPUT);

  servo1.attach(12); // PINZA
  servo2.attach(11); // ANTEBRAZO
  servo3.attach(10); // BRAZO
  servo4.attach(9);  // BASE

  BT.begin(9600);

  servo1.write(8);    // PINZA
  servo2.write(100);  // ANTEBRAZO
  servo3.write(135);  // BRAZO
  servo4.write(90);   // BASE

  delay(500);
}

void loop() {

  if (BT.available()) {

    a = BT.read();

    if (a == 'A') {
      motor1();
    }

    else if (a == 'B') {
      motor2();
    }

    else if (a == 'C') {
      motor3();
    }

    else if (a == 'D') {
      motor4();
    }

    else if (a == 'E') {
      digitalWrite(13, HIGH);
    }

    else if (a == 'F') {
      digitalWrite(13, LOW);
    }
  }
}

void motor1() {

  delay(10);

  while (BT.available()) {
    char b = BT.read();
    readString += b;
  }

  if (readString.length() > 0) {

    int angulo = constrain(readString.toInt(), 0, 180);
    servo1.write(angulo);

    readString = "";
  }
}

void motor2() {

  delay(10);

  while (BT.available()) {
    char b = BT.read();
    readString += b;
  }

  if (readString.length() > 0) {

    int angulo = constrain(readString.toInt(), 0, 180);
    servo2.write(angulo);

    readString = "";
  }
}

void motor3() {

  delay(10);

  while (BT.available()) {
    char b = BT.read();
    readString += b;
  }

  if (readString.length() > 0) {

    int angulo = constrain(readString.toInt(), 0, 180);
    servo3.write(angulo);

    readString = "";
  }
}

void motor4() {

  delay(10);

  while (BT.available()) {
    char b = BT.read();
    readString += b;
  }

  if (readString.length() > 0) {

    int angulo = constrain(readString.toInt(), 0, 180);
    servo4.write(angulo);

    readString = "";
  }
}
