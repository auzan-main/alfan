/***********************************************************
*                                                          *
                         LANGKAH KIRI
*                                                          *
***********************************************************/
void langkahKiCobaPID(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{

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
          bacaBNOAwal();
          tPa = 0;
          tPi = 0;
          tKa = -12;  //pokoknya ini nanti di plus correctionnya
          tKi = 11; 
          pi = -14; // -11 roll angkle kiri
          pa = -13; // -17 roll angkle kanan
          tjKi = -0.5; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan
          pitchKa = -nextGoalPitch;
          pitchKi = 0;
          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan , 0 , 0);
          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          bacaBNO();
          tPa = 0;
          tPi = 3;
          tKa = tKa - nextGoalRoll_Kiri;  //-10.5 Hips
          tKi = 8.5;   //10.5 Hips
          pi = -9; //-12 roll angkle kiri
          pa = -16; //-23.5 roll angkle kanan
          tjKi = 0; //5pitch angkle kiri
          tjKa = -5;//-2 pitch angkle kanan
          pitchKa = -nextGoalPitch;
          pitchKi = 0;
          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 5.5 - 3.06 , tinggiBadan - 4, -3.5 , 0);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;
        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          bacaBNO();
          tPa = 0;
          tPi = 5;
          tKa = tKa - nextGoalRoll_Kiri ;//ada yang weird disini makannya di -5
          tKi = 10;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -15; //-18 roll angkle kanan
          tjKi = 4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -3;//pitch angkle kanan
          pitchKa = -nextGoalPitch;
          pitchKi = 0;
          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1, -4.5, 0);
          //Serial.println("================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 4;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;
          pitchKa = 0;
          pitchKi = 0;

          invers(KANAN, times + 3, -3, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, 3, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("===============================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

}

void langkahKiCobaPID_FASTER(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{

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
          bacaBNOAwal();
          tPa = 0;
          tPi = 0;
          tKa = -12;  //pokoknya ini nanti di plus correctionnya
          tKi = 11; 
          pi = -15; // -11 roll angkle kiri
          pa = -14; // -17 roll angkle kanan
          tjKi = -0.5; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan
          pitchKa = -nextGoalPitch;
          pitchKi = 0;
          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan , 0 , 0);
          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          bacaBNO();
          tPa = 0;
          tPi = 3;
          tKa = tKa - nextGoalRoll_Kiri;  //-10.5 Hips
          tKi = 8.5;   //10.5 Hips
          pi = -8; //-12 roll angkle kiri
          pa = -15; //-23.5 roll angkle kanan
          tjKi = 0; //5pitch angkle kiri
          tjKa = -2;//-2 pitch angkle kanan
          pitchKa = -nextGoalPitch;
          pitchKi = 0;
          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 5.5 - 3.06 , tinggiBadan - 4, -3.5 , 0);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          bacaBNO();
          tPa = 0;
          tPi = 5;
          tKa = tKa - nextGoalRoll_Kiri ;//ada yang weird disini makannya di -5
          tKi = 10;   //15.5 Hips
          pi = -8; //-8 roll angkle kiri
          pa = -14; //-18 roll angkle kanan
          tjKi = 4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -2;//pitch angkle kanan
          pitchKa = -nextGoalPitch;
          pitchKi = 0;
          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1, -4.5, 0);
          //Serial.println("================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 4;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;
          pitchKa = 0;
          pitchKi = 0;

          invers(KANAN, times + 3, -3, tinggiBadan, 0 , 0);  //nyoba
          invers(KIRI, times  + 3, 3, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("===============================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

}

void langkahKiNganjatHue1(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{

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
          tPa = 0;
          tPi = 0;
          tKa = -7;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -15; // -11 roll angkle kiri
          pa = -16; // -17 roll angkle kanan
          tjKi = 1; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.5);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.5);
          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;


          tPa = 0;
          tPi = 2;
          tKa = -5;  //-10.5 Hips
          tKi = 9.5;   //10.5 Hips
          pi = -10; //-12 roll angkle kiri
          pa = -19; //-23.5 roll angkle kanan
          tjKi = 0; //5pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 1);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -3.5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -17; //-18 roll angkle kanan
          tjKi = 2; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0.3);
          invers(KIRI , times , 6 , tinggiBadan - 0.9, -2.3, 0.3);
          //Serial.println("================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("===============================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNganjatHue2(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{

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
          tPa = 0;
          tPi = 0;
          tKa = -7;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -15; // -11 roll angkle kiri
          pa = -16; // -17 roll angkle kanan
          tjKi = 1; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.5);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.5);
          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;


          tPa = 0;
          tPi = 3;
          tKa = -5;  //-10.5 Hips
          tKi = 9.5;   //10.5 Hips
          pi = -10; //-12 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = 2; //5pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 1);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -3.5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -17; //-18 roll angkle kanan
          tjKi = 2; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0.3);
          invers(KIRI , times , 6 , tinggiBadan - 1, -2.3, 0.3);
          //Serial.println("================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("===============================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNganjatHue3(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{

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
          tPa = 0;
          tPi = 0;
          tKa = -7;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -15; // -11 roll angkle kiri
          pa = -16; // -17 roll angkle kanan
          tjKi = 1; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.5);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.5);
          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;


          tPa = 0;
          tPi = 3;
          tKa = -5;  //-10.5 Hips
          tKi = 9.5;   //10.5 Hips
          pi = -10; //-12 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = 2; //5pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5.5 - 3.06 , tinggiBadan - 3.5, -3 , 1);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -3.5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -12; //-8 roll angkle kiri
          pa = -17; //-18 roll angkle kanan
          tjKi = 1; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0.3);
          invers(KIRI , times , 7 , tinggiBadan - 1, -2.3, 0.3);
          //Serial.println("================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("===============================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNgasaiHue1(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        PalaKananAtas(5);
        baca(2222, 5);
        waitHand(1);
        //
      }
      if (countTA == 3) {
        PalaKananBawah(5);
        baca(2223, 5);
        waitHand(1);
        Wire1.beginTransmission(8);
        Wire1.write(23);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = -1;
          tPi = 0;
          tKa = -8.5;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -14; // -12 roll angkle kiri
          pa = -14; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1.3);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1.3);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -5;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = -2; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.8);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -4;  //-15.5 Hips
          tKi = 8;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -18; //-21.5 roll angkle kanan
          tjKi = -4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -1;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.6, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNgasaiHue2(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        PalaKananAtas(5);
        baca(2222, 5);
        waitHand(1);
        //
      }
      if (countTA == 3) {
        PalaKananBawah(5);
        baca(2223, 5);
        waitHand(1);
        Wire1.beginTransmission(8);
        Wire1.write(23);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -8.5;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -14; // -12 roll angkle kiri
          pa = -14; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1.4);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1.4);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -5;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = -2; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.8);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -4;  //-15.5 Hips
          tKi = 8;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -18; //-21.5 roll angkle kanan
          tjKi = -4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -1;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.6, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNgasaiHue3(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        PalaKananAtas(5);
        baca(2222, 5);
        waitHand(1);
        //
      }
      if (countTA == 3) {
        PalaKananBawah(5);
        baca(2223, 5);
        waitHand(1);
        Wire1.beginTransmission(8);
        Wire1.write(23);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -14; // -12 roll angkle kiri
          pa = -14; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1.4);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1.4);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 2;
          tKa = -5;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = -2; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.8);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4.5;
          tKa = -4;  //-15.5 Hips
          tKi = 8;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = -4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -1;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.6, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNgasaiHaha1(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -13; // -12 roll angkle kiri
          pa = -13; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1.4);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1.4);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -5;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = -2; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.8);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -4;  //-15.5 Hips
          tKi = 8;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = -2; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.4, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNgasaiHaha2(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        Wire1.write(16);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -13; // -12 roll angkle kiri
          pa = -13; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1.4);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1.4);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -5;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = -4; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.8);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -4;  //-15.5 Hips
          tKi = 8;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = -4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -1;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.6, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiNgasaiHaha22(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        Wire1.write(37);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9.5;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -14; // -12 roll angkle kiri
          pa = -14; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 0;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1.4);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1.4);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = -2; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.4);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.4);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 5;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = -3; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.4, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , 0);
          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiPurakBarikHaha1(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9.5;  //-13.5 hips
          tKi = 10;   //-13.5 hips
          pi = -12; // -12 roll angkle kiri
          pa = -12; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 2;
          tKa = -7;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = 1; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.2);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.2);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -6;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = 5; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , -0.5);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , -0.5);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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


void langkahKiPurakBarikHaha2(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        PalaKiriAtas(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //                transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaKiriAtasIseng(3);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9.5;  //-13.5 hips
          tKi = 11;   //-13.5 hips
          pi = -13; // -12 roll angkle kiri
          pa = -13; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 2;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.5);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.5);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -17; //-23.5 roll angkle kanan
          tjKi = 2; //3pitch angkle kiri
          tjKa = 1;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.5);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.5);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 5;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = 4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.1, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 5;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , -0.5);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , -0.5);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiPurakBarikHaha3(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9.5;  //-13.5 hips
          tKi = 11;   //-13.5 hips
          pi = -13; // -12 roll angkle kiri
          pa = -13; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 2;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.5);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.5);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = -2;
          tPi = 3;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -17; //-23.5 roll angkle kanan
          tjKi = 2; //3pitch angkle kiri
          tjKa = 1;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.5);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.5);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 5;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = 4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.1, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 5;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , -0.5);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , -0.5);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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


void langkahKiPurakBarikSejajarHaha1(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        baca(3328, 3.5);
        PalaKiriAtas(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //                transmitPulsaXLPunch(100);
        baca(3329, 3.5);
        PalaKiriAtasIseng(3);
        waitHand(1);
      }
      if (countTA == 3) {
        //                transmitPulsaXLPunch(100);
        baca(3330, 3.5);
        PalaDefault(3);
        waitHand(1);
      }
      if (countTA == 4) {
        //                transmitPulsaXLPunch(100);
        baca(3331, 3.5);
        PalaBawahIseng(3);
        waitHand(1);
      }
      if (countTA == 5) {
        //                transmitPulsaXLPunch(100);
        baca(3332, 3.2);
        PalaBawah(3);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -10;  //-13.5 hips
          tKi = 10;   //-13.5 hips
          pi = -12; // -12 roll angkle kiri
          pa = -12; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.5);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.5);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 2;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -16; //-23.5 roll angkle kanan
          tjKi = -1; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.5);
          invers(KIRI , times , 3.5 - 3.06 , tinggiBadan - 3.5, -3 , 0.5);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -16; //-21.5 roll angkle kanan
          tjKi = -1; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -1;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 0 , tinggiBadan - 1.6, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, 0, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, 0, tinggiBadan - sfZ, 0 , 0);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiPurakBarikSejajarHue(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
  while (TS + 0.05 >= te)
  {
    tp = millis();
    te = tp - tn;
    t = te / 1000;

    if (countt == 0 || te - prevteTA >= 751) {
      countt = 1;
      prevteTA = te;

      if (countTA == 1) {
        //                transmitPulsaXLPunch(100);
        baca(2458, 7);
        PalaKanan(7);
        waitHand(1);
      }
      if (countTA == 2) {
        //                transmitPulsaXLPunch(100);
        baca(2457, 7);
        PalaBawahIseng(7);
        waitHand(1);
      }
      if (countTA == 3) {
        //                transmitPulsaXLPunch(100);
        countTA = 0;
      }
      countTA++;
    }

    if (te < TS * 0.25)
    {
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9.5;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -15; // -12 roll angkle kiri
          pa = -15; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1.4);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1.4);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 1;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = -4; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 3.5 - 3.06 , tinggiBadan - 3.5, -3 , 0.8);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 2;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -18; //-21.5 roll angkle kanan
          tjKi = -3; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = -1;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 0 , tinggiBadan - 1.6, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, 0, tinggiBadan, 0 , 0);
          invers(KIRI, times  + 3, 0, tinggiBadan - sfZ, 0 , 0);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiPurakBarikHaha11(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //                transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -9.5;  //-13.5 hips
          tKi = 12.5;   //-13.5 hips
          pi = -13; // -12 roll angkle kiri
          pa = -13; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -1);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -1);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 2;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -18; //-23.5 roll angkle kanan
          tjKi = 1; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.2);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.2);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 4;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = 5; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , -0.5);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , -0.5);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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


void langkahKiPurakBarikHaha22(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //                transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -10;  //-13.5 hips
          tKi = 10;   //-13.5 hips
          pi = -12.5; // -12 roll angkle kiri
          pa = -12.5; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.8);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.8);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 2;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -17; //-23.5 roll angkle kanan
          tjKi = 1; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.8);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.8);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 5;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = 1; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , -0.5);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , -0.5);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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

void langkahKiPurakBarikHaha33(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
{
  int count  = 0 , countt = 0 , countTA = 1, countte = 0;
  //  int in = 0;
  unsigned long prevteTA, base;
  double a, error, errorx;
  //  //Serial.print("IN : "); //Serial.println(indGJ3);
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
  //  //Serial.print("te : ");//Serial.println(te);
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
        PalaAtas(3);
        waitHand(1);
      }
      if (countTA == 2) {
        //                transmitPulsaXLPunch(100);
        baca(3329, 3);
        PalaAtasIseng(3);
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
      //      //Serial.println(te);
      if ((countte == 0 || (te - prevte) >= (TS * 0.25 ))) {
        if (count == 0) {
          //Serial.print("te:" ); //Serial.println(te);
          countte = 1;
          //          GJ3Ki1(times);
          prevte = te;
          walkUpdate(TS * 0.25);
          //          tjKa = 5;

          tPa = 0;
          tPi = 0;
          tKa = -10;  //-13.5 hips
          tKi = 11;   //-13.5 hips
          pi = -12; // -12 roll angkle kiri
          pa = -12; // -17 roll angkle kanan
          tjKi = 0; //-2 pitch angkle kiri
          tjKa = 1;//0 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , -0.5);
          invers(KIRI , times , -3 - 3.06 , tinggiBadan - 0.5, 0 , -0.5);

          //Serial.println("==================================Langkah 1=================================");
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
        if (count  == 1) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki2(times);

          prevte = te;
          walkUpdate(TS * 0.5);
          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 3;
          tKa = -6;  //-8.5 Hips
          tKi = 8;   //10.5 Hips
          pi = -10; //-8 roll angkle kiri
          pa = -17; //-23.5 roll angkle kanan
          tjKi = 2; //3pitch angkle kiri
          tjKa = 0;//-2 pitch angkle kanan

          invers(KANAN, times, 3 - 3.06 , tinggiBadan , 0 , 0.5);
          invers(KIRI , times , 5 - 3.06 , tinggiBadan - 3.5, -3 , 0.5);
          //Serial.println("================================================Langkah 2==================================================");
          a = 0;
          step = 3;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }

    else if (te < TS * 0.75 && te >= TS * 0.5)
    {
      if ((te - prevte) >= (TS * 0.25 )) {
        if (count == 2) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki3(times);

          prevte = te;
          walkUpdate(TS * 0.75);

          langkah = KIRI;
          tumpuan = KANAN;

          tPa = 0;
          tPi = 5;
          tKa = -5;  //-15.5 Hips
          tKi = 9.5;   //15.5 Hips
          pi = -9; //-8 roll angkle kiri
          pa = -17; //-21.5 roll angkle kanan
          tjKi = 4; //2 pitch angkle kiri kalo di + turun ato jinjit
          tjKa = 0;//pitch angkle kanan

          invers(KANAN, times, 0 , tinggiBadan , 0 , 0);
          invers(KIRI , times , 6 , tinggiBadan - 1.1, -2.5, 0);
          //Serial.println("===============================================Langkah 3===============================================");
          a = 0;
          step = 4;
          transmitPulsa(); transmitPulsaXL(); transmitPulsaAX();
          count++;

        }
      }
    }
    else if (te < TS && te >= TS * 0.75)
    {
      if (((te - prevte) >= (TS * 0.25 ))) {
        if (count == 3) {
          //Serial.print("te:" ); //Serial.println(te);
          //          GJ3Ki4(times);

          prevte = te;
          walkUpdate(TS);
          //      GJ1Ki4(times);
          langkah = KIRI;
          tumpuan = KANAN;
          //      step4_kn(times);
          tjKi = 0;
          tPa = 0;
          tPi = 0;
          tKa = 0;
          tKi = 0;
          pi = 0; //roll
          pa = 0; //badan kanan -
          tjKa = 0;

          invers(KANAN, times + 3, Xt - 3.06 + 2.5, tinggiBadan, 0 , -0.5);
          invers(KIRI, times  + 3, sfX - 3.06 + 2.5, tinggiBadan - sfZ, 0 , -0.5);

          //Serial.println("==============================================Langkah 4=========================================================");
          //Serial.println("MASUK");
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
