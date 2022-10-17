#include <iostream>

void goo(int& arg) { arg = 100; }
void hoo(int&& arg) {}


// F.19: For ��forward�� parameters, 
//       pass by TP&& and only std::forward the parameter

// ���� ���� ���ڸ� �ٸ� �Լ��� �Ϻ��ϰ� �����Ϸ���
// 1. ���ڸ� ���� �� forwarding  reference(T&&) ���
// 2. ���ڸ� �ٸ����� ������ "std::forward<T>(arg)"�� ��� ����.


template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	//�ð����
	f(std::forward<T>(arg));
	//�ɸ��ð����
}

int main()
{
	int n = 10;
	chronometry(goo, n);
	chronometry(hoo, 10);

	std::cout << n << std::endl;
}




