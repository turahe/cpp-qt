#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
enum ERR_STATUS {SUCCESS, ERROR};
ERR_STATUS Hitung(int,int &,int &);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ERR_STATUS status;
    int number, rLuasPersegi, rVolumeKubus;
    cout << "Masukan number : ";
    cin >> number;
    status = Hitung(number,rLuasPersegi,rVolumeKubus);
    if(status==SUCCESS)
    {
        cout << "Number : " << number << endl;
        cout << "pLuasPersegi : " << rLuasPersegi << endl;
        cout << "pVolumeKubus : " << rVolumeKubus << endl;
    }
    else
        cout << "Terjadi Error !!";
    return a.exec();
    }
    ERR_STATUS Hitung(int number, int &rLuasPersegi, int &rVolumeKubus)
    {
    ERR_STATUS status;
    if(number > 0)
    {
        rLuasPersegi = number * number;
        rVolumeKubus = number * number * number;
        status = SUCCESS;
        }
    else
        status = ERROR;
    return status;
}