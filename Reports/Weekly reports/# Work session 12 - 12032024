# Work session 12 - 12/03/2024

## Done tasks overview

- Test robot movement control through Bluetooth.
- Fixing an issue concerning the code for the motor ESC.

## Results

-Using arrow keys, I used the following code to control the robot movement remotely:

```
#include <Servo.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;

Servo ESCR;     // create servo object to control the ESC
Servo ESCL;

void forward(){
  ESCR.write(255);
  ESCL.write(255);
}

void backward(){
  ESCR.write(-255);
  ESCL.write(-255);
}
 void right(){
  ESCR.write(-255);
  ESCL.write(255);
}
void left(){
  ESCR.write(255);
  ESCL.write(-255);
}
void stop(){
  ESCR.write(0);
  ESCL.write(0); 
}

void setup() {
  ESCR.attach(6,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  ESCL.attach(9,1000,2000);
  Serial.begin(9600);
  BlueT.begin(9600);
}

void loop(){
  Serial.println("forward");
  forward();
  delay(3000);
  
  stop();
  Serial.println("stop");
  delay(3000);
  Serial.println("backward");
  backward();
  delay(3000);
  stop();
  while(1);
  if (BlueT.available()){
    Data=char(BlueT.read());
    if (Data=='F') {
      forward();
      delay(50);
    }
    else if (Data=='B') {
      backward();
      delay(50);
    }
    else if (Data=='R') {
      right();
      delay(50);
    }
    else if (Data=='L') {
      left();
      delay(50);
    }
    Serial.println(Data);
  }
}

```

- Only the left motor was functionning whereas the right one didn't rotate at all. I verified the state of both motors, however, the issue seemed to be unrelated to the motor parts.

- After a discussion with some of my colleagues, some parts of my code needed review. As the library i was using was used for servomotors, my ESC was considered as such, not a DC motor. As a result, I would be using values ranging from 0 to 180 to determine the ESC speed instead of values ranging from -255 to 255, with the value 90 being the point where my ESC are at a static state. Here is the revised code:

```
#include <Servo.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;

Servo ESCR;     // create servo object to control the ESC
Servo ESCL;

void forward(){
  ESCR.write(180);
  ESCL.write(180);
}

void backward(){
  ESCR.write(0);
  ESCL.write(0);
}
 void right(){
  ESCR.write(0);
  ESCL.write(180);
}
void left(){
  ESCR.write(180);
  ESCL.write(0);
}
void stop(){
  ESCR.write(90);
  ESCL.write(90); 
}

void setup() {
  ESCR.attach(6,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  ESCL.attach(9,1000,2000);
  Serial.begin(9600);
  BlueT.begin(9600);
}

void loop(){
  Serial.println("forward");
  forward();
  delay(3000);
  
  stop();
  Serial.println("stop");
  delay(3000);
  Serial.println("backward");
  backward();
  delay(3000);
  stop();
  while(1);
  if (BlueT.available()){
    Data=char(BlueT.read());
    if (Data=='F') {
      forward();
      delay(50);
    }
    else if (Data=='B') {
      backward();
      delay(50);
    }
    else if (Data=='R') {
      right();
      delay(50);
    }
    else if (Data=='L') {
      left();
      delay(50);
    }
    Serial.println(Data);
  }
}

```

## Next steps

- Test the robot movement using the revised code.
- Work on adding sensors to interact with the surrounding.



