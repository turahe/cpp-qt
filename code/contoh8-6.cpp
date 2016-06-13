#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kalender
{
	private:
	int _hari;
	int _bulan;
	int _tahun;
	void TambahHari(int hari);
	void TambahBulan(int bulan);
	void TambahTahun(int tahun);
	public:
	Kalender(int hari,int bulan, int tahun) : _hari(hari), _bulan(bulan), _tahun(tahun) {}
void TampilTanggal()
{
	cout << _hari << " / " << _bulan << " / " << _tahun << endl;
}
operator int();
bool operator == (const Kalender &objKal);
bool operator == (int tglNumber);
bool operator != (const Kalender &objKal);
bool operator != (int tglNumber);
};
Kalender::operator int()
{
	return ((_tahun*10000)+(_bulan*100)+_hari);
}
bool Kalender::operator ==(const Kalender &objKal)
{
	return ((objKal._hari==_hari) && (objKal._bulan==_bulan) && (objKal._tahun==_tahun));
}
bool Kalender::operator ==(int tglNumber)
{
	return tglNumber == (int)*this;
}
bool Kalender::operator !=(const Kalender &objKal)
{
	return !(this->operator ==(objKal));
}
bool Kalender::operator !=(int tglNumber)
{
	return !(this->operator ==(tglNumber));
}
void Kalender::TambahHari(int hari)
{
	_hari += hari;
	if(_hari>30)
	{
		TambahBulan(_hari/30);
		_hari %= 30;
		}
		}
void Kalender::TambahBulan(int bulan)
{
	_bulan += bulan;
	if(_bulan>12)
	{
		TambahTahun(_bulan/12);
		_bulan %= 12;
		}
}
void Kalender::TambahTahun(int tahun)
{
	_tahun += tahun;
}
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Kalender objKal1(23,10,2010);
	cout << "Inisialisasi Kalender 1" << endl;
	objKal1.TampilTanggal();
	cout << endl;
	Kalender objKal2(23,10,2011);
	cout << "Inisialisasi Kalender 2" << endl;
	objKal2.TampilTanggal();
	cout << endl;
	//menggunakan operator tidak sama dengan
	if(objKal1 != objKal2)
		cout << "kalender1 dan kalender2 tidak sama !" << endl;
	Kalender objKal3(23,10,2010);
	cout << "Inisialisasi Kalender 3" << endl;
	objKal3.TampilTanggal();
	cout << endl;
	//menggunakan operator sama dengan
	if(objKal1==objKal3)
		cout << "kalender1 dan kalender3 sama !" << endl;
	int intKal3 = objKal3;
	cout << "nilai integer yang ekuivalen dengan objKal3 adalah " << intKal3 << endl;
	//menggunakan overloading operator sama dengan untuk membandingkan integer
	if(objKal3 == intKal3)
		cout << "Nilai integer dari objKal3 dan intKal3 sama" << endl;
	//menggunakan overloading operator tidak sama dengan untuk membandingkan integer
	if(objKal2 != intKal3)
		cout << "Nilai integer dari objKal2 dan intKal3 tidak sama" << endl;
	return a.exec();
}