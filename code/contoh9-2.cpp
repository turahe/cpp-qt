#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kuda{
	public:
	virtual void melompat()
	{
		cout << "Lompat!" << endl;
		}
};
class Kuda_terbang :
 public Kuda{
	 public:
	 virtual void terbang()
	 {
		 cout << "terbang..." << endl;
		 }
};
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Kuda* kandang[5];
	Kuda* kudanya;
	int pilih;
	for(int nomor=0; nomor<5; nomor++)
	{
		cout << "Pilih (0) Kuda atau (1) Kuda terbang : ";
		cin >> pilih;
		if(pilih==0)
			kudanya = new Kuda();
		else
			kudanya = new Kuda_terbang();
		kandang[nomor] = kudanya;
	}
	cout << endl;
	for(int nomor=0; nomor<5; nomor++)
	{
		Kuda_terbang *pKterb = dynamic_cast<Kuda_terbang*> (kandang[nomor]);
		if (pKterb != NULL)
			pKterb->terbang();
		else
			cout << "Kuda biasa " << endl;
		delete kandang[nomor];
	}
	return a.exec();
}