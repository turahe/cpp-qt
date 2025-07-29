class Halaman{
private:
int nohal;
int jenishal;
//1 -> halaman biasa, 2 -> halaman header
public:
Halaman(){
}
Halaman(int nohal){
this->nohal = nohal;
}
Halaman(int nohal,int jenishal){
Halaman(nohal); //memanggil konstruktor Halaman diatasnya!
this->jenishal = jenishal;
}
};