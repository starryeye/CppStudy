#include <iostream>

// C35. ��� Ŭ���� �Ҹ��ڴ� virtual �̰ų� protected �̾�� �Ѵ�.
// 
class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	virtual ~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
	//Base �Ҹ��ڰ� virtual�̸� Derived �Ҹ��ڵ� virtual �̵ȴ�.
};

int main()
{
//	Derived d;

//	Derived* p = new Derived; //Derived ������ ȣ��
//	delete p;				  //Derived �Ҹ��� ȣ��

	Base* p = new Derived;	  //Derived ������ ȣ��
	delete p;		//�� ���� �Ҹ��ڸ� ȣ�� �ؾ��Ѵ�. Base�Ҹ��ڸ� ȣ��
	
	//�����Ϸ��� �����ϴ� ���
	//1. p�� Base* �̹Ƿ� Base Ŭ�������� �Ҹ��ڰ� �����Լ����� ����
	// -> �Ҹ��ڰ� �����Լ��� �ƴϸ�, ������ Base �Ҹ��� ȣ��
	// -> �Ҹ��ڰ� �����Լ����, ������ �ð����� p�� �޸� �����ϴ� ���� �ڵ� ����
	//								����� ������ ����� ���� �Ҹ��� ȣ��
	// -> ����.. Base �Ҹ��ڿ� virtual Ű���� �߰��ؾߵ�
}