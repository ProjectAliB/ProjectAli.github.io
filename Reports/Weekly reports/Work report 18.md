# Work report 18 - 07/05/2024

## Performed tasks

- Reviewing the robot structure.
- Include the camera orientation into the main code.

### Robot structure

As this session marks the last robotic class before the presentation. I reviewed the robot entirely:
- I disassembled the robot and reassembled it to make sure no part was missing.
- I've done some welding to ensure the power supply can reach every component of the robot.
- I fixed the camera on its intended support.
- I checked the wiring.

### Code

The robot will behave following a code that dictate mainly two actions:
- The robot's mobility, through its CC motors.
- The camera's orientation, through a servomotor.

Therefore, making this the final version of the main code:

```

#include <Servo.h>
Servo myservo;

#include <SoftwareSerial.h>

#define enable_right_motor 12
#define right_motor_IN1 4
#define right_motor_IN2 8

#define enable_left_motor 13
#define left_motor_IN3 6
#define left_motor_IN4 7

void forward()
{
  digitalWrite(right_motor_IN1,LOW);
  digitalWrite(right_motor_IN2,HIGH);
  analogWrite(enable_right_motor,90);

  digitalWrite(left_motor_IN3,HIGH);
  digitalWrite(left_motor_IN4,LOW);
  analogWrite(enable_left_motor,240);
}

void backward()
{
  digitalWrite(right_motor_IN1,HIGH);
  digitalWrite(right_motor_IN2,LOW);
  analogWrite(enable_right_motor,90);

  digitalWrite(left_motor_IN3,LOW);
  digitalWrite(left_motor_IN4,HIGH);
  analogWrite(enable_left_motor,240);

  delay(500);

}

void turn_left()
{
  digitalWrite(right_motor_IN1,HIGH);
  digitalWrite(right_motor_IN2,LOW);
  analogWrite(enable_right_motor,90);

  digitalWrite(left_motor_IN3,HIGH);
  digitalWrite(left_motor_IN4,LOW);
  analogWrite(enable_left_motor,240);

  delay(500);

}

void turn_right()
{
  digitalWrite(right_motor_IN1,LOW);
  digitalWrite(right_motor_IN2,HIGH);
  analogWrite(enable_right_motor,120);

  digitalWrite(left_motor_IN3,LOW);
  digitalWrite(left_motor_IN4,HIGH);
  analogWrite(enable_left_motor,120);

  delay(500);

}

void stop()
{
  digitalWrite(enable_right_motor,LOW);
  digitalWrite(enable_left_motor,LOW);

  delay(500);

}

void camera()
{
  int pos {90};
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
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

  digitalWrite(enable_right_motor,LOW);
  digitalWrite(enable_left_motor,LOW);

  myservo.attach(9);
  myservo.write(90);
  forward();
  
}

void loop()
{
  camera();
}

```

The final step would be to include an object detection extension to the existing code using an Jetson Nano for image processing. This would be done separately as it doesn't need any physical intervention and is mainly a computing task.
