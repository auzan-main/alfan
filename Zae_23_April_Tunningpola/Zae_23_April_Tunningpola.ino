 //#include <EEPROM.h>
//#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#define mtx_type double
#define DEBUGOUT Serial
#define deg_to_pulse 11.37777778
#define SerialJuna Serial5
#define SerialSuara Serial4

#define RX_timeOUT_COUNT2 (1600L) //(1000L) //porting
#define NANO_time_DELAY (12000)   //ydh added 20111228 -> 20120210 edited ydh
//#define RX_timeOUT_COUNT1   (RX_timeOUT_COUNT2*90L)// -> 110msec  before Ver 1.11e
#define RX_timeOUT_COUNT1 (RX_timeOUT_COUNT2 * 128L) //  -> 156msec for ID 110 safe access after Ver 1.11f //porting ydh

#define TxDir 6
#define RxDir 3

//_RIGHT FEET_//
#define KANAN1 180 //badan :
#define KANAN2 180 //178+kebelakang -kedepan
#define KANAN3 179 //177
#define KANAN4 180 //ujung kaki : -kebawah +keatas
#define KANAN5 179 //-Kanan +Kiri
#define KANAN6 164 //-Luar +Dalam

//_LEFT FEET_//
#define KIRI11 180
#define KIRI12 181 //-kebelakang +kedepan
#define KIRI13 181 //-Belakang +Depan
#define KIRI14 180 // ujung kaki : +kebawah -keatas
#define KIRI15 182 //+keluar -kedalam
#define KIRI16 170 //18`=1 -Luar +Dalam

//_BODY_//
#define TENGAH7 180
#define TENGAH17 180

//_RIGHT HAND_//
#define KANAN21 60 //60
#define KANAN22 76 //76
#define KANAN23 135
#define KANAN24 156
#define KANAN25 148
#define KANAN26 147 //-keluar

//_LEFT HAND_//
#define KIRI31 238 //236 //yang ini
#define KIRI32 180 //180
#define KIRI33 128
#define KIRI34 215 //145
#define KIRI35 160
#define KIRI36 149 //149 -keluar

//_HEAD_//
#define KEPALA41 136
#define KEPALA42 142 //-hang, 90 aman
#define KEPALA43 40  //132 - keatas + kebawah

#define KANAN 0
#define KIRI 1

///////////
//#define ledMerah 24
//#define ledBiru 25
////#define SwitchMerah
//#define PushOn 38
//#define Panic 37
//#define PushOn 37
//bool inLedMerah, inLedBiru;
//int SwitchIn1, SwitchIn2;
//int imu;
int lastTimeRema = 0, currentTimeRema;
unsigned long waktuIMUPrev;
double errorPrev;
float step_x, step_y, step_z;
float teta, teta1, teta2;
int setpoint_kaki[8][3], koordinat_awal[6][3];
double Xka[5][50], Yka[5][50], Xki[5][50], Yki[5][50];
int pulsa_kaki[6][3];
float dx[6], dy[6];
char data[200];
char kaki_kiri[100], kaki_kanan[100], kaki3[100];
char angkat = 0;
int delay_ms = 500;
//int     time_step = 2000;
char maju;
int setpoin[3];
char mode_sensor;
byte footBase;
byte tumpuan;
byte langkah;

byte length[14];
uint16_t sudutMX[44];

int diff;
int dif[45];

int kaki[40];
int tangan[45];
int time_step[45];
int sdtTP[7];

unsigned long prevte;

bool gb_LED = false;

int kaki_kanan1, kaki_kanan2, kaki_kanan3, kaki_kanan4, kaki_kanan5, kaki_kanan6;
int inGJ6 = 0;

int CountJalan;
int kaki_kiri11, kaki_kiri12, kaki_kiri13, kaki_kiri14, kaki_kiri15, kaki_kiri16;
int time_step1, time_step2, time_step3, time_step4, time_step5, time_step6;
int time_step11, time_step12, time_step13, time_step14, time_step15, time_step16;

double angleCoM[4][7], CoMx, CoMy, CoMz;

// ___________________ Place Global Variable Here ___________________ //
//_Variabel PID dan IMU_//
double kalAngleX, kalAngleY;
char varmenu;
float ePID, lastPitch;
double integralE, lastIntegralE;
//_Variabel Langkah_//
double tp, tn, te, t, TS, Ts, sh, tc, C, S, s;
double i, j, Z, e, X, times, x1, x2, z, comInX, comInY, Zt, vX, vY, Xt, Yt, YtKi, YtKa, sfX, tsup, sfZ, sH, xAwal, yAwal;
//double zKa,xKa,zKi,xKi;
double zKa1, xKa1, zKi1, xKi1;
double zKa2, xKa2, zKi2, xKi2;
double zKa3, xKa3, zKi3, xKi3;
byte step = 5;
byte dataIn = 0x00, dataOut = 0x00;
int adamusik;
int cek = 2;
unsigned long timea[1000], timeb[1000], timec[1000];
unsigned long asd;
int ufo = 0;

double tKa = 0, tKi = 0, tjKa = 0, tjKi = 0, tjKa2 = 0, la = 0, mm = 0, pa = 0, pi = 0, k4 = 0, tPa = 0, tPi = 0, pitchKi = 0, pitchKa = 0;

bool continueStatus;
byte countWalk;

//=====================INVERS===================
double cosQj, cosQm, cosQn;
double Qj, Qk, Qm, Qn;
double Q1, Q2, Q3, Q4, Q5, Qa;
double l1 = 3.52, l2 = 9.51, l3 = 9.5, l4 = 1, z3 = 1;
double LA, LB, Qo, Qp, Qq, c, tb;
double z1 = 3.52, z2, ztot = 21; //max 23.52 apabila x=0
double phi = 3.1428571428571430;
byte F;

#include <Alfan.h>

// ___________________ Prototype Function ________________//
void langkahKiMangkok(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void langkahKaMangkok(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void langkahKi(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void langkahKa(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void invers(byte F, double times, double x, double z, double y);
void servo(byte channel, byte degree, byte speed);

// _________________ Setup Program ____________________//
void setup()
{
  Serial.begin(9600);
  Serial4.begin(38400);
  Serial5.begin(38400);
  Wire1.begin();
  Serial2.begin(1000000);
  delay(100);
  //  /pinMode(ledBiru, OUTPUT);
  //  pinMode(ledMerah, OUTPUT);
  //  //  pinMode(SwitchMerah, INPUT_PULLUP);
  //  pinMode(PushOn, INPUT);
  //    pinMode(Panic, INPUT);
  pinMode(TxDir, OUTPUT); //activeHigh
  pinMode(RxDir, OUTPUT); //activeLow
  digitalWriteFast(TxDir, HIGH);
  digitalWriteFast(RxDir, HIGH);
  //  pinMode(38, INPUT);
  pinMode(35, INPUT_PULLUP);
  digitalWrite(TxDir, 1);
  digitalWrite(RxDir, 1);
  setupSD();
  MXsetup();
  XLsetup();
  AXsetup();

  transmitTorsi(1);
  posisiDefault();
  waitAll(2000);
  pinMode(13, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, INPUT_PULLDOWN);
  digitalWrite(13, HIGH);
  pinMode(6 , OUTPUT);
  digitalWrite(6 , LOW);
  //InversAwal();
  masker(51, 180);
  transmitPulsa();


  //  while (digitalRead(17) == 0)
  //  {
  //    Serial.println("Belom Jalan Bray");
  //  }
  //  BNOsetup();

  //              StartZae();  //IKUZOOOOOOOOOOOOOOOO`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  waitAll(3000);
  //////////////// langkah 1 ///////////////////////
  //  langkahKaInversBaru(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
//  gerakinvers(KIRI, 30+20, 0, 5, 20);
//  gerakinvers(KANAN, 30+20, 0, 5,20);
//   waitAll(2000);
//  gerakinvers(KIRI, 30+20, 3, 0, 20);
//  gerakinvers(KANAN, 30+20, -6, 0,20);
//   waitAll(2000);
   ////////////////// Step 1/////////////
//  gerakinvers(KIRI, 30, 3, 3, 20);
//  gerakinvers(KANAN,  30, 2, 5,17);
//  waitAll(3000);
//  /////////////////// Step 2//////////////
//  gerakinvers(KIRI, 20, 3, 5, 20);
//  gerakinvers(KANAN,  20, 6, 10,15);
//   waitAll(2000);
//   ///////////////////step3////////////////////////////
//  gerakinvers(KIRI, 20, 3, 2, 20);
//  gerakinvers(KANAN,  20, 5, 10,19);
//   waitAll(2000);
   ////////////////Step 4////////////////////////
  //  gerakinvers(0, 30, 9, 0, 17);//kanan turun
  //  gerakinvers(1, 30, 3, 0, 17);//kiri
  //  waitAll(3000);
      langkahKaInversBaru(-3, 3, 20, 3, 4);

  //////////////// langkah 2 ///////////////////////


  ///////////////  langkah 3 ///////////////////////
  //  tampilsudut();

  posisiDefault();


}

void loop()
{
  //  bacaBNO();
}



void masker(byte ID, int posisi)
{
  uint16_t CRC;
  unsigned char CRC_L = 0;
  unsigned char CRC_H = 0;

  uint16_t goalPos = posisi * 1024 / 300;

  uint8_t goalPos_L, goalPos_H;
  goalPos_H = goalPos >> 8;
  goalPos_L = goalPos - (goalPos_H << 8);
  unsigned char TxPacket2[14] = {0xFF, 0xFF, 0xFD, 0x00, ID, 0x07, 0x00, 0x03, 0x1E, 0x00, goalPos_L, goalPos_H, CRC_L, CRC_H};
  CRC = update_crc(0, TxPacket2, 12);
  CRC_L = (CRC & 0x00FF);
  CRC_H = (CRC >> 8) & 0x00FF;
  TxPacket2[12] = CRC_L;
  TxPacket2[13] = CRC_H;

  Serial2.write(TxPacket2, 14);
  return;
}




void gerakinvers (byte F, double times, double x, double y, double ztot)
{


  z2 = ztot - z1 - z3;
  LA = (sqrt((z2 * z2) + (x * x)));
  Serial.println(LA);
  LB = (sqrt((x * x) + (l4 * l4)));
  Serial.println(LB);
  //    Serial.println(LA);
  //    LB = (sqrt((x * x) + (l4 * l4)));
  //    Serial.println(LB);

  cosQj = ((LA * LA) + (l2 * l2) - (l3 * l3)) / (2 * LA * l2);
  cosQm = ((l3 * l3) + (l2 * l2) - (LA * LA)) / (2 * l3 * l2);
  cosQn = ((LA * LA) + (l2 * l2) - (l3 * l3)) / (2 * LA * l3);

  Qj = ((acos(cosQj) / phi) * 180);
  Qk = ((asin(x / LA) / phi) * 180);
  Qm = ((acos(cosQm) / phi) * 180);
  Qn = ((acos(cosQn) / phi) * 180);//(180 - Qj - Qm);
  Qo = ((acos(x / LA) / phi) * 180);
  Qp = ((asin(l4 / LB) / phi) * 180);
  Qq = (180 - Qn - Qo - Qp);
  //  if (x < 0) {
  //    Q1 = -(Qj + Qk);
  //  }
  //  if (x > 0) {
  Q1 = (Qj + Qk);
  //  }
  Q2 = (180 - Qm);
  Q3 = (90 - Qp - Qq);
  Q4 = ((asin(y / (l2 + l3)) / phi) * 180);
  Qa = ((acos(y / (l2 + l3)) / phi) * 180);
  Q5 = (180 - 90 - Qa);


  if (F == 0) {
    dynamixel(1, 2, KANAN2 - Q1, times); //-maju,+mundur //dynamixel(1, 2, KANAN2 - t1 - (90 - tb) - PID_Roll, times * 0.95); //-maju,+mundur
    dynamixel(1, 3, KANAN3 + Q2, times); //+nekuk
    dynamixel(1, 4, KANAN4 + Q3, times);
    dynamixel(1, 5, KANAN5 - Q4, times);
    dynamixel(1, 6, KANAN6 - Q5, times);
    waitAll (100);
  }

  else if (F == 1) {
    dynamixel(1, 12, KIRI12 + Q1, times); //-nekuk
    dynamixel(1, 13, KIRI13 - Q2, times); //+jinjit //dynamixel(1, 14, KIRI14 - t3 + tjKi+PID_Roll, times); //+jinjit
    dynamixel(1, 14, KIRI14 - Q3, times); //-buka,+nutup  times * 0.95
    dynamixel(1, 15, KIRI15 - Q4, times); //-mundur,+maju //dynamixel(1, 12, KIRI12 + t1 + (90 - tb) + PID_Roll, times * 0.95); //-mundur,+maju
    dynamixel(1, 16, KIRI16 - Q5, times); //+buka,-nutup
    waitAll(100);
  }
}


void tampilsudut() {
  Serial.print("Sudut Theta 1:");
  Serial.println(Q1);
  Serial.print("Sudut Theta 2:");
  Serial.println(Q2);
  Serial.print("Sudut Theta 3:");
  Serial.println(Q3);
  Serial.print("Sudut Theta 4:");
  Serial.println(Q4);
  Serial.print("Sudut Theta a:");
  Serial.println(Qa);
  Serial.print("Sudut Theta 5:");
  Serial.println(Q5);
  Serial.print("LA:");
  Serial.println(LA);
  Serial.print("LB:");
  Serial.println(LB);
  Serial.print("Qj:");
  Serial.println(Qj);
  Serial.print("Qk :");
  Serial.println(Qk);
  Serial.print("Cos Qj :");
  Serial.println(cosQj);
}


void langkahKaInversBaru(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
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

          gerakinvers(KIRI, times + 3, 3 - 3.06, 0 , tinggiBadan);
          gerakinvers(KANAN , times + 3, -3 - 3.06 , 0, tinggiBadan);
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
          gerakinvers(KIRI, times  + 3, 3 - 3.06, 0, tinggiBadan);
          gerakinvers(KANAN, times  + 3, 5.5 - 3.06, -5, tinggiBadan - 3.5);
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
//          gerakinvers(KIRI, times + 3, 0  , 0 , tinggiBadan);
//          gerakinvers(KANAN, times + 3, 7 , 2.5, tinggiBadan - 0.7);
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

//          gerakinvers(KIRI, times+3, -3 , 0, tinggiBadan); //m+ badan depan
//          gerakinvers(KANAN, times+3, 3, 0 , tinggiBadan - sfZ);
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

void langkahKiInversBaru(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah)
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

          gerakinvers(KIRI, times, 3 - 3.06, 0 , tinggiBadan);
          gerakinvers(KANAN , times , -3 - 3.06 , 0, tinggiBadan);
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
          gerakinvers(KIRI, times + 3 , 3 - 3.06, 0, tinggiBadan);
          gerakinvers(KANAN, times + 3 , 5.5 - 3.06, 3.2, tinggiBadan - 3.5);
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
          gerakinvers(KIRI, times + 3, 0  , 0 , tinggiBadan);
          gerakinvers(KANAN, times + 3, 7 , 2.5, tinggiBadan - 0.7);
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

          gerakinvers(KIRI, times + 3, -3 , 0, tinggiBadan); //m+ badan depan
          gerakinvers(KANAN, times + 3, 3, 0 , tinggiBadan - sfZ);
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
