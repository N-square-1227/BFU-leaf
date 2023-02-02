// li1-13.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class Point
{
private:
	double x;
	double y;
public:
	friend double distance2(Point &a, Point &b);
	Point(int a, int b)
	{
		x = a;		y = b;
	}
	static double distance1(Point &a, Point &b);
	double distance4(Point &a);

	double getx()	//��ȡx��ֵ
	{
		return x;
	}
	double gety()	//��ȡy��ֵ
	{
		return y;
	}
};

double Point::distance1(Point &a, Point &b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double distance2(Point &a, Point &b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double distance3(Point &a, Point &b)
{
	return sqrt((a.getx() - b.getx())*(a.getx() - b.getx()) + (a.gety() - b.gety())*(a.gety() - b.gety()));
}

double Point::distance4(Point &a)
{
	return sqrt((a.x - this->x)*(a.x - this->x) + (a.y - this->y)*(a.y - this->y));
}
int main()
{
	Point p1(3, 5);
	Point p2(5, 3);
	cout << p1.distance4(p2) << endl;

	
	cout << Point::distance1(p1, p2) << endl;
	cout << distance2(p1, p2) << endl;
	cout << distance3(p1, p2) << endl;
	cout << p1.distance4(p2) << endl;

	return 0;
}
