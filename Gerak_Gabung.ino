bool cekSuara = 0;
int Counter = 1;

void requestLagu() {
  if (digitalRead(17)) {
    Serial.println("Using panic Button");
    cekSuara = 1; //Tombol Panik
    return;
  }
  //Request status musik
  //     Serial.println("Sending Music Status request");
  SerialSuara.write(0xFF);

  //Wait response
  while (!SerialSuara.available()) {
    if (digitalRead(17)) {
      Serial.println("Using panic Button");
      cekSuara = 1; //Tombol Panik
      break;
    }
    //    delay);
  }

  //receive data
  if (SerialSuara.available()) {
    //    Serial.println("Music Status received");
    cekSuara = SerialSuara.read();
  }
  //  else {
  //    Serial.println("Using panic Button");
  //    cekSuara = digitalRead(17);
  //  }
}

void transmitJuna() {
  int paketJuna;
  //Komunikasi ke robot satunya
  paketJuna = (cekSuara * 128) + dataOut; // 8-bit transmisi, bit pertama status musik.
  SerialJuna.write(paketJuna);
  //    receiveData();
  Serial.println("PaketJuna: " + String(paketJuna));
  Serial.println("Data IN: " + String(dataIn));
  Serial.println("Gerak ke:  " + String(dataOut));
}

void StartZae() {
  digitalWrite(16, HIGH);
  unsigned int wkt, prevMove;

  //Sebelum musik mulai
  while (cekSuara == 0) {
    requestLagu();
    delay(5);
  }

  //    SerialJuna.write(2);
  Serial.println("Mulai!!!");
  dataOut = 1;


  while (dataOut <= 64) {
    //Mancing data dari sensor + mengosongkan buffer serial



    requestLagu();
    requestLagu();
    requestLagu();
    transmitJuna();
    //    delay(1);
    //
    //      while (!Serial5.available()) {
    //
    //      }
    receiveData();
    receiveData();
    //    receiveData();
    //    receiveData();
    //    receiveData();




    //   SerialSuara.clear();
    if (cekSuara) {
      Serial.println("Music ON");
      //millis()

      //Sinkronisasi gerakan dengan robot satunya
      while (dataIn < dataOut) {
        if (digitalRead(17)) break;
        receiveData();
        //        Serial.println("Nunggu");
      }
      //      backToLife();
      //    delay(2000);
      ////Koreografi
      switch (dataOut) {

        case 1:
          //          TanganDepanC();
          baca(2334, 20);
          PalaBawahIseng(5);
          waitAll(2000);
          PalaDefault(5);
          waitAll(500);
          PasangMaskerB();
          break;
        case 2:
          cuciKiri();
          break;
        case 3:
        
          break;
        case 4:
          cuciPunggungTangan();
          break;
        case 5:
          SalamPembukaBCaseA();
          break;
        case 6:
          SalamPembukaBCaseB();
          break;
        case 7:
          SalamPembukaBCaseC();
          break;
        case 8:
          walkNganjatHue1();
          break;
        case 9:
          NganjatTotalCaseB(); //ini cermin sama JUNA
          break;
        case 10:
          walkNganjatHue2();
          break;
        case 11:
          NganjatTotalCaseA(); //ini cermin sama JUNA
          break;
        case 12:
          walkNganjatHue3();
          break;
        case 13:
          SalamPembukaC();
          break;
        case 14:
          PeralihanZonaAkeBCaseA();
          TanganNgguk2();
          break;
        case 15:
          PeralihanZonaAkeBCaseB();
          break;
        case 16:
          PeralihanZonaAkeBCaseC();
          break;
        case 17:
          PeralihanZonaAkeBCaseD();
          break;
        case 18:
          PeralihanZonaAkeBCaseE();
          break;
        case 19:
          PeralihanZonaAkeBCaseF();
          break;
        case 20:
          Wavey1();
          break;
        case 21:
          walkNgasaiHue1();
          break;
        case 22:
          PalaDefault(4);
          baca(2219, 5);
          waitAll(500);
          break;
        case 23:
          Wavey2();
          break;
        case 24:
          walkNgasaiHue2();
          break;
        case 25:
          PalaDefault(4);
          baca(2219, 5);
          waitAll(500);
          break;
        case 26:
          Wavey2(); //emang pakek yang dua
          break;
        case 27:
          walkNgasaiHue3();
          break;
        case 28:
          PalaDefault(4);
          baca(2219, 5);
          waitAll(500);
          break;
        case 29:
          ZonaBDiemBaruCaseA();
          break;
        case 30:
          ZonaBDiemBaruCaseB();
          break;
        case 31:
          ZonaBDiemBaruCaseC();
          break;
        case 32:
          ZonaBDiemBaruCaseD();
          break;
        case 33:
          ZonaBDiemBaruCaseE();
          break;
        case 34:
          ZonaB41CaseA();
          break;
        case 35:
          ZonaB41CaseB();
          break;
        case 36:
          ZonaB42CaseA();
          break;
        case 37:
          ZonaB42CaseB();
          break;
        case 38:
          PeralihanZonaBkeCCaseA();
          break;
        case 39:
          PeralihanZonaBkeCCaseB();
          break;
        case 40:
          PeralihanZonaBkeCCaseC();
          break;
        case 41:
          walkPurakBarikHaha1();
          break;
        case 42:
          walkPurakBarikHaha2();
          break;
        case 43:
          walkPurakBarikHaha3();
          break;
        case 44:
          ZonaCDiemBaruCaseA();
          break;
        case 45:
          ZonaCDiemBaruCaseB();
          break;
        case 46:
          ZonaCDiemBaruCaseC();
          break;
        case 47:
          ZonaCDiemBaruCaseD();
          break;
        case 48:
          ZonaCDiemBaruCaseE();
          break;
        case 49:
          ZonaCDiemBaruCaseF();
          break;
        case 50:
          ZonaCDiemBaruCaseG();
          break;
        case 51:
          ZonaCDiemBaruCaseH();
          break;
        case 52:
          ZonaCDiemBaruCaseI(); //mungkin bisa cermin case I sama Case J
          break;
        case 53:
          ZonaCDiemBaruCaseJ();
          break;
        case 54:
          ZonaCDiemBaruCaseK();
          break;
        case 55:
          ZonaCDiemBaruCaseL();
          break;
        case 56:
          walkPurakBarikHaha1();
          break;
        case 57:
          walkPurakBarikHaha2();
          break;
        case 58:
          walkPurakBarikHaha3();
          break;
        case 59:
          langkahKaPurakBarikHaha2(-3, 3, 16.7, 3, 1.5);
          waitAll(200);
          langkahKiPurakBarikSejajarHaha1(-3, 3, 16.7, 3, 1.5);
          waitAll(200);
          break;
        case 60:
          pamerSayap();
          break;
        case 61:
          BukaMaskerB();
          break;
        case 62:
          masker(51, 270);
          cuciKiriAkhir();
          break;
        case 63:
          cuciPunggungTanganAkhir();
          masker(51, 270);
          stepcuci(6);
          waitAll(200); //bisa dikurangi / dimatiin
          //CEK INI WOY
          break;
        case 64:
          SalamPenutupB();
          break;
      }
      dataOut = dataOut + 1;
      //        backToLife();

    }

    else {
      prevMove = millis();
      wkt = bacaWaktuSD(dataOut); //buka file
      while (millis() - prevMove <= wkt) {
        //requestLagu();
        //        backToLife();
        //        delay(5);
      }
      //      transmitJuna();
      dataOut++;
    }

    Serial.print("counter keeeeeeeeeeeeeeeeeeee ------- "); Serial.println(dataOut);

  }
}

void JalanAja() {
  //jalannya pakai ngasasi
  //untuk mengelabui pause
  //  walkNgasaiHiya6();
  Serial.println("jalan aja woy");
  //  CountJalan+=2;
}

void JalanAjaB() {
  //jalannya pakai ngasasi (beda tuningan)
  //untuk mengelabui pause
  //  walkNgasaiHiya6();
  Serial.println("jalan aja woy");
  //  CountJalan+=2;
}

void JalanAjaC() {
  //jalannya pakai ngasasi
  //untuk mengelabui pause
  //  walkPurakBarikHiya1();
  Serial.println("jalan aja woy");
  //  CountJalan+=2;
}
//ini cuma buat inget format kalo ada ketinggalan jalan :
//case 10:
//          if (CountJalan < 6) {
//            lastMove = millis();
//            JalanAja();
//            wkt = bacaWaktuSD(Counter);
//            while (millis() - lastMove < wkt) {
//            }
//          }
//          else {
//            nundukKananKiriCaseA();   //diganti ove
//          }
//          break;
