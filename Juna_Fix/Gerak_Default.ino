void posisiDefault(void)
{
  defaultTangan(20);
  defaultKaki();
  masker(51,270); //210
}

void defaultKaki(void) {
  dynamixeldef(1, 7, TENGAH7, 10); //+kiri -kanan
  dynamixeldef(1, 1, KANAN1, 20); //-kiri,+kanan
  dynamixeldef(1, 2, KANAN2, 20); //-maju,+mundur
  dynamixeldef(1, 3, KANAN3, 20); //+nekuk
  dynamixeldef(1, 4, KANAN4, 20); //+jinjit,
  dynamixeldef(1, 5, KANAN5, 20); //-buka,+nutup
  dynamixeldef(1, 6, KANAN6, 20); //-nutup,+buka

  dynamixeldef(1, 11, KIRI11, 20); //-kiri,+kanan
  dynamixeldef(1, 12, KIRI12, 20); //-mundur,+maju
  dynamixeldef(1, 13, KIRI13, 20); //-nekuk
  dynamixeldef(1, 14, KIRI14, 20); //-jinjit
  dynamixeldef(1, 15, KIRI15, 20); //+buka,-nutup
  dynamixeldef(1, 16, KIRI16, 20); //-buka,+nutup

  dynamixeldef(1, 17, TENGAH17, 20); //-buka,+nutup
}

void defaultTangan(int w)
{
  dynamixel(2, 36, KIRI36, w); //+kiri,-kanan
  dynamixel(2, 26, KANAN26, w);//+buka

  dynamixel(2, 21, KANAN21, w); //+maju,-mundur
  dynamixel(2, 22, KANAN22, w); //+angkat,-turun
  dynamixel(2, 23, KANAN23, w); //+KANAN,-KIRI
  dynamixel(2, 24, KANAN24, w); //+otot,-jangan!!
  dynamixel(2, 25, KANAN25, w); //+KANAN,-KIRI
  dynamixel(2, 31, KIRI31, w); //+mundur,-maju
  dynamixel(2, 32, KIRI32, w); //+turun,-angkall
  dynamixel(2, 33, KIRI33, w); //+KANAN,-KIRI
  dynamixel(2, 34, KIRI34, w); //+jangan!!,-atas
  dynamixel(2, 35, KIRI35, w); //+KANAN,-KIRI
  dynamixel(2, 41, KEPALA41, w); //+KANAN,-KIRI
  dynamixel(2, 42, KEPALA42, w); //+KANAN,-KIRI
  dynamixel(2, 43, KEPALA43, w); //+KANAN,-KIRI
}
