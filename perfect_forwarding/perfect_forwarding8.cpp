#include <iostream>

// �ٽ� 1. T& �� T&& �� �ǹ̸� ��Ȯ�� ����.
// T&  : lvalue�� �ްڴٴ� �ǹ�.
// T&& : lvalue�� rvalue�� ��� �ްڴٴ� �ǹ�

template<typename T>
void foo(T&& arg)
{
	// �ٽ� 2. std::move �� std::forward �� �������� ��Ȯ�� ����.
	int n1 = std::move(arg); //arg�� �׻� rvalue�� ĳ���� (move �����ڸ� �θ������� ���� ���̱� ����..)

	int n2 = std::forward<T>(arg); //foo ȣ�� �� ���ڸ� ���� ��
									//rvalue�� �������� rvalue
									//lvalue�� �������� lvalue�� ĳ����..

	//std::move()	 : move �����ڸ� ȣ���ϰ� ���� �� ���
	//std::forward	 : ���ڸ� �ٸ� ���� ������ ���� �� ���
}

int main()
{
	int n1 = 10;

	foo(10);
	foo(n1);
}