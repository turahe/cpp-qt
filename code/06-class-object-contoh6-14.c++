#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Roda{
private:
string merk_roda;
int diameter;
public:
Roda(string merk,int diamtr){
this->diameter = diamtr;
this->merk_roda = merk;
}
Roda(){
}
string getMerk(){
return this->merk_roda;
}
int getDiameter(){
return this->diameter;
}
void setMerkRoda(string m){
this->merk_roda = m;
}
void setDiameter(int d){
this->diameter = d;
}
};
class Mobil{
private:
string merk_mobil;
Roda roda_depan1;
Roda roda_depan2;
Roda roda_belakang1;
Roda roda_belakang2;
public:
//konstruktor
Mobil(){
}
Mobil(string merk, Roda roda[4]){
this->merk_mobil = merk;
this->roda_depan1 = roda[0];
this->roda_depan2 = roda[1];
this->roda_belakang1 = roda[2];
this->roda_belakang2 = roda[3];
}
Mobil(Roda r1, Roda r2, Roda r3, Roda r4){
this->roda_depan1 = r1;
this->roda_depan2 = r2;
this->roda_belakang1 = r3;
this->roda_belakang2 = r4;
}
//desktruktor
~Mobil(){
}
//accessor method
string getMerkMobil() const{
return this->merk_mobil;
    }
//mutator method
void setMerkMobil(string m){
this->merk_mobil = m;
}
void setRoda(Roda rd[4]){
this->roda_depan1 = rd[0];
this->roda_depan2 = rd[1];
this->roda_belakang1 = rd[2];
this->roda_belakang2 = rd[3];
}
//method lain
void tampilRoda(){
cout<<"Roda depan1:"<<endl;
cout<<"Merk: "<<this->roda_depan1.getMerk()<<endl;
cout<<"Diameter: "<<this->roda_depan1.getDiameter()<<endl;
cout<<"Roda depan2:"<<endl;
cout<<"Merk: "<<this->roda_depan2.getMerk()<<endl;
cout<<"Diameter: "<<this->roda_depan2.getDiameter()<<endl;
cout<<"Roda belakang1:"<<endl;
cout<<"Merk: "<<this->roda_belakang1.getMerk()<<endl;
cout<<"Diameter: "<<this->roda_belakang1.getDiameter()<<endl;
cout<<"Roda belakang2:"<<endl;
cout<<"Merk: "<<this->roda_belakang2.getMerk()<<endl;
cout<<"Diameter: "<<this->roda_belakang2.getDiameter()<<endl;
}
void tampilSemua(){
cout<<"Merk: "<<this->getMerkMobil()<<endl;
this->tampilRoda();
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Roda r1("Bridgestone",40);
Roda r2("Bridgestone",40);
Roda r3("Bridgestone",40);
Roda r4("Bridgestone",40);
Mobil m1(r1,r2,r3,r4);
m1.setMerkMobil("Innova");
m1.tampilSemua();
return a.exec();
}