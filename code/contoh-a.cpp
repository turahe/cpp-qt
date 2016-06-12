/*
 program untuk mencari nilai minimum dari 10 
 buah bilangan bulat yang diinputkan oleh user.
*/
#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    int x [10], min;
    cout <<"Masukan 10 angka: "<< endl;
    for (int i = 1;i<=10;i++)
    {
        cout<<"Bilangan ke-"<<i<<" : ";
        cin>>x[i];
        cout<<endl;
        if (i==1)
        {min=x[1];}
        else
        {
            if (x[i]<min)
            {min=x[i];}
        }
    }
    cout << "Bilangan minimum adalah : "<<min<<endl;
    return a.exec();
}
