#include <SPI.h>
#include <SD.h>

#define PIN_SD_CS 4
File csvFile;
bool sdSetup() {
  return SD.begin(PIN_SD_CS);
}
uint8_t sdWriteDatas(char* date, char* values) {
  char filename = "";
  strcat(filename, date);
  strcat(filename, ".csv");
  csvFile = SD.open(filename, FILE_WRITE);
  if (!csvFile) return -1;
  csvFile.print(values);
  return strlen(values);
}