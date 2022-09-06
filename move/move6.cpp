#include <cstring>
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		std::cout << "copy ������" << std::endl;
	}

	Cat(Cat&& c)
		: name(c.name), age(c.age)
	{
		c.name = nullptr;

		std::cout << "move ������" << std::endl;
	}
};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	//c1�� lvalue, ���� ������ ȣ��

	Cat c3 = foo();	//temporary, rvalue, move ������ ȣ��

	Cat c4 = static_cast<Cat&&>(c2);	//move ������ ȣ��, ���̻� c2�� �Ⱦ��Ŵٶ�� �ǵ��� ����
										//�̸��ִ� lvalue�����.. move�ϰ� �ʹٸ�..

	Cat c5 = std::move(c3); //���� ���� ĳ����(static_cast<Cat&&>)�� �����Ѵ�.


	//���
	//1. std::move() ��ü�� ��ü�� �ڿ��� �̵��ϴ� ���� �ƴϴ�.
	//2. ����, ��ü�� rvalue �� ĳ�����ϴ� ���̴�.
	//3. ĳ������ ����� move ������ ȣ��.
	//4. �ᱹ, �ڿ��� �̵��ϴ� ���� Ŭ���� �ȿ� �ִ� move �����ڰ� �Ѵ�.

	//����
	//� ��ü�� std::move() �ߴµ�, �ش� Ÿ�Կ� move �����ڰ� ���ٸ�..
	//-> �׳� ���� �����ڸ� ����ϰ� �ȴ�.(const Cat& c)
	//-> ��, ��������� ������, ������ �ƴϴ�.


}