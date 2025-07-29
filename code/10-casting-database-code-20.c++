void tampilkanData (const ContohClass& mData)
{
ContohClass& refData = const_cast <ContohClass&>(mData);
refData.tampilkanAnggota(); // OK!
}