#include <iostream>

void goo(int& arg) { arg = 100; }
void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));	//int& �� arg�� int&�� ĳ�����ϴ� �ڵ�
								//�ʿ���� �ڵ������� �־ �ȴ�. (������ ������ ������ �����)
								// (�ΰ��� ���ø��� �ϳ��� ��ġ�� ����..)
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// forwarding reference �� ����ϸ� �� 2���� �Լ��� �ڵ� �����Ҽ� �ֽ��ϴ�.
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	//���� ! �Ʒ� ĳ������ "rvalue ĳ����"�� �ƴϴ�.

	// chronometry ���� 2��° ���ڷ�
	// lvalue�� �����ϸ� lvalue�� ĳ�����ϰ�
	// rvalue�� �����ϸ� rvalue�� ĳ�����Ѵ�.
//	f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); //std::forward �Լ��� ���� ���� ĳ������ �����Ѵ�.
							//C++ ǥ��
}

int main()
{
	int n = 10;

	chronometry(goo, n); //T=int&, T&&=int& &&, chronometry( int& arg)
							//���� : static_cast<int&>(arg)
	chronometry(hoo, 10);//T=int, T&&=int&&, chronometry(int&& arg)
							//���� : static_cast<int&&>(arg)

	std::cout << n << std::endl;
}




