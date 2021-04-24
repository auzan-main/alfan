#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
//ini bno
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

float presErrorPitch, presPosPitch, prevErrPitch = 0;
float presErrorRoll, presPosRoll, prevErrRoll = 0;
float presPosYaw;
float errorAccumPitch, errorAccumRoll = 0;                   //buat integrator
float dErr = 0;                                                  //buat differentiator
float nextGoalPitch, nextGoalRoll = 0;
float defaultBNO_Pitch, defaultBNO_Roll, defaultBNO_Yaw = 0;
long int prevRead, timeNow = 0;

////////////////////////tunning//////////////////////////

float Kp_Pitch = 0.8 , Ki_Pitch = 0.2, Kd_Pitch = 1;

//float Kp_Roll = 0.43 , Ki_Roll = 0.15, Kd_Roll = 1;
float Kp_Roll = 1.2 , Ki_Roll = 0.2, Kd_Roll = 1;

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
  prevRead = millis(); //baca BNO awal sama bukan bedanya cuma disini
}

void bacaBNOAwal() {
  prevRead = millis(); //baca BNO awal sama bukan bedanya cuma disini
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
  nextGoalRoll = Kp_Roll * presErrorRoll + Ki_Roll * errorAccumRoll + Kd_Roll * dErr;

  //  dynamixel(1, 4,180 + nextGoalPitch, 1);
  //  kaKi_Pitch[2] = ((180 - nextGoalPitch) * 4095) / 360;
  //  kaKi_Pitch[12] = ((180 + nextGoalPitch) * 4095) / 360;
  //  time_step[2] = 0;
  //  time_step[12] = 0;
  //  transmitPulsaMX();

  // untuk masalah timing sementara approachnya tunning

  prevErrPitch = presErrorPitch;
  prevErrRoll = presErrorRoll;
  prevRead = timeNow;

  //  delay(10);
  //  delayMicroseconds(BNO055_SAMPLERATE_DELAY_MS);
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
  currentTimeRema = millis();
  //  Serial.print("EPitch: "); Serial.print(presErrorPitch);  Serial.print("\t\t");
  nextGoalPitch = Kp_Pitch * presErrorPitch + Ki_Pitch * errorAccumPitch + Kd_Pitch * dErr;

  presErrorRoll = presPosRoll - defaultBNO_Roll;
  errorAccumRoll = errorAccumRoll + presErrorRoll;
  dErr = (presErrorRoll - prevErrRoll) / (timeNow - prevRead);
  //  Serial.print("ERoll : "); Serial.print(presErrorRoll);  Serial.println("\t\t\n");
  nextGoalRoll = Kp_Roll * presErrorRoll + Ki_Roll * errorAccumRoll + Kd_Roll * dErr;

  //   dynamixel(1, 4,180 + nextGoalPitch, 1);
  //  kaKi_Pitch[2] = ((180 - nextGoalPitch) * 4095) / 360;
  //  kaKi_Pitch[12] = ((180 + nextGoalPitch) * 4095) / 360;
  //  time_step[2] = 0;
  //  time_step[12] = 0;
  //  transmitPulsaMX();
  // untuk masalah timing sementara approachnya tunning

  prevErrPitch = presErrorPitch;
  prevErrRoll = presErrorRoll;
  prevRead = timeNow;
  if ((currentTimeRema - lastTimeRema) >= 200) {
    Serial.print(presErrorPitch / 10);
    Serial.print(" ");
    Serial.println(presErrorRoll / 10);
    lastTimeRema = millis();
  }
  //  delay(10);
  //  delayMicroseconds(BNO055_SAMPLERATE_DELAY_MS);
}
