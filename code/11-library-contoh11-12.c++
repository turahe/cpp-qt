#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QStack>
#include <QQueue>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QStack<QString> lstStack;
lstStack.push("17rick");
lstStack.push("anton");
lstStack.push("katon");
lstStack.push("budi");
//order LIFO
qDebug() << "Stack LIFO : ";
while(!lstStack.isEmpty())
{
qDebug() << lstStack.pop();
}
QQueue<QString> lstQueue;
lstQueue.enqueue("17rick");
lstQueue.enqueue("anton");
lstQueue.enqueue("katon");
lstQueue.enqueue("budi");
//order FIFO
qDebug() << "Queue FIFO : ";
while(!lstQueue.isEmpty())
{
qDebug() << lstQueue.dequeue();
}
return a.exec();
}