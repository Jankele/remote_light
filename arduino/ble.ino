void softReset()
{
asm volatile ("  jmp 0");
}

void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial);
}

void handleBle()
{
  char serialHolder;
  if(Serial.available())
  {
    serialHolder = (byte)Serial.read();

  }
  delay(1);
  if(serialBuffer != serialHolder){
  switch(serialHolder)
  {
    case 'a': //pr
    {
      if(digitalRead(LED1) == LOW)
        digitalWrite(LED1, HIGH);
      isBleUsed = true;
    }
    break;

    case 'b': //pr
    {
      if(digitalRead(LED1) == HIGH)
        digitalWrite(LED1, LOW);
      isBleUsed = true;
    } 
    break;
    
    case 'c': //pir
    {
      if(digitalRead(LED2) == LOW)
        digitalWrite(LED2, HIGH);
      isBleUsed = true;
    } 
    break;
    
    case 'd': //pir
    {
      if(digitalRead(LED2) == HIGH)
        digitalWrite(LED2, LOW);
      isBleUsed = true;
    } 
    break;
    
    case 'e': //ble
    {
      if(digitalRead(LED3) == LOW)
        digitalWrite(LED3, HIGH);
    } 
    break;
      
    case 'f': //ble
    {
      if(digitalRead(LED3) == HIGH)
        digitalWrite(LED3, LOW);
    } 
    break;

    case 'g':
    {
      EEPROM.write(ADDRESS, 1);
      softReset();
    }    
    break;
    case 'h':
    {
      EEPROM.write(ADDRESS, 2);
      softReset();
    }  
    break;
    case 'i':
    {
      EEPROM.write(ADDRESS, 3);
      softReset();
    }  
    break;
    case 'j':
    {
      EEPROM.write(ADDRESS, 4);
      softReset();
    }  
    break;
    case 'k':
    {
      EEPROM.write(ADDRESS, 5);
      softReset();
    }  
    break;
    case 'l':
    {
      EEPROM.write(ADDRESS, 6);
      softReset();
    }  
    break;
    case 'm':
    {
      EEPROM.write(ADDRESS, 7);
      softReset();
    }  
    break;
  }
}
    serialBuffer = serialHolder;
}

void handleConfig()
{
  char serialHolder;
  if(Serial.available())
  {
    serialHolder = (byte)Serial.read();

  }
  if(serialBuffer != serialHolder){
  switch(serialHolder)
  {
    case 'g':
    {
      EEPROM.write(ADDRESS, 1);
      softReset();
    }    
    break;
    case 'h':
    {
      EEPROM.write(ADDRESS, 2);
      softReset();
    }  
    break;
    case 'i':
    {
      EEPROM.write(ADDRESS, 3);
      softReset();
    }  
    break;
    case 'j':
    {
      EEPROM.write(ADDRESS, 4);
      softReset();
    }  
    break;
    case 'k':
    {
      EEPROM.write(ADDRESS, 5);
      softReset();
    }  
    break;
    case 'l':
    {
      EEPROM.write(ADDRESS, 6);
      softReset();
    }  
    break;
    case 'm':
    {
      EEPROM.write(ADDRESS, 7);
      softReset();
    }  
    break;
  }
}
    serialBuffer = serialHolder;
}
