#include <QtCore/QCoreApplication>
#include <iostream>
long int kali(long int i); /*prototype*/
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    int i,n;
    long int fak;
    n = 5;
    /*menghitun n faktorial (5!)*/
    if(n<=0)
        fak=0;
    else
        for(i=1;i<=n;i++)
            fak = kali(i);
    cout << n << " Faktorial = " << fak << endl;
    return a.exec();
}
/*---Fungsi kali---*/
long int kali(long int i)
{
    static long int f=1;
    f = f * i;
}