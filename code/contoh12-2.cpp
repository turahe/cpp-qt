#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QFile file("testfile.txt");
if(!file.exists())
{
qDebug() << "File : " << file.fileName() << " tidak ditemukan";
return a.exec();
}
if(!file.open(QIODevice::WriteOnly))
{
qDebug() << "Tidak dapat membuka file " << file.fileName() << " untuk ditulis";
return a.exec();
}
qDebug("File berhasil dibuka !");
file.close();
return a.exec();
}
