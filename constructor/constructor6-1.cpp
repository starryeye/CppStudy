#include <iostream>
#include <memory>

// C50_ Use a factory function if you need ��virtual behavior��
// during initialization

// ��ü�� ������������ �����Լ��� ȣ���ϰ� �ʹٸ�..
// -> Factory function �� ����ض�.
// -> ���� ���̺귯���� ����ϴ� ����̴�.

struct Base
{
	Base() { }

	virtual void init() { std::cout << "Base::init" << std::endl; }

	//�Ʒ� �Լ��� Factory Function �̴�.
	template<typename T>
	static std::unique_ptr<T> Create()
	{
//		T* p = new T(); //��ü�� ���� �����
		auto p = std::make_unique<T>();
		p->init();		//�����Լ��� ȣ���Ѵ�.
						//��ü�� ������ ȣ���ϹǷ� �����Լ��� ����� �����Ѵ�.
		return p;
	}

	/*
	//�Ʒ� �Լ��� Factory Function �̴�.
	template<typename T>
	static T* Create()
	{
		T* p = new T(); //��ü�� ���� �����
		p->init();		//�����Լ��� ȣ���Ѵ�.
						//��ü�� ������ ȣ���ϹǷ� �����Լ��� ����� �����Ѵ�.
		return p;
	}
	*/
};

struct Derived : public Base
{
	int x;

	Derived() : x(10) {} 

	virtual void init() override { std::cout << "Derived::init : " << x << std::endl; }
};

int main()
{
//	Derived d; // �̷��� ���� ������ ����

	auto p = Base::Create<Derived>(); //��ü�� ����� �Լ�(factory �Լ�) �� ����϶�� ��
}

//JAVA�� ��Ѱ�...?