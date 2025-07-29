#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kucing{
private:
int umur;
float berat;
string nama;
public:
//konstruktor
Kucing(int umur);
Kucing();
//desktruktor
~Kucing();
//asesor method
int getUmur();
float getBerat();
string getNama();
//mutator method
    void setUmur(int u);
void setBerat(float b);
void setNama(string s);
};
//implementasi konstruktor dan desktruktor
Kucing::Kucing(int u){
this->umur = u;
}
Kucing::Kucing(){
}
Kucing::~Kucing(){
cout<<"Obyek sudah dihancurkan!";
}
//implementasi function
int Kucing::getUmur(){
return this->umur;
}
float Kucing::getBerat(){
return this->berat;
}
string Kucing::getNama(){
return this->nama;
}
void Kucing::setUmur(int u){
this->umur = u;
}
void Kucing::setBerat(float b){
this->berat = b;
}
void Kucing::setNama(string s){
this->nama = s;
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Kucing mycat(2);
mycat.setNama("Katty");;
mycat.setBerat(4);
cout<<"Kucingku bernama "<<mycat.getNama()<<", dia berbobot "<<
mycat.getBerat()<<" kg dan sudah berumur "<<mycat.getUmur()
<<" tahun sekarang."<<endl;
mycat.setUmur(7);
cout<<"Lima tahun telah berlalu, sekarang kucingku sudah berumur:
"<<mycat.getUmur()<<" tahun"<<endl;
Kucing kucingku2;
kucingku2.setNama("Frizky");
cout<<"Nama kucing keduaku: "<<kucingku2.getNama();
return a.exec();
}