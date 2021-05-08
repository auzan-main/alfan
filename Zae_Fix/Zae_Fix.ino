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
//int lastTimeRema = 0, currentTimeRema;
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



  //  dynamixeldef(1, 7, 100, 10);
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
  waitAll(1000);
  /*============== arah invers======
     nb : arah kaki berlawanan dengan arah badan tergantung stay di ground atau enggak(kaki base)
   * *ketika kaki jadi base.
     +x = badan kebelakang
     -x = badan kedepan
     +y = badan ke kiri
     -y = badan ke kanan
     +z = badan keatas
     -z = badan kebawah
  */

  //              StartZae();  //IKUZOOOOOOOOOOOOOOOO`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  /*
     Langkah Kanan
  */

//    tb = 30;
  //    dynamixel(1, 4, KANAN4-tjKa, 20);
//    gerakinvers(KIRI, 20, 0, 0, 23.5);
//    gerakinvers(KANAN, 20, 0, 0, 23.5);
//    waitAll(4000);
  //start
  gerakinvers(KANAN, 20, 0, 0, 20);
  gerakinvers(KIRI, 20, -6, 0, 20);
  waitAll(4000);
  ////  ////////////////// Step 1/////////////
  //    gerakinvers(KIRI, 5, 0, 2, 20);
  //    gerakinvers(KANAN, 5, -6, 1, 20);
  //  waitAll(500);
  //  //////  ////  /////////////////// Step 2//////////////
  //  gerakinvers(KIRI, 5, 0 - 2, 2 + 4, 20);
  //  gerakinvers(KANAN, 5, -6 + 1, 6+3, 20 - 2.5); //Y=10, Z=16
  //  waitAll(500);
  //  ////////  ////   ///////////////////step3////////////////////////////
  //  gerakinvers(KIRI, 5, -3 - 3, 5 + 2, 20);
  //  gerakinvers(KANAN, 5, -2, 10, 20 - 2);
  //  waitAll(500);
  //  ////////  //   ////////////////Step 4 fix////////////////////////
  //  gerakinvers(KIRI, 5, -8, 0, 20);
  //  gerakinvers(KANAN, 5, 0, 0, 20);//kiri
  //  waitAll(500);

  /*
     Langkah Kiri
  */
  //start
  //  gerakinvers(KIRI, 5, -3, 0, 20);
  //  gerakinvers(KANAN, 5, 3.5, 0, 20);//kiri
  //  waitAll(4000);
  //  //  ////////////////// Step 1/////////////
  //  gerakinvers(KIRI, 5, -3, -3, 20);
  //  gerakinvers(KANAN, 5, 3.5, -2, 20);
  //  waitAll(800);
  //  /////  ////  /////////////////// Step 2//////////////
  //  gerakinvers(KIRI, 5, 2, -10, 17);
  //  gerakinvers(KANAN, 5, 3.5, -5.8, 20);//Y=10, Z=16
  //  waitAll(800);
  langkahKiInversBaru(-3, 3, 20, 3, 2);
  waitAll(200);
  langkahKaInversBaru(-3, 3, 20, 3, 2);
  waitAll(200);
  langkahKiInversBaru(-3, 3, 20, 3, 2);
  waitAll(200);
  langkahKaInversBaru(-3, 3, 20, 3, 2);
  waitAll(200);
}

void loop()
{
  //  bacaBNOAwal();
  //  delay(3000);
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

/*nb : tb itu untuk pergerakan servo 2 dan 12 bersamaan biar bisa majuin/mundurin badan
        (+ badan kebelakang - badan kedepan)
*/
  if (F == 0) {
    dynamixel(1, 1, KANAN1 + tPa, times);//+servo 1 mutar ke kanan(kondisi swing)
    dynamixel(1, 2, KANAN2 - Q1 + tb, times); // //dynamixel(1, 2, KANAN2 - t1 - (90 - tb) - PID_Roll, times * 0.95); //-maju,+mundur
    dynamixel(1, 3, KANAN3 + Q2, times);
    dynamixel(1, 4, KANAN4 + Q3 - tjKa, times);//(swing : +tapak kaki hadap belakang)(base : +badan kebelakang)
    dynamixel(1, 5, KANAN5 - Q4 - tKa, times);//(swing : + kaki kekanan)(base : +badan ke kanan)
    dynamixel(1, 6, KANAN6 - Q5 - pa, times);//(base : +badan kekiri) (swing : +tapak kaki hadap kiri)
    waitAll (100);
  }

  else if (F == 1) {
    dynamixel(1, 11, KIRI11 + tPi, times);//+servo 11 mutar ke kanan(kondisi swing)
    dynamixel(1, 12, KIRI12 + Q1 - tb, times); //
    dynamixel(1, 13, KIRI13 - Q2, times); // //dynamixel(1, 14, KIRI14 - t3 + tjKi+PID_Roll, times); //+jinjit
    dynamixel(1, 14, KIRI14 - Q3 + tjKi, times); //(swing : +tapak kaki hadap belakang)(base : +badan kebelakang)
    dynamixel(1, 15, KIRI15 - Q4 + tKi, times); //(swing : + kaki kekiri)(base : +badan ke kiri)
    dynamixel(1, 16, KIRI16 - Q5 - pi, times); //(base : +badan kekiri) (swing: +tapak kaki hadap kiri)
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

          tb = 0;
          tPa = 0;      
          tPi = 0;      
          tKa = 0; //14  
          tKi = 0; //-11.5 
          pi = 0; //15    
          pa = 0; //15    
          tjKa = 0;//-0.5  
          tjKi = 0;//-2  

          gerakinvers(KIRI, times , 0 , 2 , tinggiBadan);
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

          tb = -7;
          tPa = -3;//-1
          tPi = 0;
          tKa = 5;//8.5   
          tKi = 0;//-7.5   
          pi = 3; //18    
          pa = 0;//7     
          tjKa = 10;//-1   
          tjKi = 0;//-1  
          gerakinvers(KIRI, times+3 , 0 - 2, 2+3+1 , tinggiBadan);//y = 2+3 
          gerakinvers(KANAN, times+3 , -6 + 2, 6+4, tinggiBadan - 3);//y = 6+4
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

          tb = -5;
          tPa = -5;//-1 
          tPi = 0; 
          tKa = 4;//8   
          tKi = 0;//-6  
          pi = 3;//14    
          pa = 0;//7    
          tjKa = 10;//-2  
          tjKi = 0;//-1  
          gerakinvers(KIRI, times , 0 - 2  ,  3 +2+1, tinggiBadan);
          gerakinvers(KANAN, times , -2+3 , 6+4, tinggiBadan - 2.5);//y = 10+3
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

          gerakinvers(KIRI, times+5 , -6 , 0, tinggiBadan);
          gerakinvers(KANAN, times +5, 0, 0 , tinggiBadan );
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
          tb = 0;
          tPa = 0;      
          tPi = 0;      
          tKa = 0; //14  
          tKi = 0; //-11.5 
          pi = 0; //15    
          pa = 0; //15    
          tjKa = 0;//-0.5  
          tjKi = 0;//-2  

          gerakinvers(KANAN, times , 0 , -2 , tinggiBadan);
          gerakinvers(KIRI , times , -3 - 3.06 , 0, tinggiBadan);
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

          tb = -10;
          tPa = 0;//-1
          tPi = 3;
          tKa = 0;//8.5   
          tKi = 5;//-7.5   
          pi = 0; //18    
          pa = -2;//7     
          tjKa = 0;//-1   
          tjKi = 10;//-1  
          gerakinvers(KANAN, times+3 , 0 - 2, -2-3 , tinggiBadan);//y = 2+3 
          gerakinvers(KIRI, times+3 , -6 + 2, -6-3, tinggiBadan - 3);//y = 6+4
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

          tb = -7;
          tPa = 0;//-1 
          tPi = 6; 
          tKa = 0;//8   
          tKi = 4;//-6  
          pi = 0;//14    
          pa = -1;//7    
          tjKa = 0;//-2  
          tjKi = 10;//-1  
          gerakinvers(KANAN, times , 0 - 2  ,  -2 -2, tinggiBadan);
          gerakinvers(KIRI, times , -2+3 , -6-3, tinggiBadan - 2.5);//y = 10+3
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

          tb = -3;
          tPa = 0;
          tPi = 0;
          tKa = 0;  //hips
          tKi = 0;  //hips
          pi = 0;   //roll agkle kiri
          pa = 0;   //roll angkle kanan
          tjKa = 0; //pitch kanan
          tjKi = 0; //pitch kiri

          gerakinvers(KIRI, times+5 , 0 , 0, tinggiBadan);
          gerakinvers(KANAN, times +5, -6, 0 , tinggiBadan );
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
