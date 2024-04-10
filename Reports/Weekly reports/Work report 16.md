# Work report 16 - 10/04/2024

## Performed tasks

- Complete the servomotor support madeling and print it.
- Mount all component on the new base.
- Search for solutions to mount the camera on the servomotor.

### Support modeling

Reviewing the precedent work revealed a certain flaw. The last model didn't take into consideration the servomotor's wires. I solved the problem by adding a vertical slot through which wires can pass. Moreover, I added arms to the support in order to fix the servomotor using screw-nut system.

![Servomotor support-Final version]()

### Mounting

Taking into consideration each component's size, I placed and mounted each one of them in a way that optimized space management.
The said components are :
- Arduino microcontroller.
- Jetson nano.
- H-bridge stepper (driver).
- Bread board.
- Servomotor + Its support.
- Back motors + Wheels.
- Front multidirectional wheel.

![Robot space management-Top view]()

![Robot space management-Bottom view]()

### Camera mounting

After giving it some thoughts, I decided to use a gear system as a first solution to mount the camera on the servomotor. The servomotor is responsable for the camera orientation. Having a gear system to control the said orientation would increase its accuracy.

## Future tasks

- Camera support and gear system modeling.
- Servomotor Code writing.
