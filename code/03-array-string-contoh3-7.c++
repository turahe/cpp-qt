#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
enum Hari { Minggu, Senin, Selasa, Rabu, Kamis, Jumat, Sabtu };
int ArrayHari[7] = { 10, 20, 30, 40, 50, 60, 70 };
cout << "Nilai Hari Selasa adalah: " << ArrayHari[Selasa];
return a.exec();
}