#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Sepeda{
private:
int kecepatan;
int gigi;
string merk;
public:
void ubahKecepatan(int kec);
void ubahGigi(int g);
void setMerk(string m);
void tampilSepeda();
};
void Sepeda::ubahKecepatan(int kec){
this->kecepatan = kec;
}
void Sepeda::ubahGigi(int g){
this->gigi = g;
}
void Sepeda::setMerk(string m){
this->merk = m;
}
void Sepeda::tampilSepeda(){
cout <<"Kecepatan: "<<this->kecepatan<<endl<<
"Merk: "<<this->merk<<endl<<
"Gigi: "<<this->gigi;
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Sepeda objSpd;
objSpd.ubahGigi(2);
objSpd.ubahKecepatan(30);
objSpd.setMerk("Federal");
objSpd.tampilSepeda();
return a.exec();
}