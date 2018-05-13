#include <EEPROM.h>
#include "headers.h"

unsigned long previousTime;
unsigned long currentTime;
uint8_t configuration;
bool ledState;
char serialHolder;

void initiateConsole();
void initiatePr();
void initiatePir();
void setTimer();
void getTimer();

void setup()
{
  configuration = (uint8_t)EEPROM.read(ADDRESS);

  initiatePr();
  initiatePir();
  initiateLed();
  initiateConsole();
}

void loop()
{
  loopSwitch();
}
