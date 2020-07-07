#include <Key.h>
#include <Keypad.h>

const int OUT1 = 2;
const int OUT2 = 3;
const int IN1 = 4;
const int IN2 = 5;

const byte rows = 2;
const byte cols = 2;

char keys[rows][cols] = {
  {'0', '1'},
  {'2', '3'},
};

byte rowPins[rows] = {OUT1, OUT2}; //connect to the row pinouts of the keypad
byte colPins[cols] = {IN1, IN2}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(keypad.key[2].kchar);
}

void loop() {
  //  delay(1000);
  //  Serial.println("=================");
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.println(key);
  }

//  for (int i = 0; i < rows; i++) {
//    for (int j = 0; i < cols; i++) {
//      if (keypad.isPressed(keys[i][j])) {
//        Serial.println(keys[i][j]);
//      }
//    }
//  }
}
