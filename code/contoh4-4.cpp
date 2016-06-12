#include <QtCore/QCoreApplication>
#include <iostream>
void kali(float a, float b); /*prototype fungsi*/
float hasil; /*variabel global*/
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    kali(4,7);
    cout << "Variabel global hasil = " << hasil << endl;
    return a.exec();
}
void kali(float a, float b)
{
    hasil = a * b;
}