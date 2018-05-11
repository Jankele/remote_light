void loopPIR()
{
  static int licznik;
  if(licznik = 0)
  {
      if(digitalRead(PIR) == HIGH)
        ledOn(LED1);
  }
}
