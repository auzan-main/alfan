void walkTestingPID(){
  langkahKaCobaPID(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
  langkahKiCobaPID(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
}

void walkTestingPID_FASTER(){
  langkahKaCobaPID_FASTER(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiCobaPID_FASTER(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkNganjatHue1(){
  langkahKaNganjatHue1(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
  langkahKiNganjatHue1(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
}

void walkNganjatHue2(){
  langkahKaNganjatHue2(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
  langkahKiNganjatHue2(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
}

void walkNganjatHue3(){
  langkahKaNganjatHue3(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
  langkahKiNganjatHue3(-3, 3, 16.7, 3, 2);
  CountJalan++;
  waitAll(200);
}

void walkNgasaiHue1(){
  langkahKaNgasaiHue1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiNgasaiHue1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkNgasaiHue2(){
  langkahKaNgasaiHue2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiNgasaiHue2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkNgasaiHue3(){
  langkahKaNgasaiHue3(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiNgasaiHue3(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}


void walkPurakBarikHaha1(){
  langkahKaPurakBarikHaha1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiPurakBarikHaha1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkPurakBarikHaha2(){
  langkahKaPurakBarikHaha2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiPurakBarikHaha2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkPurakBarikHaha3(){
  langkahKaPurakBarikHaha3(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiPurakBarikHaha3(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkPurakBarikHaha11(){
  langkahKaPurakBarikHaha11(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiPurakBarikHaha11(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkPurakBarikHaha22(){
  langkahKaPurakBarikHaha22(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiPurakBarikHaha22(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void walkPurakBarikHaha33(){
  langkahKaPurakBarikHaha33(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiPurakBarikHaha33(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void mendak() {
  //mendak
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  PalaBawah(10);
  TanganDepan(10);
  transmitPulsaXL();
  waitAll(1000);
  //
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  TanganDepan(10);
  PalaDefault(10);
  transmitPulsaXL();
  waitAll(1000);
  //
}
void mendak1() {
  // //mendak
  //  tjKa=8;
  //  tjKi=8;
  //  invers(KANAN, 8, -3 - 3.06, 14, 0, -0.2);
  //  invers(KIRI, 8, 3 - 3.06, 14, 0, -0.2);
  tjKa = 9;
  tjKi = 9;
  invers(KANAN, 8, -3 - 3.06, 14, 0, -4);
  invers(KIRI, 8, 3 - 3.06, 14, 0, -4);
  transmitPulsa();
  PalaBawah(10);
  TanganDepan(10);
  transmitPulsaXL();
  waitAll(1000);
  //
  //  tjKa=8.5;
  //  tjKi=8.5;
  //  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  //  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  tjKa = 5;
  tjKi = 5;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -3.5);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -3.5);
  transmitPulsa();
  TanganDepan(10);
  PalaDefault(10);
  transmitPulsaXL();
  waitAll(1000);
  //
}
void mendakGanti() {
  //mendak
  tKa = 5;   //hips  servo 2
  tKi = -5;  //hips servo 12
  tjKa = 4;
  tjKi = 4;
  invers(KIRI, 8, -3 - 3.06, 14, 0, 0.3);
  invers(KANAN, 8, 3 - 3.06, 14, 0, 0.3);
  transmitPulsa();
  PalaBawah(10);
  TanganDepan(10);
  transmitPulsaXL();
  waitAll(1000);
  //
  tjKa = 4;
  tjKi = 4;
  invers(KIRI, 8, -3 - 3.06, 16.6, 0, -0.5);
  invers(KANAN, 8, 3 - 3.06, 16.6, 0, -0.5);
  transmitPulsa();
  TanganDepan(10);
  PalaDefault(10);
  transmitPulsaXL();
  waitAll(1000);
  //
}

void mendakSembah(){
  invers(KIRI, 13, 0, 8, 0, 0);
  invers(KANAN, 13, 0, 8, 0, 0);
  transmitPulsa();
}

void torqueOoOoff(byte id){

  unsigned char TxPacketHayo[8] = { 0xFF, 0xFF, id, 0x04, 0x03, 0x18, 0x00, 0xE8};
  byte cksm = 0;
  for (int i = 2; i < 7; i++)
  {
    cksm += TxPacketHayo[i];
  }
  TxPacketHayo[7] = ~cksm;
  Serial3.write(TxPacketHayo, 8);
  Serial3.flush();
  
//  Serial.print("========= New Request id: "); Serial.print(id); Serial.println(" ============"); 

}

void torqueOoOoN(byte id){

  unsigned char TxPacketHayo[8] = { 0xFF, 0xFF, id, 0x04, 0x03, 0x18, 0x01, 0xE8};
  byte cksm = 0;
  for (int i = 2; i < 7; i++)
  {
    cksm += TxPacketHayo[i];
  }
  TxPacketHayo[7] = ~cksm;
  Serial3.write(TxPacketHayo, 8);
  Serial3.flush();
  
//  Serial.print("========= New Request id: "); Serial.print(id); Serial.println(" ============"); 

}
