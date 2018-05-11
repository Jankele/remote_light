#include <EEPROM.h>
#include "headers.h"

unsigned long previousTime;
unsigned long currentTime;

uint8_t configuration = (uint8_t)EEPROM.read(ADDRESS);

void initiateConsole();

void setup()
{
  pinMode(PIR, INPUT);
  delay(1000); // kalibracja czujki pir

  pinMode(PR, INPUT);

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
    break;

    case EPR_BLE:
    {
      loopPR();
      loopBLE();
    }
    break;

    case EPIR_BLE:
    {
      loopPR();
      loopBLE();
    }
    break;

    case EPIR_PR_BLE:
    {
      loopPR();
      loopPIR();
      loopBLE();
    }
    break;

    default:
    {
      loopPR();
      loopPIR();
      loopBLE();
    }
  }
  previousTime = millis();
}

void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
}

void (*functions[7](void))