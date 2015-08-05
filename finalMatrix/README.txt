Final LED Matrix
(24x8 matrix)

Purpose:
To build a 24x8 LED matrix that can display strings received serially.

Materials:
192 LEDs
24 330 ohm resistors
Large perfboard
4 74HC595 shift registers
4 16-pin IC sockets
1 Arduino Uno w/ its serial cable
1 AC adapter (to power Arduino externally)
Lots of wires

Required Tools:
Soldering iron
Solder
Small pliers
Small wire stripper

Procedures:
* Note: These procedures are not comprehensive and are not meant to be followed by a beginner. The following steps are meant for the reader to understand the general idea of building an LED matrix.
1) Place and tape LEDs onto the perfboard to allow easy soldering.
2) Solder the LEDs. Then, remove the tape.
3) Connect the positive leads of LEDs that are on the same row together. To do this, place a horizontal, straight wire on each row, and solder the wire to the already-soldered positive leads.
4) Strip the positive leads of the LEDs as short as possible.
5) Strip the negative leads of the LEDs to a height of around half an inch.
6) Connect the negative leads of LEDs that are on the same column together. To do this, balance the matrix vertically so that the columns are now horizontal (I did this using a monkey spanner). Then, place a straight wire on each column and solder it to the end of each of the negative leads.
7) Solder a resistor to each of the wires that connect a column of LEDs.
8) Solder the four IC sockets so that each socket is not too close to either the LEDs or other sockets.
9) Wire the rows to the first socket based on the schematic of the 74HC595 shift register. Then wire columns 1-8 to the second socket, columns 7-16 to the third socket, and columns 17-24 to the fourth.
10) Daisy-chain the shift registers together (google this if daisy-chaining is an unfamiliar term).
11) Connect the Vcc and ground pins together.
12) Solder a 5-pin header to the board that will allow wires to connect to Vcc, ground, and the three data lines (data, clock, and latch).
13) Connect the pins to the corresponding pins on an Arduino Uno.
14) Load the code provided in the current directory to the Arduino.
15) Send data serially (Bluetooth or serial cable) and watch the strings appear visually!

Notes on using the resources (res) folder:
- schematic.jpg can be used for wiring assistance for the LEDs, but note that this schematic is for a 4x4 matrix (so it is useless in helping you wire the matrix with shift registers)
- the jpegs visually show how I built my matrix
- video.3gp helps provide more detail in how my matrix was designed
- datasheet for the 74HC595 is provided
