#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);
    cout << "Masukan nomor: ";
    int x;
    cin >> x;

    if (x > 10)
        cout << x << " lebih besar dari 10\n";
    else
        cout << x << " kurang besar dari 10\n";

    return a.exec();
}
