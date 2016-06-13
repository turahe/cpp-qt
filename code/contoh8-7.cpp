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
	Kalender(int hari,int bulan, int tahun) : _hari(hari), _bulan(bulan),_tahun(tahun) {}
void TampilTanggal()
{
	cout << _hari << " / " << _bulan << " / " << _tahun << endl;
}
operator int() const;
bool operator < (const Kalender &objKal) const;
bool operator <= (const Kalender &objKal) const;
bool operator > (const Kalender &objKal) const;
bool operator >= (const Kalender &objKal) const;
};
Kalender::operator int() const
{
	return ((_tahun*10000)+(_bulan*100)+_hari);
}
bool Kalender::operator <(const Kalender &objKal) const
{
	return (this->operator int() < objKal.operator int());
}
bool Kalender::operator >(const Kalender &objKal) const
{
	return (this->operator int() > objKal.operator int());
}
bool Kalender::operator <=(const Kalender &objKal) const
{
	return (this->operator int() <= objKal.operator int());
}
bool Kalender::operator >=(const Kalender &objKal) const
{
	return (this->operator int() >= objKal.operator int());
}
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Kalender objKal1(23,10,2010);
	Kalender objKal2(16,10,1980);
	Kalender objKal3(23,10,2010);
	cout << "objKal1 berisi : " << endl;
	objKal1.TampilTanggal();
	cout << endl;
	cout << "objKal2 berisi : " << endl;
	objKal2.TampilTanggal();
	cout << endl;
	cout << "objKal3 berisi : " << endl;
	objKal3.TampilTanggal();
	cout << endl;
	//menggunakan operator <
	cout << "objKal1 < objKal2 = ";
	cout << ((objKal1 < objKal2) ? "true" : "false") << endl;
	//menggunakan operator >
	cout << "objKal1 > objKal2 = ";
	cout << ((objKal1 > objKal2) ? "true" : "false") << endl;
	//menggunakan operator <=
	cout << "objKal1 <= objKal3 = ";
	cout << ((objKal1 <= objKal3) ? "true" : "false") << endl;
	//menggunakan operator >=
	cout << "objKal1 >= objKal3 = ";
	cout << ((objKal1 >= objKal3) ? "true" : "false") << endl;
	return a.exec();
}