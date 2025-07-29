#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QList<QString> lstNama;
lstNama << "Erick" << "Anton" << "Katon" << "Ricky";
QMutableListIterator<QString> iter(lstNama);
while(iter.hasNext())
{
if(iter.next().toLower().contains("rick"))
{
iter.setValue("update data..");
}
}
//baca data setelah diupdate
foreach (QString nama, lstNama) {
qDebug() << nama;
}
return a.exec();
}