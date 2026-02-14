The file WordLists.h contains 9 categories of German words:

Pronomen (pronouns)
Orte (places)
Haus (house)
Verben (verbs)
Adjektive (adjectives)
Namen (names)
Zeit (time)
Gegenstände (items)
Todesursachen (causes of death)

Each category contains a list of words which are separated by a slash (/).

The slash is used to separate the words when read from flash memory (PROGMEM).

The Python script reads this file and creates a speech file (mp3) per Word.

The files are named CCNNxxxx.mp3 with CC = Number of category, NN = entry index in the array, xxxxx = The word as found in the list.
