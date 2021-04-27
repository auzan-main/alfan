File myFileRekam;
char namaFileBaca[20];
String dataBaca = "";
int value, prepos, sudu; 
int hayo = 1000; //mohon maap namanya
uint8_t pos[2];
uint16_t sudut;

void rekamTangan(){
  bool a = digitalRead(35);
  if (a == LOW) {
    Serial.println("Receiving...");
    hayo++;
    delay(500);
    tulisTangan();
  }
}

void tulisTangan() {
  char namaFileBaca[20];
  dataBaca = "";
  sprintf(namaFileBaca, "GRK%d.txt", hayo);
  myFileRekam = SD.open(namaFileBaca, FILE_WRITE);
  //jika file ada
  if (myFileRekam) {
    Serial.println("File Exist");
    //    delay(2000);
    //    Serial.println(Serial4.available());
    Serial.print("gerakan: "); Serial.print(hayo); Serial.println('\t');
    
    //Tangan Kanan
    bacaSudut(21);
    bacaSudut(22);
    bacaSudut(23);
    bacaSudut(24);
    bacaSudut(25);
    bacaSudut(26);
    //Tangan Kiri
    bacaSudut(31);
    bacaSudut(32);
    bacaSudut(33);
    bacaSudut(34);
    bacaSudut(35);
    bacaSudut(36);
    //Kepala
//    bacaSudut(41);
//    bacaSudut(42);
//    bacaSudut(43);
    
    myFileRekam.close();
  }
  else {
    Serial.print("error opening gerakan"); Serial.print(hayo); Serial.println(".txt");

  }
}

void bacaSudut (byte ID)
{

  uint16_t Default[50];
  float bufferdef[50];
  float degToByte = 300.0 / 1023.0;
  uint16_t CRC;
  unsigned char CRC_L = 0;
  unsigned char CRC_H = 0;
  bool state = 0;
  byte errorStatus = 0;
//  uint8_t sudutXL1;
//  uint8_t sudutXL2;

  bufferdef[21] = KANAN21 / degToByte;
  bufferdef[22] = KANAN22 / degToByte; //150
  bufferdef[23] = KANAN23 / degToByte;
  bufferdef[24] = KANAN24 / degToByte;
  bufferdef[25] = KANAN25 / degToByte; //-keluar
  bufferdef[26] = KANAN26 / degToByte; //- nutup

  bufferdef[31] = KIRI31 / degToByte;
  bufferdef[32] = KIRI32 / degToByte; //85
  bufferdef[33] = KIRI33 / degToByte;
  bufferdef[34] = KIRI34 / degToByte;
  bufferdef[35] = KIRI35 / degToByte;
  bufferdef[36] = KIRI36 / degToByte; // +keluar
  //  bufferdef[41] = KEPALA41/degToByte;

  Default[21] = bufferdef[21];
  Default[22] = bufferdef[22]; //150
  Default[23] = bufferdef[23];
  Default[24] = bufferdef[24];
  Default[25] = bufferdef[25]; //-keluar
  Default[26] = bufferdef[26]; //- nutup

  Default[31] = bufferdef[31];
  Default[32] = bufferdef[32];  //85
  Default[33] = bufferdef[33];
  Default[34] = bufferdef[34];
  Default[35] = bufferdef[35];
  Default[36] = bufferdef[36]; // +keluar
  //  Default[41] = bufferdef[41];


  digitalWrite(TxDir, HIGH);
  digitalWrite(RxDir, HIGH);
  unsigned char TxPacket1[14] = { 0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x07, 0x00, 0x02, 0x25, 0x00, 0x02, 0x00, CRC_L, CRC_H };
  TxPacket1[4] = ID;
  CRC = update_crc(0, TxPacket1, 12);
  CRC_L = (CRC & 0x00FF);
  CRC_H = (CRC >> 8) & 0x00FF;

  TxPacket1[12] = CRC_L;
  TxPacket1[13] = CRC_H;
  //    TxPacket1[12]=0x50;
  //    TxPacket1[13]=0x55;
  Serial2.write(TxPacket1, 14);
  Serial2.flush();
  //    delay(100);
  digitalWrite(TxDir, LOW);
  digitalWrite(RxDir, LOW);
  delay(1);
  int count = 1;
  while (Serial2.available() != 0) {


    // read the incoming byte:
    byte a = Serial2.read();

    if (a == 0xFF) {
      state = 1;
    }

    if (state == 1) {
      if (count == 5)
      {
        ID = a;
      }
      if (count == 9)
      {
        errorStatus = a;
      }
      if (count == 10)
      {
        pos[0] = a;
      }
      if (count == 11)
      {
        pos[1] = a;
      }
    }
    count++;
  }

  digitalWrite(TxDir, HIGH);
  digitalWrite(RxDir, HIGH);


  Serial.print("ID: "); Serial.print(ID); Serial.print('\t');
  sudut = pos [1] << 8 | pos [0];
  sudu = sudut - Default[ID];
  Serial.print("sudut: "); Serial.print(sudu, HEX); Serial.print('\t');

if(errorStatus != 0){
  Serial.print("Error Baca sudut");
}

  //menulis data
  dataBaca += 'A';
  dataBaca += ID;
  dataBaca += ';';
  dataBaca += sudu;
  dataBaca += 'B';
  myFileRekam.println(dataBaca);
  //menutup file

  Serial.println(dataBaca);
  dataBaca = "";
}
