#include <QtCore/QCoreApplication>
#include <iostream>
int absolut(int bil);
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    int bilangan = -10;
    cout << "Bilangan : " << bilangan << endl;
    cout << "Dimutlakkan menjadi : " << absolut(bilangan) << endl;
    return a.exec();
}
int absolut(int bil)
{
    if(bil<0)
        return - bil;
    else
        return bil;
}