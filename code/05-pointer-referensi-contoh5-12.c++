#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int Hitung(int number, int *pLuasPersegi, int *pVolumeKubus);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int number, pLuasPersegi, pVolumeKubus;
    short error;
    cout << "Masukan number : ";
    cin >> number;
    error = Hitung(number,&pLuasPersegi,&pVolumeKubus);
    if(!error)
    {
        cout << "Number : " << number << endl;
        cout << "pLuasPersegi : " << pLuasPersegi << endl;
        cout << "pVolumeKubus : " << pVolumeKubus << endl;
    }
    else
        cout << "Terjadi Error !! ";
    return a.exec();
    }
    int Hitung(int number, int *pLuasPersegi, int *pVolumeKubus)
    {
    short status;
    if(number > 0)
    {
        *pLuasPersegi = number * number;
        *pVolumeKubus = number * number * number;
        status = 0;
    }
    else
    {
        status = 1;
    }
    return status;
}