CSomeClass* pObject = new CSomeClass ();
// harus dikirimkan dalam bentuk byte (unsigned char)
unsigned char* pBytes = reinterpret_cast <unsigned char*>(pObject);