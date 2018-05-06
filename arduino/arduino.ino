#include <EEPROM.h>
#include "headers.h"

enum configurations
{
  pr = 1, pir, ble, pir_pr, pr_ble, pir_ble, pir_pr_ble
};

void setup()
{
  configurations configuration = (int)(EEPROM.read(ADDRESS);
  if(configuration == pir || configuration == pir_pr || configuration == pir_ble || configuration == pir_pr_ble)
    pinMode(PIR, INPUT);
  if(configuration == pr || configuration == pir_pr || configuration == pr_ble || configuration == pir_pr_ble)
    pinMode(PR, INPUT);
  initiateLED();
  initiateConsole();
  delay(2000);
}

void loop()
{
  loopPIR();
  loopPR();
  loopBLE();
}

