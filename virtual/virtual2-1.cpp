#include <iostream>

// C35. ��� Ŭ���� �Ҹ��ڴ� virtual �̰ų� protected �̾�� �Ѵ�.
// 
class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }

	//�����Լ��� �������(�����Լ� ���̺�)�� �����Ϸ���..
	//�Ҹ��ڸ� �����Լ��� �������� protected�� ���ƾ��Ѵ�.
protected:
	~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
	Base* p = new Derived;
//	delete p; //BAse �Ҹ��ڸ� ȣ���ؾ� �ϴµ�, protected �̹Ƿ� ������ ����
				//�ǵ� : Base* Ÿ�����δ� delete ��������..

	delete static_cast<Derived*>(p); //ok
}