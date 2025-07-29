#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Manusia{
private:
string nama;
char jenis_kelamin;
public:
//konstruktor
Manusia(){
}
Manusia(string nama){
this->nama = nama;
}
//desktruktor
~Manusia(){
}
//accessor method
string getNama() const{
return this->nama;
}
char getJenis_Kelamin() const{
return this->jenis_kelamin;
}
//mutator method
void setNama(string n){
this->nama = n;
}
void setJenis_Kelamin(char jk){
this->jenis_kelamin = jk;
}
//method lain
    void tampilSemua(){
cout<<"Nama: "<<this->getNama()<<", "<<
"Jenis Kelamin: "<<this->getJenis_Kelamin()<<endl;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Manusia suami;
suami.setNama("Susanto");
suami.setJenis_Kelamin('L');
Manusia istri("Susanti");
istri.setJenis_Kelamin('P');
Manusia anak("Rudi");
anak.setJenis_Kelamin('L');
suami.tampilSemua();
istri.tampilSemua();
anak.tampilSemua();
return a.exec();
}