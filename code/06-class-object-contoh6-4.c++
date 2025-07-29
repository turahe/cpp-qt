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
s.pgigi = 3;
s.pkecepatan = 30;
s.pmerk = "Polygon";
cout<<"Gigi: "<<s.pgigi<<endl;
cout<<"Kecepatan: "<<s.pkecepatan<<endl;
cout<<"Merk: "<<s.pmerk<<endl;
return a.exec();
}