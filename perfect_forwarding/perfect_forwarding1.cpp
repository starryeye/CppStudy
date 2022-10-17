#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding
// -> �Լ� ���ڸ� �ٸ� �Լ��� �����ϴ� ��.

// perfect forwarding(�Ϻ��� ����)
// -> ���ڸ� ��� ��ȭ�� ���� �ٸ� �Լ����� ���� �ϴ� ��.
// C++98�δ� ��������.. C++11�� ����

// Ư���Լ��� ����ð��� �����ϴ� �Լ�
template<typename F, typename T>
void chronometry(F f, T arg) //���޹��� T arg�� F �� ������.. -> forwarding
{
	//�ð� ���
	f(arg);
	//�ɸ� �ð� ���
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n); //goo(n);

	std::cout << n << std::endl;
}
