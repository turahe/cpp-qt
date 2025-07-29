#include <QtCore/QCoreApplication>
#include <iostream>
#include <math.h>
using namespace std;
class Titik{
private:
int x;
int y;
public:
Titik(int x,int y){
this->x = x;
this->y = y;
}
Titik(){
}
int getX(){
return this->x;
    }
int getY(){
return this->y;
}
void setX(int x){
this->x=x;
}
void setY(int y){
this->y=y;
}
//method tambahan
void printPoint(){
cout<<"("<<this->x<<" , "<<this->y<<")"<<endl;
}
bool isOrigin(){
return (this->x == 0 && this->y == 0);
}
};
class Garis{
private:
Titik p1;
Titik p2;
public:
Garis(int x1,int y1,int x2,int y2) {
p1.setX(x1);
p1.setY(y1);
p2.setX(x2);
p2.setY(y2);
}
Garis(){
}
Garis(Titik t1,Titik t2){
p1=t1;
p2=t2;
}
void setPoint1(Titik p1){
this->p1 = p1;
}
void setPoint2(Titik p2){
this->p2 = p2;
}
void setPoints(Titik p1,Titik p2){
this->p1 = p1;
this->p2 = p2;
}
Titik getPoint1(){
return this->p1;
}
Titik getPoint2(){
return this->p2;
}
void printLine(){
cout<<"awal: ";
this->p1.printPoint();
    cout<<"akhir: ";
this->p2.printPoint();
}
//Hitung panjang garis
float getLength(){
return sqrt((this->p1.getX() - this->p2.getX())*(this->p1.getX() - this-
>p2.getX()) + (this->p1.getY() - this->p2.getY())*(this->p1.getY() - this-
>p2.getY()));
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Titik A(1,1);
cout<<"A ";
A.printPoint();
Titik B(5,1);
cout<<"B ";
B.printPoint();
Titik C(5,6);
cout<<"C ";
C.printPoint();
Titik D(1,6);
cout<<"D ";
D.printPoint();
Garis ab(A,B);
cout<<"ab ";
ab.printLine();
cout<<"Panjang garis ab: "<<ab.getLength()<<endl;
Garis bc(B,C);
cout<<"bc ";
bc.printLine();
cout<<"Panjang garis bc: "<<bc.getLength()<<endl;
Garis cd(D,C);
cout<<"cd ";
cd.printLine();
cout<<"Panjang garis cd: "<<cd.getLength()<<endl;
Garis da(D,A);
cout<<"da ";
da.printLine();
cout<<"Panjang garis da: "<<da.getLength()<<endl;
return a.exec();
}