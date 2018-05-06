loopPIR()
{
  static int licznik;
  if(licznik = 0)
  {
      if(digitalRead(PIR) == HIGH)
    {
      ledOn(LED1);
      //x czasu
      ledOff(LED1);
    }
  }
}
