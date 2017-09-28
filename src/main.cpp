// Test program TB6612FNG with Arduino Uno
// By : Eko Rudiawan
// Only test for 1 channel
// Connection
// STRBY : ALWAYS HIGH
// PWMB : ALWAYS HIGH
// BIN1 : PIN 12 Arduino
// BIN2 : PIN 13 Arduino (PWM)

#include <Arduino.h>
#define BIN1  12
#define BIN2  11
void setup() {
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
}

void driveMotor(int speed) {
    // Limit speed only -255 to 255
    if (speed < -255) {
      speed = -255;
    }
    else if (speed > 255) {
      speed = 255;
    }
    // Zero value mean short brake the motor
    // Negatif value mean motor drive to CCW direction with spesific absolut speed value
    // Positif value mean motor drive to CW direction with spesific absolut speed value
    if (speed == 0) {
      digitalWrite(BIN1, HIGH);
      analogWrite(BIN2, 255);
    }
    else if (speed < 0) {
      digitalWrite(BIN1, HIGH);
      analogWrite(BIN2, 255 - abs(speed));
    }
    else {
      digitalWrite(BIN1, LOW);
      analogWrite(BIN2, abs(speed));
    }
}

void loop() {
    // Test drive the motor with speed 90 and direction CCW
    driveMotor(-90);

}
