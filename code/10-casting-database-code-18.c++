void func(char *);
const char *x = "abcd";
func(const_cast<char *>(x));