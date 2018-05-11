#include <EEPROM.h>
#include "headers.h"

typedef enum configurations
{
  pr = 1, pir, ble, pir_pr, pr_ble, pir_ble, pir_pr_ble
};

configurations configuration = (int)EEPROM.read(ADDRESS);

void setup()
{
  if(configuration == pir || configuration == pir_pr || configuration == pir_ble || configuration == pir_pr_ble)
    pinMode(PIR, INPUT);
  if(configuration == pr || configuration == pir_pr || configuration == pr_ble || configuration == pir_pr_ble)
    pinMode(PR, INPUT);
  initiateLED();
  initiateConsole();
}

void loop()
{
  if(configuration == pr)
    loopPR();
  if(configuration == pir)
    loopPIR();
  if(configuration == ble)
    loopBLE();
  if(configuration == pir_pr)
  {
    loopPR();
    loopPIR();
  }
  if(configuration == pr_ble)
  {
    loopPR();
    loopBLE();
  }
  if(configuration == pir_ble)
  {
    loopPR();
    loopBLE();
  }
  if(configuration == pir_pr_ble)
  {
    loopPR();
    loopPIR();
    loopBLE();
  }
}
