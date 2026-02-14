
#include "WordLists.h"

class WordStorage {
private:
  int _katID = 0;
  int _totalWords = 0;
  int _wordIndex = 0; 
  int countWords(const char* flashStr);
  void getNthWord(const char* flashStr, int n, char* buffer);
  int calculateIndex(int sensorValue, int maxWords);
  char wordBuffer[40];  // Interner Speicher für das extrahierte Wort
public:
  int katID() {return _katID;};
  int totalWords() {return _totalWords;};
  int wordIndex() {return _wordIndex;};
  bool dataToWord(int data);
  const char* word(){return (char *)wordBuffer;};
};

int WordStorage::countWords(const char* flashStr) {
  int count = 0;
  char c;
  int i = 0;
  while ((c = pgm_read_byte(flashStr + i)) != '\0') {
    if (c == '/') count++;
    i++;
  }
  return count + 1;
}

void WordStorage::getNthWord(const char* flashStr, int n, char* buffer) {
  int currentWord = 0;
  int j = 0;
  char c;
  int i = 0;
  while (currentWord < n) {
    c = pgm_read_byte(flashStr + i);
    if (c == '/') currentWord++;
    if (c == '\0') break;
    i++;
  }
  while ((c = pgm_read_byte(flashStr + i)) != '/' && c != '\0') {
    buffer[j++] = c;
    i++;
  }
  buffer[j] = '\0';
}

// Deterministische Index-Berechnung (Sensor-Bits XOR Zeit-Bits)
int WordStorage::calculateIndex(int sensorValue, int maxWords) {
  unsigned long timestamp = millis();
  int index = (sensorValue ^ (int)(timestamp & 0xFF)) % maxWords;
  if (index < 0) index = -index;
  return index;
}

bool WordStorage::dataToWord(int data){
      const char* gewaehlteListe = nullptr;
      _katID = data % NumberOfCategories;
      switch (_katID) {
        case 0: gewaehlteListe = p_pronomen; break;
        case 1: gewaehlteListe = p_orte; break;
        case 2: gewaehlteListe = p_haus; break;
        case 3: gewaehlteListe = p_verben; break;
        case 4: gewaehlteListe = p_adj; break;
        case 5: gewaehlteListe = p_namen; break;
        case 6: gewaehlteListe = p_zeit; break;
        case 7: gewaehlteListe = p_gegenstaende; break;
        case 8: gewaehlteListe = p_todesursachen; break;
        default: gewaehlteListe = p_adj; break;  // Sicherheitsfall
      }
      // Sicherstellen, dass der Pointer gültig ist
      if (gewaehlteListe != nullptr) {
        _totalWords = countWords(gewaehlteListe);
        _wordIndex = calculateIndex(data, _totalWords);
        getNthWord(gewaehlteListe, _wordIndex, wordBuffer);
        return true;
      }
      return false;
}      
