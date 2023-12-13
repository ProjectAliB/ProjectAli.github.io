# Work session 03 - 08/12/2023

## Overview

My work consisted of welding many wires in order to control two brushless motors simultaneously with one potentiometer.

## Installation and wiring

In order to use the second brushless motor, i needed to connect its wires to the ESC through a connecter.

![Motor&Connector](https://github.com/ProjectAliB/ProjectAli.github.io/blob/946b2f7fd9ac70857cc8dc90dccfa22b12808db4/Ressources/Images%26Pictures/IMG-20231208-WA0001.jpg)

The next step was to follow the same diagram as for the first motor, while verifying that the two motors share the same pin on the Arduino microcontroller, to ensure both have the same speed.

![Final circuit](https://github.com/ProjectAliB/ProjectAli.github.io/blob/946b2f7fd9ac70857cc8dc90dccfa22b12808db4/Ressources/Images%26Pictures/IMG-20231208-WA0005.jpg)

![Final circuit](https://github.com/ProjectAliB/ProjectAli.github.io/blob/946b2f7fd9ac70857cc8dc90dccfa22b12808db4/Ressources/Images%26Pictures/IMG-20231208-WA0007.jpg)

Some wires were impossible to connect through the connecter, wich called for the use of welding.
The end resut was that both brushless motors were working and turning at the same speed, the speed being changeable through the potentiometer.

## Next goal

Making the installation and wiring for the real motors that will be actually used for the vehicle prototype, while measuring the velocity of each of the motors.