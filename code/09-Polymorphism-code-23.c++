class Binatang //<-- common base class (kelas dasar bersama)
class Kuda : virtual public Binatang //<-- penurunan secara virtual
class Burung : virtual public Binatang //<-- penurunan secara virtual
class Kuda_terbang : public Kuda, public Burung