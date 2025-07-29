#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kucing{
private:
int umur;
float berat;
string nama;
public:
//asesor method
int getUmur();
float getBerat();
string getNama();
//mutator method
void setUmur(int u);
void setBerat(float b);
void setNama(string s);
//method tambahan
void berlari();
};
//implementasi
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
void Kucing::berlari(){
cout<<"Kucing "<<this->getNama()<<" sedang berlari!";
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Kucing mycat;
mycat.setNama("Katty");;
mycat.setBerat(4);
mycat.setUmur(2);
cout<<"Kucingku bernama "<<mycat.getNama()<<", dia berbobot "<<
mycat.getBerat()<<" kg dan sudah berumur "<<mycat.getUmur()
    <<" tahun sekarang."<<endl;
mycat.berlari();
return a.exec();
}