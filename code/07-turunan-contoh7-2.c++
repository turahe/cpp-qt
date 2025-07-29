int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Silinder drum(50,125);
cout << "Milik Base Class --> " << drum.getLuas() << endl;
cout << "Volume drum = " << drum.getVolume() << " Cm2" << endl;
return a.exec();
}