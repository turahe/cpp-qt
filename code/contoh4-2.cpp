#include <QtCore/QCoreApplication>
#include <iostream>
void hello(int kali);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    hello(3);
    return a.exec();
}
void hello(int kali)
{
    using namespace std;
    for(int x=0;x<kali;x++)
        cout << "Hello World!" << endl;
} 