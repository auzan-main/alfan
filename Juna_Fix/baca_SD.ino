File myFile;
String isi = "", isi2 = "", judul = "", urut = "", dataBaru = "";


void setupSD()
{
  delay(2000);
  Serial.print("Initializing SD card...");
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("initialization failed!");
    return;
  }

  Serial.println("initialization done.");
}

void aksesSD() {
  /* Petunjuk:
      untuk cek isi file = C"namafile" , contoh C512
      untuk edit isi file= E"nama file";urutan;textbaru . contoh E512;4;A36;-235B
  */

  int length, isi3, judulInt, cnt = 0, j = 0, index;
  boolean parsing = false, buka = false, tulis = false, timpa = false;
  char nfile[200];
  String dt[500], dtBaru;

  if (Serial.available() > 0) {
    char dataIN = (char) Serial.read();
    isi += dataIN;
    if (dataIN == '\n') {
      parsing = true;
    }
  }

  if (parsing) {
    if ((isi[0] == 'C') || (isi[0] == 'c')) {
      Serial.println("=========Cek isi file============");
      for (unsigned int i = 1; i < isi.length(); i++) {
        isi2 += isi[i];
      }
      buka = true;
    }

    if ((isi[0] == 'E') || (isi[0] == 'e')) {
      buka = false;

      for (int i = 1; i < isi.length(); i++) {
        if (isi[i] == ';') {
          break;
        }
        else {
          judul += isi[i];
        }
      }
      //      Serial.println(judul);
      cnt = 0;

      for (int i = 1; i < isi.length(); i++) {
        //        Serial.print(isi[i]);

        if ((isi[i] == ';') && (cnt != 2)) {
          cnt++;
          continue;

        }
        if ((cnt == 1) && (isi[i] != ';')) {
          urut += isi[i];
          //          Serial.print(urut);
        }
        if (cnt == 2) {
          dataBaru += isi[i];
        }
      }

      //      Serial.println(urut);
      //      Serial.println(dataBaru);

      tulis = true;
    }

    isi = "";
    parsing = false;

  }

  if (buka) {
    isi3 = isi2.toInt();
    length = sprintf(nfile, "GRK%d.txt", isi3);
    myFile = SD.open(nfile);
    if (myFile) {
      Serial.print("Isi File :"); Serial.println(nfile);
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      myFile.close();
    }
    else {
      Serial.println("buka file Error!!");
    }
    buka = false;
    isi2 = "";
  }

  if (tulis) {
    judulInt = judul.toInt();
    length = sprintf(nfile, "GRK%d.txt", judulInt);
    myFile = SD.open(nfile);
    if (myFile) {

      for (int i = 0; i < 12; i++) {
        dt[i] = "";
      }

      Serial.print("\nTulis file ke :"); Serial.println(nfile);
      while (myFile.available()) {
        char x = myFile.read();
        dt[j] = dt[j] + x;
        if (x == 'B') {
          dt[j] = dt[j].trim();
          j++;
        }

      }
      myFile.close();
    }

    else {
      Serial.println("buka file Error!!");
    }

    index = urut.toInt();

    dataBaru = dataBaru.trim();
    dt[index] = "";
    dt[index] = dataBaru;

    //       for(int i=0;i<12;i++){
    //          Serial.println(dt[i]);
    //        }

    timpa = true;

    tulis = false;
    judul = "";
    j = 0;

  }

  if (timpa) {
    SD.remove(nfile);

    //       if (SD.exists(nfile)) {
    //        Serial.println("masih ada");
    //       }
    //       else {
    //        Serial.println("Tak ade");
    //       }

    myFile = SD.open(nfile, FILE_WRITE);
    if (myFile) {
      Serial.println("Memperbaharui data\n");
      for (int i = 0; i < 12; i++) {
        myFile.println(dt[i]);
      }
      myFile.close();
    }
    else {
      Serial.println("membuat file gagal!!");
    }
    timpa = false;
  }

}

void baca(int gerakan , int waktuTari) {
  //status awal
  String data = "";
  int state;
  String stringId, stringSudut;
  int id, sudut;
  int count = -1;
  char namaFile[200];
  int length;
  int16_t Default[50];
  float bufferdef[50];

  bufferdef[21] = KANAN21 / 0.29;
  bufferdef[22] = KANAN22 / 0.29; //150
  bufferdef[23] = KANAN23 / 0.29;
  bufferdef[24] = KANAN24 / 0.29;
  bufferdef[25] = KANAN25 / 0.29; //-keluar
  bufferdef[26] = KANAN26 / 0.29; //- nutup

  bufferdef[31] = KIRI31 / 0.29;
  bufferdef[32] = KIRI32 / 0.29; //85
  bufferdef[33] = KIRI33 / 0.29;
  bufferdef[34] = KIRI34 / 0.29;
  bufferdef[35] = KIRI35 / 0.29;
  bufferdef[36] = KIRI36 / 0.29; // +keluar
  //  bufferdef[41] = KEPALA41/0.29;
  //  bufferdef[42] = KEPALA42/0.29;
  //  bufferdef[43] = KEPALA43/0.29;

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
  Default[41] = bufferdef[41];
  Default[42] = bufferdef[42];
  Default[43] = bufferdef[43];

  state = 0;

  //buka file gerakan, nama file bisa diganti sesuai kebutuhan
  //  if(a == 'c'){
  //  length = sprintf(namaFile, "GRA%d.txt", gerakan);
  //  Serial.println("4");}
  //else
  length = sprintf(namaFile, "GRK%d.txt", gerakan);
  //Serial.write(namaFile); Serial.println();
  //Serial.println(myFile.available());
  myFile = SD.open(namaFile);
  //  Serial.println(myFile.available());
  //Serial.println("sd");
  //jika file ada
  if (myFile) {
    //    Serial.println("File Exist");
    //    Serial.println(myFile.available());
    //    Serial.println("Reading...");
    while (myFile.available()) {

      //baca data file
      char a = myFile.read();
      //Serial.print(a);
      if (a == 'A' ) {
        state = 1;
        count = count + 1;
      }
      //baca yaw
      if ((state == 1) && (a != ';') && (a != 'A')) {
        stringId += a;
      }
      if ((state == 1) && (a == ';')) {
        state = 2;
        a = ' ';
      }
      //baca pitch
      if ((state == 2) && (a != 'B')) {
        stringSudut += a;
      }
      if ((state == 2) && (a == 'B')) {
        state = 3;
      }
      if (a == 'B' ) {
        //Tampilkan nilai
        //        Serial.print("ID    : ");
        //        Serial.println(stringId.toInt());
        //
        //        Serial.print("Sudut : ");
        //        Serial.println(stringSudut.toInt());
        //
        //        Serial.print("count : ");
        //        Serial.println(count);
        id = stringId.toInt();
        sudut = stringSudut.toInt();
        stringSudut = "";
        stringId = "";
        dynamixel2(id, sudut + Default[id], waktuTari);

      }
    }
    //Tutup file:
    myFile.close();
  }
  else {
    Serial.println("error opening gerakan.txt");
  }
}


void tulisWaktuSD(int nama, int waktu) {
  int length;
  char nfile[200];
  length = sprintf(nfile, "WKT%d.txt", nama);

  myFile = SD.open(nfile);

  if (myFile) {
    SD.remove(nfile);
    myFile = SD.open(nfile, FILE_WRITE);
    if (myFile) {
      Serial.print("Menulis Waktu ke Sd - Case ke -"); Serial.println(nama);
      myFile.print(waktu);
      myFile.close();
    }
    else {
      Serial.println("menulis file baru gagal");
    }
  }

  else {
    myFile = SD.open(nfile, FILE_WRITE);
    if (myFile) {
      Serial.print("Menulis Waktu ke Sd - Case ke -"); Serial.println(nama);
      myFile.print(waktu);
      myFile.close();
    }
    else {
      Serial.println("menulis file gagal");
    }
  }

}


int bacaWaktuSD(int nama) {
  int length, timesss;
  char nfile[200], q;
  String timess = "";
  length = sprintf(nfile, "WKT%d.txt", nama);

  myFile = SD.open(nfile);

  if (myFile) {
    Serial.println("membuka file");
    while (myFile.available()) {
      q = myFile.read();
      timess += q;
    }
    myFile.close();
    timesss = timess.toInt();
  }
  else
  {
    Serial.println("Gagal membuka ");
  }
  return timesss;
}
