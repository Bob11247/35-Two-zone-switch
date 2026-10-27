Код:
#include <TouchScreen.h>

const int YP = A3;
const int XM = A2;
const int YM = 9;
const int XP = 8;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int x, y = 0;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void switchOn() {
  digitalWrite(10, HIGH);
  Serial.print("Turned ON at X = ");
  Serial.print(x);
  Serial.print(" Y = ");
  Serial.println(y);
  delay(200);
}

void switchOff() {
  digitalWrite(10, LOW);
  Serial.print("Turned OFF at X = ");
  Serial.print(x);
  Serial.print(" Y = ");
  Serial.println(y);
  delay(200);
}

void loop() {
  TSPoint p = ts.getPoint();

  if (p.z > 0) {
    x = p.x;
    y = p.y;

    if (x >= 500 && x <= 900) {
      switchOn();
    } 
    else if (x >= 100 && x < 500) {
      switchOff();
    }
  }
}
