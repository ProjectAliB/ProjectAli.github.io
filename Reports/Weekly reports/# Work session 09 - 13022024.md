# Work session 09 - 13/02/2004

## Overview

The focus of this work session was on the possible solutions available for making the front wheels, as well as the power supply for the robot.

## Front wheels

Two choices were available for making the front wheels:
- Have two big wheels, similar in size to the driving wheels, with 3 degrees of freedom using a ball bearing system. This solution put design and outward appearance over practicality as it is very complex to achieve using the available tools.

![ball-bearing system](https://github.com/ProjectAliB/ProjectAli.github.io/blob/2a1ca53ff429579bca9b1b5f719874a67cc837d7/Ressources/Images%26Pictures/Work%20session%2010/20240213_103211.jpg)

- Using multi-directionnal wheels, a choice that would prioritize practicality over design, and the standard solution for similar robots.

![Multi-directionnal wheels](https://github.com/ProjectAliB/ProjectAli.github.io/blob/2a1ca53ff429579bca9b1b5f719874a67cc837d7/Ressources/Images%26Pictures/Work%20session%2010/20240213_103206.jpg)

The choice would be done later after testing both solutions.

## Power supply

In order to accuratly determine the power source (the battery), to use as a power supply for our robot, it is necessary to clarify what components of the robot would need power supply, and what are their specs.
The current situation requires the powering of two brushless motors, each one with the specs below according to their manufacturer:

![Motor specs](https://github.com/ProjectAliB/ProjectAli.github.io/blob/f4e692affaa73d4b6739bb4843d057b13e5b4d30/Ressources/Images%26Pictures/Work%20session%2010/Screenshot%202024-02-13%20090609.png)

The capacity of the battery isn't a priority in the curent situation as this is a prototype.
As a result, the battery used should have the following specs:
- Rated current of 80A.
- Rated voltage of 12V.

Out of the available batteries, the one which is the most adapted is a rechargeable Lithium-Ion battery with thoe following specs:
- Rated current of 66A.
- Rated voltage of 11.1V.
- Capacity of 24.42Wh.

![Li-ion battery](https://github.com/ProjectAliB/ProjectAli.github.io/blob/f4e692affaa73d4b6739bb4843d057b13e5b4d30/Ressources/Images%26Pictures/Work%20session%2010/20240213_091004.jpg)

In order to connect the motors to the battery, the following piece was used:

![Y piece](https://github.com/ProjectAliB/ProjectAli.github.io/blob/f4e692affaa73d4b6739bb4843d057b13e5b4d30/Ressources/Images%26Pictures/Work%20session%2010/20240213_103158.jpg)

All that was left was welding the to motorrs wires together to connect them both to the battery.

![Welding](https://github.com/ProjectAliB/ProjectAli.github.io/blob/f4e692affaa73d4b6739bb4843d057b13e5b4d30/Ressources/Images%26Pictures/Work%20session%2010/20240213_105453.jpg)

![Welding](https://github.com/ProjectAliB/ProjectAli.github.io/blob/f4e692affaa73d4b6739bb4843d057b13e5b4d30/Ressources/Images%26Pictures/Work%20session%2010/20240213_113421.jpg)

## Next session goal

Finish welding the wires, connect it to the battery, and install the front wheels.
