#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QString nama = "Slamet ";
nama.append("");
nama.append(",BA");
nama.prepend("Pak. ");
qDebug() << "Nama : " << nama;
nama.insert(16,",SE");
qDebug() << nama;
return a.exec();
}