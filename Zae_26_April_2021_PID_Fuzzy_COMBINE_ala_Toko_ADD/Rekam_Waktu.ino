//File myFile;
int lastMove, elapsedPerCase, wkt;

void rekamWaktu() {
  dataOut = 1;
  while (dataOut <= 63) {
    lastMove = millis();
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
          walkPurakBarikHaha22();
          break;
        case 58:
          walkPurakBarikHaha33();
          break;
        case 59:
          langkahKaPurakBarikHaha4(-3, 3, 16.7, 3, 1.5);
          waitAll(200);
          langkahKiPurakBarikSejajarHaha1(-3, 3, 16.7, 3, 1.5);
          waitAll(200);
          break;
        case 60:
          BukaMaskerB();
          break;
        case 61:
          masker(51,270);
          cuciKiriAkhir();
          break;
        case 62:
          cuciPunggungTanganAkhir();
          masker(51,270);
          stepcuci(6);
          waitAll(200); //bisa dikurangi / dimatiin
          //CEK INI WOY
          break;
        case 63:
          SalamPenutupB();
          break;
      

    }
    elapsedPerCase = millis() - lastMove;
    //masukin ke sd card
    tulisWaktuSD(dataOut, elapsedPerCase);
    /////////////////////////
    dataOut = dataOut + 1;
  }
  Serial.println("Selesai");
  digitalWrite(16, HIGH);
}
