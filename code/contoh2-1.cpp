#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    int panjang, lebar;
    panjang = 15; //<-- nilai diubah menjadi 15
    lebar = 12; //<-- nilai diubah menjadi 12
    cout << "Panjang = " << panjang << endl;
    cout << "Lebar = " << lebar << endl;
    return a.exec();
}
