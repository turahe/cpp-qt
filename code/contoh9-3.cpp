#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kuda{
public:
Kuda() 
{
	cout << "Konstruktor Kuda ... ";
}
virtual ~Kuda() 
{
	cout << "Destruktor Kuda ... \n";
	}
virtual void meringkik() const {
	cout << " Kikikikikkkk...";
	}
};
class Burung{
	public:
	Burung() 
	{ 
	cout << "Konstruktor Burung ... ";
	}
virtual ~Burung() 
{
	cout << "Destruktor Burung ... "; 
	}
virtual void berkicau() const {
	cout << " Cicit cuit... "; 
	}
virtual void terbang() const {
	cout << " Terbang ... "; 
	}
};
class Kuda_terbang : public Kuda, public Burung{
public:
void berkicau() const {
	meringkik(); 
	}
Kuda_terbang() {
	cout << "Konstruktor Kuda_terbang ... "; 
	}
~Kuda_terbang() {
	cout << "Destruktor Kuda_terbang ... "; 
	}
};
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Kuda* daftar_kuda[2]; //<-- kumpulan Kuda
	Burung* daftar_burung[2]; //<-- kumpulan Burung
	cout << "Menciptakan objek Kuda:" << endl;
	daftar_kuda[0] = new Kuda(); //<-- objek Kuda
	cout << "\nMenciptakan objek Kuda_terbang:" << endl;
	daftar_kuda[1] = new Kuda_terbang(); //<-- objek Kuda_terbang
	cout << "\nMenciptakan objek Burung:" << endl;
	daftar_burung[0] = new Burung(); //<-- objek Burung
	cout << "\nMenciptakan objek Kuda_terbang:" << endl;
	daftar_burung[1] = new Kuda_terbang();//<-- objek Kuda_terbang
	cout << "\n\nTampilkan daftar_kuda :" << endl;
	daftar_kuda[0]->meringkik(); //<-- berisi objek Kuda
	cout << "\nHapus Kuda : ";
	delete daftar_kuda[0];
	daftar_kuda[1]->meringkik(); //<-- berisi objek Kuda_terbang
	cout << "\nHapus Kuda_terbang : ";
	delete daftar_kuda[1];
	cout << "\nTampilkan daftar_burung :" << endl;
	daftar_burung[0]->berkicau(); //<-- berisi objek Burung
	daftar_burung[0]->terbang(); //<-- berisi objek Burung
	cout << "\nHapus Burung : " ;
	delete daftar_burung[0];
	cout << endl;
	daftar_burung[1]->berkicau(); //<-- berisi objek Kuda_terbang
	daftar_burung[1]->terbang(); //<-- berisi objek Kuda_terbang
	cout << "\nHapus Kuda_terbang : ";
	delete daftar_burung[1];
	return a.exec();
}