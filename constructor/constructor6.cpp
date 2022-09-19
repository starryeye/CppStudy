#include <iostream>

// C50_ Use a factory function if you need ��virtual behavior��
// during initialization

// C.82 : Don't call virtual functions in constuctors and destuctors
// �����ڿ� �Ҹ��ڿ����� "�����Լ��� �������� �ʽ��ϴ�." ������ �ڽ��� �ɹ� �Լ��� ȣ��˴ϴ�..

struct Base
{
	Base() { init(); } // Base�� init ȣ��

	void foo() { init(); }; //this->init() �ε� �� ��ġ���� this�� Base* �̴�.
							//init()�� ������ �ƴϸ� Base::init() ȣ��
							//init()�� �����̸� Derived::init() ȣ��
	//void init() { std::cout << "Base::init" << std::endl; }     // 1
	virtual void init() { std::cout << "Base::init" << std::endl; }     // �ذ��
};

struct Derived : public Base
{
	int x;
						//�����Ϸ��� ����
	Derived() : x(10) {} //Derived() : Base(), x(10) {}
						//�����Ϸ��� Base()�� ���� ȣ���Ѵ�. (Derived()�� �ʱ�ȭ �ϱ�����..)
						//�׷��� �ʱ�ȭ �Ǳ� ���� ���� ���� �����Ƿ�.. ����/�Ҹ꿡�� init �Լ��� ���� init �Լ� �ݵ� 

	//void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
	virtual void init() override { std::cout << "Derived::init : " << x << std::endl; } // 2
};

int main()
{
	Derived d;
	d.foo();   // ��� ������ ������
}

