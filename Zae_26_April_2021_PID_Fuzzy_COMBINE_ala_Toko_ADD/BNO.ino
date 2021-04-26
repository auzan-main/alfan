#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

int lastTimeRema = 0, currentTimeRema;

float presErrorPitch, presPosPitch, prevErrPitch = 0;
float presErrorRoll, presPosRoll, prevErrRoll = 0;
float presPosYaw;
float errorAccumPitch, errorAccumRoll = 0;                   //buat integrator
float dErr = 0;                                                  //buat differentiator
float nextGoalPitch, nextGoalRoll_Kanan ,nextGoalRoll_Kiri = 0;
float defaultBNO_Pitch, defaultBNO_Roll, defaultBNO_Yaw = 0;
long int prevRead, timeNow = 0;

float Kp_Pitch = 0, Ki_Pitch = 0, Kd_Pitch = 0;
float Kp_Roll_Kanan = 0 , Ki_Roll_Kanan = 0, Kd_Roll_Kanan = 0;
float Kp_Roll_Kiri = 0 , Ki_Roll_Kiri = 0, Kd_Roll_Kiri = 0;

////////////////////////tunning//////////////////////////

/////////////Walk periode 2/////////////////////

//float Kp_Pitch = 0.8 , Ki_Pitch = 0.2, Kd_Pitch = 1;
//float Kp_Pitch = 0.7 , Ki_Pitch = 0.2, Kd_Pitch = 0.5; //error ekstrim
//float Kp_Pitch = 0.4 , Ki_Pitch = 0.1, Kd_Pitch = 0.4; //error sedang
//float Kp_Pitch_Kanan = 0.3 , Ki_Pitch_Kanan = 0.1, Kd_Pitch_Kanan = 0.3; //error rendah
//float Kp_Pitch = 0.3 , Ki_Pitch = 0.1, Kd_Pitch = 0.3; //error rendah
//float Kp_Roll = 1.2 , Ki_Roll = 0.2, Kd_Roll = 1;
//float Kp_Roll = 0.9 , Ki_Roll = 0.2, Kd_Roll = 0.5; //error ekstrim
//float Kp_Roll = 0.4 , Ki_Roll = 0.2, Kd_Roll = 0.2; //error sedang
//float Kp_Roll = 0.1 , Ki_Roll = 0.05, Kd_Roll = 0.05; //error rendah
//float Kp_Roll_Kanan = 0.2 , Ki_Roll_Kanan = 0.5, Kd_Roll_Kanan = 0.5; //error rendah
//float Kp_Roll_Kiri = 0.15 , Ki_Roll_Kiri = 0.2, Kd_Roll_Kiri = 0.2; //error rendah

/*
 * untuk ROll error rendah untuk error < 10 derajat. Error sedang untuk 10 < error < 15. Error ekstrim untuk error > 15.
 * untuk PITCH error rendah untuk error < 5 derajat. Error sedang untuk 5 < error < 10. Error ekstrim untuk error > 10.
 */

////////////ini buat FASTER walk periode 1.5///////////////////

//float Kp_Pitch = 0.7 , Ki_Pitch = 0.2, Kd_Pitch = 0.5; //error ekstrim
//float Kp_Pitch = 0.4 , Ki_Pitch = 0.1, Kd_Pitch = 0.4; //error sedang
//float Kp_Pitch = 0.3 , Ki_Pitch = 0.1, Kd_Pitch = 0.3; //error rendah
//float Kp_Roll = 0.9 , Ki_Roll = 0.2, Kd_Roll = 0.5; //error ekstrim
//float Kp_Roll = 0.4 , Ki_Roll = 0.2, Kd_Roll = 0.2; //error sedang
//float Kp_Roll = 0.1 , Ki_Roll = 0.05, Kd_Roll = 0.05; //error rendah

/////////////////////////////////////////////////////////

void BNOsetup() {
  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }

  delay(1000);
  bno.setExtCrystalUse(true);
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  defaultBNO_Pitch = euler.y();
  defaultBNO_Roll = euler.z();
  defaultBNO_Yaw = euler.x();
  delay(2000);
  prevRead = millis();
}

void bacaBNOAwal() {
  errorAccumPitch = 0;
  errorAccumRoll = 0;
  prevErrPitch = 0;
  prevErrRoll = 0;
  prevRead = 0;
  prevRead = millis(); //baca BNO awal sama bukan bedanya cuma disini
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  presPosPitch = euler.y();
  presPosRoll = euler.z();
  presPosYaw = euler.x();
  timeNow = millis();

//  Serial.print(" Pitch: "); Serial.print(presPosPitch); Serial.print("\t\t");
//  Serial.print(" Roll : "); Serial.print(presPosRoll); Serial.println("\t\t");

  presErrorPitch = presPosPitch - defaultBNO_Pitch;
  Kp_Pitch = calculateFuzzy(1 , presErrorPitch, 1);
  Ki_Pitch = calculateFuzzy(1 , presErrorPitch, 2);
  Kd_Pitch = calculateFuzzy(1 , presErrorPitch, 3);
  errorAccumPitch = errorAccumPitch + presErrorPitch;
  dErr = (presErrorPitch - prevErrPitch) / (timeNow - prevRead);
  Serial.print("kp");
  Serial.println(Kp_Pitch);
  Serial.print("ki");
  Serial.println(Ki_Pitch);
  Serial.print("kd");
  Serial.println(Kd_Pitch);
//  Serial.print("EPitch: "); Serial.print(presErrorPitch);  Serial.print("\t\t");
  nextGoalPitch = Kp_Pitch * presErrorPitch + Ki_Pitch * errorAccumPitch + Kd_Pitch * dErr;

  presErrorRoll = presPosRoll - defaultBNO_Roll;
  Kp_Roll_Kanan = calculateFuzzy(2 , presErrorRoll, 1);
  Ki_Roll_Kanan = calculateFuzzy(2 , presErrorRoll, 2);
  Kd_Roll_Kanan = calculateFuzzy(2 , presErrorRoll, 3);
  Kp_Roll_Kiri  = calculateFuzzy(2 , presErrorRoll, 1);
  Ki_Roll_Kiri  = calculateFuzzy(2 , presErrorRoll, 2);
  Kd_Roll_Kiri  = calculateFuzzy(2 , presErrorRoll, 3);
  errorAccumRoll = errorAccumRoll + presErrorRoll;
  dErr = (presErrorRoll - prevErrRoll) / (timeNow - prevRead);
//  Serial.print("ERoll : "); Serial.print(presErrorRoll);  Serial.println("\t\t\n");
  nextGoalRoll_Kanan = Kp_Roll_Kanan * presErrorRoll + Ki_Roll_Kanan * errorAccumRoll + Kd_Roll_Kanan * dErr;
  nextGoalRoll_Kiri = Kp_Roll_Kiri * presErrorRoll + Ki_Roll_Kiri * errorAccumRoll + Kd_Roll_Kiri * dErr;
  // untuk masalah timing sementara approachnya tunning

  prevErrPitch = presErrorPitch;
  prevErrRoll = presErrorRoll;
  prevRead = timeNow;
  currentTimeRema = millis();
  if ((currentTimeRema - lastTimeRema) >= 10) {
//    Serial.print(presErrorPitch / 1);
//    Serial.print(" ");
//    Serial.println(presErrorRoll / 1);
    lastTimeRema = millis();
  }
}

void bacaBNO() {
  //  prevRead = millis(); //baca BNO awal sama bukan bedanya cuma disini
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  presPosPitch = euler.y();
  presPosRoll = euler.z();
  presPosYaw = euler.x();
  timeNow = millis();

//  Serial.print(" Pitch: "); Serial.print(presPosPitch); Serial.print("\t\t");
//  Serial.print(" Roll : "); Serial.print(presPosRoll); Serial.println("\t\t");

  presErrorPitch = presPosPitch - defaultBNO_Pitch;
  errorAccumPitch = errorAccumPitch + presErrorPitch;
  dErr = (presErrorPitch - prevErrPitch) / (timeNow - prevRead);
//  Serial.print("EPitch: "); Serial.print(presErrorPitch);  Serial.print("\t\t");
  nextGoalPitch = Kp_Pitch * presErrorPitch + Ki_Pitch * errorAccumPitch + Kd_Pitch * dErr;

  presErrorRoll = presPosRoll - defaultBNO_Roll;
  errorAccumRoll = errorAccumRoll + presErrorRoll;
  dErr = (presErrorRoll - prevErrRoll) / (timeNow - prevRead);
//  Serial.print("ERoll : "); Serial.print(presErrorRoll);  Serial.println("\t\t\n");
  nextGoalRoll_Kanan = Kp_Roll_Kanan * presErrorRoll + Ki_Roll_Kanan * errorAccumRoll + Kd_Roll_Kanan * dErr;
  nextGoalRoll_Kiri = Kp_Roll_Kiri * presErrorRoll + Ki_Roll_Kiri * errorAccumRoll + Kd_Roll_Kiri * dErr;

  prevErrPitch = presErrorPitch;
  prevErrRoll = presErrorRoll;
  prevRead = timeNow;
  currentTimeRema = millis();
  if ((currentTimeRema - lastTimeRema) >= 10) {
    Serial.print(presErrorPitch / 1);
    Serial.print(" ");
    Serial.println(presErrorRoll / 1);
    lastTimeRema = millis();
  }
}
