#include <QtCore/QCoreApplication>
#include <iostream>
float kali(float a, float b); /*prototype fungsi*/
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    float hasil;
    hasil = kali(4,7);
    cout << "Hasil = " << hasil << endl;
    return a.exec();
}
float kali(float a, float b)
{
    float c;
    c = a * b;
    return c;
}