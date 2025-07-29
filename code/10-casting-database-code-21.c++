void tampilkanData (const ContohClass* pData)
{
// pData->DisplayMembers(); Error: attempt to invoke a non-const function!
CSomeClass* pCastedData = const_cast <CSomeClass*>(pData);
pCastedData->DisplayMembers(); // Allowed!
}