#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

//�ٽ� : �Ϻ��� ������ �Ϸ���
// -> int&, int&& ������ �Լ��� ���� �����ؾ��Ѵ�.

// -> �׷���, �Ʒ� chronometry���� �ϳ��� �������� �����Ѵ�.
// -> ���� �ҽ� ����.
template<typename F>
void chronometry(F f, int& arg) //n
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg) //10
{
	f(arg);
}

int main()
{
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	std::cout << n << std::endl; //100
}
