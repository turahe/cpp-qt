#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int bil1 = 18;
int &rBil = bil1;
cout << "Nilai bil1 : " << bil1 << endl;
cout << "Nilai &rBil : " << rBil << endl;
bil1 = 19;
cout << "Nilai bil1 : " << bil1 << endl;
cout << "Nilai &rBil : " << rBil << endl;
rBil = 33;
cout << "Nilai bil1 : " << bil1 << endl;
cout << "Nilai &rBil : " << rBil << endl;
cout << "Menampilkan alamat memory :" << endl;
cout << "&bil1 : " << &bil1 << endl;
cout << "&rBil : " << &rBil << endl;
return a.exec();
}