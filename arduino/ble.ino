void (softReset)
{
asm volatile ("  jmp 0");
}

void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
}

void handleBLE()
{
  if(Serial.available())
    serialHolder = (byte)Serial.read();

  switch(serialHolder)
  {
    case 'a':
    {
      if(digitalRead(LED1) == LOW)
        digitalWrite(LED1, HIGH);
    }
    break;

    case 'b':
    {
      if(digitalRead(LED1) == HIGH)
        digitalWrite(LED1, LOW);
    } 
    break;
    
    case 'c':
    {
      if(digitalRead(LED2) == LOW)
        digitalWrite(LED2, HIGH);
    } 
    break;
    
    case 'd':
    {
      if(digitalRead(LED2) == HIGH)
        digitalWrite(LED2, LOW);
    } 
    break;
    
    case 'e':
    {
      if(digitalRead(LED3) == LOW)
        digitalWrite(LED3, HIGH);
    } 
    break;
      
    case 'f':
    {
      if(digitalRead(LED3) == HIGH)
        digitalWrite(LED3, LOW);
    } 
    break;
    
    case 'g':
      softReset();
    break;
    
    case 'h':
      EEPROM.write(ADDRESS, 1);
    break;
    
    case 'i':
      EEPROM.write(ADDRESS, 2);
    break;
    
    case 'j':
      EEPROM.write(ADDRESS, 3);
    break;
    
    case 'k':
      EEPROM.write(ADDRESS, 4);
    break;
    
    case 'l':
      EEPROM.write(ADDRESS, 5);
    break;
    
    case 'm':
      EEPROM.write(ADDRESS, 6);
    break;
    
    case 'n':
      EEPROM.write(ADDRESS, 7);
    break;
    }
}

void handleConfig()
{
  if(Serial.available())
     serialHolder = (byte)Serial.read();

  switch(serialHolder)
  {
    case 'g':
      softReset();
    break;
    case 'h':
      EEPROM.write(ADDRESS, 1);
    break;
    case 'i':
      EEPROM.write(ADDRESS, 2);
    break;
    case 'j':
      EEPROM.write(ADDRESS, 3);
    break;
    case 'k':
      EEPROM.write(ADDRESS, 4);
    break;
    case 'l':
      EEPROM.write(ADDRESS, 5);
    break;
    case 'm':
      EEPROM.write(ADDRESS, 6);
    break;
    case 'n':
      EEPROM.write(ADDRESS, 7);
    break;
  }
}