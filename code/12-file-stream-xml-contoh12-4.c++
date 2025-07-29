#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QList>
#include <QColor>
#include <QFile>
struct Warna
{
QString text;
QColor color;
};
QDataStream &operator << (QDataStream &stream, const Warna &data)
{
stream << data.text << data.color;
return stream;
}
QDataStream &operator >>(QDataStream &stream, Warna &data)
{
stream >> data.text;
stream >> data.color;
return stream;
}
void saveList()
{
QList<Warn list;
Warna data;
data.text = "Merah";
data.color = Qt::red;
list << data;
data.text = "Biru";
data.color = Qt::blue;
list << data;
data.text = "Kuning";
data.color = Qt::yellow;
list << data;
data.text = "Hijau";
data.color = Qt::green;
list << data;
QFile file( "datastream.dat" );
if( !file.open( QIODevice::WriteOnly ) )
return;
QDataStream stream( &file );
stream.setVersion( QDataStream::Qt_4_7);
stream << list;
file.close();
}
void loadList()
{
QList<Warn list;
QFile file( "datastream.dat" );
if( !file.open( QIODevice::ReadOnly ) )
return;
QDataStream stream(&file);
stream.setVersion(QDataStream::Qt_4_7);
stream >> list;
file.close();
foreach( Warna data, list )
qDebug() << data.text << "("
<< data.color.red() << ","
<< data.color.green() << ","
<< data.color.blue() << ")";
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
saveList();
loadList();
return a.exec();
}