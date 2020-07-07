#include <Key.h>
#include <Keypad.h>

const int OUT1 = 2;
const int OUT2 = 3;
const int IN1 = 5;
const int IN2 = 6;

const byte outs = 2;
const byte ins = 2;
byte outPins[outs] = {OUT1, OUT2};
byte inPins[ins] = {IN1, IN2};
bool changed = false;

volatile bool pushStatus[outs][ins] = {
  { false, false },
  { false, false }
};

void setup() {
  Serial.begin(9600);

  pinMode(OUT1, OUTPUT);
  digitalWrite(OUT1, HIGH);
  pinMode(OUT2, OUTPUT);
  digitalWrite(OUT2, LOW);

  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
}

void loop() {
  for (int i = 0; i < outs; i++) {
    for (int j = 0; j < outs; j++) {
      if (i == j) {
        digitalWrite(outPins[j], HIGH);
      }
      else {
        digitalWrite(outPins[j], LOW);
      }
    }

    // delay(1);
    for (int j = 0; j < ins; j++) {
      bool result = digitalRead(inPins[j]);
      if (pushStatus[i][j] != result) {
        pushStatus[i][j] = result;
        changed = true;
      }
    }
  }
  if (changed) {
    changed = false;
    for (int i = 0; i < outs; i++) {
      for (int j = 0; j < ins; j++) {
        Serial.print(pushStatus[i][j]);
      }
    }
    Serial.println();
  }
}
