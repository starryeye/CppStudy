#include <iostream>

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg) // int&& arg = 0
{
	return f(std::forward<T>(arg));
}


void foo(int* p) {}

int main()
{
	int arg = 0;
	
	foo(0); // ok, 0�� int Ÿ�������� �����ͷ� �Ͻ��� ����ȯ�� �ȴ�.
			// ��, ���ͷ� 0 �� �����ͷ� �Ͻ��� ����ȯ ����.
	foo(arg);// error. 0�� ���� ������ ������ �����ͷ� ��ȯ �ȵ�.

//	chronometry(foo, 0); // error. �� ���� ������ nullptr ����ϴ� ��.
	chronometry(foo, nullptr);
}
// �ٽ� : �Լ��� �����͸� ���ڷ� ������
//			�Ϻ��� ������ ����ϴ� ��� �������� 0 ��� nullptr �������.
//		std::emplace_back(), std::make_shared(), chronometry()
