loopPIR()
{
    if(digitalRead(PIR) == HIGH)
  {
    ledOn(LED1);
    ledOn(LED2);
    ledOn(LED3);
    delay(1000);
    ledOff(LED1);
    ledOff(LED2);
    ledOff(LED3);
  }
}
