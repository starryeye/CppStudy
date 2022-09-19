#include <iostream>

// ������ ȣ����� �� �˾� �μ���.
// �����!! �������� ���� �������� ����..
// "��Ȯ�� ������ �����ϰ�, �������� ����.."

struct BM //BM : Base Member
{
	BM() { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM //DM : Drived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;

	// ����� �ڵ�		// �����Ϸ��� ������ �ڵ�
	Base()				// Base() : bm()
	{
		// call BM::BM() �� ���� �ڵ� ���� ( C++ �ڵ�� ǥ���Ҷ��� �� �ʱ�ȭ ����Ʈ�� ǥ��)

		std::cout << "Base()" << std::endl;
	}
	~Base() 
	{ 
		std::cout << "~Base()" << std::endl; 

		//�Ҹ��ڴ� ~Base()���� ��� ������ �����Ŀ� �ɹ��� �Ҹ��ڸ� ȣ��
		// ~bm()
	}
};

struct Derived : public Base
{
	DM dm;
	
	//�ٽ� 1. �����Ϸ��� ������ִ� �ڵ带 ��������..
	// ����� �ڵ�		//�����Ϸ��� ������ ��.
//	Derived()			//Derived() : Base(), dm()

	//�ٽ� 2. ����ڰ� ���Ŭ������, �ɹ������� �����ڸ�
	// ��������� ȣ�� �� ���� ������..
	// ������ ȣ�� ������ ���� ���� �� �� ����.
	// -> �׻�, �ɹ� ������ ����, ��� Ŭ���� �����ڰ� ���� �Ҹ�.
	Derived() : dm(), Base()
	{
		std::cout << "Derived()" << std::endl;
	}
	~Derived() 
	{ 
		std::cout << "~Derived()" << std::endl; 

		//~dm()
		//~Base()
	}
};

int main()
{
	Derived d; // �� ������ ����� ������ ������.
				// call Derived::Derived()
				//�����Ϸ��� �ʱ�ȭ ����Ʈ�� �������..
				// �ʱ�ȭ ����Ʈ ���� �θ�.
}
