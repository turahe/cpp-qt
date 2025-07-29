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
cout<<"Sepeda pertama:\n";
Sepeda objSpdArray[5];
for(int i=0;i<5;i++){
objSpdArray[i].setMerk("Merk-"+i);
objSpdArray[i].ubahGigi(i+10);
objSpdArray[i].ubahKecepatan(i+30);
}
for(int i=0;i<5;i++){
cout<<"Tampilan Sepeda ke-"<<(i+1)<<endl;
objSpdArray[i].tampilSepeda();
cout<<endl;
}
return a.exec();
}