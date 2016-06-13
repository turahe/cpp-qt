#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class CTampil
{
	public:
	void operator()(string msg) const
{
	cout << msg << endl;
}
};
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	CTampil objTampil;
	//penulisan ekuivalen dengan objTampil.operator ()("Hello Function Operator !");
	objTampil("Hello Function Operator !");
	return a.exec();
}