class A {};
class B {};
A * a = new A;
B * b = reinterpret_cast<B*>(a);