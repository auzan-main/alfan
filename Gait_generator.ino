void walkInit()
{
  tsup = Ts;

  tc = sqrt(23 * 0.101936 * 0.01); // Konstanta waktu lintasan COM
  C = cosh(tsup / tc);             // Cos parabolic
  S = sinh(tsup / tc);             // Sin parabolic
  if (footBase == 0) {
    comInY = (13 / 2); //12 Posisi awal COM pada sumbu y kaki kanan
  }
  else if (footBase == 1) {
    comInY = -(16.2 / 2);
  }
  comInX = s / 2;             // Posisi awal COM pada sumbu x


  Zt = 23;                      // Posisi awal COM pada sumbu z
  vX = (-comInX) * (C + 1) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup
  vY = (comInY) * (C - 1) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup

  // Tujuan pada detik 0
  Xt = ((x1 + x2) / 2) + (comInX * cosh(0 / tc) + tc * vX * sinh(0 / tc));                          //Posisi tujuan COM pada sumbu x ketika detik 0
  YtKi = comInY - (comInY * cosh(0 / tc) + tc * -vY * sinh(0 / tc));                             //Posisi tujuan COM pada sumbu y ketika detik 0 kiri base
  YtKa = -comInY + (comInY * cosh(0 / tc) + tc * -vY * sinh(0 / tc));                             //Posisi tujuan COM pada sumbu y ketika detik 0 kanan base
  sfX = x1 + (((s) / (2 * 3.14)) * (((2 * 3.14 * 0) / tsup) - sin((2 * 3.14 * 0) / tsup))); //Posisi tujuan langkah kaki pada sumbu x ketika detik 0

}

void walkInitGJ3()
{
  tsup = Ts;

  tc = sqrt((16.7-1) * 0.101936 * 0.01); // Konstanta waktu lintasan COM
  C = cosh(tsup / tc);             // Cos parabolic
  S = sinh(tsup / tc);             // Sin parabolic
  if (footBase == 0) {
    comInY = 4.5; //13 Posisi awal COM pada sumbu y kaki kanan
  }
  else if (footBase == 1) {
    comInY = 4.5; //15.5stable
  }
  comInX = 3 ;             // Posisi awal COM pada sumbu x

  sH = 6;

  Zt = 23;                      // Posisi awal COM pada sumbu z
  vX = (-comInX) * (C + 1) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup
  vY = (comInY) * (C - 1) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup

  // Tujuan pada detik 0
  Xt = ((x1 + x2) / 2) + (comInX * cosh(0 / tc) + tc * vX * sinh(0 / tc));                          //Posisi tujuan COM pada sumbu x ketika detik 0
  YtKi = (comInY * cosh(0 / tc) + tc * -vY * sinh(0 / tc));                             //Posisi tujuan COM pada sumbu y ketika detik 0 kiri base
  YtKa = (comInY * cosh(0 / tc) + tc * -vY * sinh(0 / tc));                             //Posisi tujuan COM pada sumbu y ketika detik 0 kanan base
  sfX = x1 + (((s) / (2 * 3.14)) * (((2 * 3.14 * 0) / tsup) - sin((2 * 3.14 * 0) / tsup))) + 1; //Posisi tujuan langkah kaki pada sumbu x ketika detik 0
  sfZ = sH - ((sH) * (1 - sin((3.14 * 0) / tsup)));
}

void walkInitGJ3Belok(double SxAwal, double SxAkhir, double SyAwal, double SyAkhir) {
  double XtAkhir, YtAkhir;
  tsup = Ts;

  tc = sqrt((16.7 - 3) * 0.101936 * 0.01); // Konstanta waktu lintasan COM
  C = cosh(tsup / tc);             // Cos parabolic
  S = sinh(tsup / tc);             // Sin parabolic
  if (footBase == 0) {
    comInY = 4.5; //13 Posisi awal COM pada sumbu y kaki kanan
  }
  else if (footBase == 1) {
    comInY = -4.5; //15.5stable
  }

  xAwal = SxAwal;
  yAwal = SyAwal;
  XtAkhir = SxAkhir;
  YtAkhir = SyAkhir;

  sH = 7;

  vX = (XtAkhir - (xAwal * C)) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup
  vY = (YtAkhir - (yAwal * C)) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup

  // Tujuan pada detik 0
  Xt = (xAwal * cosh(0 / tc)) + (tc * vX * sinh(0 / tc));                          //Posisi tujuan COM pada sumbu x ketika detik 0
  Yt = (yAwal * cosh(0 / tc)) + (tc * -vY * sinh(0 / tc));                           //Posisi tujuan COM pada sumbu y ketika detik 0 kanan base
  sfX = x1 + (((s) / (2 * 3.14)) * (((2 * 3.14 * 0) / tsup) - sin((2 * 3.14 * 0) / tsup))) + 1; //Posisi tujuan langkah kaki pada sumbu x ketika detik 0
  sfZ = sH - ((sH) * (1 - sin((3.14 * 0) / tsup)));

  //  Serial.print("vX: "); Serial.println(vX);
  //  Serial.print("vY: "); Serial.println(vY);
  //
  //  Serial.print("Ytakhir: "); Serial.println(YtAkhir);
  //  Serial.print("Xtakhir: "); Serial.println(XtAkhir);
}

void walkInitGJ6Belok(double SxAwal, double SxAkhir, double SyAwal, double SyAkhir) {
  double XtAkhir, YtAkhir;
  tsup = Ts;

  tc = sqrt((16.7 - 3) * 0.101936 * 0.01); // Konstanta waktu lintasan COM
  C = cosh(tsup / tc);             // Cos parabolic
  S = sinh(tsup / tc);             // Sin parabolic
  if (footBase == 0) {
    comInY = 4.5; //13 Posisi awal COM pada sumbu y kaki kanan
  }
  else if (footBase == 1) {
    comInY = -4.5; //15.5stable
  }

  xAwal = SxAwal;
  yAwal = SyAwal;
  XtAkhir = SxAkhir;
  YtAkhir = SyAkhir;

  sH = 10;

  vX = (XtAkhir - (xAwal * C)) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup
  vY = (YtAkhir - (yAwal * C)) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup

  // Tujuan pada detik 0
  Xt = (xAwal * cosh(0 / tc)) + (tc * vX * sinh(0 / tc));                          //Posisi tujuan COM pada sumbu x ketika detik 0
  Yt = (yAwal * cosh(0 / tc)) + (tc * -vY * sinh(0 / tc));                           //Posisi tujuan COM pada sumbu y ketika detik 0 kanan base
  sfX = x1 + (((s) / (2 * 3.14)) * (((2 * 3.14 * 0) / tsup) - sin((2 * 3.14 * 0) / tsup))) + 1; //Posisi tujuan langkah kaki pada sumbu x ketika detik 0
  sfZ = sH - ((sH) * (1 - sin((3.14 * 0) / tsup)));

  //  Serial.print("vX: "); Serial.println(vX);
  //  Serial.print("vY: "); Serial.println(vY);
  //
  //  Serial.print("Ytakhir: "); Serial.println(YtAkhir);
  //  Serial.print("Xtakhir: "); Serial.println(XtAkhir);
}

/*--------------------------------- walkupdate ---------------------------------
  |  Fungsi walkUpdate                                                          |
  |                                                                             |
  |  Tujuan :  Memperbarui tujuan selanjutnya pola berjalan robot               |
  |                                                                             |
  |  Parameter :                                                                |
  |  temp(INT) -- waktu tujuan selanjutnya dalam milidetik                  |
  |                                                                             |
  |  Returns:  Pola berjalan pada detik t                                       |
  -------------------------------------------------------------------------------*/

void walkUpdate(int temp)
{
  // Waktu saat ini
  t = (double)temp / 1000;

  Xt =  (xAwal * cosh(t / tc)) + (tc * vX * sinh(t / tc));                         //Posisi tujuan COM pada sumbu x ketika detik t
  Yt = (yAwal * cosh(t / tc)) + (tc * vY * sinh(t / tc));             //Posisi tujuan COM pada sumbu y ketika detik t
  sfX = (((s) / (2 * 3.14)) * (((2 * 3.14 * t) / tsup) - sin((2 * 3.14 * t) / tsup)))+x1; //Posisi tujuan langkah kaki pada sumbu x ketika detik t
  sfZ = sH - ((sH) * (1 - sin((3.14 * t) / tsup)));

  //  Serial.print("vX: "); Serial.println(vX);
  //  Serial.print(t);
  //  Serial.print(" ");
  //  // Serial.print(YtKi);
  //  // Serial.print(" ");
  //     Serial.print(YtKa);
  //  Serial.print(" ");
  //  Serial.println(YtKa);
}
/*--------------------------------- walkupdate ---------------------------------
  |  Fungsi walkUpdate                                                          |
  |                                                                             |
  |  Tujuan :  Memperbarui tujuan selanjutnya pola berjalan robot               |
  |                                                                             |
  |  Parameter :                                                                |
  |  temp(INT) -- waktu tujuan selanjutnya dalam milidetik                  |
  |                                                                             |
  |  Returns:  Pola berjalan pada detik t                                       |
  -------------------------------------------------------------------------------*/

/*void walkUpdate(int temp)
{
  // Waktu saat ini
  t = (double)temp / 1000;

  // Tujuan pada detik t
  vX = (-comInX) * (C + 1) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup
  vY = (comInY) * (C - 1) / (tc * S); //Kecepatan awal agar dapat berpindah dari posisi awal ke posisi akhir dengan periode tsup

  Xt =  (comInX * cosh(t / tc) + tc * vX * sinh(t / tc));                         //Posisi tujuan COM pada sumbu x ketika detik 0 ((x1 + x2) / 2) +
  YtKi = (comInY * cosh(t / tc) + tc * -vY * sinh(t / tc));                           //Posisi tujuan COM pada sumbu y ketika detik 0 kiri base
  YtKa = (comInY * cosh(t / tc) + tc * -vY * sinh(t / tc));                             //Posisi tujuan COM pada sumbu y ketika detik 0 kanan base
  sfX = x1 + (((s) / (2 * 3.14)) * (((2 * 3.14 * t) / tsup) - sin((2 * 3.14 * t) / tsup))) + 2; //Posisi tujuan langkah kaki pada sumbu x ketika detik 0
  sfZ = sH - ((sH) * (1 - sin((3.14 * t) / tsup)));
  //  Serial.print("xt: "); Serial.println(Xt);
  //  Serial.print(t);
  //  Serial.print(" ");
  //  // Serial.print(YtKi);
  //  // Serial.print(" ");
  //     Serial.print(YtKa);
  //  Serial.print(" ");
  //  Serial.println(YtKa);

}*/
