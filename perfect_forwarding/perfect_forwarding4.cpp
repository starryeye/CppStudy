#include <iostream>

void hoo(int&& arg) {}

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10);
	chronometry(hoo, 10);

	int&& arg = 10; //10�� rvalue �Դϴ�.
					//arg�� �̸��� �ִ�..�׸��� lvalue�̴�..
	//Ÿ�԰� value �Ӽ��� �� ���� �ؾ��Ѵ�.
	//			Ÿ��		value �Ӽ�
	//10		int			rvalue
	//arg		int&&		lvalue..(��ȣ�� ����.. �׸��� �̸������ϱ�..)

	hoo(10); //hoo(rvalue) �̹Ƿ� ok
	hoo(arg);//hoo(lvalue) �̹Ƿ� error

	hoo(static_cast<int&&>(arg)); //ok
					// -> arg�� int&& Ÿ���ε�, �ᱹ ���� Ÿ�� ĳ���� �ƴѰ�..?
					// -> �� ǥ����� "Ÿ�� ĳ����"�� �ƴ�,
					// -> value �Ӽ��� �����ϴ�.. ĳ�����̴�.
					// -> C++ǥ�� ������ ��õǾ�����.
					// lvalue�� rvalue�� �����ϴ� value �Ӽ� ĳ�����̴�.
}
