#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Lingkaran{
public:
//Konstruktor
Lingkaran(float radius = 0){
Lingkaran::radius = radius;
}
//Destruktor
~Lingkaran(){}
protected :
float radius;
public :
float getLuas(){
return 3.14 * radius * radius;
}
};
class Silinder : public Lingkaran{
public:
//Konstruktor
Silinder(float radius, float tinggi){
Silinder::radius = radius; //<-- warisan
Silinder::tinggi = tinggi; //<-- anggota baru
}
//Destruktor
~Silinder(){}
private:
float tinggi; //<-- anggota baru
public:
float getLuas(){ //<-- Overriding
float luasTutup = 3.14 * this->radius * this->radius;
float luasSelimut = 2 * 3.14 * this->radius * this->tinggi;
float luasSilinder = 2 * luasTutup + luasSelimut;
return luasSilinder;
}
float getVolume(){ //<-- anggota baru
//getLuas() sebenarnya sudah ditimpa
return getLuas() * tinggi;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Silinder drum(50,125);
cout << "Luas Silinder = " << drum.getLuas() << " Cm2" << endl;
cout << "Milik Base Class --> " << drum.getLuas() << endl;
cout << "Volume drum = " << drum.getVolume() << " Cm3" << endl;
return a.exec();
}