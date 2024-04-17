# Work report 17 - 16/04/2024

## Performed tasks

- Camera support and its gear system modeling.
- Camera support printing.
- Camera orientation code writing.
- Arduino-Mega shield welding.

---

### Camera support

Based on the servomotor arm, I modeled a circle shaped suuport that would be mounted and fixed on the servomotor's rotor using a screw-nut system. It fits the used camera's size perfectly. The camera used will be a **"logitech c505e"**.

[Here is the camera support model.](https://github.com/ProjectAliB/ProjectAli.github.io/blob/548c127ccb65e4a5e9cb52a2d0ff039dcaf16cb6/Ressources/Images%26Pictures/Week%2017/Camera%20support%20v2.stl)
---
![Camera support](https://github.com/ProjectAliB/ProjectAli.github.io/blob/cdf559802194ace25d813042670dd25d1a477346/Ressources/Images%26Pictures/Week%2017/WhatsApp%20Image%202024-04-17%20at%2013.35.52_8f29d4c5.jpg)
---
![Camera mouunted on the robot](https://github.com/ProjectAliB/ProjectAli.github.io/blob/cdf559802194ace25d813042670dd25d1a477346/Ressources/Images%26Pictures/Week%2017/WhatsApp%20Image%202024-04-17%20at%2013.35.52_8d04202a.jpg)

### Camera orientation code

This is a code for getting started with the servomotor. It still wasn't modified in way to be adapted to the robot's main code.
```
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);
  Serial.begin(9600);
}

void loop() 
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
```

### Arduino-Mega welding

I switched from an arduino uno to an arduino mega to increase the number of usable pins. I did some welding on its shield to ensure no wire gets disconnected during robot operations.

## Next steps

- Include the camera code to the main one.
- Learn how to use objetc detection with tha camera and the Jetson nano.
