#include <Fuzzy.h>

// Instantiating a Fuzzy object
Fuzzy *fuzzy = new Fuzzy();

void setupFuzzy()
{
  // Set the Serial output
  //  Serial.begin(9600);


  // Instantiating a FuzzyInput object
  FuzzyInput *pitch = new FuzzyInput(1);
  // Instantiating a FuzzySet object
  FuzzySet *rendah = new FuzzySet(0, 0, 4, 6);
  // Including the FuzzySet into FuzzyInput
  pitch->addFuzzySet(rendah);
  // Instantiating a FuzzySet object
  FuzzySet *sedang = new FuzzySet(4, 6, 9, 11);
  // Including the FuzzySet into FuzzyInput
  pitch->addFuzzySet(sedang);
  // Instantiating a FuzzySet object
  FuzzySet *ekstrim = new FuzzySet(9, 11, 20, 20);
  // Including the FuzzySet into FuzzyInput
  pitch->addFuzzySet(ekstrim);
  // Including the FuzzyInput into Fuzzy
  fuzzy->addFuzzyInput(pitch);

  FuzzyInput *roll = new FuzzyInput(2);
  // Instantiating a FuzzySet object
  FuzzySet *Rrendah = new FuzzySet(0, 0, 10, 11);
  // Including the FuzzySet into FuzzyInput
  roll->addFuzzySet(Rrendah);
  // Instantiating a FuzzySet object
  FuzzySet *Rsedang = new FuzzySet(10, 11, 14, 16);
  // Including the FuzzySet into FuzzyInput
  roll->addFuzzySet(Rsedang);
  // Instantiating a FuzzySet object
  FuzzySet *Rekstrim = new FuzzySet(14, 16, 22, 22);
  // Including the FuzzySet into FuzzyInput
  roll->addFuzzySet(Rekstrim);
  // Including the FuzzyInput into Fuzzy
  fuzzy->addFuzzyInput(roll);


  // Instantiating a FuzzyOutput objects
  FuzzyOutput *kp = new FuzzyOutput(1);
  // Instantiating a FuzzySet object
  FuzzySet *kprendah = new FuzzySet(0.1, 0.1, 0.3, 0.5);
  // Including the FuzzySet into FuzzyOutput
  kp->addFuzzySet(kprendah);
  // Instantiating a FuzzySet object
  FuzzySet *kpsedang = new FuzzySet(0.3, 0.5, 0.7, 0.9);
  // Including the FuzzySet into FuzzyOutput
  kp->addFuzzySet(kpsedang);
  // Instantiating a FuzzySet object
  FuzzySet *kpekstrim = new FuzzySet(0.7, 0.9, 1.1, 1.1);
  // Including the FuzzySet into FuzzyOutput
  kp->addFuzzySet(kpekstrim);
  // Including the FuzzyOutput into Fuzzy
  fuzzy->addFuzzyOutput(kp);

  // Instantiating a FuzzyOutput objects
  FuzzyOutput *ki = new FuzzyOutput(2);
  // Instantiating a FuzzySet object
  FuzzySet *kirendah = new FuzzySet(0.01, 0.01, 0.1, 0.2);
  // Including the FuzzySet into FuzzyOutput
  ki->addFuzzySet(kirendah);
  // Instantiating a FuzzySet object
  FuzzySet *kitinggi = new FuzzySet(0.1, 0.2, 0.3, 0.3);
  // Including the FuzzySet into FuzzyOutput
  ki->addFuzzySet(kitinggi);
  // Instantiating a FuzzySet object
  fuzzy->addFuzzyOutput(ki);

  // Instantiating a FuzzyOutput objects
  FuzzyOutput *kd = new FuzzyOutput(3);
  // Instantiating a FuzzySet object
  FuzzySet *kdrendah = new FuzzySet(0.1, 0.1, 0.3, 0.4);
  // Including the FuzzySet into FuzzyOutput
  kd->addFuzzySet(kdrendah);
  // Instantiating a FuzzySet object
  FuzzySet *kdsedang = new FuzzySet(0.3, 0.4, 0.4, 0.5);
  // Including the FuzzySet into FuzzyOutput
  kd->addFuzzySet(kdsedang);
  // Instantiating a FuzzySet object
  FuzzySet *kdekstrim = new FuzzySet(0.4, 0.5, 0.7, 0.7);
  // Including the FuzzySet into FuzzyOutput
  kd->addFuzzySet(kdekstrim);
  // Including the FuzzyOutput into Fuzzy
  fuzzy->addFuzzyOutput(kd);

  // Building FuzzyRule "IF pitch = small THEN kp = slow"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *ifrendah = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifrendah->joinSingle(rendah);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKprendah = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKprendah->addOutput(kprendah);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule01 = new FuzzyRule(1, ifrendah, thenKprendah);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule01);

  FuzzyRuleAntecedent *ifRendah = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRendah->joinSingle(rendah);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKirendah = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKirendah->addOutput(kirendah);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule04 = new FuzzyRule(4, ifRendah, thenKirendah);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule04);

  FuzzyRuleAntecedent *ifREndah = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifREndah->joinSingle(rendah);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKdrendah = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKirendah->addOutput(kdrendah);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule05 = new FuzzyRule(5, ifREndah, thenKdrendah);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule05);

  // Building FuzzyRule "IF pitch = safe THEN kp = average"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *ifsedang = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifsedang->joinSingle(sedang);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKpsedang = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKpsedang->addOutput(kpsedang);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule02 = new FuzzyRule(2, ifsedang, thenKpsedang);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule02);

  FuzzyRuleAntecedent *ifSedang = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifSedang->joinSingle(sedang);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKitinggi = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKitinggi->addOutput(kitinggi);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule06 = new FuzzyRule(6, ifSedang, thenKitinggi);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule06);

  FuzzyRuleAntecedent *ifSEdang = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifSEdang->joinSingle(sedang);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKdsedang = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKdsedang->addOutput(kdsedang);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule07 = new FuzzyRule(7, ifsedang, thenKdsedang);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule07);

  // Building FuzzyRule "IF pitch = big THEN kp = high"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *ifekstrim = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifekstrim->joinSingle(ekstrim);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKpekstrim = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKpekstrim->addOutput(kpekstrim);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule03 = new FuzzyRule(3, ifekstrim, thenKpekstrim);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule03);

  FuzzyRuleAntecedent *ifEkstrim = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifEkstrim->joinSingle(ekstrim);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenkitinggi = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenkitinggi->addOutput(kitinggi);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule08 = new FuzzyRule(8, ifEkstrim, thenkitinggi);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule08);

  FuzzyRuleAntecedent *ifEKstrim = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifEKstrim->joinSingle(ekstrim);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKdekstrim = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKdekstrim->addOutput(kdekstrim);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule09 = new FuzzyRule(9, ifEKstrim, thenKdekstrim);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule09);

  //===========================ROLL=====================================
  // Instantiating a FuzzyOutput objects
  FuzzyOutput *kpR = new FuzzyOutput(4);
  // Instantiating a FuzzySet object
  FuzzySet *kpRrendah = new FuzzySet(0.1, 0.1, 0.3, 0.5);
  // Including the FuzzySet into FuzzyOutput
  kpR->addFuzzySet(kpRrendah);
  // Instantiating a FuzzySet object
  FuzzySet *kpRsedang = new FuzzySet(0.3, 0.5, 0.7, 0.9);
  // Including the FuzzySet into FuzzyOutput
  kpR->addFuzzySet(kpRsedang);
  // Instantiating a FuzzySet object
  FuzzySet *kpRekstrim = new FuzzySet(0.7, 0.9, 1.1, 1.1);
  // Including the FuzzySet into FuzzyOutput
  kpR->addFuzzySet(kpRekstrim);
  // Including the FuzzyOutput into Fuzzy
  fuzzy->addFuzzyOutput(kpR);

  // Instantiating a FuzzyOutput objects
  FuzzyOutput *kiR = new FuzzyOutput(5);
  // Instantiating a FuzzySet object
  FuzzySet *kiRrendah = new FuzzySet(0.01, 0.01, 0.1, 0.2);
  // Including the FuzzySet into FuzzyOutput
  kiR->addFuzzySet(kiRrendah);
  // Instantiating a FuzzySet object
  FuzzySet *kiRtinggi = new FuzzySet(0.1, 0.2, 0.3, 0.3);
  // Including the FuzzySet into FuzzyOutput
  kiR->addFuzzySet(kiRtinggi);
  // Instantiating a FuzzySet object
  fuzzy->addFuzzyOutput(kiR);

  // Instantiating a FuzzyOutput objects
  FuzzyOutput *kdR = new FuzzyOutput(6);
  // Instantiating a FuzzySet object
  FuzzySet *kdRrendah = new FuzzySet(0.1, 0.1, 0.3, 0.4);
  // Including the FuzzySet into FuzzyOutput
  kdR->addFuzzySet(kdRrendah);
  // Instantiating a FuzzySet object
  FuzzySet *kdRsedang = new FuzzySet(0.3, 0.4, 0.4, 0.5);
  // Including the FuzzySet into FuzzyOutput
  kdR->addFuzzySet(kdRsedang);
  // Instantiating a FuzzySet object
  FuzzySet *kdRekstrim = new FuzzySet(0.4, 0.5, 0.7, 0.7);
  // Including the FuzzySet into FuzzyOutput
  kdR->addFuzzySet(kdRekstrim);
  // Including the FuzzyOutput into Fuzzy
  fuzzy->addFuzzyOutput(kdR);

  // Building FuzzyRule "IF pitch = small THEN kp = slow"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *ifRrendah = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRrendah->joinSingle(Rrendah);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKpRrendah = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKpRrendah->addOutput(kpRrendah);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule10 = new FuzzyRule(10, ifRrendah, thenKpRrendah);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule10);

  FuzzyRuleAntecedent *ifRRendah = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRRendah->joinSingle(Rrendah);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKiRrendah = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKiRrendah->addOutput(kiRrendah);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule11 = new FuzzyRule(11, ifRRendah, thenKiRrendah);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule11);

  FuzzyRuleAntecedent *ifRREndah = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRREndah->joinSingle(Rrendah);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKdRrendah = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKdRrendah->addOutput(kdRrendah);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule12 = new FuzzyRule(12, ifRREndah, thenKdRrendah);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule12);

  // Building FuzzyRule "IF pitch = safe THEN kp = average"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *ifRsedang = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRsedang->joinSingle(Rsedang);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKpRsedang = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKpRsedang->addOutput(kpRsedang);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule13 = new FuzzyRule(13, ifRsedang, thenKpRsedang);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule13);

  FuzzyRuleAntecedent *ifRSedang = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRSedang->joinSingle(Rsedang);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKiRtinggi = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKiRtinggi->addOutput(kiRtinggi);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule14 = new FuzzyRule(14, ifRSedang, thenKiRtinggi);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule14);

  FuzzyRuleAntecedent *ifRSEdang = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRSEdang->joinSingle(Rsedang);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKdRsedang = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKdRsedang->addOutput(kdRsedang);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule15 = new FuzzyRule(15, ifRsedang, thenKdRsedang);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule15);

  // Building FuzzyRule "IF pitch = big THEN kp = high"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *ifRekstrim = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifRekstrim->joinSingle(Rekstrim);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKpRekstrim = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKpRekstrim->addOutput(kpRekstrim);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule16 = new FuzzyRule(16, ifRekstrim, thenKpRekstrim);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule16);

  FuzzyRuleAntecedent *ifREkstrim = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifREkstrim->joinSingle(Rekstrim);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKIRtinggi = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKIRtinggi->addOutput(kiRtinggi);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule17 = new FuzzyRule(17, ifREkstrim, thenKIRtinggi);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule17);

  FuzzyRuleAntecedent *ifREKstrim = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  ifREKstrim->joinSingle(Rekstrim);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *thenKdRekstrim = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  thenKdRekstrim->addOutput(kdRekstrim);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule18 = new FuzzyRule(18, ifREKstrim, thenKdRekstrim);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule18);
}

float calculateFuzzy(int tipe, int input, int address)
{
  //tipe : 1 -> pitch, 2 -> roll
  //input : nyesuain roll apa pitch, inpuntnya error bacaaan BNO
  //address : 1 -> kp, 2 -> ki, 3 -> kd
  // Set the random value as an input
  //  int input=0;
  //  int input1=0;
  //  input = kp_pitch_fuzzy;
  //  input1 = kp_roll_fuzzy;
  fuzzy->setInput(tipe, input);
  //  fuzzy->setInput(1, input);
  //  fuzzy->setInput(2, input);
  // Running the Fuzzification
  fuzzy->fuzzify();

  // Running the Defuzzification
  float out = fuzzy->defuzzify(address);
  ////-------------PITCH--------------------
  //  float output = fuzzy->defuzzify(1);
  //  float output1 = fuzzy->defuzzify(2);
  //  float output2 = fuzzy->defuzzify(3);
  ////-------------ROLL--------------------
  //  float output3 = fuzzy->defuzzify(4);
  //  float output4 = fuzzy->defuzzify(5);
  //  float output5 = fuzzy->defuzzify(6);
//  Serial.print("OUT: ");
//  Serial.println(out);
//  Serial.print( ");
//  Serial.println(out);
  return out;
}
