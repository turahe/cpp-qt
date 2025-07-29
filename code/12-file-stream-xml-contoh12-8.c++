#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QFile file("simple.xml");
if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
{
qDebug() << "File tidak ditemukan ";
return a.exec();
}
QXmlStreamReader reader;
reader.setDevice(&file);
while(!reader.atEnd())
{
reader.readNext();
if(reader.isStartElement())
{
qDebug() << reader.name();
if(reader.name() == "Nim")
{
qDebug() << "Nama Attribute :" << reader.attributes().value("nama");
qDebug() << "Teks : " << reader.readElementText();
}
}
}
file.close();
return a.exec();
}