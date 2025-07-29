#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
//pembuatan class Sepeda
class Sepeda{
private:
//daftar member variabel
int kecepatan;
int gigi;
string merk;
public:
//daftar member function
void ubahKecepatan(int kec);
void ubahGigi(int g);
void setMerk(string m);
void tampilSepeda();
};
//implementasi member function berada diluar class Sepeda
//function ubahKecepatan menerima input jumlah kecepatan
//mengubah kecepatan Sepeda
void Sepeda::ubahKecepatan(int kec){
this->kecepatan = kec;
}
//function ubahGigi menerima input jumlah gigi
//mengubah gigi Sepeda
void Sepeda::ubahGigi(int g){
this->gigi = g;
}
//function setMerk menerima input string merk
//mengisi merk Sepeda
void Sepeda::setMerk(string m){
this->merk = m;
}
//function tampilSepeda tidak menerima input
//fungsinya hanya untuk menampilkan informasi obyek Sepeda
void Sepeda::tampilSepeda(){
cout <<"Kecepatan: "<<this->kecepatan<<endl<<
"Merk: "<<this->merk<<endl<<
"Gigi: "<<this->gigi;
}
//function main
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