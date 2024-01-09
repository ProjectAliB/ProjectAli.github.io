#include <Servo.h>

Servo ESC1;     // create servo object to control the ESC
Servo ESC2;

int potValue1;  // value from the analog pin
int potValue2;

void setup() {
  // Attach the ESC on pin 9
  ESC1.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  ESC2.attach(11,1000,2000);
  Serial.begin(9600);
}

void loop() {
  potValue1 = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue2 = analogRead(A1);
  potValue1 = map(potValue1, 0, 1023, 0, 255);   // scale it to use it with the servo library (value between 0 and 180)
  potValue2 = map(potValue2, 0, 1023, 0, 255);
  ESC1.write(potValue1);    // Send the signal to the ESC
  ESC2.write(potValue2);
  Serial.print(potValue1);
  Serial.print("-");
  Serial.println(potValue2);
  delay(100);
}