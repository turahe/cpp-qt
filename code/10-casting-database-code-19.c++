ContohClass
{
public:
// ...
void tampilkanAnggota (); // method ini berjenis const
};
void tampilkanData (const ContohClass& mData)
{
mData.tampilkanAnggota (); // compile error, karena "call to a non-const member using
a const reference"
}