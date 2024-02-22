# Work session 10 - 21/02/2024

## Overview

This session's tasks consisted of wiringand fixing the front wheels.

## Wiring

The more captors and electronic pieces I use, the more difficult it becomes to distinguish which wire does what. To simplify future tasks and make it easier to discern each component, I placed my wires in a organised and smooth way.

![Wiring](https://github.com/ProjectAliB/ProjectAli.github.io/blob/789e78f4e298a1794a3a90cd20c97fbd545787a1/Ressources/Images%26Pictures/Work%20session%2010/20240221_170640.jpg)

I also merged both motors' power supply cables into a single one in order to use a single battery instead of two separate ones.

![Merge](https://github.com/ProjectAliB/ProjectAli.github.io/blob/789e78f4e298a1794a3a90cd20c97fbd545787a1/Ressources/Images%26Pictures/Work%20session%2010/20240221_145751.jpg)

## Front wheels

After analysing the pros and cons of each of the two solutions given last session ("Multi-directional wheels" VS "Regular wheels"), it was decided that using multi-directional wheels wheels was a better choice. The main resons are:
- Easy to assemble.
- More freedom.
- Less time-consuming.

![Front wheels](https://github.com/ProjectAliB/ProjectAli.github.io/blob/789e78f4e298a1794a3a90cd20c97fbd545787a1/Ressources/Images%26Pictures/Work%20session%2010/20240221_153405.jpg)

Using a wood plank measuring around 33mm in thickness to adjust the height of the front wheels.

![Wood plank](https://github.com/ProjectAliB/ProjectAli.github.io/blob/789e78f4e298a1794a3a90cd20c97fbd545787a1/Ressources/Images%26Pictures/Work%20session%2010/20240221_153358.jpg)

![Robot](https://github.com/ProjectAliB/ProjectAli.github.io/blob/789e78f4e298a1794a3a90cd20c97fbd545787a1/Ressources/Images%26Pictures/Work%20session%2010/20240221_170627.jpg)

![Robot](https://github.com/ProjectAliB/ProjectAli.github.io/blob/789e78f4e298a1794a3a90cd20c97fbd545787a1/Ressources/Images%26Pictures/Work%20session%2010/20240221_170634.jpg)

## Mistakes Made

During today's test of the wheels speed control, i accidently burned the arduino micro-controller. After discussing the problem with my collegues, i found that the problem resides in the amount of voltage and power supplied to the arduino. The arduino controller supports 5V, however my power source ddelivered 12V as demanded by my motors. The amount of supplied power being overwhelmingly superior to the upper limit, the burning was inevitable.
To ensure such a accident doesn't happen, it is essential to supply the controller through its power converter, which can support a 12V voltage and convert it to the 5V used for the arduino.

## Next session goal

Install a bluetooth system on the robot to be able to control it remotely.
