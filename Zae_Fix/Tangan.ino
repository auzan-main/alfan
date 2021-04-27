void pamerSayap() {
  float IAMSPEED = 5;
  float IAMTIME = 500;

  baca(3350, IAMSPEED);
  PalaBawah(IAMSPEED);
  waitAll(IAMTIME);
  baca(3353, IAMSPEED);
  PalaKananAtas(IAMSPEED); //di juna kiriatas
  Wire1.beginTransmission(8);
  Wire1.write(37);
  Wire1.endTransmission();
  waitAll(IAMTIME);
  baca(3353, IAMSPEED);
  PalaKananAtas(IAMSPEED); //di juna kiriatas
  waitAll(IAMTIME);
  baca(3350, IAMSPEED);
  PalaBawah(IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(IAMTIME);
  baca(3353, IAMSPEED);
  PalaKiriAtas(IAMSPEED); //di juna kanan atas
  Wire1.beginTransmission(8);
  Wire1.write(30);
  Wire1.endTransmission();
  waitAll(IAMTIME);
  baca(3353, IAMSPEED);
  PalaKiriAtas(IAMSPEED); //di juna kanan atas
  waitAll(IAMTIME);
  baca(3356, IAMSPEED);
  PalaBawah(IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(IAMTIME);
}

void TanganDepanC() {
  baca(2334, 5);
  waitAll(500);
}

void BukaMaskerB() {

  baca(2393, 3);
  baca(2413, 4);
  waitAll(400);

  baca(2411, 3);
  waitAll(500);

  baca(2392, 2);
  baca(2412, 2);
  masker(51, 270);
  waitAll(400);

  PalaDefault(4);
  masker(51, 270);
  baca(2413, 5);
  waitAll(500);

}

void PasangMaskerB() {

  baca(2101, 5);
  waitAll(500);

  baca(2392, 5);
  baca(2102, 5);
  waitAll(600);

  baca(2393, 9); //tadinya 4
  baca(2103, 9);
  masker(51, 80);
  waitAll(900);

  baca(2389, 11);
  baca(2106, 11);
  waitAll(1100);
}

void SalamPembukaB() {
  /////////////////////////////////////////////CaseA/////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  TanganDepanC();
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2381, 4);
  baca(2039, 4);
  waitAll(400);

  baca(2040, 7);
  waitAll(700);

  baca(2382, 4);
  baca(2041, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -3;  //-13.5 hips
  tKi = 3;   //-13.5 hips
  pi = -1; // -12 roll angkle kiri
  pa = -1; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2383, 4);
  baca(2042, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -13;  //-13.5 hips
  tKi = 13;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2381, 4);
  baca(2043, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2334, 4); //ini tanganDepanC
  PalaDefault(4);
  waitAll(400);

  ////////////////////////////////////////CaseB/////////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2384, 4);
  baca(2044, 4);
  waitAll(400);

  baca(2045, 7);
  waitAll(700);

  baca(2385, 4);
  baca(2046, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 3;  //-13.5 hips
  tKi = -3;   //-13.5 hips
  pi = 1; // -12 roll angkle kiri
  pa = 1; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2383, 4);
  baca(2047, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 13;  //-13.5 hips
  tKi = -13;   //-13.5 hips
  pi = 11; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2384, 4);
  baca(2048, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaDefault(4);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);

  //////////////////////////////////////////////CaseC/////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 14.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 14.6, 0, -0.5);
  PalaBawah(4);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -0.5);
  PalaDefault(8);
  baca(2334, 8); //ini tanganDepanC
  waitAll(1200);
}

void SalamPembukaC() {
  float IAMSPEED = 3.5;
  float IAMTIME = 350;
  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.7, 0 , -0.5);
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.7, 0 , -0.5);
  TanganDepanC();//
  waitAll(200);//
  PalaBawahIseng(IAMSPEED);
  baca(3101, IAMSPEED);
  waitAll(IAMTIME);//
  PalaKiriBawah(IAMSPEED);
  baca(3102, IAMSPEED);
  waitAll(IAMTIME);//
  baca(3103, IAMSPEED);
  waitAll(IAMTIME);//
  baca(3104, IAMSPEED);
  waitAll(IAMTIME);//
  baca(3105, IAMSPEED);
  waitAll(IAMTIME);//
  dynamixel(1, 7, 165, IAMSPEED);
  PalaKiri(IAMSPEED);
  baca(3106, IAMSPEED);
  waitAll(IAMTIME);//
  dynamixel(1, 7, 150, IAMSPEED);
  PalaKiriAtas(IAMSPEED);
  baca(3123, IAMSPEED);
  waitAll(IAMTIME);//
  dynamixel(1, 7, 180, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  TanganDepanC();//
  waitAll(500);//
  baca(3110, IAMSPEED);
  PalaKananBawah(IAMSPEED);
  waitAll(IAMTIME);//
  baca(3111, 3);
  waitAll(IAMTIME);//
  baca(3112, IAMSPEED);
  waitAll(IAMTIME);//
  baca(3113, IAMSPEED);
  waitAll(IAMTIME);//
  baca(3114, IAMSPEED);
  waitAll(IAMTIME);//
  dynamixel(1, 7, 195, IAMSPEED);
  PalaKanan(IAMSPEED);
  baca(3115, IAMSPEED);
  waitAll(IAMTIME);//
  dynamixel(1, 7, 210, IAMSPEED);
  PalaKananAtas(IAMSPEED);
  baca(3116, IAMSPEED);
  waitAll(IAMTIME);//
  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.7, 0 , -0.5);
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.7, 0 , -0.5);
  dynamixel(1, 7, 180, IAMSPEED);
  PalaDefault(IAMSPEED);
  TanganDepanC();//
  //  waitAll(200);//
}

void SalamPembukaBCaseA() {
  /////////////////////////////////////////////CaseA/////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.6);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.6);
  TanganDepanC();
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.6);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.6);
  baca(2381, 4);
  baca(2039, 4);
  waitAll(400);

  baca(2040, 7);
  waitAll(700);

  baca(2382, 4);
  baca(2041, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -3;  //-13.5 hips
  tKi = 3;   //-13.5 hips
  pi = -4; // -12 roll angkle kiri
  pa = -4; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.6);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.6);
  baca(2383, 4);
  baca(2042, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -12; // -12 roll angkle kiri
  pa = -10; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.6);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.6);
  baca(2381, 4);
  baca(2043, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  baca(2334, 4); //ini tanganDepanC
  PalaDefault(4);
  waitAll(400);
}

void SalamPembukaBCaseB() {
  ////////////////////////////////////////CaseB/////////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.6);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.6);
  baca(2384, 4);
  baca(2044, 4);
  waitAll(400);

  baca(2045, 7);
  waitAll(700);

  baca(2385, 4);
  baca(2046, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 3;  //-13.5 hips
  tKi = -3;   //-13.5 hips
  pi = 4; // -12 roll angkle kiri
  pa = 4; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.6);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.6);
  baca(2383, 4);
  baca(2047, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 10; // -12 roll angkle kiri
  pa = 12; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.6);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.6);
  baca(2384, 4);
  baca(2048, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaDefault(4);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);
}

void SalamPembukaBCaseC() {
  //////////////////////////////////////////////CaseC/////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 14.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 14.6, 0, -1);
  PalaBawah(4);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -1);
  PalaDefault(8);
  baca(2334, 8); //ini tanganDepanC
  waitAll(1200);
}

void NganjatDepan () {
  baca(2107, 5);
  waitAll(500);

  baca(2108, 3);
  waitAll(300);

  baca(2109, 3);
  waitAll(300);

  baca(2110, 3);
  waitAll(300);

  baca(2111, 3);
  waitAll(300);

  baca(2112, 3);
  waitAll(300);

  baca(2113, 3);
  waitAll(300);

  baca(2107, 3);
  waitAll(300);

  baca(2108, 3);
  waitAll(300);

  baca(2109, 3);
  waitAll(300);

  baca(2110, 3);
  waitAll(300);

  baca(2111, 3);
  waitAll(300);

  baca(2112, 3);
  waitAll(300);

  baca(2113, 3);
  waitAll(300);
}

void NganjatTotal() {
  ////////////////////////////////////////////////////CaseA///////////////////////////////////////
  walkNganjatHue1();

  dynamixel(1 , 7 , 150, 5);
  baca(2388, 4);
  baca(2119, 5);
  waitAll(500);

  baca(2118, 5);
  waitAll(500);

  baca(2117, 5);
  waitAll(500);

  baca(2116, 5);
  waitAll(500);

  dynamixel(1 , 7 , 180, 5);
  baca(2115, 5);
  waitAll(500);

  //////////////////////////////////////////////////CaseB////////////////////////////////////////////
  walkNganjatHue2();

  dynamixel(1 , 7 , 210, 5);
  baca(2389, 4);
  baca(2120, 5);
  waitAll(500);

  baca(2121, 5);
  waitAll(500);

  baca(2122, 5);
  waitAll(500);

  baca(2123, 5);
  waitAll(500);

  dynamixel(1 , 7 , 180, 5);
  baca(2124, 5);
  waitAll(500);

  //////////////////////////////////////////////////////////CaseC///////////////////////////
  walkNganjatHue3();

  dynamixel(1 , 7 , 150, 5);
  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6 - sfZ, 0 , -0.5);
  baca(2388, 4);
  baca(2119, 5);
  waitAll(500);

  baca(2118, 5);
  waitAll(500);

  baca(2117, 5);
  waitAll(500);

  baca(2116, 5);
  waitAll(500);

  dynamixel(1 , 7 , 180, 5);
  baca(2115, 5);
  waitAll(500);

}

void NganjatTotalCaseA() {
  ////////////////////////////////////////////////////CaseA///////////////////////////////////////
  //  walkNganjatHue1(); //dipisah case

  dynamixel(1 , 7 , 150, 5);
  //  baca(2388, 4);
  PalaKananAtas(5);
  baca(2119, 5);
  waitAll(500);

  baca(2118, 5);
  PalaKananBawah(5);
  waitAll(500);

  baca(2117, 5);
  PalaKananAtas(5);
  waitAll(500);

  baca(2116, 5);
  PalaKananBawah(5);
  waitAll(500);

  dynamixel(1 , 7 , 180, 5);
  PalaDefault(5);
  baca(2115, 5);
  waitAll(500);
}

void NganjatTotalCaseB() {
  //////////////////////////////////////////////////CaseB////////////////////////////////////////////
  //  walkNganjatHue2(); //dipisah case

  dynamixel(1 , 7 , 210, 5);
  //  baca(2389, 4);
  PalaKiriAtas(5);
  baca(2120, 5);
  waitAll(500);

  baca(2121, 5);
  PalaKiriBawah(5);
  waitAll(500);

  baca(2122, 5);
  PalaKiriAtas(5);
  waitAll(500);

  baca(2123, 5);
  PalaKiriBawah(5);
  waitAll(500);

  dynamixel(1 , 7 , 180, 5);
  PalaDefault(5);
  baca(2124, 5);
  waitAll(500);
}

void NganjatTotalCaseC() {
  //////////////////////////////////////////////////////////CaseC///////////////////////////
  //  walkNganjatHue3(); //dipisah case

  dynamixel(1 , 7 , 150, 5);
  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6 - sfZ, 0 , -0.5);
  baca(2388, 4);
  baca(2119, 5);
  waitAll(500);

  baca(2118, 5);
  waitAll(500);

  baca(2117, 5);
  waitAll(500);

  baca(2116, 5);
  waitAll(500);

  dynamixel(1 , 7 , 180, 5);
  baca(2115, 5);
  waitAll(500);

}


void PeralihanA1() {
  ////////////////////////////////////////////CaseA//////////////////////////////////////////////////////////
  TanganNgguk(); //ada mendek mendek disini

  ////////////////////////////////////////////CaseB/////////////////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 4, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);
  invers(KIRI, 4, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  dynamixel(1 , 7 , 150, 4);
  baca(2388, 3);
  baca(2131, 4);
  waitAll(400);

  dynamixel(1 , 7 , 180, 4);
  PalaDefault(3);
  baca(2132, 4);
  waitAll(400);

  dynamixel(1 , 7 , 210, 4);
  baca(2389, 3);
  baca(2133, 4);
  waitAll(400);

  dynamixel(1 , 7 , 180, 4);
  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);

  ////////////////////////////////////////////CaseC/////////////////////////////////////////////////
  SragSrag();
}

void PeralihanA1CaseA() {
  ////////////////////////////////////////////CaseA//////////////////////////////////////////////////////////
  TanganNgguk(); //ada mendek mendek disini
}

void PeralihanA1CaseB() {
  ////////////////////////////////////////////CaseB/////////////////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 4, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);
  invers(KIRI, 4, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  dynamixel(1 , 7 , 150, 4);
  baca(2388, 3);
  baca(2131, 4);
  waitAll(400);

  dynamixel(1 , 7 , 180, 4);
  PalaDefault(3);
  baca(2132, 4);
  waitAll(400);

  dynamixel(1 , 7 , 210, 4);
  baca(2389, 3);
  baca(2133, 4);
  waitAll(400);

  dynamixel(1 , 7 , 180, 4);
  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);
}

void PeralihanA1CaseC() {
  ////////////////////////////////////////////CaseC/////////////////////////////////////////////////
  SragSrag();
}

void PeralihanZonaAkeB() {
  float IAMSPEED = 5;
  float IAMTIME = 500;
  ////////////////////////////////////////////CaseA//////////////////////////////////////////////////////////
  TanganNgguk(); //ada mendek mendek disini + kepala angguk

  ////////////////////////////////////////////CaseB////////////////////////////////////
  PalaBawah(IAMSPEED);
  baca(3152, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3153, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawahIseng(IAMSPEED);
  baca(3154, IAMSPEED);
  waitAll(IAMTIME);
  PalaAtas(IAMSPEED);
  baca(3155, IAMSPEED);
  waitAll(IAMTIME);
  ////////////////////////////////////////////CaseC/////////////////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 4, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 4, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  dynamixel(1 , 7 , 150, 4);
  baca(2388, 3);
  baca(2131, 4);
  waitAll(400);

  dynamixel(1 , 7 , 180, 4);
  PalaDefault(3);
  baca(2132, 4);
  waitAll(400);

  dynamixel(1 , 7 , 210, 4);
  baca(2389, 3);
  baca(2133, 4);
  waitAll(400);

  //ini tambahan
  //  dynamixel(1 , 7 , 180, 4);
  //  baca(2389, 3);
  //  baca(2133, 4);
  //  waitAll(400);
  //
  //  tPa = 0;
  //  tPi = 0;
  //  tKa = -9;  //-13.5 hips
  //  tKi = 9;   //-13.5 hips
  //  pi = -11; // -12 roll angkle kiri
  //  pa = -11; // -17 roll angkle kanan
  //  tjKi = 0; //-2 pitch angkle kiri
  //  tjKa = 0;//0 pitch angkle kanan
  //
  //  invers(KANAN, 4, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  //  invers(KIRI, 4, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  //  baca(2389, 4);
  //  baca(2133, 4);
  //  waitAll(400);
  //
  //  tPa = 0;
  //  tPi = 0;
  //  tKa = 0;  //-13.5 hips
  //  tKi = 0;   //-13.5 hips
  //  pi = 0; // -12 roll angkle kiri
  //  pa = 0; // -17 roll angkle kanan
  //  tjKi = 0; //-2 pitch angkle kiri
  //  tjKa = 0;//0 pitch angkle kanan
  //
  //  invers(KANAN, 4, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  //  invers(KIRI, 4, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  //  baca(2389, 4);
  //  baca(2133, 4);
  //  waitAll(400);


  dynamixel(1 , 7 , 180, 4);
  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);

  ////////////////////////////////////////////CaseD/////////////////////////////////////////////////
  SragSrag();

  //////////////////////////////////////////CaseE////////////////////////////////////
  //ini dadah 6 step
  dynamixel(1, 7, 180, IAMSPEED);
  PalaDefault(IAMSPEED);
  baca(3157, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3158, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3159, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3160, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3161, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3162, IAMSPEED);
  waitAll(IAMTIME);
  //////////////////////////////////////////////////CaseF////////////////////////
  //ini yang angkat apalah itu
  //kekanan dulu
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2381, 4);
  baca(2139, 5);
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  //ke kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2384, 4);
  baca(2143, 5);
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  waitAll(800);
}

void PeralihanZonaAkeBCaseA() {
  ////////////////////////////////////////////CaseA//////////////////////////////////////////////////////////
  TanganNgguk(); //ada mendek mendek disini + kepala angguk

}

void PeralihanZonaAkeBCaseB() {
  float IAMSPEED = 5;
  float IAMTIME = 500;
  ////////////////////////////////////////////CaseB////////////////////////////////////
  PalaBawah(IAMSPEED);
  baca(3152, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3153, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawahIseng(IAMSPEED);
  baca(3154, IAMSPEED);
  waitAll(IAMTIME);
  PalaAtas(IAMSPEED);
  baca(3155, IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanZonaAkeBCaseC() {
  float IAMSPEED = 5;
  float IAMTIME = 500;
  ////////////////////////////////////////////CaseC/////////////////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 4, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 4, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  dynamixel(1 , 7 , 210, 4);
  baca(2389, 3);
  baca(2133, 4);
  waitAll(400);

  dynamixel(1 , 7 , 180, 4);
  PalaDefault(3);
  baca(2132, 4);
  waitAll(400);

  dynamixel(1 , 7 , 150, 4);
  baca(2388, 3);
  baca(2131, 4);
  waitAll(400);

  dynamixel(1 , 7 , 180, 4);
  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);
}

void PeralihanZonaAkeBCaseD() {
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  //////////////////////////////////////////CaseD////////////////////////////////////
  //ini dadah 6 step
  dynamixel(1 , 7 , 180, IAMSPEED);
  PalaDefault(IAMSPEED);
  baca(3157, IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(1);
  Wire1.endTransmission();
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3158, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3159, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3160, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3161, IAMSPEED);
  waitAll(IAMTIME);

  PalaBawah(IAMSPEED);
  baca(3162, IAMSPEED);
  waitAll(IAMTIME);

}

void PeralihanZonaAkeBCaseE() {
  ////////////////////////////////////////////CaseE/////////////////////////////////////////////////
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  SragSrag();
}

void PeralihanZonaAkeBCaseF() {
  //////////////////////////////////////////////////CaseF////////////////////////
  //ini yang angkat apalah itu
  //kekanan dulu
  dynamixel(1, 7, 180, 2);
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2381, 4);
  baca(2139, 5);
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  //ke kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2384, 4);
  baca(2143, 5);
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  waitAll(800);
}

void SragSrag() {

  dynamixel(1, 7, 195, 4);
  baca(2389, 2.5);
  baca(2134, 4);
  waitAll(400);

  dynamixel(1, 7, 165, 4);
  baca(2388, 2.5);
  baca(2135, 4);
  waitAll(400);

  dynamixel(1, 7, 195, 4);
  baca(2389, 2.5);
  baca(2134, 4);
  waitAll(400);

  dynamixel(1, 7, 165, 4);
  baca(2388, 2.5);
  baca(2135, 4);
  waitAll(400);
}

void TanganNgguk() {
  double mendaktime = 3;
  double mendakduration = 300;
  double toron1 = 14.8;
  double toron2 = 14.8;
  double pinggul1 = -0.5;
  double pinggul2 = -0.7;
  //1
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, toron1, 0 , pinggul1);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, toron2, 0 , pinggul1);
  PalaDefault(mendaktime);
  baca(2198, mendaktime);
  waitAll(mendakduration);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, 16.6, 0 , pinggul2);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, 16.6, 0 , pinggul2);
  PalaBawah(mendaktime);
  baca(2199, mendaktime);
  waitAll(mendakduration);

  //2
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 3; //-2 pitch angkle kiri
  tjKa = -1;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, toron1, 0 , pinggul1);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, toron2, 0 , pinggul1);
  PalaDefault(mendaktime);
  baca(2200, mendaktime);
  waitAll(mendakduration);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, 16.6, 0 , pinggul2);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, 16.6, 0 , pinggul2);
  PalaBawah(mendaktime);
  baca(2201, mendaktime);
  waitAll(mendakduration);

  //3
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 3; //-2 pitch angkle kiri
  tjKa = -1;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, toron1, 0 , pinggul1);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, toron2, 0 , pinggul1);
  PalaDefault(mendaktime);
  baca(2202, mendaktime);
  waitAll(mendakduration);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, 16.6, 0 , pinggul2);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, 16.6, 0 , pinggul2);
  PalaBawah(mendaktime);
  baca(2203, mendaktime);
  waitAll(mendakduration);

}

void TanganNgguk2() {
  float mendaktime = 3;
  float mendakduration = 300;
  double toron1 = 14.8;
  double toron2 = 14.8;
  double pinggul1 = -0.5;
  double pinggul2 = -0.7;
  //4
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 3; //-2 pitch angkle kiri
  tjKa = -1;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, toron1, 0 , pinggul1);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, toron2, 0 , pinggul1);
  PalaDefault(mendaktime);
  baca(2204, mendaktime);
  waitAll(300);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, 16.6, 0 , pinggul2);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, 16.6, 0 , pinggul2);
  PalaBawah(mendaktime);
  baca(2205, mendaktime);
  waitAll(300);

  //5
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 3; //-2 pitch angkle kiri
  tjKa = -1;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, toron1, 0 , pinggul1);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, toron2, 0 , pinggul1);
  PalaDefault(mendaktime);
  baca(2206, mendaktime);
  waitAll(300);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, 16.6, 0 , pinggul2);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, 16.6, 0 , pinggul2);
  PalaBawah(mendaktime);
  baca(2207, mendaktime);
  waitAll(300);

  //6
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 3; //-2 pitch angkle kiri
  tjKa = -1;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, toron1, 0 , pinggul1);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, toron2, 0 , pinggul1);
  PalaDefault(mendaktime);
  baca(2208, mendaktime);
  waitAll(300);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, mendaktime, Xt - 3.06 + 2.5, 16.6, 0 , -0.9);
  invers(KIRI, mendaktime, sfX - 3.06 + 2.5, 16.6, 0 , -0.9);
  PalaBawah(mendaktime);
  baca(2209, mendaktime);
  waitAll(300);

}


void PeralihanA2() {
  ///////////////////////////////////CaseA////////////////////////////////////
  //kanan
  PalaDefault(5);
  baca(2136, 5);
  waitAll(500);

  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2381, 4);
  baca(2139, 5);
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  //////////////////////////////////////////CaseB/////////////////////////////////////
  //kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2384, 4);
  baca(2143, 5);
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  waitAll(800);

  //  baca(2136,5);
  //  waitAll(500);

}

void PeralihanA2CaseA() {
  ///////////////////////////////////CaseA////////////////////////////////////
  //kanan
  PalaDefault(5);
  baca(2136, 5);
  waitAll(500);

  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2381, 4);
  baca(2139, 5);
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

}

void PeralihanA2CaseB() {
  //////////////////////////////////////////CaseB/////////////////////////////////////
  //kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2384, 4);
  baca(2143, 5);
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  waitAll(800);

}

void Wavey1() {
  baca(2392, 3);
  baca(2211, 3);
  waitAll(300);

  baca(2393, 3);
  baca(2212, 3);
  waitAll(300);

  baca(2392, 3);
  baca(2213, 3);
  waitAll(300);

  baca(2393, 3);
  baca(2212, 3);
  waitAll(300);
}
void Wavey2() {

  baca(2393, 3);
  baca(2212, 3);
  waitAll(300);

  baca(2392, 3);
  baca(2213, 3);
  waitAll(300);

  baca(2393, 3);
  baca(2212, 3);
  waitAll(300);
}


void ZonaB1() {
  Wavey1();

  walkNgasaiHue1();
  PalaDefault(4);
  baca(2219, 5);
  waitAll(500);
}

void ZonaB2() {
  Wavey2();

  walkNgasaiHue2();
  PalaDefault(4);
  baca(2219, 5);
  waitAll(500);
}

void ZonaB3() {
  Wavey2(); //emang pakek yang dua

  walkNgasaiHue3();
  PalaDefault(4);
  baca(2219, 5);
  waitAll(500);
}

void DadahKanan() {
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2389, 3);
  baca(2263, 4);
  waitAll(400);

  baca(2264, 3);
  waitAll(300);

  baca(2265, 3);
  waitAll(300);

  baca(2266, 3);
  waitAll(300);

  baca(2267, 3);
  waitAll(300);

  baca(2268, 3);
  waitAll(300);

  baca(2381, 4);
  baca(2279, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -8;  //-13.5 hips
  tKi = 8;   //-13.5 hips
  pi = -12; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2280, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2280, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -8;  //-13.5 hips
  tKi = 8;   //-13.5 hips
  pi = -12; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2280, 2);
  waitAll(500);
}

void DadahKiri() {
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2388, 3);
  baca(2291, 4);
  waitAll(400);

  baca(2292, 3);
  waitAll(300);

  baca(2293, 3);
  waitAll(300);

  baca(2294, 3);
  waitAll(300);

  baca(2295, 3);
  waitAll(300);

  baca(2296, 3);
  waitAll(300);

  baca(2384, 4);
  baca(2288, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2289, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2289, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2289, 2);
  waitAll(500);
}


void ZonaBDiem () {
  ///////////////////////////////////////////////caseA/////////////////////////////////////////////////
  DadahKanan();
  //////////////////////////////////////////////CaseB//////////////////////////////////////////////////
  DadahKiri();
  ///////////////////////////////////////////////CaseC///////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  PalaDefault(3);
  baca(2298, 3);
  waitAll(300);

  tPa = 0;
  tPi = 0;
  tKa = -14;  //-13.5 hips
  tKi = 14;   //-13.5 hips
  pi = -7; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(800);
}

void ZonaBDiemCaseA() {
  ///////////////////////////////////////////////caseA/////////////////////////////////////////////////
  DadahKanan();
}

void ZonaBDiemCaseB() {
  //////////////////////////////////////////////CaseB//////////////////////////////////////////////////
  DadahKiri();
}

void ZonaBDiemCaseC() {
  ///////////////////////////////////////////////CaseC///////////////////////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  PalaDefault(3);
  baca(2298, 3);
  waitAll(300);

  //ini ke kanan dulu
  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -10; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 10; // -12 roll angkle kiri
  pa = 10; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(800);
}

void ZonaBDiemBaru() {
  /////////////////////////////////////CaseA///////////////////////////
  //ini yang dadah kiri bawah
  PalaKanan(4);
  baca(3196, 4);
  waitAll(400);
  baca(3197, 3);
  waitAll(300);
  dynamixel(1, 7, 210, 4);
  PalaKiriBawahIseng(4);
  baca(3198, 4);
  waitAll(400);
  baca(3199, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaKanan(4);
  baca(3196, 4);
  waitAll(400);
  baca(3197, 3);
  waitAll(300);
  dynamixel(1, 7, 210, 4);
  PalaKiriBawahIseng(4);
  baca(3198, 4);
  waitAll(400);
  baca(3199, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaDefault(4);
  baca(3200, 2.5);
  waitAll(250);
  PalaKiriBawah(4);
  baca(3201, 4);
  waitAll(400);
  ////////////////////////////////////////////CaseB/////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiriBawah(4);
  baca(3201, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiriBawah(4);
  baca(3201, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiriBawah(4);
  baca(3201, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiriBawah(4);
  baca(3201, 4);
  waitAll(400);

  ////////////////////////////////////////Case C///////////////////////////
  //ini yang dadah kanan bawah
  PalaKiri(4);
  baca(3177, 4);
  waitAll(400);
  baca(3178, 3);
  waitAll(300);
  dynamixel(1, 7, 150, 4);
  PalaKananBawahIseng(4);
  baca(3179, 4);
  waitAll(400);
  baca(3180, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaKiri(4);
  baca(3177, 4);
  waitAll(400);
  baca(3178, 3);
  waitAll(300);
  dynamixel(1, 7, 150, 4);
  PalaKananBawahIseng(4);
  baca(3179, 4);
  waitAll(400);
  baca(3180, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaDefault(4);
  baca(3181, 2.5);
  waitAll(250);
  PalaKananBawah(4);
  baca(3182, 4);
  waitAll(400);
  ///////////////////////////////////////CaseD///////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKananBawah(4);
  baca(3182, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKananBawah(4);
  baca(3182, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKananBawah(4);
  baca(3182, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKananBawah(4);
  baca(3182, 4);
  waitAll(400);
  ////////////////////////////////////CaseE///////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan
  dynamixel(1, 7, 150, 3);
  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  PalaDefault(3);
  baca(2298, 3);
  waitAll(300);

  //ini ke kanan dulu
  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -10; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 10; // -12 roll angkle kiri
  pa = 10; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  waitAll(400);
  dynamixel(1, 7, 180, 4);
  baca(2299, 2);
  waitAll(400);
}

void ZonaBDiemBaruCaseA() {
  /////////////////////////////////////CaseA///////////////////////////
  //ini yang dadah kiri bawah
  PalaKanan(4);
  baca(3196, 4);
  waitAll(400);
  baca(3197, 3);
  waitAll(300);
  dynamixel(1, 7, 210, 4);
  PalaKiriBawahIseng(4);
  baca(3198, 4);
  waitAll(400);
  baca(3199, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaKanan(4);
  baca(3196, 4);
  waitAll(400);
  baca(3197, 3);
  waitAll(300);
  dynamixel(1, 7, 210, 4);
  PalaKiriBawahIseng(4);
  baca(3198, 4);
  waitAll(400);
  baca(3199, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaDefault(4);
  baca(3200, 2.5);
  waitAll(250);
  PalaKiriBawah(4);
  baca(3201, 4);
  waitAll(400);
}

void ZonaBDiemBaruCaseB() {
  ////////////////////////////////////////////CaseB/////////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiriBawah(4);
  baca(3201, 4);
  Wire1.beginTransmission(8);
  Wire1.write(37);
  Wire1.endTransmission();
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKanan(4);
  baca(3201, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiriBawah(4);
  baca(3201, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKanan(4);
  baca(3201, 4);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(400);
}

void ZonaBDiemBaruCaseC() {
  ////////////////////////////////////////Case C///////////////////////////
  //ini yang dadah kanan bawah
  PalaKiri(4);
  baca(3177, 4);
  waitAll(400);
  baca(3178, 3);
  waitAll(300);
  dynamixel(1, 7, 150, 4);
  PalaKananBawahIseng(4);
  baca(3179, 4);
  waitAll(400);
  baca(3180, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaKiri(4);
  baca(3177, 4);
  waitAll(400);
  baca(3178, 3);
  waitAll(300);
  dynamixel(1, 7, 150, 4);
  PalaKananBawahIseng(4);
  baca(3179, 4);
  waitAll(400);
  baca(3180, 3);
  waitAll(300);
  dynamixel(1, 7, 180, 4);
  PalaDefault(4);
  baca(3181, 2.5);
  waitAll(250);
  PalaKananBawah(4);
  baca(3182, 4);
  waitAll(400);
}

void ZonaBDiemBaruCaseD() {
  ///////////////////////////////////////CaseD///////////////////////////
  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKananBawah(4);
  baca(3182, 4);
  Wire1.beginTransmission(8);
  Wire1.write(37);
  Wire1.endTransmission();
  waitAll(400);
  
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiri(4);
  baca(3182, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKananBawah(4);
  baca(3182, 4);
  waitAll(400);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -0.5);
  PalaKiri(4);
  baca(3182, 4);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(400);
}

void ZonaBDiemBaruCaseE() {
  ////////////////////////////////////CaseE///////////////////////
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan
  dynamixel(1, 7, 150, 3);
  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  PalaDefault(3);
  baca(2298, 3);
  Wire1.beginTransmission(8);
  Wire1.write(30);
  Wire1.endTransmission();
  waitAll(300);

  //ini ke kanan dulu
  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -10; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  PalaMiringKiri(4);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 10; // -12 roll angkle kiri
  pa = 10; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  PalaMiringKanan(4);
  baca(2299, 2);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, -1);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, -1);
  baca(2299, 2);
  PalaDefault(4);
  waitAll(400);
  dynamixel(1, 7, 180, 4);
  baca(2299, 2);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(400);
}

void ZonaB41() {
  /////////////////////////////////////////////CaseA//////////////////////////////////////////////
  langkahKaNgasaiHaha1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiNgasaiHaha1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKaNgasaiHaha1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  /////////////////////////////////////////////CaseB//////////////////////////////////////////////
  baca(2517, 5);
  waitAll(500);
  dynamixel(1, 7, 130, 5);
  PalaKiriPol(5);
  baca(2518, 5);
  waitAll(500);
  dynamixel(1, 7, 180, 5);
  PalaDefault(5);
  baca(2528, 5);
  waitAll(500);
  PalaBawah(5);
  baca(2531, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KIRI, 5, -3, 16.6, 0, -0.5); //langkah terakhir zae
  invers(KANAN, 5, 3, 16.6, 0, -0.5);
  PalaKiriBawah(5);
  baca(2532, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KIRI, 5, -3, 16.6, 0, -0.5);
  invers(KANAN, 5, 3, 16.6, 0, -0.5);
  PalaDefault(5);
  baca(2334, 5); //ini tangandepanC
  waitAll(500);
}

void ZonaB41CaseA() {
  /////////////////////////////////////////////CaseA//////////////////////////////////////////////
  //tadinya pakek langka ka-ki ngasaiHaha
  langkahKaNgasaiHaha1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiNgasaiHaha1(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKaNgasaiHaha11(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void ZonaB41CaseB() {
  /////////////////////////////////////////////CaseB//////////////////////////////////////////////
  //  baca(2517, 5);
  //  waitAll(500);
  //  dynamixel(1, 7, 130, 5);
  //  PalaKiriPol(5);
  //  baca(2518, 5);
  //  waitAll(500);
  //  dynamixel(1, 7, 180, 5);
  //  PalaDefault(5);
  //  baca(2528, 5);
  //  waitAll(500);
  PalaBawah(5);
  baca(2531, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KIRI, 5, -3, 16.6, 0, -0.5); //langkah terakhir zae
  invers(KANAN, 5, 3, 16.6, 0, -0.5);
  PalaKiriBawah(5);
  baca(2532, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KIRI, 5, -3, 16.6, 0, -0.5);
  invers(KANAN, 5, 3, 16.6, 0, -0.5);
  PalaDefault(5);
  baca(2334, 5); //ini tangandepanC
  waitAll(500);
}

void ZonaB42() {
  ///////////////////////////////////////////////////////CaseA///////////////////////////////////////
  //tadinya pakek langkah ka-ki ngasaiHaha

  langkahKiNgasaiHaha2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKaNgasaiHaha2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiNgasaiHaha22(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  /////////////////////////////////////////////////CaseB/////////////////////////////////////
  baca(2517, 5);
  waitAll(500);
  dynamixel(1, 7, 230, 5);
  PalaKananPol(5);
  baca(2535, 5);
  waitAll(500);
  PalaDefault(500);
  dynamixel(1, 7, 180, 5);
  baca(2530, 5);
  waitAll(500);
  PalaBawah(5);
  baca(2533, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKananBawah(5);
  baca(2534, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaDefault(5);
  baca(2334, 5);
  waitAll(500);
}

void ZonaB42CaseA() {
  ///////////////////////////////////////////////////////CaseA///////////////////////////////////////
  langkahKiNgasaiHaha2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKaNgasaiHaha2(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
  langkahKiNgasaiHaha22(-3, 3, 16.7, 3, 1.5);
  CountJalan++;
  waitAll(200);
}

void ZonaB42CaseB() {
  /////////////////////////////////////////////////CaseB/////////////////////////////////////
  //  baca(2517, 5);
  //  waitAll(500);
  //  dynamixel(1, 7, 230, 5);
  //  PalaKananPol(5);
  //  baca(2535, 5);
  //  waitAll(500);
  //  PalaDefault(500);
  //  dynamixel(1, 7, 180, 5);
  //  baca(2530, 5);
  //  waitAll(500);
  PalaBawah(5);
  baca(2533, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKananBawah(5);
  baca(2534, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaDefault(5);
  baca(2334, 5);
  waitAll(500);
}

void ZonaB31() {
  langkahKaNgasaiHaha1(-3, 3, 16.7, 3, 1.5);
  invers(KIRI, 5, -3 , 16.6, 0, -0.2); //ini langkah terakhirnya zae
  invers(KANAN, 5, 3  , 16.6, 0, -0.2);
  waitAll(500);
  palaJelek2();
  dynamixel(1, 7, 165, 5); //tak
  waitAll(500);
  invers(KIRI, 5, -3 , 14.6, 0, -0.2); //tak sambil mendek
  invers(KANAN, 5, 3  , 14.6, 0, -0.2);
  dynamixel(1, 7, 150, 5);
  waitAll(500);

  //  invers(KIRI, 5, -3 , 16.6, 0, -0.2);
  //  invers(KANAN, 5, 3  , 16.6, 0, -0.2);
  //  dynamixel(1, 7, 180, 5); //ini mau mbalikin
  //  waitAll(500);
  //bentar ini mau rekam
}

void ZonaB32() {
  langkahKiNgasaiHaha1(-3, 3, 16.7, 3, 1.5);
  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , 0); //langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 14.6, 0 , 0);
  waitAll(500);
  palaJelek1();
  dynamixel(1, 7, 195, 5); //tak
  waitAll(500);
  invers(KANAN, 5, Xt - 3.06 + 2.5, 14.6, 0 , -0.2); //tak sambil mendak
  invers(KIRI, 5, sfX - 3.06 + 2.5, 14.6, 0 , -0.2);
  dynamixel(1, 7, 210, 5);
  waitAll(500);

  //  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.2); //ini mau mbalikin
  //  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.2);
  //  dynamixel(1, 7, 210, 5);
  //  waitAll(500);
  //bentar ini mau rekam
}

void PeralihanB1() {
  /////////////////////////////CaseA/////////////////////////////
  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , 0);
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , 0);
  baca(2315, 5);
  waitAll(500);

  baca(2316, 5);
  waitAll(500);

  baca(2317, 5);
  waitAll(500);

  baca(2318, 5);
  waitAll(500);

  baca(2319, 5);
  waitAll(500);

  baca(2320, 5);
  waitAll(500);

  TanganDepanC();
  waitAll(500);

  //////////////////////////////////////CaseB///////////////////////
  //miring kanan
  baca(2382, 3);
  baca(2321, 4);
  waitAll(400);

  PalaDefault(3);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);

  //miringkiri
  baca(2385, 3);
  baca(2322, 4);
  waitAll(400);

  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);
}

void PeralihanB1CaseA() {
  /////////////////////////////CaseA/////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , 0);
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , 0);
  baca(2315, IAMSPEED);
  waitAll(IAMTIME);

  baca(2316, IAMSPEED);
  waitAll(IAMTIME);

  baca(2317, IAMSPEED);
  waitAll(IAMTIME);

  baca(2318, IAMSPEED);
  waitAll(IAMTIME);

  baca(2319, IAMSPEED);
  waitAll(IAMTIME);

  baca(2320, IAMSPEED);
  waitAll(IAMTIME);

  TanganDepanC();
}

void PeralihanB1CaseB() {
  //////////////////////////////////////CaseB///////////////////////
  //miring kanan
  baca(2382, 3);
  baca(2321, 4);
  waitAll(400);

  PalaDefault(3);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);

  //miringkiri
  baca(2385, 3);
  baca(2322, 4);
  waitAll(400);

  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);
}

void PeralihanB2() {
  /////////////////////////////////////////////////CaseA////////////////////////////////////////
  baca(2551, 5);
  PalaBawahIseng(5);
  waitAll(500);
  baca(2552, 5);
  PalaDefault(5);
  waitAll(500);
  baca(2551, 5);
  PalaBawahIseng(5);
  waitAll(500);
  baca(2552, 5);
  PalaDefault(5);
  waitAll(500);
  ////////////////////////////////////////////////CaseB/////////////////////////////////////
  baca(2519, 5);
  waitAll(500);
  baca(2553, 5);
  PalaBawahIseng(5);
  waitAll(500);
  baca(2554, 5);
  PalaDefault(5);
  waitAll(500);
  baca(2553, 5);
  PalaBawahIseng(5);
  waitAll(500);
  baca(2554, 5);
  PalaDefault(5);
  waitAll(500);
  baca(2555, 5);
  ///////////////////////////////////////////////CaseC/////////////////////////////////////////
  PalaBawah(5);
  waitAll(500);
  baca(2557, 5);
  PalaAtas(5);
  waitAll(500);
  baca(2519, 5);
  PalaDefault(5);
  waitAll(500);
  baca(2558, 5);
  waitAll(500);
  baca(2334, 5);
  waitAll(500);
  ////////////////////////////////////////////CaseD///////////////////////////////////////
  baca(2517, 5);
  waitAll(500);
  dynamixel(1, 7, 230, 5);
  PalaKananPol(5);
  baca(2535, 5);
  waitAll(500);
  PalaDefault(500);
  dynamixel(1, 7, 180, 5);
  baca(2530, 5);
  waitAll(500);
  //////////////////////////////////////////CaseE///////////////////////////////////////
  baca(2517, 5);
  waitAll(500);
  dynamixel(1, 7, 130, 5);
  PalaKiriPol(5);
  baca(2518, 5);
  waitAll(500);
  dynamixel(1, 7, 180, 5);
  PalaDefault(5);
  baca(2528, 5);
  waitAll(500);

  ////////////////////////////////////////////////CaseF//////////////////////////////
  baca(2559, 5);
  waitAll(500);
  baca(2560, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, 5);
  waitAll(500);

  ///////////////////////////////////////CaseG///////////////////////////////////////
  baca(2559, 5);
  waitAll(500);
  baca(2561, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2561, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2561, 5);
  waitAll(500);

  ////////////////////////////////////////CaseH//////////////////////////////////////
  baca(2559, 5);
  waitAll(500);
  baca(2562, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 8, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 8, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, 5);
  waitAll(800);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, 5);
  waitAll(500);

  baca(2559, 5);
  waitAll(500);

}

void PeralihanZonaBkeC() {
  /////////////////////////////CaseA/////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , 0);
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , 0);
  baca(2315, IAMSPEED);
  waitAll(IAMTIME);

  baca(2316, IAMSPEED);
  waitAll(IAMTIME);

  baca(2317, IAMSPEED);
  waitAll(IAMTIME);

  baca(2318, IAMSPEED);
  waitAll(IAMTIME);

  baca(2319, IAMSPEED);
  waitAll(IAMTIME);

  baca(2320, IAMSPEED);
  waitAll(IAMTIME);

  TanganDepanC();
  //////////////////////////////////////////CaseB///////////////////
  PalaBawah(IAMSPEED);
  baca(3152, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3153, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawahIseng(IAMSPEED);
  baca(3154, IAMSPEED);
  waitAll(IAMTIME);
  PalaAtas(IAMSPEED);
  baca(3155, IAMSPEED);
  waitAll(IAMTIME);
  //////////////////////////////////////CaseC///////////////////////
  //miring kanan
  baca(2382, 3);
  baca(2321, 4);
  waitAll(400);

  PalaDefault(3);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);

  //miringkiri
  baca(2385, 3);
  baca(2322, 4);
  waitAll(400);

  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);

}

void PeralihanZonaBkeCCaseA() {
  /////////////////////////////CaseA/////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , 0);
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , 0);
  PalaBawah(IAMSPEED);
  baca(2315, IAMSPEED);
  waitAll(IAMTIME);

  PalaAtas(IAMSPEED);
  baca(2316, IAMSPEED);
  waitAll(IAMTIME);

  PalaBawah(IAMSPEED);
  baca(2317, IAMSPEED);
  waitAll(IAMTIME);

  PalaAtas(IAMSPEED);
  baca(2318, IAMSPEED);
  waitAll(IAMTIME);

  dynamixel(1, 7, 150, IAMSPEED); //ini nanti cermin
  PalaKananBawah(IAMSPEED);
  baca(2319, IAMSPEED);
  waitAll(IAMTIME);

  PalaKananPol(IAMSPEED);
  baca(2320, IAMSPEED);
  waitAll(IAMTIME);

  dynamixel(1, 7, 180, IAMSPEED);
  TanganDepanC();
}

void PeralihanZonaBkeCCaseB() {
  float IAMSPEED = 4.5;
  float IAMTIME = 450;

  //////////////////////////////////////////CaseB///////////////////
  PalaBawah(IAMSPEED);
  baca(3152, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(3153, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawahIseng(IAMSPEED);
  baca(3154, IAMSPEED);
  waitAll(IAMTIME);
  PalaAtas(IAMSPEED);
  baca(3155, IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanZonaBkeCCaseC() {
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  //////////////////////////////////////CaseC///////////////////////
  //miring kanan
  //  baca(2382, 3);
  Wire1.beginTransmission(8);
  Wire1.write(17); //sementara
  Wire1.endTransmission();
  PalaMiringKanan(3);
  baca(2321, 4);
  waitAll(400);

  PalaDefault(3);
  baca(2334, 4); //ini tanganDepanC
  waitAll(400);

  //miringkiri
  //  baca(2385, 3);
  Wire1.beginTransmission(8);
  Wire1.write(17); //sementara
  Wire1.endTransmission();
  PalaMiringKiri(3);
  baca(2322, 4);
  waitAll(400);

  PalaDefault(5);
  baca(2334, 5); //ini tanganDepanC
  waitAll(500);
  Wire1.beginTransmission(8);
  Wire1.write(0); //sementara
  Wire1.endTransmission();

}

void PeralihanB2CaseA() {
  /////////////////////////////////////////////////CaseA////////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2551, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2552, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2551, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2552, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanB2CaseB() {
  ////////////////////////////////////////////////CaseB/////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2519, IAMSPEED);
  waitAll(IAMTIME);
  baca(2553, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2554, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2553, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2554, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2555, IAMSPEED);
  PalaBawah(IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanB2CaseC() {
  ///////////////////////////////////////////////CaseC/////////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2557, IAMSPEED);
  PalaAtas(IAMSPEED);
  waitAll(IAMTIME);
  baca(2519, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2558, IAMSPEED);
  waitAll(IAMTIME);
  baca(2334, IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanB2CaseD() {
  ////////////////////////////////////////////CaseD///////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2517, IAMSPEED);
  waitAll(IAMTIME);
  dynamixel(1, 7, 230, IAMSPEED);
  PalaKananPol(IAMSPEED);
  baca(2535, IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMTIME);
  dynamixel(1, 7, 180, IAMSPEED);
  baca(2530, IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanB2CaseE() {
  //////////////////////////////////////////CaseE///////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2517, IAMSPEED);
  waitAll(IAMTIME);
  dynamixel(1, 7, 130, IAMSPEED);
  PalaKiriPol(IAMSPEED);
  baca(2518, IAMSPEED);
  waitAll(IAMTIME);
  dynamixel(1, 7, 180, IAMSPEED);
  PalaDefault(IAMSPEED);
  baca(2528, IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanB2CaseF() {
  ////////////////////////////////////////////////CaseF//////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanB2CaseG() {
  ///////////////////////////////////////CaseG///////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);
}

void PeralihanB2CaseH() {
  ////////////////////////////////////////CaseH//////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 7.5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 7.5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, 5);
  waitAll(750);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  baca(2559, 5);
  waitAll(500);

}



void PurakBarikTotal1() {
  //Catatan : ini tiap set satu dua dan tiga kepalanya beda-beda, unique semua
  walkPurakBarikHaha1();
  walkPurakBarikHaha2();
  walkPurakBarikHaha3();
}

void PurakBarikTotal2() {
  //Catatan : ini tiap set satu dua dan tiga kepalanya beda-beda, unique semua
  walkPurakBarikHaha1();
  walkPurakBarikHaha2();
  walkPurakBarikHaha3();
}

void ZonaCDiem1() {
  ///////////////////////////////////////////////////CaseA//////////////////////////////////////////////
  TanganDepanC();
  baca(2338, 5);
  waitAll(500);
  baca(2339, 5);
  waitAll(500);
  TanganDepanC();
  ////////////////////////////////////////////////CaseB////////////////////////////////////////////////
  //ini yang tak-tak-tak-tak-tak
  PalaDefault(3);
  baca(2425, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2426, 3);
  waitAll(300);
  PalaDefault(3);
  baca(2427, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2428, 3);
  waitAll(300);
  PalaDefault(3);
  baca(2429, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2430, 3);
  waitAll(300);
  /////////////////////////////////////////////CaseC///////////////////////////////////////
  //ini zona C yang ada hadap hadapnya Zae sama juna mungkin bisa agak di variasi disini..."mungkin"
  PalaKanan(5);
  baca(2448, 5);
  dynamixel(1 , 7 , 150, 5);
  waitAll(500);
  PalaKiri(5);
  baca(2449, 5);
  waitAll(500);
  baca(2450, 5);
  dynamixel(1 , 7 , 210, 5);
  waitAll(500);
  PalaKanan(5);
  baca(2451, 5);
  waitAll(500);
  PalaDefault(5);
  baca(2334, 5); //ini TanganDepanC
  dynamixel(1 , 7 , 180, 5);
  waitAll(500);
}

void ZonaCDiem1CaseA() {
  ///////////////////////////////////////////////////CaseA//////////////////////////////////////////////
  TanganDepanC();
  baca(2338, 5);
  waitAll(500);
  baca(2339, 5);
  waitAll(500);
  TanganDepanC();
}

void ZonaCDiem1CaseB() {
  ////////////////////////////////////////////////CaseB////////////////////////////////////////////////
  //ini yang tak-tak-tak-tak-tak
  PalaDefault(3);
  baca(2425, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2426, 3);
  waitAll(300);
  PalaDefault(3);
  baca(2427, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2428, 3);
  waitAll(300);
  PalaDefault(3);
  baca(2429, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2430, 3);
  waitAll(300);
}

void ZonaCDiem1CaseC() {
  /////////////////////////////////////////////CaseC///////////////////////////////////////
  //ini zona C yang ada hadap hadapnya Zae sama juna mungkin bisa agak di variasi disini..."mungkin"
  PalaKanan(5);
  baca(2448, 5);
  dynamixel(1 , 7 , 150, 5);
  waitAll(500);
  PalaKiri(5);
  baca(2449, 5);
  waitAll(500);
  baca(2450, 5);
  dynamixel(1 , 7 , 210, 5);
  waitAll(500);
  PalaKanan(5);
  baca(2451, 5);
  waitAll(500);
  PalaDefault(5);
  baca(2334, 5); //ini TanganDepanC
  dynamixel(1 , 7 , 180, 5);
  waitAll(500);
}

void ZonaCDiemBaru() {
  ///////////////////////////////////////////////////CaseA//////////////////////////////////////////////
  TanganDepanC();
  baca(2338, 5);
  waitAll(500);
  baca(2339, 5);
  waitAll(500);
  TanganDepanC();
  ////////////////////////////////////////////////CaseB////////////////////////////////////////////////
  //ini yang tak-tak-tak-tak-tak
  PalaDefault(3);
  baca(2425, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2426, 3);
  waitAll(300);
  PalaDefault(3);
  baca(2427, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2428, 3);
  waitAll(300);
  PalaDefault(3);
  baca(2429, 3);
  waitAll(300);
  PalaBawahIseng(3);
  baca(2430, 3);
  waitAll(300);
  /////////////////////////////////////////////CaseC///////////////////////////////////////
  //ini zona C yang ada hadap hadapnya Zae sama juna mungkin bisa agak di variasi disini..."mungkin"
  PalaKanan(5);
  baca(2448, 5);
  dynamixel(1 , 7 , 150, 5);
  waitAll(500);
  PalaKiri(5);
  baca(2449, 5);
  waitAll(500);
  baca(2450, 5);
  dynamixel(1 , 7 , 210, 5);
  waitAll(500);
  PalaKanan(5);
  baca(2451, 5);
  waitAll(500);
  PalaDefault(5);
  baca(2334, 5); //ini TanganDepanC
  dynamixel(1 , 7 , 180, 5);
  waitAll(500);
  /////////////////////////////////////////////////CaseD//////////////////////////////////
  //ini yang angkat apalah itu
  //kekanan dulu
  dynamixel(1, 7, 180, 2);
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2381, 4);
  baca(2139, 5);
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);


  //////////////////////////////////////////////////////////////CaseE/////////////////////////
  //ke kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2384, 4);
  baca(2143, 5);
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  waitAll(800);

  /////////////////////////////////////////////////CaseF////////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2551, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2552, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2551, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2552, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);


  ////////////////////////////////////////////////CaseG/////////////////////////////////////
  baca(2519, IAMSPEED);
  waitAll(IAMTIME);
  baca(2553, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2554, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2553, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2554, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2555, IAMSPEED);
  PalaBawah(IAMSPEED);
  waitAll(IAMTIME);

  ///////////////////////////////////////////////CaseH/////////////////////////////////////////
  baca(2557, IAMSPEED);
  PalaAtas(IAMSPEED);
  waitAll(IAMTIME);
  baca(2519, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2558, IAMSPEED);
  waitAll(IAMTIME);
  baca(2334, IAMSPEED);
  waitAll(IAMTIME);

  ////////////////////////////////////////////////CaseI//////////////////////////////
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);
  ///////////////////////////////////////CaseJ///////////////////////////////////////
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);
  ////////////////////////////////////////CaseK//////////////////////////////////////

  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 7.5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 7.5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, 5);
  waitAll(750);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  baca(2559, 5);
  waitAll(500);

  ////////////////////////////////////////CaseL//////////////////////////////////////

  baca(3324, IAMSPEED);
  waitAll(IAMTIME);
  baca(3325, IAMSPEED);
  waitAll(IAMTIME);
  baca(3326, IAMSPEED);
  waitAll(IAMTIME);
  baca(3329, IAMSPEED); //27
  waitAll(IAMTIME);
  baca(3328, IAMSPEED);
  waitAll(IAMTIME);
  baca(3328, IAMSPEED);
  waitAll(IAMTIME);
  baca(3329, IAMSPEED);
  waitAll(IAMTIME);
  baca(3330, IAMSPEED);
  waitAll(IAMTIME);
  baca(3331, IAMSPEED);
  waitAll(IAMTIME);
  baca(3332, IAMSPEED);
  waitAll(IAMTIME);

}

void ZonaCDiemBaruCaseA() {
  ///////////////////////////////////////////////////CaseA//////////////////////////////////////////////
  TanganDepanC();
  tPa = 0;
  tPi = 0;
  tKa = -8;  //-13.5 hips
  tKi = 8;   //-13.5 hips
  pi = -10; // -12 roll angkle kiri
  pa = -8; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaMiringKiri(5);
  baca(2338, 5);
  waitAll(500);
  tPa = 0;
  tPi = 0;
  tKa = 8;  //-13.5 hips
  tKi = -8;   //-13.5 hips
  pi = 8; // -12 roll angkle kiri
  pa = 10; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaMiringKanan(5);
  baca(2339, 5);
  waitAll(500);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(5);
  TanganDepanC();
}

void ZonaCDiemBaruCaseB() {
  float IAMSPEED = 3;
  float IAMTIME = 300;
  //////////////////////////////////////////CaseB////////////////////////////////////
  //ini dadah 6 step
  dynamixel(1 , 7 , 180, IAMSPEED);
  PalaDefault(IAMSPEED);
  baca(3157, IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(1);
  Wire1.endTransmission();
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3158, IAMSPEED);
  waitAll(IAMTIME);
  PalaKanan(IAMSPEED);
  baca(3159, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3160, IAMSPEED);
  waitAll(IAMTIME);
  PalaKanan(IAMSPEED);
  baca(3161, IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(3162, IAMSPEED);
  waitAll(IAMTIME);
}

void ZonaCDiemBaruCaseC() {
  /////////////////////////////////////////////CaseC///////////////////////////////////////
  //ini zona C yang ada hadap hadapnya Zae sama juna mungkin bisa agak di variasi disini..."mungkin"
  //
  PalaKiri(5);
  baca(2450, 5);
  dynamixel(1 , 7 , 150, 5);
  Wire1.beginTransmission(8);
  Wire1.write(24); //kuning
  Wire1.endTransmission();
  waitAll(500);
  //
  PalaKanan(5);
  baca(2451, 5);
  waitAll(500);
  //
  baca(2448, 5);
  dynamixel(1 , 7 , 210, 5);
  Wire1.beginTransmission(8);
  Wire1.write(24); //kuning
  Wire1.endTransmission();
  waitAll(500);
  //
  PalaKiri(5);
  baca(2449, 5);
  waitAll(500);
  //
  PalaDefault(5);
  baca(2334, 5); //ini TanganDepanC
  dynamixel(1 , 7 , 180, 5);
  waitAll(500);
}

void ZonaCDiemBaruCaseD() {
  /////////////////////////////////////////////////CaseD//////////////////////////////////
  //ini yang angkat apalah itu
  //kekanan dulu
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2381, 4);
  baca(2139, 5);
  Wire1.beginTransmission(8);
  Wire1.write(30);
  Wire1.endTransmission();
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2136, 5);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(500);
}

void ZonaCDiemBaruCaseE() {

  ////////////////////////////////////////////////CaseE/////////////////////////
  //ke kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);

  baca(2384, 4);
  baca(2143, 5);
  Wire1.beginTransmission(8);
  Wire1.write(30);
  Wire1.endTransmission();
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 5, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, 5, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(800);
}

void ZonaCDiemBaruCaseF() {
  /////////////////////////////////////////////////CaseF////////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  baca(2551, IAMSPEED);
  PalaMiringKanan(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);
  Wire1.beginTransmission(8);
  Wire1.write(38);//cyan
  Wire1.endTransmission();
  baca(2552, IAMSPEED);
  PalaMiringKiri(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);

  baca(2551, IAMSPEED);
  PalaMiringKanan(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = 9;  //-13.5 hips
  tKi = -9;   //-13.5 hips
  pi = 9; // -12 roll angkle kiri
  pa = 11; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);

  baca(2552, IAMSPEED);
  PalaDefault(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);

}

void ZonaCDiemBaruCaseG() {
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  ////////////////////////////////////////////////CaseG/////////////////////////////////////
  baca(2519, IAMSPEED);
  waitAll(IAMTIME);
  baca(2553, IAMSPEED);
  PalaMiringKiri(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);
  Wire1.beginTransmission(8);
  Wire1.write(31);
  Wire1.endTransmission();
  
  baca(2554, IAMSPEED);
  PalaMiringKanan(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);

  baca(2553, IAMSPEED);
  PalaMiringKiri(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = -9;  //-13.5 hips
  tKi = 9;   //-13.5 hips
  pi = -11; // -12 roll angkle kiri
  pa = -9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);

  baca(2554, IAMSPEED);
  PalaDefault(IAMSPEED);
  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0 , -0.5);//langkah terakhir zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0 , -0.5);
  waitAll(IAMTIME);

  baca(2555, IAMSPEED);
  PalaBawah(IAMSPEED);
  waitAll(IAMTIME);

}

void ZonaCDiemBaruCaseH() {
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  ///////////////////////////////////////////////CaseH/////////////////////////////////////////
  dynamixel(1, 7, 150, IAMSPEED); //di juna nanti 210 cuma dynamixel ini doang
  baca(2557, IAMSPEED);
  PalaAtas(IAMSPEED);
  waitAll(IAMTIME);
  baca(2519, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2558, IAMSPEED);
  PalaBawah(IAMSPEED);
  waitAll(IAMTIME);
  baca(2334, IAMSPEED);
  //  dynamixel(1, 7, 180, 9);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
}

void ZonaCDiemBaruCaseI() {
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  ////////////////////////////////////////////////CaseI//////////////////////////////
  dynamixel(1, 7, 180, IAMSPEED);
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  dynamixel(1, 7, 210, IAMSPEED);
  baca(2560, IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(37);
  Wire1.endTransmission();
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKanan(IAMSPEED);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, IAMSPEED);
  PalaBawah(IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKanan(IAMSPEED);
  baca(2560, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  baca(2560, IAMSPEED);
  PalaBawah(IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(IAMTIME);
}

void ZonaCDiemBaruCaseJ() {
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  ///////////////////////////////////////CaseJ///////////////////////////////////////
  dynamixel(1, 7, 180, IAMSPEED);
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  dynamixel(1, 7, 150, IAMSPEED);
  baca(2561, IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(1);
  Wire1.endTransmission();
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKiri(IAMSPEED);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaBawah(IAMSPEED);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKiri(IAMSPEED);
  baca(2561, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaBawah(IAMSPEED);
  baca(2561, IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(IAMTIME);

}

void ZonaCDiemBaruCaseK() {
  ////////////////////////////////////////CaseK//////////////////////////////////////
  float IAMSPEED = 4.5;
  float IAMTIME = 450;
  dynamixel(1, 7, 180, IAMSPEED);
  baca(2559, IAMSPEED);
  waitAll(IAMTIME);
  baca(2562, IAMSPEED);
  Wire1.beginTransmission(8);
  Wire1.write(2);
  Wire1.endTransmission();
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = -11;  //-13.5 hips
  tKi = 11;   //-13.5 hips
  pi = -9; // -12 roll angkle kiri
  pa = -7; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKiri(IAMSPEED);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  tPa = 0;
  tPi = 0;
  tKa = 11;  //-13.5 hips
  tKi = -11;   //-13.5 hips
  pi = 7; // -12 roll angkle kiri
  pa = 9; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, 7.5, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, 7.5, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaKanan(IAMSPEED);
  baca(2562, 5);
  waitAll(750);

  tPa = 0;
  tPi = 0;
  tKa = 0;  //-13.5 hips
  tKi = 0;   //-13.5 hips
  pi = 0; // -12 roll angkle kiri
  pa = 0; // -17 roll angkle kanan
  tjKi = 0; //-2 pitch angkle kiri
  tjKa = 0;//0 pitch angkle kanan

  invers(KANAN, IAMSPEED, Xt - 3.06 + 2.5, 16.6, 0, -0.5); //langkah terakhir Zae
  invers(KIRI, IAMSPEED, sfX - 3.06 + 2.5, 16.6, 0, -0.5);
  PalaBawah(IAMSPEED);
  baca(2562, IAMSPEED);
  waitAll(IAMTIME);

  PalaDefault(IAMSPEED);
  baca(2559, 5);
  Wire1.beginTransmission(8);
  Wire1.write(0);
  Wire1.endTransmission();
  waitAll(500); //ini timing buat ngepasin ending
  //CEK INI WOY
}

void ZonaCDiemBaruCaseL() {
  ////////////////////////////////////////CaseL//////////////////////////////////////
  dynamixel(1, 7, 195, 4);
  baca(2389, 2.5);
  baca(2134, 4);
  waitAll(400);

  dynamixel(1, 7, 165, 4);
  baca(2388, 2.5);
  baca(2135, 4);
  waitAll(400);

  dynamixel(1, 7, 195, 4);
  baca(2389, 2.5);
  baca(2134, 4);
  waitAll(400);

  dynamixel(1, 7, 165, 4);
  baca(2388, 2.5);
  baca(2135, 4);
  waitAll(400);
  dynamixel(1, 7, 180, 5);
  PalaDefault(5);
  Wire1.beginTransmission(8);
  Wire1.write(30);
  Wire1.endTransmission();
  TanganDepanC();
  //  float IAMSPEED=3;
  //  float IAMTIME=300;
  //  baca(3324, IAMSPEED);
  //  waitAll(IAMTIME);//1
  //  baca(3325, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3326, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3329, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3328, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3328, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3329, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3330, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3331, IAMSPEED);
  //  waitAll(IAMTIME);
  //  baca(3332, IAMSPEED);
  //  waitAll(IAMTIME);//10
}

void ZonaCDiem2() {
  ///////////////////////////////////////////////CaseA///////////////////////////////////////
  //kiri
  float IAMSPEED = 2.5; //ada sekitar 30
  float IAMTIME = 250;
  baca(2574, IAMSPEED);
  PalaKiriPol(IAMSPEED);
  waitAll(IAMTIME);
  baca(2573, IAMSPEED);
  waitAll(IAMTIME);
  baca(2574, IAMSPEED);
  waitAll(IAMTIME);
  baca(2573, IAMSPEED);
  waitAll(IAMTIME);
  baca(2585, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2586, IAMSPEED);
  waitAll(IAMTIME);
  baca(2587, IAMSPEED);
  waitAll(IAMTIME);
  baca(2588, IAMSPEED);
  waitAll(IAMTIME);
  baca(2589, IAMSPEED);
  waitAll(IAMTIME);
  baca(2590, IAMSPEED);
  waitAll(IAMTIME);
  baca(2591, IAMSPEED);
  waitAll(IAMTIME);
  baca(2593, IAMSPEED);
  waitAll(IAMTIME);
  baca(2594, IAMSPEED);
  waitAll(IAMTIME);
  /////////////////////////////////////////////////////////CaseB////////////////////////////////////
  //transisi
  baca(2595, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(2597, IAMSPEED);
  waitAll(IAMTIME);
  //kanan
  baca(2583, IAMSPEED);
  PalaKananPol(IAMSPEED);
  waitAll(IAMTIME);
  baca(2582, IAMSPEED);
  waitAll(IAMTIME);
  baca(2583, IAMSPEED);
  waitAll(IAMTIME);
  baca(2582, IAMSPEED);
  waitAll(IAMTIME);
  baca(2599, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2601, IAMSPEED);
  waitAll(IAMTIME);
  baca(2602, IAMSPEED);
  waitAll(IAMTIME);
  baca(2603, IAMSPEED);
  waitAll(IAMTIME);
  baca(2604, IAMSPEED);
  waitAll(IAMTIME);
  baca(2605, IAMSPEED);
  waitAll(IAMTIME);
  baca(2606, IAMSPEED);
  waitAll(IAMTIME);
  baca(2607, IAMSPEED);
  waitAll(IAMTIME);
  ////////////////////////////////////////////////////////CaseC//////////////////////////////////
  baca(2595, IAMSPEED); //ini transisi
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2334, IAMSPEED); //ini tangan depan c
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(2136, IAMSPEED);
  waitAll(500);
  /////////////////////////////////////////////////CaseD//////////////////////////////////
  //kanan
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2381, 4);
  baca(2139, 5);
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);
  //////////////////////////////////////////////////////////////CaseE/////////////////////////
  //kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2384, 4);
  baca(2143, 5);
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  waitAll(800);
}

void ZonaCDiem2CaseA() {
  ///////////////////////////////////////////////CaseA///////////////////////////////////////
  //kiri
  float IAMSPEED = 3; //ada sekitar 30
  float IAMTIME = 300;
  baca(2574, IAMSPEED);
  PalaKiriPol(IAMSPEED);
  waitAll(IAMTIME);
  baca(2573, IAMSPEED);
  waitAll(IAMTIME);
  baca(2574, IAMSPEED);
  waitAll(IAMTIME);
  baca(2573, IAMSPEED);
  waitAll(IAMTIME);
  baca(2585, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2586, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2587, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2588, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2589, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2590, IAMSPEED);
  transisiKananBawah(IAMSPEED);
  //pala agak ke kanan bawah
  waitAll(IAMTIME);
  baca(2591, IAMSPEED);
  transisiKanan(IAMSPEED);
  //pala agak ke kanan
  waitAll(IAMTIME);
  baca(2593, IAMSPEED);
  transisiKananBawah(IAMSPEED);
  //pala agak ke kanan bawah
  waitAll(IAMTIME);
  baca(2594, IAMSPEED);
  transisiKanan(IAMSPEED);
  //pala agak ke kanan
  waitAll(IAMTIME);
}

void ZonaCDiem2CaseB() {
  float IAMSPEED = 3;
  float IAMTIME = 300;
  /////////////////////////////////////////////////////////CaseB////////////////////////////////////
  //transisi
  baca(2595, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  PalaBawah(IAMSPEED);
  baca(2597, IAMSPEED);
  waitAll(IAMTIME);
  //kanan
  baca(2583, IAMSPEED);
  PalaKananPol(IAMSPEED);
  waitAll(IAMTIME);
  baca(2582, IAMSPEED);
  waitAll(IAMTIME);
  baca(2583, IAMSPEED);
  waitAll(IAMTIME);
  baca(2582, IAMSPEED);
  waitAll(IAMTIME);
  baca(2599, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2601, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2602, IAMSPEED);
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2603, IAMSPEED);
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  baca(2604, IAMSPEED);
  transisiKiriBawah(IAMSPEED);
  waitAll(IAMTIME);
  baca(2605, IAMSPEED);
  transisiKiri(IAMSPEED);
  waitAll(IAMTIME);
  baca(2606, IAMSPEED);
  transisiKiriBawah(IAMSPEED);
  waitAll(IAMTIME);
  baca(2607, IAMSPEED);
  transisiKiri(IAMSPEED);
  waitAll(IAMTIME);
}

void ZonaCDiem2CaseC() {
  float IAMSPEED = 3;
  float IAMTIME = 300;
  ////////////////////////////////////////////////////////CaseC//////////////////////////////////
  baca(2595, IAMSPEED); //ini transisi
  PalaBawahIseng(IAMSPEED);
  waitAll(IAMTIME);
  baca(2334, IAMSPEED); //ini tangan depan c
  PalaDefault(IAMSPEED);
  waitAll(IAMTIME);
  PalaDefault(IAMSPEED);
  baca(2136, IAMSPEED);
  waitAll(500);
}

void ZonaCDiem2CaseD() {
  /////////////////////////////////////////////////CaseD//////////////////////////////////
  //kanan
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2137, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2381, 4);
  baca(2139, 5);
  waitAll(500);

  baca(2388, 4);
  baca(2140, 5);
  waitAll(500);

  baca(2382, 4);
  baca(2141, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);
}

void ZonaCDiem2CaseE() {
  //////////////////////////////////////////////////////////////CaseE/////////////////////////
  //kiri
  PalaAtas(2);
  //  baca(2393, 1);
  baca(2142, 2);
  waitAll(200);

  PalaDefault(4);
  baca(2136, 5);
  waitAll(500);

  baca(2384, 4);
  baca(2143, 5);
  waitAll(500);

  baca(2389, 4);
  baca(2144, 5);
  waitAll(500);

  baca(2385, 4);
  baca(2145, 5);
  waitAll(500);

  PalaDefault(4);
  baca(2334, 5); //ini tangan depanC
  waitAll(800);
}



void SalamPenutupB() {

  PalaDefault(4);
  baca(2326, 5);
  waitAll(500);

  invers(KIRI, 7, 0, 8, 0, 0);
  invers(KANAN, 7, 0, 8, 0, 0);
  baca(2327, 5);
  waitAll(700);
  torqueOoOoff(3);
  torqueOoOoff(13);

  baca(2343, 4);
  waitHand(400);

  baca(2344, 3);
  waitHand(300);

  //tangan kanan atas
  baca(2389, 2);
  baca(2345, 3);
  waitAll(300);

  //tangan kiri atas
  dynamixel(1 , 7 , 150, 3);
  //  baca(2388, 2);
  PalaKananAkhir(2);
  baca(2346, 3);
  Wire1.beginTransmission(8);
  Wire1.write(30);
  Wire1.endTransmission();
  waitAll(300);
}


void TanganDepanB(int n) {
  dynamixel(2, 36, KIRI36 - 80, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 70, n); //+buka

  dynamixel(2, 21, KANAN21 + 75, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 4, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 90, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 97, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 80, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 12, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 95, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}



//=============================================================================================================================
//==================================================batas lama dan baru========================================================
//=============================================================================================================================


void pasangMasker() {
  stepcuci(10); //ngakali step nya juna
  waitAll(1000);
  pasang1(10);
  waitAll(1000);
  pasang2(10);
  waitAll(1000);
  masker(51, 295);
}
void lepasMasker() {
  stepcuci(10); //ngakali step nya juna
  waitAll(1000);
  pasang1(10);
  waitAll(1000);
  pasang2(10);
  waitAll(1000);
  masker(51, 180);
}
void cuciKiri() {
  ////cuci kiri
  int ka = 6, uu = 600; //tadinya waktu 1 detik
  CuciPunggung5(ka);
  PalaDefault(ka); //ini ditambahin ove
  waitAll(uu);
  Cuci1(ka);
  waitAll(uu);
  Cuci2(ka);
  waitAll(uu);
  Cuci1(ka);
  waitAll(uu);
  Cuci3(ka);
  waitAll(uu);
  //  Cuci1(ka);
  //  waitAll(uu);
  //  Cuci2(ka);
  //  waitAll(uu);
  //  Cuci1(ka);
  //  waitAll(uu);
  //  Cuci3(ka);
  //  waitAll(uu);
  //  Cuci1(ka);
  //  waitAll(uu);
}
void cuciPunggungTangan() {
  //punggung tangan
  int ki = 6 , ta = 600;
  dynamixel(1, 7, 130, ki);
  CuciPunggung1(ki);
  PalaBawah(ki); //ditambahin ove
  waitAll(ta);
  CuciPunggung2(ki);
  waitAll(ta);
  CuciPunggung1(ki);
  waitAll(ta);
  CuciPunggung2(ki);
  waitAll(ta);
  CuciPunggung1(ki);
  dynamixel(1, 7, 180, ki);
  PalaDefault(ki);
  waitAll(ta);
  //  CuciPunggung5(ki);
  //  dynamixel(1,7,180,ki);
  //  PalaDefault(ki);
  //  waitAll(ta);
  //  CuciPunggung4(ki);
  //  waitAll(ta);
  //  CuciPunggung3(ki);
  //  waitAll(ta);
  //  CuciPunggung4(ki);
  //  waitAll(ta);
  //  CuciPunggung3(ki);
  //  waitAll(ta);
  //  dynamixel(1,7,180,ki);
  //  PalaDefault(ki);
  //  CuciPunggung4(ki);
  //  waitAll(ta);
}
void cuciTangan() {
  ////cuci kiri
  baca(601, 10);
  waitAll(1000);
  baca(603, 10);
  waitAll(1000);
  baca(604, 10);
  waitAll(1000);
  baca(603, 10);
  waitAll(1000);
  baca(614, 10);
  waitAll(1000);
  baca(603, 10);
  waitAll(1000);
  baca(604, 10);
  waitAll(1000);
  baca(603, 5);
  waitAll(500);
  baca(614, 5);
  waitAll(500);
  baca(603, 10);
  waitAll(1000);

  //punggung tangan
  baca(651, 10);
  waitAll(1000);
  baca(652, 10);
  waitAll(1000);
  baca(653, 10);
  waitAll(1000);
  baca(651, 10);
  waitAll(1000);
  baca(652, 10);
  waitAll(1000);
  baca(654, 10);
  waitAll(1000);
  baca(651, 10);
  waitAll(1000);

}
void pembukaCaseA() {
  baca(664, 10);
  PalaDefault(10); //ini yang ditambahin ove
  waitAll(1000);
  baca(663, 10);//initransisi
  waitAll(1000);
  baca(668, 10);
  PalaKanan(10); //ini yang ditambahin ove
  waitAll(1000);
  baca(669, 10);
  waitAll(1000);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  KananAtas(10);  //ini yang diganti ove
  transmitPulsa();
  transmitPulsaXL();
  baca(670, 10);
  waitAll(1000);

  tjKa = 4.5; //3.5
  tjKi = 4.5;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, -0.5);
  transmitPulsa();
  transmitPulsaXL();
  baca(669, 10);
  waitAll(1000);
}
void pembukaCaseB() {
  baca(662, 10);
  PalaKanan(10); //ini yang ditambahin ove
  waitAll(1000);
  baca(663, 10);
  PalaDefault(10); //ini yang ditambahin ove
  waitAll(1000);
  baca(664, 10);
  waitAll(1000);
  PalaKiri(1000); //ini yang ditambahin ove
  baca(666, 10);
  waitAll(1000);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  KiriAtas(10); //ini yang diganti ove
  transmitPulsa();
  transmitPulsaXL();
  baca(667, 10);
  waitAll(1000);

  tjKa = 4.5; //3.5
  tjKi = 4.5;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, -0.5);
  //  PalaDefault(10); //diilangin ove
  transmitPulsa();
  transmitPulsaXL();
  baca(666, 10);
  waitAll(1000);

  baca(664, 10);
  PalaKiri(10); // ini ditambahin ove
  waitAll(1000);
  //  baca(663, 10);
  TanganDepan(10);
  PalaDefault(10); //ditambahin ove
  waitAll(1000);
}
void pembukaCaseC() {
  tjKa = 2;
  tjKi = 2;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(8);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(800);

  tjKa = 3.5; //2.5
  tjKi = 3.5;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -0.5);
  PalaDefault(8);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(800);

  tjKa = 0;
  tjKi = 0;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -0.2);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -0.2);

  transmitPulsa();
  waitAll(800);
}
void pembukaU() {
  baca(662, 10);
  waitAll(1000);
  baca(663, 10);
  waitAll(1000);
  baca(664, 10);
  waitAll(1000);
  baca(666, 10);
  waitAll(1000);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(666, 10);
  waitAll(1000);

  tjKa = 3.5; //3.5
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, -0.5);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(667, 10);
  waitAll(1000);

  baca(664, 10);
  waitAll(1000);
  baca(663, 10);
  waitAll(1000);
  baca(668, 10);
  waitAll(1000);
  baca(669, 10);
  waitAll(1000);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(670, 10);
  waitAll(1000);

  tjKa = 3.5; //3.5
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, -0.5);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(669, 10);
  waitAll(1000);


  baca(668, 10);
  waitAll(1000);
  //  baca(663, 10);
  TanganDepan(10);
  waitAll(1000);

  tjKa = 2;
  tjKi = 2;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(8);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(800);

  tjKa = 2.5; //2.5
  tjKi = 2;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -0.5);
  PalaDefault(8);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(800);

  tjKa = 0;
  tjKi = 0;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -0.2);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -0.2);

  transmitPulsa();

  waitAll(800);

}
void nundukKananKiriCaseA() {
  int ka = 6, mu = 800;
  baca(757, ka);
  PalaBawah(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(757, ka);
  PalaBawah(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
}
void nundukKananKiriCaseB() {
  int ka = 6, mu = 800;
  LintangSamping1(ka);
  PalaKanan(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
  LintangSamping1(ka);
  PalaKiri(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
}
void lambaiKanan() {
  baca(702, 10);
  waitAll(1000);

  //lambai kanan
  baca(705, 10);
  waitAll(1000);
  baca(707, 10);
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  KananBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);

  baca(705, 10);
  waitAll(1000);

  tjKa = 4;
  tjKi = 4;
  baca(702, 10);
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);
}
void lambaiKiri() {
  //lambai kiri
  baca(703, 10);
  waitAll(1000);
  baca(704, 10);
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  KiriBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);
  baca(703, 10);
  waitAll(1000);

  baca(702, 10);
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);
  ///////////////////////////lambai kiri selesai
}
void miringKanan() {
  dynamixel(1 , 7 , 150, 10);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  PalaKanan(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);
}
void lambaiKiriKanan() {
  baca(702, 10);
  waitAll(1000);

  //lambai kanan
  baca(705, 10);
  waitAll(1000);
  baca(707, 10);
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  KananBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);
  baca(705, 10);
  waitAll(1000);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(702, 10);
  waitAll(1000);
  ///lambai kanan selesai

  //lambai kiri
  baca(703, 10);
  waitAll(1000);
  baca(704, 10);
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  KiriBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);
  baca(703, 10);
  waitAll(1000);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(702, 10);
  waitAll(1000);
  ///////////////////////////lambai kiri selesai


  /////miring kanan
  dynamixel(1 , 7 , 150, 10);
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 10, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 14, 0, 0);
  PalaKanan(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);


  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(1000);

}
////////mundurbadan////////////////
void mundurBadanBoongan() {
  //mundurin badan
  tjKa = 0; //+ badan kebelakang
  tjKi = 0;
  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
}
void mundurBadanGanti() {
  //mundurin badan
  tjKa = 4; //+ badan kebelakang
  tjKi = 4;
  invers(KIRI, 6, -3 - 3.06, 16.6, 0, -0.3);
  invers(KANAN, 6, 3 - 3.06, 16.6, 0, -0.3);
  transmitPulsa();
}
void mundurBadan() {
  //mundurin badan
  tjKa = 6; //+ badan kebelakang
  tjKi = 6;
  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
}
void terbangLintangCaseA() {
  transmitPulsaXLPunch(20);
  int ak = 3.8, ku = 380;
  ////////////
  baca(752, ak);
  PalaDefault(ak);
  waitAll(ku);
  baca(753, ak);
  waitAll(ku);
  baca(755, ak);
  waitAll(ku);
  baca(757, ak);
  waitAll(ku);
  ////////////
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);

  tjKa = 5;
  tjKi = 5.5;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(759, 3.8);
  waitAll(800);
}
void terbangLintangCaseB() {
  int ak = 3.8, ku = 380;
  baca(772, ak);
  PalaDefault(10);
  waitAll(ku);
  baca(2, ak);
  waitAll(ku);
  baca(772, ak);
  waitAll(ku);
  baca(759, ak);
  waitAll(ku);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);


  //Kepala ke kanan atas, tangan ke kanan atas
  tjKa = 5;
  tjKi = 5.5;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  KananAtas(10);//
  transmitPulsa();
  transmitPulsaXL();
  baca(774, 3.8);
  waitAll(800);
}
void terbangLintangCaseC() {
  int ak = 3.8, ku = 380;
  baca(4, ak);
  waitAll(ku);
  baca(774, ak);
  waitAll(ku);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);

  //kepala ke kiri atas, tangan kiri atas
  tjKa = 5;
  tjKi = 5.5;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  KiriAtas(10);//
  transmitPulsa();
  transmitPulsaXL();
  baca(773, 3.8);
  waitAll(800);
}
void terbangLintangCaseD() {
  int ak = 3.8, ku = 380;
  baca(3, ak);
  waitAll(ku);
  baca(773, ak);
  waitAll(ku);
  //////////////

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);

  tjKa = 5;
  tjKi = 5.5;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(800);

  //   tjKa=0;
  //   tjKi=0;
  //   invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  //   invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  //   PalaDefault(10);
  //   transmitPulsa();
  //   transmitPulsaXL();
  waitAll(800);
}

void terbangLintang() {
  //mundurin badan
  tjKa = 5; //+ badan kebelakang
  tjKi = 5;

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();


  ////terbanglintang
  transmitPulsaXLPunch(20);
  int ak = 3.8, ku = 380;
  ////////////
  baca(752, ak);
  PalaDefault(10);
  waitAll(ku);
  baca(753, ak);
  waitAll(ku);
  baca(755, ak);
  waitAll(ku);
  baca(757, ak);
  waitAll(ku);
  ////////////
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);


  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(759, 3.8);
  waitAll(800);
  ///////////////
  baca(772, ak);
  PalaDefault(10);
  waitAll(ku);
  baca(2, ak);
  waitAll(ku);
  baca(772, ak);
  waitAll(ku);
  baca(759, ak);
  waitAll(ku);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);


  //Kepala ke kanan atas, tangan ke kanan atas
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  KananAtas(10);//
  transmitPulsa();
  transmitPulsaXL();
  baca(774, 3.8);
  waitAll(800);

  baca(4, ak);
  waitAll(ku);
  baca(774, ak);
  waitAll(ku);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);

  //kepala ke kiri atas, tangan kiri atas
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  KiriAtas(10);//
  transmitPulsa();
  transmitPulsaXL();
  baca(773, 3.8);
  waitAll(800);

  baca(3, ak);
  waitAll(ku);
  baca(773, ak);
  waitAll(ku);
  //////////////

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  PalaBawah(10);
  transmitPulsa();
  transmitPulsaXL();
  baca(758, 3.8);
  waitAll(800);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 10, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 10, 3 - 3.06, 16.6, 0, 0);
  PalaDefault(10);
  transmitPulsa();
  transmitPulsaXL();
  waitAll(800);

  //  tjKa=0;
  //  tjKi=0;
  //  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  //  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  //  PalaDefault(10);
  //  transmitPulsa();
  //  transmitPulsaXL();
  waitAll(800);
}
void ngajatCaseA() {
  int ka = 3.8, mu = 380;
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(514, ka);
  KiriBawah(ka); //tadinya kananBawah
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);

  //badan miring kanan
  dynamixel(1 , 7 , 150, 10);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(517, ka);
  KananAtas(ka); //tadinya KiriAtas
  waitAll(800);

  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(512, ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 7.5;
  tjKi = 7.5;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(514, ka);
  PalaDefault(ka);
  waitAll(800);
}
void ngajatCaseB() {
  int ka = 3.8, mu = 380;
  //badan miring kiri
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(514, ka);
  KiriBawah(ka); //tadinya KananBawah
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);

  dynamixel(1 , 7 , 210, 10);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(517, ka); //
  KiriAtas(ka); //tadinya KananAtas
  waitAll(800);

  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(512, ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 7.5;
  tjKi = 7.5;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(514, ka);
  PalaDefault(ka);
  waitAll(800);
}
void ngajat() {
  int ka = 3.8, mu = 380;
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(514, ka);
  KiriBawah(ka); //tadinya kananBawah
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);

  //badan miring kanan
  dynamixel(1 , 7 , 150, 10);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(517, ka);
  KananAtas(ka); //tadinya KiriAtas
  waitAll(800);

  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(512, ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(514, ka);
  PalaDefault(ka);
  waitAll(800);

  //badan miring kiri
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(514, ka);
  KiriBawah(ka); //tadinya KananBawah
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);
  baca(512, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);

  dynamixel(1 , 7 , 210, 10);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(517, ka); //
  KiriAtas(ka); //tadinya KananAtas
  waitAll(800);

  baca(516, ka);
  PalaAtas(ka);
  waitAll(mu);
  baca(515, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(512, ka);
  waitAll(mu);
  baca(513, ka);
  PalaBawah(ka);
  waitAll(mu);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(514, ka);
  PalaDefault(ka);
  waitAll(800);
}
void lambaiDepan() {
  //lambai depan
  baca(746, 10);
  waitAll(1000);
  baca(747, 10);
  waitAll(1000);
  baca(748, 10);
  waitAll(1000);
  baca(747, 10);
  waitAll(1000);
  baca(748, 10);
  waitAll(1000);
  baca(747, 10);
  waitAll(1000);
  baca(748, 10);
  waitAll(1000);
  baca(747, 10);
  waitAll(1000);
  baca(746, 10);
  waitAll(1000);
}
void dorongLambaiCaseA() {
  //ini gerakan di zonC
  tjKa = 4; //+ badan kebelakang
  tjKi = 4;

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();

  //ini kanan
  ///diganti ove pewaktuannya
  int ak = 5 , ku = 500;  //tadinya 6
  baca(118, ak);
  PalaKanan(ak);
  waitAll(ku);
  baca(121, ak);
  KananBawah(ak);
  waitAll(ku);
  baca(118, ak);
  PalaKanan(ak);
  waitAll(ku);
  baca(121, ak);
  KananBawah(ak);
  waitAll(ku);
  TanganDepan(ak);
  PalaDefault(ak);
  waitAll(ku);
}
void dorongLambaiCaseB() {
  //waktunya ove ganti
  //ini kiri
  int ak = 5 , ku = 500; //tadinya 6
  baca(111, ak);
  PalaKiri(ak);
  waitAll(ku);
  baca(112, ak);
  KiriBawah(ak);
  waitAll(ku);
  baca(111, ak);
  PalaKiri(ak);
  waitAll(ku);
  baca(112, ak);
  KiriBawah(ak);
  waitAll(ku);
  TanganDepan(ak);
  PalaDefault(ak); //ove tambahin
  waitAll(ku);
}
void doronglambai() {
  //ini gerakan di zonC
  tjKa = 5; //+ badan kebelakang
  tjKi = 5;

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();

  //ini kanan
  baca(118, 10);
  PalaKanan(10);
  waitAll(1000);
  baca(121, 10);
  KananBawah(10);
  waitAll(1000);
  baca(118, 10);
  PalaKanan(10);
  waitAll(1000);
  baca(121, 10);
  KananBawah(10);
  waitAll(1000);
  TanganDepan(10);
  waitAll(1000);

  //ini kiri
  baca(111, 10);
  PalaKiri(10);
  waitAll(1000);
  baca(112, 10);
  KiriBawah(10);
  waitAll(1000);
  baca(111, 10);
  PalaKiri(10);
  waitAll(1000);
  baca(112, 10);
  KiriBawah(10);
  waitAll(1000);
  TanganDepan(10);
  PalaDefault(10);
  waitAll(1000);
}
void lintangLintangCaseA() {
  //badan ntar goyang ngikut arah kepala
  int al = 6, fan = 600;
  //    TanganDepan(al);
  //    PalaDefault(al); //ditambahin ove
  //    waitAll(fan);

  //badan miring kanan
  dynamixel(1 , 7 , 150, 10);
  //  transmitPulsaMX();
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 14, 0, -0.3);
  invers(KIRI, 8, 3 - 3.06, 14, 0, -0.3);
  transmitPulsa();
  transmitPulsaXL();

  //ini kanan
  baca(764, al);
  PalaKiri(al);
  waitAll(fan);
  KiriBawah(6);
  waitAll(600);
  PalaKiri(6);
  waitAll(600);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 7.7;
  tjKi = 7.7;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(al);
  PalaDefault(al);
  waitAll(fan);
}
void lintangLintangCaseB() {
  int al = 6, fan = 600;
  //badan miring kiri
  dynamixel(1 , 7 , 210, 10);
  transmitPulsaMX();
  tjKa = 2.5;
  tjKi = 2.5;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0.3);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0.3);
  transmitPulsa();
  transmitPulsaXL();

  //ini kiri
  baca(763, al);
  PalaKanan(al);
  waitAll(fan);
  KananBawah(6);
  waitAll(600);
  PalaKanan(6);
  waitAll(600);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 5.7;
  tjKi = 5.7;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(al);
  PalaDefault(al);  //ini ditambah ove
  waitAll(fan);

  tjKa = 0;
  tjKi = 0;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, -0.5);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, -0.5);
  transmitPulsa();
  waitAll(800);
}
void lintangLintang() {
  //badan ntar goyang ngikut arah kepala
  int al = 15, fan = 1500;
  TanganDepan(al);
  waitAll(fan);

  //badan miring kanan
  dynamixel(1 , 7 , 150, 10);
  //  transmitPulsaMX();
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();

  //ini kanan
  baca(764, al);
  PalaKiri(al);
  waitAll(fan);
  KiriBawah(6);
  waitAll(600);
  PalaKiri(6);
  waitAll(600);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(al);
  waitAll(fan);

  //badan miring kiri
  dynamixel(1 , 7 , 210, 50);
  transmitPulsaMX();
  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();

  //ini kiri
  baca(763, al);
  PalaKanan(al);
  waitAll(fan);
  KananBawah(6);
  waitAll(600);
  PalaKanan(6);
  waitAll(600);

  dynamixel(1 , 7 , TENGAH7, 10);
  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(al);
  waitAll(fan);

  //ini buat persiapan jalan ngasai
  tjKa = 0;
  tjKi = 0;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  waitAll(800);
}
void penutupCaseA() {
  int ju = 5 , na = 500;
  //  tjKa=4;
  //  tjKi=4;
  //  invers(KIRI, 8, -3 - 3.06, 16.6, 0, -0);
  //  invers(KANAN, 8, 3 - 3.06, 16.6, 0, -0);
  //  transmitPulsa();

  tjKa = 2;
  tjKi = 2;
  invers(KIRI, 8, 0, 12, 0, 1);
  invers(KANAN, 8, 6, 12, 0, 1);
  transmitPulsa();
  transmitPulsaXL();
  baca(125, ju); //di juna 124, zae 125
  KiriBawah(ju);
  waitAll(na);

  tjKa = 1;
  tjKi = 1;
  invers(KIRI, 8, 0, 16.6, 0, 0);
  invers(KANAN, 8, 6, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(ju);
  PalaDefault(ju);    //ini ditambah ove
  waitAll(na);
}
void penutupCaseB() {
  int ju = 5 , na = 500;
  tjKa = 2;
  tjKi = 2;
  invers(KIRI, 8, 0, 12, 0, 1);
  invers(KANAN, 8, 6, 12, 0, 1);
  transmitPulsa();
  transmitPulsaXL();
  baca(126, ju); //ini tengah
  PalaBawah(ju);
  waitAll(na);

  tjKa = 1;
  tjKi = 1;
  invers(KIRI, 8, 0, 16.6, 0, 0);
  invers(KANAN, 8, 6, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(ju);
  PalaDefault(ju);
  waitAll(na);
}
void penutupCaseC() {
  int ju = 5 , na = 500;
  tjKa = 2;
  tjKi = 2;
  invers(KIRI, 8, 0, 12, 0, 1);
  invers(KANAN, 8, 6, 12, 0, 1);
  transmitPulsa();
  PalaBawah(ju);
  transmitPulsaXL();
  waitAll(na);


  tjKa = 2;
  tjKi = 2;
  invers(KIRI, 8, 0, 16.6, 0, 0);
  invers(KANAN, 8, 6, 16.6, 0, 0);
  transmitPulsa();
  PalaDefault(ju);
  transmitPulsaXL();
  waitAll(na);

}
void Penutup() {
  int ju = 10 , na = 1000;
  tjKa = 5; //+ badan kebelakang
  tjKi = 5;

  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(125, ju); //di juna 124, zae 125
  KiriBawah(ju);
  waitAll(na);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(ju);
  waitAll(na);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  baca(126, ju); //ini tengah
  PalaBawah(ju);
  waitAll(na);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  transmitPulsaXL();
  TanganDepan(ju);
  PalaDefault(ju);
  waitAll(na);

  tjKa = 3;
  tjKi = 3;
  invers(KANAN, 8, -3 - 3.06, 14, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 14, 0, 0);
  transmitPulsa();
  PalaBawah(ju);
  transmitPulsaXL();
  waitAll(na);

  tjKa = 4;
  tjKi = 4;
  invers(KANAN, 8, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 8, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  PalaDefault(ju);
  transmitPulsaXL();
  waitAll(na);
}
void cuciKiriAkhir() {
  ////cuci kiri
  int ka = 3.7, uu = 370; //tadinya waktu 1 detik
  CuciPunggung5(ka);
  PalaBawah(ka); //ini ditambahin ove
  waitAll(uu);
  Cuci1(ka);
  waitAll(uu);
  Cuci2(ka);
  waitAll(uu);
  Cuci1(ka);
  waitAll(uu);
  Cuci3(ka);
  waitAll(uu);
  Cuci1(ka);
  waitAll(uu);
  Cuci2(ka);
  waitAll(uu);
  Cuci1(ka);
  waitAll(uu);
  Cuci3(ka);
  waitAll(uu);
  Cuci1(ka);
  waitAll(uu);
}
void cuciPunggungTanganAkhir() {
  //punggung tangan
  int ki = 3.7 , ta = 370;
  dynamixel(1, 7, 130, ki);
  CuciPunggung1(ki);
  PalaBawah(ki); //ditambahin ove
  waitAll(ta);
  CuciPunggung2(ki);
  waitAll(ta);
  CuciPunggung1(ki);
  waitAll(ta);
  CuciPunggung2(ki);
  waitAll(ta);
  CuciPunggung1(ki);
  waitAll(ta);
  CuciPunggung5(ki);
  waitAll(ta);
  CuciPunggung4(ki);
  waitAll(ta);
  CuciPunggung3(ki);
  waitAll(ta);
  CuciPunggung4(ki);
  waitAll(ta);
  CuciPunggung3(ki);
  waitAll(ta);
  CuciPunggung4(ki);
  waitAll(ta);
  dynamixel(1, 7, 180, ki);
  CuciPunggung5(ki);
  waitAll(ta);

}

///////////////////gerakan lagu baru/////////////////
void nundukKananKiri() {
  int ka = 6, mu = 800;
  baca(757, ka);
  PalaBawah(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(757, ka);
  PalaBawah(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
  LintangSamping1(ka);
  PalaKanan(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
  LintangSamping1(ka);
  PalaKiri(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
}
void nundukTanganDepan() {
  int ka = 6, mu = 600;
  baca(757, ka);
  PalaBawah(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(757, ka);
  PalaBawah(ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);

  int ak = 3.8, ku = 380;
  defaultTangan(ak);
  waitAll(ku);
  baca(752, ak);
  PalaDefault(ak);
  waitAll(ku);
  baca(753, ak);
  waitAll(ku);
  baca(755, ak);
  waitAll(ku);
  baca(757, ak);
  waitAll(ku);
  PalaBawah(ak);
  waitAll(ku);
  TanganDepan(ak);
  PalaDefault(ak);
  waitAll(ku);
}
void kipasKiri() {
  int ak = 6, ku = 800;
  NekukKiri1(ak);
  PalaKiri(ak);
  waitAll(ku);
  NekukKiri2(ak);
  KiriBawah(ak);
  waitAll(ku);
  NekukKiri1(ak);
  PalaKiri(ak);
  waitAll(ku);
  NekukKiri2(ak);
  KiriBawah(ak);
  waitAll(ku);
  NekukKiri1(ak);
  PalaKiri(ak);
  waitAll(ku);
}
void kipasKanan() {
  int ak = 6, ku = 800;
  NekukKanan1(ak);
  PalaKanan(ak);
  waitAll(ku);
  NekukKanan2(ak);
  KananBawah(ak);
  waitAll(ku);
  NekukKanan1(ak);
  PalaKanan(ak);
  waitAll(ku);
  NekukKanan2(ak);
  KananBawah(ak);
  waitAll(ku);
  NekukKanan1(ak);
  PalaKanan(ak);
  waitAll(ku);
}
void kipasLintangKanan() {
  int ak = 6 , ku = 600;
  LintangKanan1(ak);
  PalaKiri(ak);
  waitAll(ku);
  LintangKanan2(ak);
  KiriBawah(ak);
  waitAll(ku);

  LintangKanan1(ak);
  PalaKiri(ak);
  waitAll(ku);
  LintangKanan2(ak);
  KiriBawah(ak);
  waitAll(ku);
}
void kipasLintangKiri() {
  int ak = 6, ku = 600;
  LintangKiri1(ak);
  PalaKanan(ak);
  waitAll(ku);
  LintangKiri2(ak);
  KananBawah(ak);
  waitAll(ku);

  LintangKiri1(ak);
  PalaKanan(ak);
  waitAll(ku);
  LintangKiri2(ak);
  KananBawah(ak);
  waitAll(ku);
}

//////paling baru/////
void naikKiri() {
  int ak = 5, ku = 500;
  NekukKiriB1(ak);
  PalaAtas(ak);
  waitAll(ku);
  NekukKiriB2(ak);
  PalaBawah(ak);
  waitAll(ku);
  NekukKiriC1(ak);
  PalaAtas(ak);
  waitAll(ku);
  NekukKiriC2(ak);
  PalaBawah(ak);
  waitAll(ku);
  NekukKiri1(ak);
  PalaKiri(ak);
  waitAll(ku);
  NekukKiri2(ak);
  KiriBawah(ak);
  waitAll(ku);
  TanganDepan(6);
  PalaDefault(6);
  waitAll(600);
}
void naikKanan() {
  int ak = 5, ku = 500;
  NekukKananB1(ak);
  PalaAtas(ak);
  waitAll(ku);
  NekukKananB2(ak);
  PalaBawah(ak);
  waitAll(ku);
  NekukKananC1(ak);
  PalaAtas(ak);
  waitAll(ku);
  NekukKananC2(ak);
  PalaBawah(ak);
  waitAll(ku);
  NekukKanan1(ak);
  PalaKanan(ak);
  waitAll(ku);
  NekukKanan2(ak);
  KananBawah(ak);
  waitAll(ku);
  stepcuci(6);
  waitAll(600);
  TanganDepan(6);
  PalaDefault(6);
  waitAll(600);
}
void tonjokKananKiri() {
  int ka = 7, mu = 700;
  TanganDepan(ka);
  waitAll(mu);
  baca(1003, ka);
  waitAll(mu);
  baca(1004, ka);
  KananAtas(ka);
  waitAll(mu);
  baca(1003, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(1005, ka);
  KananBawah(ka);
  waitAll(mu);
  baca(1003, ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);

  baca(1007, ka);
  waitAll(mu);
  baca(1009, ka);
  KiriAtas(ka);
  waitAll(mu);
  baca(1007, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(1010, ka);
  KiriBawah(ka);
  waitAll(mu);
  baca(1007, ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
}
void tonjokKiriKanan() {
  int ka = 7, mu = 700;
  baca(1007, ka);
  waitAll(mu);
  baca(1009, ka);
  KiriAtas(ka);
  waitAll(mu);
  baca(1007, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(1010, ka);
  KiriBawah(ka);
  waitAll(mu);
  baca(1007, ka);
  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);

  baca(1003, ka);
  waitAll(mu);
  baca(1004, ka);
  KananAtas(ka);
  waitAll(mu);
  baca(1003, ka);
  PalaDefault(ka);
  waitAll(mu);
  baca(1005, ka);
  KananBawah(ka);
  waitAll(mu);
  //  baca(1003, ka);
  //  waitAll(mu);
  TanganDepan(ka);
  PalaDefault(ka);
  waitAll(mu);
}

////tembak gerakan baru////////////////////
void LintangKanan1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 45, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 0, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 30, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI
}
void LintangKanan2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 45, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 0, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 30, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI
}
void LintangKiri1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 0, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 30, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 45, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void LintangKiri2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 0, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 30, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 45, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void LintangSamping1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void LintangSamping2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void LintangDepan1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 0, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 0, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void LintangDepan2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 0, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 0, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void NekukKanan1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 100, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 10, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 90, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI
}
void NekukKanan2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 100, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 10, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 90, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI

}
void NekukKananB1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 50, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 0, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 60, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 70, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI
}
void NekukKananB2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 50, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 0, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 60, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 70, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI

}
void NekukKananC1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 70, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 10, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 90, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI
}
void NekukKananC2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 90, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 60, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 0, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 70, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 10, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 90, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI

}
void NekukKiri1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 85, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 10, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 90, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 90, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void NekukKiri2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 85, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 10, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 90, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 90, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void NekukKiriB1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 35, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 0, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 60, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 70, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void NekukKiriB2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 35, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 0, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 60, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 70, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void NekukKiriC1(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 55, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 10, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 90, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 90, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void NekukKiriC2(int n) {
  dynamixel(2, 36, KIRI36 - 0, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 0, n); //+buka

  dynamixel(2, 21, KANAN21 + 55, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 10, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 90, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 90, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 90, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 75, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 0, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 0, n); //+KANAN,-KIRI
}
void StepNaik(int n) {
}

//////////////////kepala////////////////////
void PalaDefault(int t) {
  dynamixel(2, 41, KEPALA41, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}
void PalaKiri(int t) {
  dynamixel(2, 41, KEPALA41 + 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 10, t); //+KANAN,-KIRI
}
void PalaKiriPol(int t) {
  dynamixel(2, 41, KEPALA41 + 75, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}
void KiriBawah(int t) {
  dynamixel(2, 41, KEPALA41 + 60, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 20, t); //+KANAN,-KIRI
}
void PalaKiriBawah(int t) {
  dynamixel(2, 41, KEPALA41 + 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 30, t); //+KANAN,-KIRI
}
void PalaKiriBawahIseng(int t) {
  dynamixel(2, 41, KEPALA41 + 8, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 30, t); //+KANAN,-KIRI
}
void KiriAtas(int t) {
  dynamixel(2, 41, KEPALA41 + 60, t); //+mundur,-majuni
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 30, t); //+KANAN,-KIRI
}
void PalaKanan(int t) {
  dynamixel(2, 41, KEPALA41 - 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 10, t); //+KANAN,-KIRI
}
void PalaKananIseng(int t) {
  dynamixel(2, 41, KEPALA41 - 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 10, t); //+KANAN,-KIRI
}
void PalaKananAkhir(int t) {
  dynamixel(2, 41, KEPALA41 - 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 10, t); //+KANAN,-KIRI
}
void PalaKananPol(int t) {
  dynamixel(2, 41, KEPALA41 - 75, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}
void KananBawah(int t) {
  dynamixel(2, 41, KEPALA41 - 60, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 20, t); //+KANAN,-KIRI
}
void PalaKananBawah(int t) {
  dynamixel(2, 41, KEPALA41 - 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 30, t); //+KANAN,-KIRI
}
void PalaKananBawahIseng(int t) {
  dynamixel(2, 41, KEPALA41 - 8, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 30, t); //+KANAN,-KIRI
}
void KananAtas(int t) {
  dynamixel(2, 41, KEPALA41 - 60, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 30, t); //+KANAN,-KIRI
}
void PalaKananAtasIseng(int t) {
  dynamixel(2, 41, KEPALA41 - 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 15, t); //+KANAN,-KIRI
}
void PalaKiriAtasIseng(int t) {
  dynamixel(2, 41, KEPALA41 + 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 15, t); //+KANAN,-KIRI
}
void PalaKananAtas(int t) {
  dynamixel(2, 41, KEPALA41 - 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 30, t); //+KANAN,-KIRI
}
void PalaKiriAtas(int t) {
  dynamixel(2, 41, KEPALA41 + 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 30, t); //+KANAN,-KIRI
}
void PalaAtas(int t) {
  dynamixel(2, 41, KEPALA41, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 30, t); //+KANAN,-KIRI
}
void PalaAtasIseng(int t) {
  dynamixel(2, 41, KEPALA41, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 - 15, t); //+KANAN,-KIRI
}
void PalaBawah(int t) {
  dynamixel(2, 41, KEPALA41, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 35, t); //+KANAN,-KIRI
}
void PalaBawahIseng(int t) {
  dynamixel(2, 41, KEPALA41, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 15, t); //+KANAN,-KIRI
}
void PalaMiringKanan(int t) {
  dynamixel(2, 41, KEPALA41 - 10, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42 + 30, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}
void PalaMiringKiri(int t) {
  dynamixel(2, 41, KEPALA41 + 10, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42 - 30, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}

//////////tambahan tunning tangan//////////////
void TanganDepan(int n) {
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 80, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 10, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 90, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 90, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 80, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 10, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 90, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 90, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 90, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}


void TanganDepana(int n) {

  dynamixel(2, 36, KIRI36 + 45, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 - 45, n); //+buka

  dynamixel(2, 21, KANAN21 + 35, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 10, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 , n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 , n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 45 , n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 35, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 10, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 , n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 , n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 45 , n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void TerbangNgasai(int n) {
  //  transmitPulsaXLPunch(50);
  dynamixel(2, 36, KIRI36 - 90, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 90, n); //+buka

  dynamixel(2, 21, KANAN21 + 80, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 10, n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 , n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 40, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 , n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 80, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 10, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 , n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 40, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 , n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void Cuci1(int n) {
  dynamixel(2, 36, KIRI36 - 15, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 15, n); //+buka

  dynamixel(2, 21, KANAN21 + 70, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 20 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 40, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 45, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 110, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 80, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 20 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 40, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 45, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 110, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void Cuci2(int n) {
  dynamixel(2, 36, KIRI36 - 15, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 15, n); //+buka

  dynamixel(2, 21, KANAN21 + 70, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 20 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 40, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 45, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 110, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 , n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 40, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 90, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 110, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void Cuci3(int n) {
  dynamixel(2, 36, KIRI36 - 15, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 15, n); //+buka

  dynamixel(2, 21, KANAN21 , n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 40, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 90, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 110, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 80, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 20 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 40, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 45, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 110, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void CuciPunggung1(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 30, n); //+buka

  dynamixel(2, 21, KANAN21 + 50, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 20 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 70, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 30, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 10, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 70, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 20 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 70, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 60, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 10, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void CuciPunggung2(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 30, n); //+buka

  dynamixel(2, 21, KANAN21 + 50, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 20 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 70, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 40, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 10, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 , n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 20 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 40, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 100, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 10, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void CuciPunggung3(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 30, n); //35 +buka

  dynamixel(2, 21, KANAN21 , n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 20 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 40, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 100, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 10, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 30, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 15, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 40, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 55, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 + 10, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void CuciPunggung4(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 30, n); //35 +buka

  dynamixel(2, 21, KANAN21 + 50, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 20 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 45, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 55, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 10, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 30, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 15, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 40, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 40, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 + 10, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void CuciPunggung5(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 30, n); //+buka

  dynamixel(2, 21, KANAN21 + 60, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 20 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 40, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 10, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 60, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 20 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 40, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 10, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void stepcuci(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 30, n); //+buka

  dynamixel(2, 21, KANAN21 + 60, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 0 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 0, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 40, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 10, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 60, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 10 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 40, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 10, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}
void pasang1(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 20, n); //+buka

  dynamixel(2, 21, KANAN21 + 70, n); //150 +maju,-mundur
  dynamixel(2, 22, KANAN22 + 10 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 50, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 60, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 60, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 0, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 40, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 10, n); //+KANAN,-KIRI
  //  PalaAtas(n);
}
void pasang2(int n) {
  dynamixel(2, 36, KIRI36 - 30, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26 + 20, n); //+buka

  dynamixel(2, 21, KANAN21 + 120, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 - 15 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23 - 60, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24 + 80, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31 - 60, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 + 0, n); //+turun,-angkall

  dynamixel(2, 33, KIRI33 + 0, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34 - 40, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35 - 10, n); //+KANAN,-KIRI
  //  PalaAtas(n);
}

void stepAwal(int n) {
  dynamixel(2, 36, KIRI36, n); //+kiri,-kanan
  dynamixel(2, 26, KANAN26, n); //+buka

  dynamixel(2, 21, KANAN21, n); //+maju,-mundur
  dynamixel(2, 22, KANAN22 + 30 , n); //+angkat,-turun
  dynamixel(2, 23, KANAN23, n); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24, n); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25, n); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31, n); //+mundur,-maju
  dynamixel(2, 32, KIRI32 - 30 , n); //+turun,-angkall

  dynamixel(2, 33, KIRI33, n); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34, n); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35, n); //+KANAN,-KIRI
  //  PalaDefault(n);
}

void palaJelek1() {

  PalaJelekKanan(3);
  waitAll(300);
  transisiJelekKanan(1.5);
  waitAll(150);
  PalaJelekKanan(3);
  waitAll(300);
  transisiJelekKanan(1.5);
  waitAll(150);
  PalaDefault(3);
  waitAll(300);

}

void palaJelek2() {

  PalaJelekKiri(3);
  waitAll(300);
  transisiJelekKiri(1.5);
  waitAll(150);
  PalaJelekKiri(3);
  waitAll(300);
  transisiJelekKiri(1.5);
  waitAll(150);
  PalaDefault(3);
  waitAll(300);

}

void PalaCantikKanan(int t) {
  dynamixel(2, 41, KEPALA41 + 20, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42 + 20, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 10, t); //+KANAN,-KIRI
}

void PalaCantikKiri(int t) {
  dynamixel(2, 41, KEPALA41 - 20, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42 - 20, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 10, t); //+KANAN,-KIRI
}

void PalaJelekKanan(int t) {
  dynamixel(2, 41, KEPALA41 - 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42 + 35, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}

void PalaJelekKiri(int t) {
  dynamixel(2, 41, KEPALA41 + 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42 - 35, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}

void transisiJelekKanan(int t) {
  dynamixel(2, 41, KEPALA41 - 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}

void transisiJelekKiri(int t) {
  dynamixel(2, 41, KEPALA41 + 30, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}

void transisiKanan(int t) {
  dynamixel(2, 41, KEPALA41 - 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}

void transisiKananBawah(int t) {
  dynamixel(2, 41, KEPALA41 - 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 15, t); //+KANAN,-KIRI
}

void transisiKiri(int t) {
  dynamixel(2, 41, KEPALA41 + 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43, t); //+KANAN,-KIRI
}
void transisiKiriBawah(int t) {
  dynamixel(2, 41, KEPALA41 + 15, t); //+mundur,-maju
  dynamixel(2, 42, KEPALA42, t); //+turun,-angkall
  dynamixel(2, 43, KEPALA43 + 15, t); //+KANAN,-KIRI
}
