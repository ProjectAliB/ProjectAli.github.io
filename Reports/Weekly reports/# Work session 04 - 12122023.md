# Work session 04 - 12/12/2023

## Overview

During this session, i mainly focused on wiring both motors with the arduino controller and testing the program.

## Wiring

Now that i have a clear idea of how a correct installation is conducted, i started working with the real motors, along with its ESC, that are actually going to be used for the prototype.

![New motor](https://github.com/ProjectAliB/ProjectAli.github.io/blob/d8a4ca8610ed1222c247f67e1516d9147a9ec232/Ressources/Images%26Pictures/Work%20session%2004/IMG-20231212-WA0006.jpg)

![ESC](https://github.com/ProjectAliB/ProjectAli.github.io/blob/d8a4ca8610ed1222c247f67e1516d9147a9ec232/Ressources/Images%26Pictures/Work%20session%2004/IMG-20231212-WA0005.jpg)

After wiring, i succeded in controlling the speed of both motors using the ancient code, by connecting both motors in the same PWM pin 9. That allows both motors to turn at the exact same speed, giving the the have the exact same parameters.

![1 motor](https://github.com/ProjectAliB/ProjectAli.github.io/blob/d8a4ca8610ed1222c247f67e1516d9147a9ec232/Ressources/Images%26Pictures/Work%20session%2004/IMG-20231212-WA0004.jpg)

![2 motors](https://github.com/ProjectAliB/ProjectAli.github.io/blob/d8a4ca8610ed1222c247f67e1516d9147a9ec232/Ressources/Images%26Pictures/Work%20session%2004/IMG-20231212-WA0007.jpg)

## Code

Even though my last code was perfectly working, the fact that is calls another library "servo" makes it hard for me to visualize how the code really works, which slows me down when i am trying to bring modifications to the code. I decided to write a new code, similar to the first, but easier to understand. The new one does include the "<Servo.h>" library:

```
int x;
int y;
#define pot A0
#define mot1 9

void setup(){
  pinMode(pot, INPUT);
  pinMode(mot1, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  delay(50);
  x = analogRead(pot);
  y = map(x, 0, 1023, 0, 255);  // Use the map function for better scaling
  analogWrite(mot1, y);
  Serial.println(y);
  delay(250);  // Add a small delay to avoid rapid serial prints
}

```

This code does work fine. However, further modifications must be done as i observed that the motor does not work consistentlyat some times, a problem that i didn't face with the first code.

## Next goal

Optimize the second code and test its efficacy. Start modeling the prototype on Fusion 360.