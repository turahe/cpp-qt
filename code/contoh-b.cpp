// program yang untuk menginputkan sebuah bilangan dan 
// mengenalinya apakah bialangan tersebut genap atau ganjil

#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    int bil, bilangan;
    cout<<"masukkan sebuah bilangan : ";
    cin>>bil;
    bil=bilangan%2;
    if (bilangan==0)
    { cout<<"\n"<<bil<<" adalah bilangan genap."<<endl;
    }
    else
    {
        cout<<"\n"<<bil<<" adalah bilangan ganjil."<<endl;
    }
    return a.exec();
}
