#include <iostream>
//2�� ����

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
	return f(std::forward<T>(arg));
}


void foo(int* p) {}

int main()
{
	// 2��° ���ڸ� ���� "T" �� � Ÿ������ �߷е��� �����غ���.
//	chronometry(foo, 0);		//int&& arg = 0 �ε� �ᱹ
								//foo(arg) �� �ǹǷ� error

	chronometry(foo, nullptr);  // std::nullptr_t&& arg = nullptr;
								//foo(arg)�ε�
							//std::nullptr_t Ÿ���� ��� ������ �����ͷ� ��ȯ����
							//ok..
}

//�����Ϸ��� 0�� int Ÿ���ΰ� �˰��ִ�.