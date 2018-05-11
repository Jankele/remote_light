#include <EEPROM.h>
#include "headers.h"

unsigned long previousTime;
unsigned long currentTime;

enum configurations
{
  EPR = 1, EPIR, EBLE, EPIR_PR, EPR_BLE, EPIR_BLE, EPIR_PR_BLE
};

void initiateConsole();

void setup()
{
  uint_8t configuration = (uint_8t)EEPROM.read(ADDRESS);
  if(configuration == pir || configuration == pir_pr || configuration == pir_ble || configuration == pir_pr_ble)
  {
    pinMode(PIR, INPUT);
    delay(1000); // kalibracja czujki pir
  }
  if(configuration == pr || configuration == pir_pr || configuration == pr_ble || configuration == pir_pr_ble)
  {
    pinMode(PR, INPUT);
  }
  initiateLED();
  initiateConsole();
  previousTime = millis();
}

void loop()
{
  currentTime = millis();
  switch (configuration)
  {
    case EPR:
      loopPR();
    break;
      
    case EPIR: 
      loopPIR();
    break;
      
    case EBLE:
      loopBLE();
    break;
      
    case EPIR_PR
    {
      loopPR();
      loopPIR();
    }
      
    case EPR_BLE:
      loopPR();
      loopBLE();
    break;
    case EPIR_BLE:
    loopPR();
    loopBLE();
    loopPR();
    loopPIR();
    loopBLE();
  }
  previousTime = millis();
}

void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
}
