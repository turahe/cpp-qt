#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QList<QString> lstNama;
//menambahkan data di akhir list
lstNama << "erick";
lstNama.append("katon");
//menambahkan data di awal list
lstNama.prepend("anton");
//menambahkan data pada index tertentu
lstNama.insert(2,"budi");
lstNama.insert(4,"naren");
foreach (QString nama, lstNama) {
qDebug() << nama;
}
return a.exec();
}