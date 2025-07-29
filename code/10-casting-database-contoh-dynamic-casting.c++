#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class CAnimal
{
public:
virtual void Bersuara () = 0;
};
class CDog : public CAnimal
{
public:
void KibasEkor () {
cout << "Dog: Kibas-kibas ekor!" << endl;
}
void Bersuara () {
cout << "Dog: Guk-guk!" << endl;
}
};
class CCat : public CAnimal
{
public:
void TangkapTikus () {
cout << "Cat: tikus tertangkap!" << endl;
}
void Bersuara () {
cout << "Cat: Meong!" << endl;
}
};
void TentukanTipeClass (CAnimal* pAnimal);
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
// pAnimal1 berupa obyek Dog
CAnimal* pAnimal1 = new CDog ();
// pAnimal2 berupa obyek Cat
CAnimal* pAnimal2 = new CCat ();
cout << "Penggunaan dynamic_cast untuk menentukan jenis Animal 1" << endl;
TentukanTipeClass(pAnimal1);
cout << "Penggunaan dynamic_cast untuk menentukan jenis Animal 2" << endl;
TentukanTipeClass (pAnimal2);
// Penggunaan virtual function override
cout << "Verifikasi tipe: Animal 1 Besuara!" << endl;
pAnimal1->Bersuara ();
cout << "Verifikasi tipe: Animal 2 Besuara!" << endl;
pAnimal2->Bersuara ();
return a.exec();
}
void TentukanTipeClass (CAnimal* pAnimal)
{
CDog* pDog = dynamic_cast <CDog*>(pAnimal);
if (pDog)
{
cout << "Binatang Dog!" << endl;
// panggil fungsi dog
pDog->KibasEkor();
}
CCat* pCat = dynamic_cast <CCat*>(pAnimal);
if (pCat)
{
cout << "Binatang kucing!" << endl;
pCat->TangkapTikus();
}
}