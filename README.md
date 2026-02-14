# PARA-METER
Pseudo "Paranormal Activity Meter" - A system to retrieve and replay words based on random values

Directory Python:
Contains a script that converts the word lists in WordLists.h to speech and saves a separate mp3 per entry

Directory mp3:
Contains sound files for the words as in WordLists.h

Directory src:
Contains the .ino and header files that are required to compile and upload PARA-METER to an ARDUINO UNO or NANO
or the like.

The project has been developed and tested with

* 1 x Arduino Nano
* 1 x LCD (16 x 2) with I2C interface
* 1 x DFRobot Player Mini
* 1 x 32 GB SD Card
* 1 x 8 Ohm Loudspeaker (saved from an old PC)

Create a directory "MP3" on the SD Card, unzip and copy the mp3 files.

Add a 1kOhm resistor between the Arduino TX and the Player's RX pin to avoid possible 
electromagnetic interference (noise) from the Arduino transmission.

Arduino TX --- 1k ---- Player RX
Arduino RX ----------- Player TX

The project uses 

Arduino RX Pin 10 and
Arduino TX Pin 11 both for SoftwareSerial communication with the DFRobot Player
Arduino A4 (open) to feed randomSeed()
Arduino A1 (open or with a short antenna) to create random input for the category/word choice

To display German Umlaute äöü etc. the project uses a specific LCD library developed by noiasca.
It can be downloaded from https://werner.rothschopf.net/202009_arduino_liquid_crystal_intro.htm

Many thanks to my Arduino Forum Member noiasca for providing this library for free!
