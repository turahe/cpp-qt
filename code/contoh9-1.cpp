
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kuda{
	public:
	void melompat(){ cout << "Lompat!" << endl;
}
virtual void terbang()
{
	cout <<"kuda tidak bisa terbang" << endl;
	}
};
class Kuda_terbang :
 public Kuda
 {
	 public:
	 void terbang()
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
		kandang[nomor]->terbang();
		delete kandang[nomor];
		}
		return a.exec();
}