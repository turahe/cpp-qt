#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kuda{
public:
Kuda(string nama)
{
	cout << "Konstruktor Kuda, nama = " << nama << endl;
	}
};
class Burung{
public:
Burung(string warna)
{
	cout << "Konstruktor Burung, warna = " << warna << endl;
	}
};
class Kuda_terbang : public Kuda, public Burung{
public:
Kuda_terbang():Kuda("Gondrong"),Burung("Merah")
{
	cout << "Konstuktor Kuda_terbang";
	}
};
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Kuda_terbang* gondrong = new Kuda_terbang();
	return a.exec();
}