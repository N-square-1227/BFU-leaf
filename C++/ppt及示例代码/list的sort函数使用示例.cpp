// ConsoleApplication24.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include<string>
using namespace std;

class Student //������
{
public:
	string no;
	int age;
public:
	Student(string no, int age)
	{
		this->no = no;
		this -> age = age;
	}
	 friend bool operator>(const Student &s1,const Student &s2)  //�������������>
	{
		if (s1.age > s2.age)
			return true;
		return false;
	}
};

class S   //�Զ�����
{
public:
	bool operator()(const Student &s1, const Student &s2)  //�������������
	{
		if (s1.age < s2.age)
			return true;
		return false;
	}
};

int main()
{
	list<int> list1;       //Ԫ��Ϊ������������
	list1.push_back(100);
	list1.push_back(20);
	list1.push_back(300);
	list1.push_back(40);
	list1.sort(greater<int>());   //���⺯��greater<type>()���ݸ�sort������������������
	list<int>::iterator i1;
	for (i1 = list1.begin();i1 != list1.end();i1++)
		cout << *i1 << endl;

	list<string> list2;     //Ԫ��Ϊstring����
	list2.push_back("abc");
	list2.push_back("123");
	list2.push_back("078");
	list2.push_back("xyz");
	list2.push_back("tttt");

	list2.sort();         //������������ʾ�Ի������͵�Ԫ����������

	list<string>::iterator i2;
	for (i2 = list2.begin();i2 != list2.end();i2++)
		cout << *i2 << endl;

	list<Student> list3;   //Ԫ��ΪStudent��������

	list3.push_back(Student("111", 21));
	list3.push_back(Student("222", 22));
	list3.push_back(Student("333", 29));
	list3.push_back(Student("444", 20));

	list3.sort(greater<Student>());  //���⺯��greater<type>()���ݸ�sort����������Student����������>�������������������
	list<Student>::iterator i3;
	for (i3 = list3.begin();i3 != list3.end();i3++)
	{
		cout << (*i3).no<<","<<(*i3).age << endl;
	}


	list3.sort(S());    //���Զ���Ķ��󴫵ݸ�sort��������������S�У������������()��������������������������
	for (i3 = list3.begin();i3 != list3.end();i3++)
	{
		cout << (*i3).no << "," << (*i3).age << endl;
	}

	return 0;
}

