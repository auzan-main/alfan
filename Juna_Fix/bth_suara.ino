//__ SOUND VARIABLE __//
unsigned short adcSuara = 0, filteredSuara = 0, samplingSuara = 0, prevADC = 0, currentADC = 0;

//__ time __//
unsigned long prevmillis = millis();
unsigned long currentmillis,nowMillis,lastTime =  0;
unsigned long jadi = 0;

void waitHand(unsigned int variable)
{
  transmitPulsaXL();
  transmitPulsaAX();
  delayMicroseconds(150);
  //  transmitPulsaAX();
  //  delayMicroseconds(150);
  prevmillis = millis();
  currentmillis = millis();
  jadi = currentmillis - prevmillis;
  while (currentmillis - prevmillis < variable)
  {
    currentmillis = millis();
    jadi = currentmillis - prevmillis;
//    
    //        Serial.print("Jadi: "); Serial.println(jadi);
  }
}

void waitLeg(unsigned int variable)
{
  transmitPulsa();
  delayMicroseconds(150);
  //  transmitPulsaAX();
  //  delayMicroseconds(150);
  prevmillis = millis();
  currentmillis = millis();
  jadi = currentmillis - prevmillis;
  while (currentmillis - prevmillis < variable)
  {
    currentmillis = millis();
    jadi = currentmillis - prevmillis;
//    
    //        Serial.print("Jadi: "); Serial.println(jadi);
  }
}

void waitAll2(unsigned int variable)
{
  transmitPulsa();
  transmitPulsaXL();
  delayMicroseconds(150);
  transmitPulsaAX();
  delayMicroseconds(150);
  prevmillis = micros();
  currentmillis = micros();
  jadi = currentmillis - prevmillis;
  while (currentmillis - prevmillis < variable * 1000)
  {
    currentmillis = micros();
    jadi = currentmillis - prevmillis;
    
  }
}

void waitAll(unsigned int variable)
{
  transmitPulsaMX();
//  delayMicroseconds(150);
  transmitPulsaXL();
//  delayMicroseconds(150);
  transmitPulsaAX();
  delayMicroseconds(150);
  prevmillis = micros();
  currentmillis = micros();
  jadi = currentmillis - prevmillis;
  while (currentmillis - prevmillis < variable * 1000)
  {
    currentmillis = micros();
    jadi = currentmillis - prevmillis;
//    
  }
}

void waitAllTest2(unsigned int variable)
{ 
  //ini niatnya akses data teros terosan sambil nunggu milis
  transmitPulsaMX();
//  delayMicroseconds(150);
  transmitPulsaXL();
//  delayMicroseconds(150);
  transmitPulsaAX();
  delayMicroseconds(150);
  prevmillis = micros();
  currentmillis = micros();
  jadi = currentmillis - prevmillis;
  while (currentmillis - prevmillis < variable * 1000)
  {
    currentmillis = micros();
    jadi = currentmillis - prevmillis;
//    
  }
}

void waitAllTest3(unsigned int variable)
{ 
  //ini niatnya ambil data sekali tiap waitAll
  transmitPulsaMX();
//  delayMicroseconds(150);
  transmitPulsaXL();
//  delayMicroseconds(150);
  transmitPulsaAX();
  delayMicroseconds(150);
  prevmillis = micros();
  currentmillis = micros();
  jadi = currentmillis - prevmillis;
  int once = 1;
  while (currentmillis - prevmillis < variable * 1000)
  {
    if (once == 1) {
      //ambil data
    }
    currentmillis = micros();
    jadi = currentmillis - prevmillis;
    once = 0;
//    
  }
}

void waitAllBNO(unsigned int variable)
{
  transmitPulsaMX();
  delayMicroseconds(150);
  transmitPulsaXL();
  delayMicroseconds(150);
  transmitPulsaAX();
  delayMicroseconds(150);
  prevmillis = micros();
  currentmillis = micros();
  jadi = currentmillis - prevmillis;
  while (currentmillis - prevmillis < variable * 1000)
  {
    nowMillis = millis();
    currentmillis = micros();
    jadi = currentmillis - prevmillis;
    //    
    if ((nowMillis - lastTime) >= variable / 4) {
      Serial.println((nowMillis - lastTime));
      bacaBNO();
      lastTime = millis();
    }
  }

}

void transmitPulsa() {
  //  transmitPulsaXL();
  //  delayMicroseconds(150);
  //  transmitPulsaAX();
  //  delayMicroseconds(150);

  transmitPulsaMX();
  delayMicroseconds(150);
}


void receiveData()
{
//  int payload;
  if (Serial5.available())
  {
    dataIn=Serial5.read();
//    payload = Serial5.read();
//    //Serial.println(dataIn);
//    adamusik=payload/128;
//    dataIn=payload-(128*adamusik);
  }
}
