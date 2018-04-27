#include "headers.h"

void setup() {
  pinMode(PIR, INPUT);
  pinMode(PR, INPUT);
  initiateLED();
  initiateConsole();
  delay(2000);
}

void loop()
{
  loopPIR();
  loopPR();
}
