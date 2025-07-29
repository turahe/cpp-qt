int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Lingkaran* objek1; //<-- variabel pointer bertipe kelas dasar
objek1 = new Silinder(); //<-- objek bertipe kelas turunan
objek1->getLuas(); //<-- memanggil metode yang dioverride
static_cast<Silinder*>(objek1)->getVolume(); //<-- casting mjd Silinder
return a.exec();
}