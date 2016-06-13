#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class COpArray
{
	private:
	int *_myArray;
	int _numElement;
	public:
	COpArray(int numElement);
	~COpArray();
	int& operator[](int index);
	};
int& COpArray::operator [](int index)
{
	return _myArray[index];
}
COpArray::COpArray(int numElement)
{
	_myArray = new int[numElement];
	_numElement = numElement;
}
COpArray::~COpArray()
{
	delete [] _myArray;
}
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	COpArray arrOp(5);
	arrOp[0]=23;
	arrOp[1]=16;
	arrOp[2]=9;
	arrOp[3]=20;
	arrOp[4]=55;
	cout << "The content array are : " << "{";
	for(int i=0;i<5;++i)
	{
		cout << arrOp[i] << " ";
		}
		cout << "}" << endl;
		return a.exec();
}