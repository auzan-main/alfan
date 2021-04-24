void manasinServo() {
  baca(516, 10);
  PalaAtas(10);
  invers(KIRI, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KANAN, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  waitAll(1000);
  baca(517, 10);
  PalaBawah(10);
  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  waitAll(1000);
  baca(516, 10);
  PalaKanan(10);
  invers(KIRI, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KANAN, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  waitAll(1000);
  baca(517, 10);
  PalaKiri(10);
  invers(KANAN, 6, -3 - 3.06, 16.6, 0, 0);
  invers(KIRI, 6, 3 - 3.06, 16.6, 0, 0);
  transmitPulsa();
  waitAll(1000);
}
