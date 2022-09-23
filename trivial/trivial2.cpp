#include <iostream>
#include <type_traits> 

class Test
{
	int data;
public:
	virtual void foo() {} //�����Լ��� ������ �����ڰ� trivial ���� ����

	void goo() {} // �Ϲ� �ɹ��Լ��� ������ �����ڴ� trivial �ϴ�.

	Test() {} //����ڰ� �����ڸ� �����ϸ� trivial ���� ����.

	Test() = default; //�����Ϸ��� �� �ȴ�.
						//trivial �ϴ�.
						//���� int data = 0;��� �ϸ�..
						//trivial ���� ����, (�����ڿ��� �ʱ�ȭ �Ұ��̹Ƿ�)
};

int main()
{
	// trivial ���θ� �����ϴ� ���
	bool b1 = std::is_trivially_default_constructible<Test>::value; //C++11
	bool b2 = std::is_trivially_default_constructible_v<Test>; //C++17

	std::cout << b2 << std::endl;
}