#include <iostream>
#include <string>

//C. 61: A copy operation should copy
//C. 64 : A copy operation should move and leave ists source in a valid state
//���� �����ڿ����� ���縦
//move �����ڿ����� move�� �϶�.

class People
{
	char* name;
	int   age;
	std::string address; //string Ÿ���� �ɹ������� �߰��Ǿ���.
public:
	People(const char* s, int a, const std::string& addr = "unknown") 
		: age(a), address(addr)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}

	~People() { delete[] name; }

	//���� ������
	People(const People& p) : age(p.age), address(p.address)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}

	//���� ������
	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		delete[] name;

		age = p.age;
		address = p.address;

		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;
	}

	//move ������ (�̵� ������)
	People(People&& p) 
//		: name(p.name), age(p.age), address(p.address) // <- �߸��� �ڵ��̴�.
		//string�� ���� �����ڰ� ȣ�� �Ȱ��̴�.
		: name(p.name), age(p.age), address(std::move(p.address)) // ok
		// -> move �����ڴ� ��� �ɹ��� move�� �Űܾ��Ѵ�.
		// -> ��, primitive type�� std::move�� ����ص� �ǰ� ���ص� ��(�ǹ� ����)
	{
		p.name = nullptr;
	}

	//move ���� ������ (�̵� ���� ������)
	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		delete[] name;

		age = p.age;
		name = p.name;
//		address = p.address;			//���� ���� �����ڸ� ����ߴ�.. move ���� �����ڸ� ����ؾ��Ѵ�.
		address = std::move(p.address); //ok

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



