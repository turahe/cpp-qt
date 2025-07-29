#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Sepeda{
private:
int kecepatan;
int gigi;
string merk;
public:
int pkecepatan;
int pgigi;
string pmerk;
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
cout<<"Pengaksesan public:\n";
Sepeda s;
s.gigi = 3;
s.kecepatan = 30;
s.merk = "Federal";
cout<<"Gigi: "<<s.gigi<<endl;
cout<<"Kecepatan: "<<s.kecepatan<<endl;
cout<<"Merk: "<<s.merk<<endl;
return a.exec();
}