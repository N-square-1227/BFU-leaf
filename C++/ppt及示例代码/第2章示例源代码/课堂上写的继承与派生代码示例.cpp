// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Point
{
private:
	double x;
	double y;
public:
	Point(double x, double y);
	double getx();
	double gety();
	~Point();
};
Point::Point(double x, double y)
{
	cout << "ִ��Point��Ĺ��캯��" << endl;
	this->x = x;
	this->y = y;
}
Point::~Point()
{
	cout << "ִ��Point�����������" << endl;
}

double Point::getx()
{
	return x;
}
double Point::gety()
{
	return y;
}

class Circle :public Point
{
private:
	double r;
public:
	Circle(double x, double y, double r);
	double area();
	double getr();
	~Circle();
};
Circle::Circle(double x, double y, double r):Point(x,y)
{
	cout << "ִ��Circle��Ĺ��캯��" << endl;
	this->r = r;
}
Circle::~Circle()
{
	cout << "ִ��Circle�����������" << endl;
}
double Circle::area()
{
	return 3.14*r*r;
}
double Circle::getr()
{
	return r;
}

class Cylinder :public Circle
{
private:
	double h;
public:
	Cylinder(double x, double y, double r, double h);
	double volume();
	double geth();
	~Cylinder();
	double area();
};
double Cylinder::area()
{
	return 2 * 3.14*getr()*h + 3.14*getr()*getr() * 2;
}
Cylinder::Cylinder(double x, double y, double r, double h):Circle(x,y,r)
{
	cout << "ִ��Cylinder��Ĺ��캯��" << endl;
	this->h = h;
}
Cylinder::~Cylinder()
{
	cout << "ִ��Cylinder�����������" << endl;
}
double Cylinder::volume()
{
	return Circle::area()*h;
	//return getr()*getr()*3.14*h;
}

double Cylinder::geth()
{
	return h;
}

int main()
{
	Cylinder c(100, 200, 10, 50);
	cout << "Բ�����꣺(" << c.getx() << "," << c.gety() << ")" << endl;
	cout << "Բ�İ뾶��" << c.getr() << endl;
	cout << "��Բ�����" << c.Circle::area() << endl;
	cout << "�߶ȣ�" << c.geth() << endl;
	cout << "�����" << c.volume() << endl;
	cout << "�����" << c.area() << endl;

    return 0;
}

