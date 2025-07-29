#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
//deklarasi string
QString nama = "Erick Kurniawan";
qDebug() << nama;
//cek ukuran string
int ukuran = nama.size();
qDebug() << "Ukuran string " << ukuran;
QString test = "";
//cek apakah string null
if(test.isNull())
qDebug() << "test null";
else
qDebug() << "test not null";
//cek apakah string empty
if(test.isEmpty())
qDebug() << "test empty";
else
qDebug() << "test not empty";
QString testing;
//cek apakah string null
if(testing == QString::null)
qDebug() << "testing null";
else
qDebug() << "testing not null";
return a.exec();
}