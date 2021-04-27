uint8_t stallStatus21, stallStatus22, stallStatus31, stallStatus32;

void backToLife() {
  Serial.println("Back to Life");
  stallStatus21 = cekStall(0x15);
  stallStatus31 = cekStall(0x1F);
  stallStatus22 = cekStall(0x16);
  stallStatus32 = cekStall(0x20);
  if (stallStatus21 == 1 || stallStatus31 == 1 || stallStatus22 == 1 || stallStatus32 == 1) {
    int cek = micros();
//    Serial.print("Stall Status   :"); Serial.println(stallStatus21, HEX);
//    Serial.print("Stall Status   :"); Serial.println(stallStatus31, HEX);
    if (stallStatus21 == 1) {
      reboot(0x15);
    }
    if (stallStatus31 == 1) {
      reboot(0x1F);
    }
    if (stallStatus22 == 1) {
      reboot(0x16);
    }
    if (stallStatus32 == 1) {
      reboot(0x20);
    }
    
    waitLeg(600); //bisa rupanya, kalo 4 600
//    TanganDepan(10); //ini buat ngetes doang
//    waitAll(1000);
  int cek1 = micros();
  Serial.print("reboot semua : "); Serial.println(cek1-cek);
  //reboot 2 servo makan 0.6 detik
  }
  Serial.println("IM ALIVE!!!");
//return;
}

void reboot(byte hayo) {
  Serial.println("Rebooting..............");
  uint16_t CRC;
  uint8_t CRC_L = 0;
  uint8_t CRC_H = 0;
  unsigned char TxPacketHayo[10] = { 0xFF, 0xFF, 0xFD, 0x00, 0x15, 0x03, 0x00, 0x08, CRC_L, CRC_H };
  TxPacketHayo[4] = hayo;
  CRC = update_crc(0, TxPacketHayo, 8);
  CRC_L = (CRC & 0x00FF);
  CRC_H = (CRC >> 8) & 0x00FF;
  TxPacketHayo[8] = CRC_L;
  TxPacketHayo[9] = CRC_H;

  digitalWriteFast(TxDir, HIGH);
  digitalWriteFast(RxDir, HIGH);
  Serial2.write(TxPacketHayo, 10);
  Serial2.flush();
  waitLeg(1);
//  return;
}


byte cekStall(byte hiya) {
  int a[14] = {}, i = 0;
  uint16_t CRC;
  uint8_t CRC_L = 0;
  uint8_t CRC_H = 0;
  unsigned char TxPacketCuk1[14] = { 0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x07, 0x00, 0x02, 0x32, 0x00, 0x01, 0x00, CRC_L, CRC_H };
  TxPacketCuk1[4] = hiya;
  CRC = update_crc(0, TxPacketCuk1, 12);
  CRC_L = CRC;
  CRC_H = CRC >> 8;

  TxPacketCuk1[12] = CRC_L;
  TxPacketCuk1[13] = CRC_H;
  digitalWrite(TxDir, HIGH);
  digitalWrite(RxDir, HIGH);
  Serial2.write(TxPacketCuk1, 14);
  
  Serial2.flush();
  
//  delay(5000);
  digitalWrite(TxDir, LOW);
  digitalWrite(RxDir, LOW);
  
  delay(1); //ini makan 10 milisecon, kalo pakek delay cuma makan 1 milisekon
  
  while (Serial2.available()) {
    a[i++] = Serial2.read();
  }
  Serial.print("Return Packet   :");
  for (i = 0; i < 12; i++) {
    Serial.print(a[i], HEX);
    Serial.print("  ");
  }
  
  Serial.print('\n');
  digitalWrite(TxDir, HIGH);
  digitalWrite(RxDir, HIGH);
  return a[9]&B1;
}
