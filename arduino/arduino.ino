//TODO -review code
#include <EEPROM.h>
#include "config.h"

unsigned long previousTime;
unsigned long currentTime;
unsigned long previousTimePir;
unsigned long currentTimePir;
unsigned long previousTimePr;
unsigned long currentTimePr;
uint8_t configuration;
char serialHolder;
bool isBleUsed;
bool isLedTurnedOn;
const unsigned long maxInterval = 1000;

void setup()
{
  configuration = (uint8_t)EEPROM.read(ADDRESS);
  isBleUsed = false;
  initiatePr();
  initiatePir();
  initiateLed();
  initiateConsole();
  previousTime = millis();
  previousTimePir = millis();
}

void loop()
{
  loopSwitch();
}
