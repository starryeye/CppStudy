#include <iostream>

void hoo(int&& arg) {}

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

// main					chronometry						hoo(int&&)
//hoo(10) ----------------------------------------------> ok		//�ٷ� ������ ��������.
//chronometry(10) ---> int&& arg = 10								//���ڱ� �̸��� ���� (-> lvalue����)
//						hoo(arg) ----------------------> error		//�׷��� ����
//						hoo(static_cast<int&&>(arg) ---> ok			//�ٽ� rvalue�� �ٲ㼭 ����.

template<typename F>
void chronometry(F f, int&& arg)
{
	//f(arg);//error
	f(static_cast<int&&>(arg)); //ok
}

int main()
{
	hoo(10);
	chronometry(hoo, 10);
}
