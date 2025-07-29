#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QList<int> lstNumber;
lstNumber << 12 << 24 << 36 << 48 << 60;
//menggunakan iterator
QListIterator<int> iter(lstNumber);
while(iter.hasNext())
{
qDebug() << iter.next();
}
//cara lain dengan cara STL
QList<int>::const_iterator stlIter;
for(stlIter=lstNumber.begin();stlIter!=lstNumber.end();++stlIter)
{
qDebug() << (*stlIter);
}
return a.exec();
}