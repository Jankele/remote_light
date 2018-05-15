#include <EEPROM.h>
#include "headers.h"

unsigned long previousTime;
unsigned long currentTime;
uint8_t configuration;
char serialHolder;
bool ledState;

const unsigned long maxInterval = 1000;

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
