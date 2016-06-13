#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
foreach (QFileInfo drive, QDir::drives()) {
qDebug() << "Drive : " << drive.absolutePath();
QDir dir = drive.dir();
dir.setFilter(QDir::Dirs);
foreach (QFileInfo rootDirs, dir.entryInfoList()) {
qDebug() << " " << rootDirs.fileName() ;
}
}
return a.exec();
}