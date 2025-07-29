public:
float getLuas(){ //<-- Overriding
float luasSelimut = 2 * 3.14 * this->radius * this->tinggi;
float luasSilinder = 2 * Lingkaran::getLuas() + luasSelimut;
return luasSilinder;
}
float getVolume(){ //<-- anggota baru
//getLuas() milik kelas dasar
return Lingkaran::getLuas() * tinggi;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Silinder drum(50,125);
cout << "Luas Silinder = " << drum.getLuas() << " Cm2" << endl;
cout << "Milik Base Class --> " << drum.Lingkaran::getLuas() << endl;
cout << "Volume drum = " << drum.getVolume() << " Cm3" << endl;
return a.exec();
}