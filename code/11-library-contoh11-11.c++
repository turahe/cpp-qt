#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QStringList>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QStringList lstKota;
lstKota << "Jogjakarta" << "Jakarta" << "Bandung" << "Semarang";
//menggabungkan string dengan tanda ',' sebagai pemisah
QString gabung = lstKota.join(",");
qDebug() << gabung;
//memecah string menjadi QStringList
QStringList listSplit = gabung.split(",");
foreach (QString kota, listSplit) {
qDebug() << kota;
}
//mengganti elenet dalam array
listSplit.replaceInStrings("a","aaa");
foreach (QString kota, listSplit) {
qDebug() << kota;
}
return a.exec();
}