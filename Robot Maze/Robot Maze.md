# Robot Maze

## What is the robot capable of using this code?

-The robot is capable of finding a single black square in a maze regardless of the maze's size or the black square's position.
-Not having the black square near a wall is not a problem at all.
-This code is still functionning not matter where the starting point (the red square) is.
-This code does not prioritize speed, however it has a nearly 100% success rate.
-The robot is only finding one black square before returning to the red square.
-Changing the red square position after the code starts is not a problem.

## What is happening in the code?

-After starting the code, a first loop will start. The ending condition is the light sensor returning a value equal to 0, which means finding the black color.
-While in the loop, the robot will keep moving forward as long as both its front proximity sensors don't detect any obstacles.
-While moving forward, the robot will keep checking with its "VerfifyBlack" function if it is on a black square. Finding it will make the robot break from this while loop. The "VerifyBlack" is also capable of distinguishing between a black line and a black square. How it is done is explained in the code.
-If the robot detect an obstacle at the front, it will turn, right or left depending on the obstacle's position, until there is no more obstacle at the front.
-After turning, the robot will check again for the black square using the "VerifyBlack" function.
-This marks the end of the first while loop. Breaking this loop means the robot succeded in finding the black square.
-After finding the black square and breaking from the first while loop, the robot will enter a second while loop similar to the first. The only difference being the ending condition. This time, the ending condtion is the light sensor returning a analog value between 250 and 300.
-A analog value between 250 and 300 means the robot is standing on a red square, this has bee, confirmed through several trials.
-The robot will then follow the same method as in the first loop, except it will be using the "VerifyRed" function instead of the "VerifyBlack" one. How it works is explained in the code.
-The robot will keep executing the code in the second loop until finding the red square. It will then stop moving.

## Used functions

-"forward()": Moving the robot forward.
-"backward(): Moving the robot backward.
-"stop(): Completely stoping the robot from moving.
-"TurnRight()": The robot turns right.
-"TurnLeft()": The robot turns left.
-"VerifyBlack()": Verifying the robot reached a black square.
 -"VerifyRed()": Verifying the robot reached a red square.

## Code

```
#define LIGHT_SENSOR_PIN A0

#define PROX_SENSOR_L_PIN A1
#define PROX_SENSOR_R_PIN 11 //A2
#define PROX_SENSOR_FL_PIN 6
#define PROX_SENSOR_FR_PIN 9 //A4
#define PROX_SENSOR_RL_PIN A5
#define PROX_SENSOR_RR_PIN A2
#define PROX_SENSOR_DL_PIN A3
#define PROX_SENSOR_DR_PIN A4 //9

#define MOTOR_RF_PIN 2
#define MOTOR_RB_PIN 4
#define MOTOR_R_SPEED 3
#define MOTOR_LF_PIN 7
#define MOTOR_LB_PIN 8
#define MOTOR_L_SPEED 5

void hardware_setup() {
  new DCMotor_Hbridge(MOTOR_RF_PIN, MOTOR_RB_PIN, MOTOR_R_SPEED, "ePuck_rightJoint", 2.5, 3 * 3.14159, 1);
  new DCMotor_Hbridge(MOTOR_LF_PIN, MOTOR_LB_PIN, MOTOR_L_SPEED, "ePuck_leftJoint", 2.5, 3 * 3.14159, 1);

  new VisionSensor(LIGHT_SENSOR_PIN, "ePuck_lightSensor", 0.1);

  new ProximitySensor(PROX_SENSOR_FL_PIN, "ePuck_proxSensor3", 0.1, 1);
  new ProximitySensor(PROX_SENSOR_FR_PIN, "ePuck_proxSensor4", 0.1, 1);
  new ProximitySensor(PROX_SENSOR_L_PIN, "ePuck_proxSensor1", 0.1, 1);
  new ProximitySensor(PROX_SENSOR_R_PIN, "ePuck_proxSensor6", 0.1, 1);
  new ProximitySensor(PROX_SENSOR_RL_PIN, "ePuck_proxSensor7", 0.1, 1);
  new ProximitySensor(PROX_SENSOR_RR_PIN, "ePuck_proxSensor8", 0.1, 1);
  new ProximitySensor(PROX_SENSOR_DL_PIN, "ePuck_proxSensor2", 0.1, 1);
  new ProximitySensor(PROX_SENSOR_DR_PIN, "ePuck_proxSensor5", 0.1, 1);
}

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_RF_PIN, OUTPUT);
  pinMode(MOTOR_RB_PIN, OUTPUT);
  pinMode(MOTOR_R_SPEED, OUTPUT);
  pinMode(MOTOR_LF_PIN, OUTPUT);
  pinMode(MOTOR_LB_PIN, OUTPUT);
  pinMode(MOTOR_L_SPEED, OUTPUT);
    // Set speed
  analogWrite(MOTOR_R_SPEED, 200);
  analogWrite(MOTOR_L_SPEED, 200);
}

void stop(){
  digitalWrite(MOTOR_RF_PIN, LOW);
  digitalWrite(MOTOR_RB_PIN, LOW);
  digitalWrite(MOTOR_LF_PIN, LOW);
  digitalWrite(MOTOR_LB_PIN, LOW);  
}

void forward(){
  digitalWrite(MOTOR_RF_PIN, HIGH);
  digitalWrite(MOTOR_RB_PIN, LOW);
  digitalWrite(MOTOR_LF_PIN, HIGH);
  digitalWrite(MOTOR_LB_PIN, LOW);
  delay(49);  
}

void backward(){
  digitalWrite(MOTOR_RF_PIN, LOW);
  digitalWrite(MOTOR_RB_PIN, HIGH);
  digitalWrite(MOTOR_LF_PIN, LOW);
  digitalWrite(MOTOR_LB_PIN, HIGH);
  delay(500);  
}

void TurnRight(){
  digitalWrite(MOTOR_RF_PIN, LOW);
  digitalWrite(MOTOR_RB_PIN, HIGH);
  digitalWrite(MOTOR_LF_PIN, HIGH);
  digitalWrite(MOTOR_LB_PIN, LOW);
  delay(10);  
}

void TurnLeft(){
  digitalWrite(MOTOR_RF_PIN, HIGH);
  digitalWrite(MOTOR_RB_PIN, LOW);
  digitalWrite(MOTOR_LF_PIN, LOW);
  digitalWrite(MOTOR_LB_PIN, HIGH);
  delay(10);
}

//This function allow the robot to verify if the black line it detected is from a black square or a black line: To ensure that the black color is from a square and not a line, the robot will slightly move forward, check if it still detects a black color, turn both right and left and check again. If it still detects a balck color, that would mean it is a square indeed.
void VerifyBlack(){
  forward();
  if (digitalRead(LIGHT_SENSOR_PIN) !=0){
    TurnRight();
    delay(140);
    if (digitalRead(LIGHT_SENSOR_PIN) !=0){
      TurnLeft();
      delay(290);
    }
  }
}

//The same logic behind the function "VerifyBlack", except it is for red square.
void VerifyRed(){
  forward();
  if (analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
    TurnRight();
    delay(80);
    if (analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
      TurnLeft();
      delay(170);
    }
  }  
}

void loop(){
  while (digitalRead(LIGHT_SENSOR_PIN) !=0){
    Serial.println("Black Search");
    //As long as the robot doesn't detect an obstacle with the two sensors at its front, it will keep moving forward.
    while ((analogRead(PROX_SENSOR_FL_PIN)>60) && (analogRead(PROX_SENSOR_FR_PIN)>60)){
      forward();
      delay(50);
      
      //While moving forward, the robot will constantly check if it crossed a black square:
      if (digitalRead(LIGHT_SENSOR_PIN) ==0){
        VerifyBlack();
        if (digitalRead(LIGHT_SENSOR_PIN) ==0){
          break;
        }
      }
    }
    // After detecting any obstacle in front of him, the robot will check if there are any obstacles at its sides using both right and left sensors, and will turn to the opposite side of the detected obstacle.
    if (analogRead(PROX_SENSOR_FL_PIN)<60){
      while (analogRead(PROX_SENSOR_FL_PIN)<60){
        TurnRight();
      }
    }
    if (analogRead(PROX_SENSOR_FR_PIN)<60){
      while (analogRead(PROX_SENSOR_FR_PIN)<60){
        TurnLeft();
      }
    }
    if (digitalRead(LIGHT_SENSOR_PIN) ==0){
      VerifyBlack();
      if (digitalRead(LIGHT_SENSOR_PIN) ==0){
        break;
      }
    }
  }

  //Leaving the last "while loop" would mean that the robot cleared the condition "digitalRead(LIGHT_SENSOR_PIN) !=0", which means that it found the black square.
  Serial.println("Black Found");
  forward();
  stop();
  delay(1500);

  //The robot will move on to finding the red square using the same method as for the black square.
  while (analogRead(LIGHT_SENSOR_PIN)<250 || analogRead(LIGHT_SENSOR_PIN)>300){
    Serial.println("Red Search");
    while ((analogRead(PROX_SENSOR_FL_PIN)>60) && (analogRead(PROX_SENSOR_FR_PIN)>60)){
      forward();
      if (analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
        VerifyRed();
        if(analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
          while (analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
            stop();
          }
        }
      }
    }

    if (analogRead(PROX_SENSOR_FL_PIN)<60){
      while (analogRead(PROX_SENSOR_FL_PIN)<60){
        TurnRight();
      }
    }
    if (analogRead(PROX_SENSOR_FR_PIN)<60){
      while (analogRead(PROX_SENSOR_FR_PIN)<60){
        TurnLeft();
      }
    }

    if (analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
      VerifyRed();
      if (analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
        break;
      }
    }

  }
  Serial.println("Red Found");
  stop();
  while (analogRead(LIGHT_SENSOR_PIN)>250 && analogRead(LIGHT_SENSOR_PIN)<300){
    stop();
  }
}

```