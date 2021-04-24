/**********************************************************

*                                                          *
                         LANGKAH KANAN
*                                                          *
***********************************************************/
void langkahKaCobaPID(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  int count  = 0 , countt = 0 , countTA = 1 , countte = 0;
  //  int in = 0;
  unsigned long prevteTA;
  double a, error, errorx;
  //  Serial.print("IN : "); Serial.println(indGJ3);
  footBase = 0;   //0 = kanan sebagai tumpuan
  step = 0;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x1 = xKakiKiri;
  x2 = xKakiKanan;
  z = tinggiBadan;

  s = x2 - x1;

  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4) - 1;
  tp = millis();
  tn = tp;
  prevte = 0;
  prevteTA = prevte;
  t = 0;
  te = 0;
  //  kordinatLangkahKi();
  //  walkInitGJ3();
  walkInitGJ3Belok(3, -3, 4.5, 4.5);
  //  Serial.print("te : ");Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 280) {
      countt = 1;
      //      Serial.print("Count: "); Serial.println(countTA);
      prevteTA = te;

      if (countTA == 1) {

        baca(2107, 3);
        PalaDefault(3);
        waitHand(1);
        //        Serial.println("gerakan 1");

      }
      if (countTA == 2) {

        baca(2108, 3);
        PalaBawahIseng(3);
        waitHand(1);
        //        Serial.println("gerakan 2");

      }
      if (countTA == 3) {
        baca(2109, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 4) {
        baca(2110, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        baca(2111, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 6) {
        baca(2112, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 7) {
        baca(2113, 3);
        PalaAtas(3);
        waitHand(1);
        countTA++;
      }
      if (countTA == 8) {
        countTA = 0;

      }
      countTA++;
    }


    if (te < TS * 0.25)
    {
      //      Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
//          bacaBNOAwal();
          //          tjKa = 5;
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 14;
          tKi = -9;  //hips servo 12
          pi = 15;     //11.5; //roll agkle kiri servo 16
          pa = 17;     //11.5; //roll angkle kanan servo 6
          tjKa = -0.5;   //pitch kanan servo 4
          tjKi = -2;  //pitch kiri servo 14
          pitchKa = 0;
          pitchKi = 0;
          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , 0);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan , 0 , 0);
          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
//          bacaBNO();
          tPa = -1;
          tPi = 0;
          tKa = 8.5;   //hips 13.5
          tKi = tKi + nextGoalRoll;   //hips -13.5
          pi = 18;     //13; //roll agkle kiri
          pa = 7;     //18; //roll angkle kanan
          tjKa = 3;   //pitch telapak kanan
          tjKi = -2;  //pitch telapak kiri
          pitchKa = 0;
          pitchKi = -nextGoalPitch;
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , 0);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3.2 , 0);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
          //          bacaBNO();
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);
//          bacaBNO();
          tPa = -1; //Yaw servo 1
          tPi = 0; //yaw servo 11
          tKa = 8;   //15.5 hips
          //          tKi = -6;  //-15.5 hips
          tKi = tKi + nextGoalRoll;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 7;    //9 roll angkle kanan
          tjKa = 0;   //2pitch kanan
          tjKi = -1;  //pitch kiri
          pitchKa = 0;
          pitchKi = -nextGoalPitch;
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 7 , tinggiBadan - 1, 2.5 , 0);
          //          //         Serial.println("AWAL=========================================Langkah 3============================================F======");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;
          //          bacaBNO();
        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          pitchKa = 0;
          pitchKi = 0;

          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //         Serial.println("AWAL=========================================Langkah 4============================================F======");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          //          bacaBNO();
          count++;
        }
      }
    }
    //
    else if (te >= TS)
    {

      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {
          //          GJ3Ki1(times);
        }
        prevte = te;
        walkUpdate(te);

        langkah = KIRI;
        tumpuan = KANAN;
        //        tjKa = 0;
        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;

      }
    }



    if (count == 4) {
      count = 0;
    }
  }
  //

  //
}

void langkahKaNganjatHue1(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  int count  = 0 , countt = 0 , countTA = 1 , countte = 0;
  //  int in = 0;
  unsigned long prevteTA;
  double a, error, errorx;
  //  Serial.print("IN : "); Serial.println(indGJ3);
  footBase = 0;   //0 = kanan sebagai tumpuan
  step = 0;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x1 = xKakiKiri;
  x2 = xKakiKanan;
  z = tinggiBadan;

  s = x2 - x1;

  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4) - 1;
  tp = millis();
  tn = tp;
  prevte = 0;
  prevteTA = prevte;
  t = 0;
  te = 0;
  //  kordinatLangkahKi();
  //  walkInitGJ3();
  walkInitGJ3Belok(3, -3, 4.5, 4.5);
  //  Serial.print("te : ");Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 280) {
      countt = 1;
      //      Serial.print("Count: "); Serial.println(countTA);
      prevteTA = te;

      if (countTA == 1) {

        baca(2107, 3);
        PalaDefault(3);
        waitHand(1);
        //        Serial.println("gerakan 1");

      }
      if (countTA == 2) {

        baca(2108, 3);
        PalaBawahIseng(3);
        waitHand(1);
        //        Serial.println("gerakan 2");

      }
      if (countTA == 3) {
        baca(2109, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 4) {
        baca(2110, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        baca(2111, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 6) {
        baca(2112, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 7) {
        baca(2113, 3);
        PalaAtas(3);
        waitHand(1);
        countTA++;
      }
      if (countTA == 8) {
        countTA = 0;

      }
      countTA++;
    }


    if (te < TS * 0.25)
    {
      //      Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 14;   //hips  servo 2
          tKi = -11.5;  //hips servo 12
          pi = 15;     //11.5; //roll agkle kiri servo 16
          pa = 15;     //11.5; //roll angkle kanan servo 6
          tjKa = -0.5;   //pitch kanan servo 4
          tjKi = -2;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , 0);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan , 0 , 0);
          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);

          tPa = -1;
          tPi = 0;
          tKa = 8.5;   //hips 13.5
          tKi = -7.5;   //hips -13.5
          pi = 18;     //13; //roll agkle kiri
          pa = 7;     //18; //roll angkle kanan
          tjKa = -1;   //pitch kanan
          tjKi = -1;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , 0);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3.2 , 0);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = -1; //Yaw servo 1
          tPi = 0; //yaw servo 11
          tKa = 8;   //15.5 hips
          tKi = -6;  //-15.5 hips
          pi = 14;    //20 roll agkle kiri
          pa = 7;    //9 roll angkle kanan
          tjKa = -2;   //2pitch kanan
          tjKi = -1;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 7 , tinggiBadan - 0.7, 2.5 , 0);
          //          //         Serial.println("AWAL=========================================Langkah 3============================================F======");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri

          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //         Serial.println("AWAL=========================================Langkah 4============================================F======");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    //
    else if (te >= TS)
    {

      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {
          //          GJ3Ki1(times);
        }
        prevte = te;
        walkUpdate(te);

        langkah = KIRI;
        tumpuan = KANAN;
        //        tjKa = 0;
        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;

      }
    }



    if (count == 4) {
      count = 0;
    }
  }

}

void langkahKaNganjatHue2(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  int count  = 0 , countt = 0 , countTA = 1 , countte = 0;
  //  int in = 0;
  unsigned long prevteTA;
  double a, error, errorx;
  //  Serial.print("IN : "); Serial.println(indGJ3);
  footBase = 0;   //0 = kanan sebagai tumpuan
  step = 0;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x1 = xKakiKiri;
  x2 = xKakiKanan;
  z = tinggiBadan;

  s = x2 - x1;

  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4) - 1;
  tp = millis();
  tn = tp;
  prevte = 0;
  prevteTA = prevte;
  t = 0;
  te = 0;
  //  kordinatLangkahKi();
  //  walkInitGJ3();
  walkInitGJ3Belok(3, -3, 4.5, 4.5);
  //  Serial.print("te : ");Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 280) {
      countt = 1;
      //      Serial.print("Count: "); Serial.println(countTA);
      prevteTA = te;

      if (countTA == 1) {

        baca(2107, 3);
        PalaDefault(3);
        waitHand(1);
        //        Serial.println("gerakan 1");

      }
      if (countTA == 2) {

        baca(2108, 3);
        PalaBawahIseng(3);
        waitHand(1);
        //        Serial.println("gerakan 2");

      }
      if (countTA == 3) {
        baca(2109, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 4) {
        baca(2110, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        baca(2111, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 6) {
        baca(2112, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 7) {
        baca(2113, 3);
        PalaAtas(3);
        waitHand(1);
        countTA++;
      }
      if (countTA == 8) {
        countTA = 0;

      }
      countTA++;
    }


    if (te < TS * 0.25)
    {
      //      Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;
          tPa = -1;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 14;   //hips  servo 2
          tKi = -10.5;  //hips servo 12
          pi = 14;     //11.5; //roll agkle kiri servo 16
          pa = 15;     //11.5; //roll angkle kanan servo 6
          tjKa = -0.5;   //pitch kanan servo 4
          tjKi = -1;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , 0);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan , 0 , 0);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);

          tPa = -1;
          tPi = 0;
          tKa = 8.5;   //hips 13.5
          tKi = -6;   //hips -13.5
          pi = 19;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = -1;   //pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , 0);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3.2 , 0);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw servo 1
          tPi = 0; //yaw servo 11
          tKa = 8;   //15.5 hips
          tKi = -6;  //-15.5 hips
          pi = 16;    //20 roll agkle kiri
          pa = 6;    //9 roll angkle kanan
          tjKa = -2;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 7 , tinggiBadan - 1.1, 2.5 , 0);
          //          //         Serial.println("AWAL=========================================Langkah 3============================================F======");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri

          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //         Serial.println("AWAL=========================================Langkah 4============================================F======");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    //
    else if (te >= TS)
    {

      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {
          //          GJ3Ki1(times);
        }
        prevte = te;
        walkUpdate(te);

        langkah = KIRI;
        tumpuan = KANAN;
        //        tjKa = 0;
        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;

      }
    }



    if (count == 4) {
      count = 0;
    }
  }

}

void langkahKaNganjatHue3(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  int count  = 0 , countt = 0 , countTA = 1 , countte = 0;
  //  int in = 0;
  unsigned long prevteTA;
  double a, error, errorx;
  //  Serial.print("IN : "); Serial.println(indGJ3);
  footBase = 0;   //0 = kanan sebagai tumpuan
  step = 0;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x1 = xKakiKiri;
  x2 = xKakiKanan;
  z = tinggiBadan;

  s = x2 - x1;

  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4) - 1;
  tp = millis();
  tn = tp;
  prevte = 0;
  prevteTA = prevte;
  t = 0;
  te = 0;
  //  kordinatLangkahKi();
  //  walkInitGJ3();
  walkInitGJ3Belok(3, -3, 4.5, 4.5);
  //  Serial.print("te : ");Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 280) {
      countt = 1;
      //      Serial.print("Count: "); Serial.println(countTA);
      prevteTA = te;

      if (countTA == 1) {

        baca(2107, 3);
        PalaDefault(3);
        waitHand(1);
        //        Serial.println("gerakan 1");

      }
      if (countTA == 2) {

        baca(2108, 3);
        PalaBawahIseng(3);
        waitHand(1);
        //        Serial.println("gerakan 2");

      }
      if (countTA == 3) {
        baca(2109, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 4) {
        baca(2110, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        baca(2111, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 6) {
        baca(2112, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 7) {
        baca(2113, 3);
        PalaAtas(3);
        waitHand(1);
        countTA++;
      }
      if (countTA == 8) {
        countTA = 0;

      }
      countTA++;
    }


    if (te < TS * 0.25)
    {
      //      Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 14;   //hips  servo 2
          tKi = -10.5;  //hips servo 12
          pi = 14;     //11.5; //roll agkle kiri servo 16
          pa = 15;     //11.5; //roll angkle kanan servo 6
          tjKa = -0.5;   //pitch kanan servo 4
          tjKi = -2;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , 0);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan , 0 , 0);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);

          tPa = -1;
          tPi = 0;
          tKa = 8.5;   //hips 13.5
          tKi = -6;   //hips -13.5
          pi = 19;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = -2;   //pitch kanan
          tjKi = -1;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , 0);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3.2 , 0);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = -1; //Yaw servo 1
          tPi = 0; //yaw servo 11
          tKa = 8;   //15.5 hips
          tKi = -6;  //-15.5 hips
          pi = 17;    //20 roll agkle kiri
          pa = 6;    //9 roll angkle kanan
          tjKa = -3;   //2pitch kanan
          tjKi = -1;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 7 , tinggiBadan - 1.3, 2.5 , 0);
          //          //         Serial.println("AWAL=========================================Langkah 3============================================F======");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri

          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //         Serial.println("AWAL=========================================Langkah 4============================================F======");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    //
    else if (te >= TS)
    {

      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {
          //          GJ3Ki1(times);
        }
        prevte = te;
        walkUpdate(te);

        langkah = KIRI;
        tumpuan = KANAN;
        //        tjKa = 0;
        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;

      }
    }



    if (count == 4) {
      count = 0;
    }
  }

}

void langkahKaNgasaiHue1(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 750) {
      countt = 1;
      //      Serial.print("Count: "); Serial.println(countTA);
      prevteTA = te;

      if (countTA == 1) {
        PalaDefault(5);
        baca(2219, 5);
        waitHand(1);

        //        Serial.println("gerakan 1");

      }
      if (countTA == 2) {
        PalaKiriAtas(5);
        baca(2220, 5);
        waitHand(1);
        //
      }
      if (countTA == 3) {
        PalaKiriBawah(5);
        baca(2221, 5);
        waitHand(1);
        Wire1.beginTransmission(8);
        Wire1.write(30);
        Wire1.endTransmission();
        //        Serial.println("gerakan 2");
        countTA++;
      }
      if (countTA == 4) {
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 12;   //hips  servo 2
          tKi = -10.5;  //hips servo 12
          pi = 13;     //11.5; //roll agkle kiri servo 16
          pa = 13;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = -2;
          tPi = 0;
          tKa = 9.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = -2;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3, 3 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = -3; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = -1;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , -0.2);
          invers(KANAN, times, 7 , tinggiBadan - 0.9, 3.5 , -0.2); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = -2;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.2); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.2);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaNgasaiHue2(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 750) {
      countt = 1;
      //      Serial.print("Count: "); Serial.println(countTA);
      prevteTA = te;

      if (countTA == 1) {
        PalaDefault(5);
        baca(2219, 5);
        waitHand(1);

        //        Serial.println("gerakan 1");

      }
      if (countTA == 2) {
        PalaKiriAtas(5);
        baca(2220, 5);
        waitHand(1);
        //
      }
      if (countTA == 3) {
        PalaKiriBawah(5);
        baca(2221, 5);
        waitHand(1);
        Wire1.beginTransmission(8);
        Wire1.write(30);
        Wire1.endTransmission();
        //        Serial.println("gerakan 2");
        countTA++;
      }
      if (countTA == 4) {
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 12;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 12;     //11.5; //roll agkle kiri servo 16
          pa = 12;     //11.5; //roll angkle kanan servo 6
          tjKa = 0;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 9.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = -2;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8;  //-15.5 hips
          pi = 16;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = -1;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 7 , tinggiBadan - 1.2, 3.5 , 0); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.3); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.3);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaNgasaiHue3(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 750) {
      countt = 1;
      //      Serial.print("Count: "); Serial.println(countTA);
      prevteTA = te;

      if (countTA == 1) {
        PalaDefault(5);
        baca(2219, 5);
        waitHand(1);

        //        Serial.println("gerakan 1");

      }
      if (countTA == 2) {
        PalaKiriAtas(5);
        baca(2220, 5);
        waitHand(1);
        //
      }
      if (countTA == 3) {
        PalaKiriBawah(5);
        baca(2221, 5);
        waitHand(1);
        Wire1.beginTransmission(8);
        Wire1.write(30);
        Wire1.endTransmission();
        //        Serial.println("gerakan 2");
        countTA++;
      }
      if (countTA == 4) {
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 12;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 13;     //11.5; //roll agkle kiri servo 16
          pa = 13;     //11.5; //roll angkle kanan servo 6
          tjKa = 0;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 9.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = -2;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8;  //-15.5 hips
          pi = 16;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 0;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 7 , tinggiBadan - 1.2, 3.5 , 0); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.3); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.3);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}


void langkahKaNgasaiHaha1(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaKananAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaKananAtas(3);
        Wire1.beginTransmission(8);
        Wire1.write(9);
        Wire1.endTransmission();

        waitHand(1);

      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 12;   //hips  servo 2
          tKi = -10.5;  //hips servo 12
          pi = 13;     //11.5; //roll agkle kiri servo 16
          pa = 13;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 9.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = -2;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3, 3 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 0;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , -0.2);
          invers(KANAN, times, 7 , tinggiBadan - 0.9, 3.5 , -0.2); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.2); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.2);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaNgasaiHaha11(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaKiriAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaKiriAtas(3);
        Wire1.beginTransmission(8);
        Wire1.write(23);
        Wire1.endTransmission();
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 10;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 11;     //11.5; //roll agkle kiri servo 16
          pa = 11;     //11.5; //roll angkle kanan servo 6
          tjKa = 2;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 8;   //10.5 hips 13.5
          tKi = -8;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = -2;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8;   //10.5 15.5 hips
          tKi = -8;  //-15.5 hips
          pi = 16;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 0;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , -0.2);
          invers(KANAN, times, 7 , tinggiBadan - 1.2, 3.5 , -0.2); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.2); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.2);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaNgasaiHaha2(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;

      if (countTA == 1) {
        //                transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaKananAtas(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //                transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaKananAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //                transmitPulsaXLPunch(100);
        baca(3330, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //                transmitPulsaXLPunch(100);
        baca(3331, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //                transmitPulsaXLPunch(100);
        baca(3332, 3);
        PalaBawah(3);
        Wire1.beginTransmission(8);
        Wire1.write(0);
        Wire1.endTransmission();
        waitHand(1);
      }
      if (countTA == 6) {
        //                transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 10;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 12.5;     //11.5; //roll agkle kiri servo 16
          pa = 12.5;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 2;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.3);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.3);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 8.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 17;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5.5 - 3.06, tinggiBadan - 3.5, 3 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8;  //-15.5 hips
          pi = 17;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = -2;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , -0.2);
          invers(KANAN, times, 7 , tinggiBadan - 1.2, 3.5 , -0.2); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.2); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.2);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}


void langkahKaPurakBarikHaha1(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaKananAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaKananAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 12;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 13;     //11.5; //roll agkle kiri servo 16
          pa = 13;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 9.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 17;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = -2;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = -1;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , -0.2);
          invers(KANAN, times, 6 , tinggiBadan - 1, 3.3 , -0.2); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.2); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.2);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaPurakBarikHaha2(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaKiriAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaKiriAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 10;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 12;     //11.5; //roll agkle kiri servo 16
          pa = 12;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 1;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = -1;
          tPi = 0;
          tKa = 8.5;   //10.5 hips 13.5
          tKi = -9;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 1;   //pitch kanan
          tjKi = 1;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = -2; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 3;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 6 , tinggiBadan - 1.2, 3.3 , 0); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaPurakBarikHaha3(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaKananAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaKananAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 10;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 12;     //11.5; //roll agkle kiri servo 16
          pa = 12;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 1;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = -1;
          tPi = 0;
          tKa = 8.5;   //10.5 hips 13.5
          tKi = -9;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 1;   //pitch kanan
          tjKi = 1;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = -2; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 3;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 6 , tinggiBadan - 1.2, 3.3 , 0); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaPurakBarikHaha4(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 10;   //hips  servo 2
          tKi = -11;  //hips servo 12
          pi = 12.5;     //11.5; //roll agkle kiri servo 16
          pa = 12.5;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 2;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.3);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.3);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 1;
          tPi = 0;
          tKa = 8.5;   //10.5 hips 13.5
          tKi = -9;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = 1;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 3; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 1;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 6 , tinggiBadan - 1.2, 3.3 , 0); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaPurakBarikSejajarHaha1(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 12;   //hips  servo 2
          tKi = -10.5;  //hips servo 12
          pi = 13;     //11.5; //roll agkle kiri servo 16
          pa = 13;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.3);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.3);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 9.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 16;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 3.5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = -3; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 0;   //2pitch kanan
          tjKi = 1;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , -0.2);
          invers(KANAN, times, 0 , tinggiBadan - 0.8, 3 , -0.2); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, 0 , tinggiBadan, 0, -0.2); //m+ badan depan
          invers(KANAN, times + 3, 0  , tinggiBadan - sfZ, 0, -0.2);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaPurakBarikHaha11(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 12;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 13;     //11.5; //roll agkle kiri servo 16
          pa = 13;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 0;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 9.5;   //10.5 hips 13.5
          tKi = -8.5;   //hips -13.5
          pi = 17;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = -2;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = -1;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , -0.2);
          invers(KANAN, times, 6 , tinggiBadan - 1, 3.3 , -0.2); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0.2); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0.2);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaPurakBarikHaha22(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 10;   //hips  servo 2
          tKi = -10;  //hips servo 12
          pi = 12;     //11.5; //roll agkle kiri servo 16
          pa = 12;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 1;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.2);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.2);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 8.5;   //10.5 hips 13.5
          tKi = -9;   //hips -13.5
          pi = 17;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 1;   //pitch kanan
          tjKi = 1;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 16;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 3;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 6 , tinggiBadan - 1.2, 3.3 , 0); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}

void langkahKaPurakBarikHaha33(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int in = 0;
  double a, error, errorx;
  footBase = 1;   //1 = kiri sebagai tumpuan
  int count  = 0, countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA;

  Ts = periodeLangkah;
  sh = tinggiLangkah;
  x2 = xKakiKiri;
  x1 = xKakiKanan;
  z = tinggiBadan;
  //  //         Serial.print("te : ");
  s = x2 - x1;
  TS = Ts * 1000;
  times = ((Ts + 0.05) * 10 / 4 ) - 1;
  tp = millis();
  tn = tp;
  t = 0;
  prevte = 0;
  te = 0;
  prevte = 0;
  //  kordinatLangkahKa();
  //  walkInitGJ3();
  walkInitGJ3Belok(3 , -3 , 4.5 , 4.5 );
  //  //         Serial.print("te : "); //         Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 300) {
      countt = 1;
      prevteTA = te;
      if (countTA == 1) {
        //        transmitPulsaXLPunch(100);
        baca(3324, 3);
        PalaBawah(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //        transmitPulsaXLPunch(100);
        baca(3325, 3);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //        transmitPulsaXLPunch(100);
        baca(3326, 3);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //        transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //        transmitPulsaXLPunch(100);
        baca(3328, 3);
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 6) {
        //        transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //            //         Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        //        //         Serial.println("1");
        if (count == 0 ) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          tPa = 0;      //yaw servo 1
          tPi = 0;      //yaw servo 11
          tKa = 10;   //hips  servo 2
          tKi = -11;  //hips servo 12
          pi = 13;     //11.5; //roll agkle kiri servo 16
          pa = 13;     //11.5; //roll angkle kanan servo 6
          tjKa = -2;   //pitch kanan servo 4
          tjKi = 2;  //pitch kiri servo 14

          invers(KIRI, times, 3 - 3.06 , tinggiBadan , 0  , -0.3);
          invers(KANAN , times , -3 - 3.06 , tinggiBadan - 0.5 , 0 , -0.3);
          //          //         Serial.println("==============================================Langkah 1==================================================");
          a = 0;
          step = 2;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }
    else if (te < TS * 0.50 && te >= TS * 0.25)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 1) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;
          tPa = 0;
          tPi = 0;
          tKa = 8.5;   //10.5 hips 13.5
          tKi = -9;   //hips -13.5
          pi = 17;     //13; //roll agkle kiri
          pa = 6;     //18; //roll angkle kanan
          tjKa = 0;   //pitch kanan
          tjKi = 1;  //pitch kiri
          invers(KIRI, times , 3 - 3.06, tinggiBadan, 0 , -0.2);
          invers(KANAN, times , 5 - 3.06, tinggiBadan - 3, 2.5 , -0.2);
          //          //         Serial.println("=========================================Langkah 2===============================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25)) {
        if (count == 2) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS * 0.75);

          tPa = 0; //Yaw
          tPi = 0;
          tKa = 8.5;   //10.5 15.5 hips
          tKi = -8.5;  //-15.5 hips
          pi = 15;    //20 roll agkle kiri
          pa = 5;    //9 roll angkle kanan
          tjKa = 1;   //2pitch kanan
          tjKi = 0;  //pitch kiri
          invers(KIRI, times, 0   , tinggiBadan, 0 , 0);
          invers(KANAN, times, 6 , tinggiBadan - 1.2, 3.3 , 0); //tinggi-2.7
          //          //         Serial.println("AWAL=========================================Langkah 3==================================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          in++;
          count++ ;

        }
        //
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if ( count == 3) {
          //          //         Serial.print("te:" ); //         Serial.println(te);
          prevte = te;
          walkUpdate(TS);

          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri
          invers(KIRI, times + 3, -3 , tinggiBadan, 0, 0); //m+ badan depan
          invers(KANAN, times + 3, 3  , tinggiBadan - sfZ, 0, 0);
          //          //         Serial.println("==========================================Langkah 4============================================");
          //          //         Serial.println("MASUK");
          step = 5;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te >= TS)
    {
      if (((te - prevte + 8) >= (TS * 0.25 ))) {
        if (count == 4) {

        }
        prevte = te;
        walkUpdate(te);
        tjKa = 0;
        //        tjKi = 0;
        tPa = 0;
        tPi = 0;
        tKa = 0;
        tKi = 0;
        pi = 0;
        pa = 0;
      }
    }
    if ( count == 4) {
      count = 0;
    }

    //    if (in == 1) {
    //      in = 0;
    //    }
  }
}
