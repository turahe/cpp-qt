#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kalender
{
private:
int _hari;
int _bulan;
int _tahun;
void TambahHari(int hari)
{
    _hari += hari;
    if(_hari>30)
    {
        TambahBulan(_hari/30);
        _hari %= 30;
    }
}
void TambahBulan(int bulan)
{
    _bulan += bulan;
    if(_bulan>12)
    {
        TambahTahun(_bulan/12);
        _bulan %= 12;
    }
}
void TambahTahun(int tahun)
{
    _tahun += tahun;
}
public:
Kalender(int hari, int bulan, int tahun) :
    _hari(hari), _bulan(bulan),_tahun(tahun) {} Kalender operator + (int hari)
{
    Kalender objKal(_hari,_bulan,_tahun);
    objKal.TambahHari(hari);
    return objKal;
}
void TampilTanggal()
{
    cout << _hari << " / " << _bulan << " / " << _tahun << endl;
}
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Kalender objKal(23,10,2011);
    cout << "Inisialisasi Data " << endl;
    objKal.TampilTanggal();
    cout << "Menambahkan 25 hari kedepan " << endl;
    Kalender objKalBaru(objKal + 25);
    cout << "Hasil setelah ditambahkan 25 hari " << endl;
    objKalBaru.TampilTanggal();
    //cara penulisan yang lain
    objKal=objKal+20;
    objKal.TampilTanggal();
    return a.exec();
}
