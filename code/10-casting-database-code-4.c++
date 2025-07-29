CInduk* pInduk = new CTurunan (); // membuat obyek Cturunan dari Cinduk (polymorfisme)
CTurunan* pTurunan = static_cast<CTurunan*>(pInduk); // mengcasting pInduk menjadi Cturunan, valid!
// CTdkAdaHubungan merupakan class yang tidak ada hubungannya dengan CInduk melalui inheritance
CTdkAdaHubungan* pTdkHub = static_cast<CTdkAdaHubungan*>(pInduk); // Error
//karena casting tidak diperbolehkan, tidak ada hubungan class!