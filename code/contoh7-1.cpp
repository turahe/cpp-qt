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
float getVolume(){ //<-- anggota baru
//getLuas() adalah warisan
return getLuas() * tinggi;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Silinder drum(50,125);
cout << "Volume drum = " << drum.getVolume() << " Cm2" << endl;
return a.exec();
}