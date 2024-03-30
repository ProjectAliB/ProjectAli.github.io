# Work session 14 - 29/03/2024

## Undertaken tasks

### 1) Replacing brushless motors with CC motors:

After many hours working with brushless motors for the robot mobility, I abandoned the idea and decided to switch to CC motors.
There are two motoves behind this decision :
- The brushless motors used for the robot are an overkill. Their speed is way higher thatn what is needed, and the power needed to be supplied is big compared to the robot task nature. Moreover, controlling its speed remotely has proven to be a real hurdle which I could not overcome even with the help of my colleagues.
- The CC motor require less power, and is easier to code and control using the arduino IDE.

As a result I decided to switch to CC motors instead of staying blocked with brusless ones, as I already wasted a lot of time.

![CC motors](https://github.com/ProjectAliB/ProjectAli.github.io/blob/a6a563d409cdd19a945c290b5418cb7a2424d8f4/Ressources/Images%26Pictures/Work%20session%2014/WhatsApp%20Image%202024-03-29%20at%2014.07.36_736025d4.jpg)

![CC motors](https://github.com/ProjectAliB/ProjectAli.github.io/blob/a6a563d409cdd19a945c290b5418cb7a2424d8f4/Ressources/Images%26Pictures/Work%20session%2014/WhatsApp%20Image%202024-03-30%20at%2012.37.52_eb57547b.jpg)

### 2) Mounting the motor driver along with its wiring:

In order to control the motor's rotation direction, I needed a driver. I chose the L298N dual Hbridge stepper, which works both as a stepper to change direction, and a 12V power supplier. After mounting it, I've also reworked the wiring and the smelting to power both the driver and the arduino with a single power source.

![L298N](https://github.com/ProjectAliB/ProjectAli.github.io/blob/a6a563d409cdd19a945c290b5418cb7a2424d8f4/Ressources/Images%26Pictures/Work%20session%2014/WhatsApp%20Image%202024-03-29%20at%2014.07.36_0ab449b9.jpg)

![L298N](https://github.com/ProjectAliB/ProjectAli.github.io/blob/a6a563d409cdd19a945c290b5418cb7a2424d8f4/Ressources/Images%26Pictures/Work%20session%2014/WhatsApp%20Image%202024-03-30%20at%2012.37.52_cdfb3731.jpg)

### 3) Arrange the code for CC motors' use:

As i switched to CC motors, it was no longer needed to use the `` <servo.h> `` library. The latest version of the code is as followed:

```

#include <SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;

#define enable_right_motor 9
#define right_motor_IN1 4
#define right_motor_IN2 8

#define enable_left_motor 3
#define left_motor_IN3 6
#define left_motor_IN4 7

void forward()
{
  digitalWrite(right_motor_IN1,LOW);
  digitalWrite(right_motor_IN2,HIGH);
  analogWrite(enable_right_motor,128);

  digitalWrite(left_motor_IN3,HIGH);
  digitalWrite(left_motor_IN4,LOW);
  analogWrite(enable_left_motor,128);

}

void backward()
{
  digitalWrite(right_motor_IN1,HIGH);
  digitalWrite(right_motor_IN2,LOW);
  analogWrite(enable_right_motor,128);

  digitalWrite(left_motor_IN3,LOW);
  digitalWrite(left_motor_IN4,HIGH);
  analogWrite(enable_left_motor,128);

}

void turn_right()
{
  digitalWrite(right_motor_IN1,HIGH);
  digitalWrite(right_motor_IN2,LOW);
  analogWrite(enable_right_motor,128);

  digitalWrite(left_motor_IN3,HIGH);
  digitalWrite(left_motor_IN4,LOW);
  analogWrite(enable_left_motor,128);

}

void turn_left()
{
  digitalWrite(right_motor_IN1,LOW);
  digitalWrite(right_motor_IN2,HIGH);
  analogWrite(enable_right_motor,128);

  digitalWrite(left_motor_IN3,LOW);
  digitalWrite(left_motor_IN4,HIGH);
  analogWrite(enable_left_motor,128);

}

void stop()
{
  digitalWrite(enable_right_motor,LOW);
  digitalWrite(enable_left_motor,LOW);

}

void setup()
{
  pinMode(enable_right_motor,OUTPUT);
  pinMode(right_motor_IN1,OUTPUT);
  pinMode(right_motor_IN2,OUTPUT);
  
  pinMode(enable_left_motor,OUTPUT);
  pinMode(left_motor_IN3,OUTPUT);
  pinMode(left_motor_IN4,OUTPUT);

  Serial.begin(9600);
  BlueT.begin(9600);

  digitalWrite(enable_right_motor,LOW);
  digitalWrite(enable_left_motor,LOW);
}

void loop()
{
  if (BlueT.available()){
    Data=char(BlueT.read());
    if (Data=='F') {
      forward();
      delay(500);
    }
    else if (Data=='B') {
      backward();
      delay(500);
    }
    else if (Data=='R') {
      turn_right();
      delay(500);
    }
    else if (Data=='L') {
      turn_left();
      delay(500);
    }
    else if (Data=='S') {
      stop();
      delay(500);
    }
    Serial.println(Data);
  }
}

```

I implemented this code and run several tests to ensure an accurate control of the robot behaviour. The test was a success.

## Next steps

- Run more tests to verify that there are no problem regarding the precedently done tasks.
- Optimize the cable management.
- Model the system that will support the camera to be mounted on the robot.
