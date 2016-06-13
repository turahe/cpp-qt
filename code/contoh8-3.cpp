#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kalender
{
private:
int _hari;
int _bulan;
int _tahun;
public:
Kalender(int hari,int bulan,int tahun) : _hari(hari), _bulan(bulan), _tahun(tahun) {}
operator int()
{
    return ((_tahun*1000) + (_bulan*100) + _hari);
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
    cout << "Inisialisasi data : " << endl;
    objKal.TampilData();
    cout << endl; cout << endl;
    int nData = objKal;
    cout << "Integer yang sesuai dengan data " << nData << endl;
    return a.exec();
}
