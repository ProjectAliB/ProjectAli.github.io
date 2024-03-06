# Work session 11 - 05/03/2024

## Overview

Today's work session focused on controlling the robot with a phone app through bluetooth.

## Bluetooth module

The bluetooth module that will be used for remote control is the "HC-06" module.

![HC-06](https://github.com/ProjectAliB/ProjectAli.github.io/blob/abf662fe4821fbe78f45c9f7e9e41f8277266722/Ressources/Images%26Pictures/Work%20session%2011/Screenshot%202024-03-06%20154450.png)

Following an online guide, I connected the bluetooth module to the arduino micro-controller.

![Schematic](https://github.com/ProjectAliB/ProjectAli.github.io/blob/abf662fe4821fbe78f45c9f7e9e41f8277266722/Ressources/Images%26Pictures/Work%20session%2011/Screenshot%202024-03-06%20154520.png)

![Arduino+Module](https://github.com/ProjectAliB/ProjectAli.github.io/blob/abf662fe4821fbe78f45c9f7e9e41f8277266722/Ressources/Images%26Pictures/Work%20session%2011/WhatsApp%20Image%202024-03-06%20at%2015.07.54_42f2d100.jpg)

The app used for this purpose is "Bluetooth Electronics" available on any android phone.

## Code

For practical reasons, I decided to use the joyctick option to control the robot's speed and direction remotely. This called for a code that converts the joystick angular values and coordinates into actual data useful for the arduino micro-controller.
The following code is the code used when using a physical joyctick directly connected to the arduino:

```

#include <Servo.h>
Servo servo1;
Servo servo2;
int x_key = A1;                                               
int y_key = A0;                                               
int x_pos;
int y_pos;
int servo1_pin = 8;
int servo2_pin = 9;  
int initial_position = 90;
int initial_position1 = 90;

void setup ( ) {
Serial.begin (9600) ;
servo1.attach (servo1_pin ) ; 
servo2.attach (servo2_pin ) ; 
servo1.write (initial_position);
servo2.write (initial_position1);
pinMode (x_key, INPUT) ;                     
pinMode (y_key, INPUT) ;                      
}

void loop ( ) {
x_pos = analogRead (x_key) ;  
y_pos = analogRead (y_key) ;                      

if (x_pos < 300){
if (initial_position < 10) { } else{ initial_position = initial_position - 20; servo1.write ( initial_position ) ; delay (100) ; } } if (x_pos > 700){
if (initial_position > 180)
{  
}  
else{
initial_position = initial_position + 20;
servo1.write ( initial_position ) ;
delay (100) ;
}
}

if (y_pos < 300){
if (initial_position1 < 10) { } else{ initial_position1 = initial_position1 - 20; servo2.write ( initial_position1 ) ; delay (100) ; } } if (y_pos > 700){
if (initial_position1 > 180)
{  
}        
else{
initial_position1 = initial_position1 + 20;
servo2.write ( initial_position1 ) ;
delay (100) ;
}
}
}

```

Using a code as a base to convert position data to data for the arduino, I decided to merge it with the code for controlling the arduino micro-controller remotely through a virtual joystick on the bluetooth app:

```

#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
void setup(){
Serial.begin(9600);
BlueT.begin(9600);
delay(500);}
void loop(){
while (BlueT.available()) {
Serial.print(char(BlueT.read())); }
while (Serial.available()) {
BlueT.write(char(Serial.read())); }
}

```

## Next session goal

Adapt the bluetooth code to the robot needs, by adjusting its inputs and outputs, and merge it with the joystick controlled code.
