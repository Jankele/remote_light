void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
}
