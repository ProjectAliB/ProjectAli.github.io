# Work session 02 - 21/11/2023

## Overview

During this session, my work mainly consisted of finding a code for controlling the speed of the brushless motor and looking for ways to measure its velocity.

## Code

After reading some articles and tutorials on the net concerning arduino brushless motor control, i've found an complete tutorial on the [How to mechatrocnics](https://howtomechatronics.com/tutorials/arduino/arduino-brushless-motor-control-tutorial-esc-bldc/?utm_content=cmp-true) clarifying how the installation and code are done.

![Circuit diagram](https://github.com/ProjectAliB/ProjectAli.github.io/blob/1cbd9e94f73587c167a03dce4441c8c7379153ef/Ressources/Images%26Pictures/Arduino_brushless_motor.png)

After following the given model, the installation was now complete.

![Self made circuit](https://github.com/ProjectAliB/ProjectAli.github.io/blob/1cbd9e94f73587c167a03dce4441c8c7379153ef/Ressources/Images%26Pictures/IMG-20231121-WA0001.jpg)
![Self made circuit](https://github.com/ProjectAliB/ProjectAli.github.io/blob/1cbd9e94f73587c167a03dce4441c8c7379153ef/Ressources/Images%26Pictures/IMG-20231121-WA0004.jpg)

All that was left was to implement the code.

  ```
  #include <Servo.h>
  
  Servo ESC;     // create servo object to control the ESC
  
  int potValue;  // value from the analog pin
  
  void setup() {
    // Attach the ESC on pin 9
    ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
    Serial.begin(9600);
  }
  
  void loop() {
    potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
    potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
    ESC.write(potValue);    // Send the signal to the ESC
    Serial.println(potValue);
  }
  ```

After executing the code, i was able to control the speed of the brushless motor using the potentiometer connected to the arduino.

## Measuring velocity

Now that i am able to control the speed of the motor, i must have a way to quantify this speed. For this purpose, i procured a MH sensor as well as an adhesive tape capable of reflecting light.

![MH sensor](https://github.com/ProjectAliB/ProjectAli.github.io/blob/1cbd9e94f73587c167a03dce4441c8c7379153ef/Ressources/Images%26Pictures/IMG-20231121-WA0003.jpg)
![Tape](https://github.com/ProjectAliB/ProjectAli.github.io/blob/1cbd9e94f73587c167a03dce4441c8c7379153ef/Ressources/Images%26Pictures/IMG-20231121-WA0002.jpg)

After gluing a small part of the tape on the motor or the wheel, and by measuring the frequence at which the MH sensor capture light reflected by this tape, i will be able to know the exact speed at which the motor, or the wheel, is running.

## Next goal

Add the MH sensor to the brushless motor circuit and make the code for measuring velocity.
