//#include <EEPROM.h>
//#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#define mtx_type double
#define DEBUGOUT Serial
#define deg_to_pulse 11.37777778
#define SerialJuna Serial5
#define SerialSuara Serial4

#define RX_timeOUT_COUNT2    (1600L) //(1000L) //porting
#define NANO_time_DELAY     (12000) //ydh added 20111228 -> 20120210 edited ydh
//#define RX_timeOUT_COUNT1   (RX_timeOUT_COUNT2*90L)// -> 110msec  before Ver 1.11e
#define RX_timeOUT_COUNT1     (RX_timeOUT_COUNT2*128L)//  -> 156msec for ID 110 safe access after Ver 1.11f //porting ydh

#define TxDir 6
#define RxDir 3

//_RIGHT FEET_//
#define KANAN1 178//badan :
#define KANAN2 180//178+kebelakang -kedepan
#define KANAN3 179//177
#define KANAN4 180 //ujung kaki : -kebawah +keatas
#define KANAN5 179//-Kanan +Kiri
#define KANAN6 164//-Luar +Dalam

//_LEFT FEET_//
#define KIRI11 182
#define KIRI12 181//-kebelakang +kedepan
#define KIRI13 181//-Belakang +Depan
#define KIRI14 180 // ujung kaki : +kebawah -keatas
#define KIRI15 182//+keluar -kedalam
#define KIRI16 170//18`=1 -Luar +Dalam

//_BODY_//
#define TENGAH7 180
#define TENGAH17 180

//_RIGHT HAND_//
#define KANAN21 60 //60
#define KANAN22 76//76
#define KANAN23 135
#define KANAN24 156
#define KANAN25 148
#define KANAN26 147 //-keluar

//_LEFT HAND_//
#define KIRI31 238  //236 //yang ini
#define KIRI32 180  //180
#define KIRI33 128
#define KIRI34 215 //145
#define KIRI35 160
#define KIRI36 149 //149 -keluar

//_HEAD_//
#define KEPALA41 136
#define KEPALA42 142//-hang, 90 aman
#define KEPALA43 143//40 - keatas + kebawah

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
unsigned long waktuIMUPrev;
double errorPrev;
float   step_x, step_y, step_z;
float   teta, teta1, teta2;
int     setpoint_kaki[8][3], koordinat_awal[6][3];
double Xka[5][50] , Yka[5][50], Xki[5][50], Yki[5][50];
int     pulsa_kaki[6][3];
float   dx[6], dy[6];
char    data[200];
char    kaki_kiri[100], kaki_kanan[100], kaki3[100];
char    angkat = 0;
int     delay_ms  = 500;
//int     time_step = 2000;
char    maju;
int     setpoin[3];
char    mode_sensor;
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
double tp, tn, te, t, TS, Ts, sh, tc, C , S, s;
double i, j, Z, e, X, times, x1, x2, z, comInX, comInY, Zt, vX, vY, Xt, Yt, YtKi, YtKa, sfX, tsup, sfZ, sH, xAwal, yAwal;
//double zKa,xKa,zKi,xKi;
double zKa1, xKa1, zKi1, xKi1;
double zKa2, xKa2, zKi2, xKi2;
double zKa3, xKa3, zKi3, xKi3;
byte step = 5;
byte dataIn = 0x00, dataOut = 0x00;
int adamusik;
int cek = 2;
unsigned long timea[1000] , timeb[1000] , timec[1000];
unsigned long asd;
int ufo = 0;


double tKa = 0, tKi = 0, tjKa = 0, tjKi = 0, tjKa2 = 0, la = 0, mm = 0, l4 = 0, pa = 0, pi = 0, k4 = 0, tPa = 0, tPi = 0, pitchKi = 0, pitchKa = 0;

bool continueStatus;
byte countWalk;

#include <Alfan.h>

// ___________________ Prototype Function ________________//
void langkahKiMangkok(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void langkahKaMangkok(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void langkahKi(double xKakiKiri, double xKakiKanan, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void langkahKa(double xKakiKanan, double xKakiKiri, double tinggiBadan, double tinggiLangkah, double periodeLangkah);
void invers(byte F, double times, double x, double z, double y);
void servo(byte channel, byte degree, byte speed);

// _________________ Setup Program ____________________//
void setup() {
  Serial.begin(9600);
  Serial4.begin(38400);
  Serial5.begin(38400);
  Wire1.begin();
  Serial2.begin(1000000);
  delay(100);
  pinMode(TxDir, OUTPUT); //activeHigh
  pinMode(RxDir, OUTPUT); //activeLow
  digitalWriteFast(TxDir, HIGH);
  digitalWriteFast(RxDir, HIGH);
  pinMode(35, INPUT_PULLUP);
  digitalWrite(TxDir, 1);
  digitalWrite(RxDir, 1);
  pinMode(13, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, INPUT_PULLDOWN);
  digitalWrite(13, HIGH);
  Serial.println("Mulai oi");
  setupSD();
  MXsetup();
  XLsetup();
  AXsetup();
  setupFuzzy();

  transmitTorsi(1);
  posisiDefault();
  waitAll(2000);
  
  InversAwal();
  waitAll(3000);
  
  int HUAHAHA = digitalRead(17);
//  while (digitalRead(17) == HUAHAHA) {
//  }
  BNOsetup();

  //  masker(51, 270);
  //  defaultTangan(30);
  //  waitAll(3000);

  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  //...........................................................................................


//                StartZae();  //IKUZOOOOOOOOOOOOOOOO`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  //...........................................................................................
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  /////////////////////////////Ngerekam timing gerakan//////////////////////
  
  //  rekamWaktu();

  /////////////////////////////nyampah buat coba coba///////////////////////



  /////////////////////////////nyampah buat tunning/////////////////////////
//walkTestingPID(); //periode jalan 2
//walkTestingPID_FASTER(); //periode jalan 1.5
}


void loop() {
//  walkTestingPID(); //periode jalan 2
//  Serial.println("Bodoh");
  bacaBNOAwal();
  delay(2000);
//walkTestingPID_FASTER(); //periode jalan 1.5

}




void InversAwal() {
  invers(KANAN, 30, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 30, 3 - 3.06, 16.6, 0, 0);
}
