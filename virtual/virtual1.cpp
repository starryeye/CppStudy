#include <iostream>

// C.140: Do not provide different default arguments 
//        for a virtual function and an overrider

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};

class Derived : public Base
{
public:
	virtual void foo(int a = 20) { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;
	p->foo(); // ��� �����غ���..
				// ��� : "Derived : 10"
				//
				// ���ڵ尡 �����ϵǸ�
				// p->foo(10) ���� �����.

				// �׷���.. ���� � foo�� ȣ�������� 
				// ����ð��� p�� ����Ű�� ���� �޸� ������ ����

	//�ٽ�
	// �Ʒ� �ΰ����� ������ ��������..
	//����Ʈ ���ڸ� ä���ִ� �� : ������ �ð��� �۾�
	//� �Լ��� ȣ������ ����(�����Լ�) : ����ð��� �۾�
}