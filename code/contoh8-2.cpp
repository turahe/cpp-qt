#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kalender
{
private:
int _hari;
int _bulan;
int _tahun;
void AddHari(int hari)
{
    _hari += hari;
    if(_hari > 30)
{
        AddBulan(_hari/30);
        _hari %= 30;
}
}
void AddBulan(int bulan)
{
    _bulan += bulan;
    if(_bulan > 12)
{
        AddTahun(_bulan/12);
        _bulan %= 12;
}
}
void AddTahun(int tahun)
{
    _tahun += tahun;
}
public:
Kalender(int hari,int bulan, int tahun):_hari(hari),_bulan(bulan),_tahun(tahun){ }
Kalender operator ++ (int)
{
    Kalender objKal(_hari,_bulan,_tahun);
    AddHari(1);
    return objKal;
}
void TampilData()
{
    cout << _hari << " / " << _bulan << " / " << _tahun << endl;
}
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Kalender objKal(23,10,2010);
    cout << "Membuat object kalender dan memberi inisialisasi" << endl;
    objKal.TampilData();
    cout << endl;
    cout << "Menggunakan notasi postfix" << endl;
    //menggunakan notasi postfix
    Kalender objLama(objKal++);
    cout << "objLama : ";
    objLama.TampilData();
    cout << "objKal : ";
    objKal.TampilData();
    return a.exec();

}