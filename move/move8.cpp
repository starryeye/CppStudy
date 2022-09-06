#include <iostream>

// Rule Of 3/5

// Rule Of 3 : Ŭ���� �ȿ� �����Ͱ� �ְ�, �����Ҵ��ϴ� �ڵ尡 �ִٸ�
//				3���� special member function �� ������ �Ѵ�.
//				(�Ҹ���, ���� ������, ���� ������)
//				C++98 ������ ��Ģ

// Rule Of 5 : C++11 ���ʹ� �� ��Ģ�ܿ� 2���� �� �����ؾ��Ѵ�.
//				(move ������, move ���� ������)
class People
{
	char* name;
	int   age;
public:
	People(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s)+1, s);
	}

	~People() { delete[] name; }

	//���� ������
	People(const People& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}

	//���� ������
	//���� �����ڸ� ����� ��� "�׻� ���Կ�����"�� ������ �Ѵ�.
	People& operator=(const People& p)
	{
		if (&p == this) return *this; //�ڽŰ��� �� ����

		delete[] name;

		age = p.age;
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;
	}

	//move ������ (�̵� ������)
	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;
	}

	//move ���� ������ (�̵� ���� ������)
	People& operator=(People&& p)
	{
		if (&p == this) return *this; //�ڽŰ��� �� ����

		delete[] name;

		age = p.age;
		name = p.name;
		p.name = nullptr;

		return *this;
	}
};
int main()
{
	People p1("kim", 20);
	People p2 = p1;			//���� ������ (����鼭 �ֱ�)
	p2 = p1;				//���� ������ (�����Ŀ� �ֱ�)
	//=======C++98=========


	//=======C++11=========
	People p3 = std::move(p1);
	p3 = std::move(p2);		  
}



