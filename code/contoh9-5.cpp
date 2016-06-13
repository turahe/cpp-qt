#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Binatang{
public:
Binatang(int umur=5):umur(5)
{
	cout << "Konstruktor Binatang\n";
	}
~Binatang()
{
	cout << "Destruktor Binatang\n";
	}
protected:
int umur;
public:
virtual int const getUmur()
{
	cout << "dari Binatang...";
	return umur;
	}
};
class Kuda : public Binatang{
public:
Kuda()
{
	cout << "Konstruktor Kuda\n";
	}
~Kuda()
{
	cout << "Destruktor Kuda\n";
	}
virtual int const getUmur()
{
	cout << "dari Kuda...";
	return umur;
	}
};
class Burung : public Binatang{
public:
Burung()
{
	cout << "Konstruktor Burung\n";
	}
~Burung()
{
	cout << "Destruktor Burung\n";
	}
virtual int const getUmur()
{
	cout << "dari Burung...";
	return umur;
	}
};
class Kuda_terbang : public Kuda, public Burung
{
public:
Kuda_terbang()
{
	cout << "Konstruktor Kuda_terbang\n";
	}
~Kuda_terbang()
{
	cout << "Destruktor Kuda_terbang\n";
	}
virtual int const getUmur()
{
	cout << "dari Kuda_terbang...";
	return Kuda::getUmur();
	}
};
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Kuda_terbang* gondrong = new Kuda_terbang();
	cout << "Umur : " << gondrong->getUmur() << endl;
	delete gondrong;
	return a.exec();
}