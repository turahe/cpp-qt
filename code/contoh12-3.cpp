#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QFile>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QFile file("D:\\sample.txt");
if(!file.exists())
{
qDebug() << "File " << file.fileName() << " tidak ditemukan !";
return a.exec();
}
if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
{
qDebug() << "File " << file.fileName() << " tidak dapat diakses !";
return a.exec();
}
QTextStream stream(&file);
//membaca semua teks yang ada dalam sample.txt
QString teks = stream.readAll();
qDebug() << teks;
//membaca teks per line
while(!stream.atEnd())
{
QString line = stream.readLine();
qDebug() << line;
}
file.close();
return a.exec();
}