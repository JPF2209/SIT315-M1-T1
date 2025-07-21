# Recreate Task In TinkerCad

## Components Needed
- 1 Arduino Uno R3
- 2 Pushbuttons
- 1 Green LED
- 1 Red LED
- 1 Blue LED
- 5 1 kO resistor
  
## Steps To Recreate Layout
**Or use the picture here**

<img width="1366" height="673" alt="Screenshot (182)" src="https://github.com/user-attachments/assets/a7e7cd13-7420-4fd5-952a-9697cc836e93" />

1. Get Arduino Uno and set one breadboard on top and one on the right
2. On the bottom of the Uno, get the 5V pin, connect a wire and connect it to the bottom positive pin holes of the right breadboard
3. On the bottom of the Uno, get the GND pin, connect a wire to the top negative pin hole area of the right breadboard
4. In the gap between the two main pinhole areas of the right breadboard, add two buttons
5. On the bottom right on the buttons, connect a wire from here to the same line of pinholes to the bottom positive pinholes area
6. On the top left, on the line of pins to connect, connect the resistor to the negative top pinholes where the GND is connected to
7. On the same line of sight for each button, for the left most one, connect a pin and connect t to digital pin 2. Repeat the same thing for the right button to pin 3.
8. For the top breadboard, connect the top GND pin on the Uno to the bottom negative pinholes of the breadboard
9. Then line up and add the green, red and blue leds.
10. On the left of each LED, for the pinholes there, connect a resistor from one of the holes to the bottom negative pinholes for all 3 LEDs
11. Then connect the digital pin 8 to the right side of the pinholes for the red LED.
12. Do the same things for pin 9 to the green LED and pin 10 for the blue LED

## Add Code To Tinkercad
- Get the ino code in the library, copy it and past it to the code section of the tinkercade code area. Make sure for the code that the edit mode of it is just text.
- Then to run it, press start simulation and just press the buttons as needed.
