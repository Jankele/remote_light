//TODO -review code
#include <EEPROM.h>
#include "headers.h"

unsigned long previousTime;
unsigned long currentTime;
unsigned long previousTimePir;
unsigned long currentTimePir;
uint8_t configuration;
char serialHolder;
bool isBleUsed;

const unsigned long maxInterval = 1000;

void initiateConsole();
void initiatePr();
void initiatePir();

void setup()
{
  configuration = (uint8_t)EEPROM.read(ADDRESS);
  isBleUsed = false;
  initiatePr();
  initiatePir();
  initiateLed();
  initiateConsole();
  previousTime = millis();
  spreviousTimePir = millis();
}

void loop()
{
  loopSwitch();
}
