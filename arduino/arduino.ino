#include <EEPROM.h>
#include "config.h"

unsigned long previousTime;
unsigned long currentTime;
unsigned long previousTimePir;
unsigned long currentTimePir;
unsigned long previousTimePr;
unsigned long currentTimePr;
int configuration;
char serialBuffer;
bool isBleUsed;
bool isLedTurnedOn;
bool isPirUsed;
const unsigned long maxInterval = 2000;

void setup()
{
  //configuration = EEPROM.read(ADDRESS);
  configuration = 7;
  isBleUsed = false;
  isPirUsed = false;
  initiatePr();
  initiatePir();
  initiateLed();
  initiateConsole();
  previousTime = millis();
  previousTimePir = millis();
  serialBuffer = 'z';
}

void loop()
{
  loopSwitch();
}
