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


void ledOn(uint8_t Led);
void initiateLed();
void ledOff(uint8_t Led);
void handlePir();
bool isBright();
void handlePr();
void initiateConsole();
void initiatePr();
void initiatePir();
void softReset();
void handleBLE();
void handleConfig();
void loopEpir();
void loopEble();
void loopEpr_pir();
void loopEpr_ble();
void loopEpir_ble();
void loopEpr_pir_ble();
void loopSwitch();



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
