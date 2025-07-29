#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QString nama = "Nur Wachid";
QString balik;
for(int i=nama.length()-1;i>=0;i--)
{
balik+=nama[i];
}
qDebug() << "Balik : " << balik;
return a.exec();
}