#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QMap<QString,int> lstAge;
lstAge["erick"] = 29;
lstAge["anton"] = 29;
lstAge["katon"] = 42;
qDebug() << "erick age : " << lstAge["erick"];
qDebug() << "menampilkan semua data yg ada di map :";
foreach (QString key, lstAge.keys()) {
qDebug() << key << " : " << lstAge[key];
}
//menggunakan iterator
qDebug() << "Mengakses data menggunakan iterator";
QMap<QString, int>::ConstIterator itr;
for (itr=lstAge.constBegin();itr!=lstAge.constEnd();++itr) {
qDebug() << itr.key() << " : " << itr.value();
}
return a.exec();
}