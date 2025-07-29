CInduk* pInduk = new CTurunan();
// Melakukan down casting
CTurunan* pTurunan = dynamic_cast <CTurunan*> (pInduk);
if (pTurunan) // cek apakah sukses?
pTurunan->CallFungsiClassTurunan ();