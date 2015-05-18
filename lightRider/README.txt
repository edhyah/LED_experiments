Light Rider:

Simple circuit that shows the power of using the shift register.

Materials:
8 LEDs
8 Resistors (above 300 ohms)
1 74HC595 Shift Register
1 Arduino

Procedure:
Hook up each LED/resistor pair to an output pin on the shift register. Then connect SER, SRCLK, and RCLK (pins 14, 11, 12 on the shift register) to pins 8, 10, 9 on the Arduino. Finally, connect VCC, GND, SRCLR, and OE (pins 16, 8, 10, 13 on the shift register) to the 5V, GND, GND, 5V pins of the Arduino, respectively.It may be useful to find the datasheet of the 74HC595 shift register to assist with the wiring of this circuit. Now, load the code onto the Arduino and enjoy.
