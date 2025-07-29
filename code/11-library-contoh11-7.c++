#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QList<QString> lstNama;
lstNama << "Erick" << "Anton" << "Katon" << "Budi";
//mengakses data berdasarkan index tertentu
qDebug() << lstNama[0];
//akan menghasilkan error karena tipe bukan string
//lstNama << 12 << 13;
//membaca dan menampilkan semua data pada list
foreach (QString nama, lstNama) {
qDebug() << nama;
}
return a.exec();
}