#include <iostream>
template<typename T> void foo(T&& arg)
{
	// Ȯ���ϴ¹�
	//1. �Ʒ�ó�� typeid()�� Ȯ������ ����..
	//->typeid��.. &,&&,const, volitile ���� ��µ��� ����
	//std::cout << typeid(arg).name() << std::endl;

	// ���� ������ �Լ��� �̸��� ����ؼ� Ȯ������.
//	std::cout << __func__ << std::endl; //�Լ� �̸��� ���� C++ ǥ�� ��ũ��, ��¥ �Լ��̸��� ����..

	std::cout << __FUNCSIG__ << std::endl; //���ڸ� ������ �Լ� ��ü �̸�
											//C++ ǥ�� �ƴ�..
											//visual studio �� ����..

	std::cout << __PRETTY_FUNCTION__ << std::endl; //g++, clang++�� ����
													//visual studio �ȵ�..
}
int main()
{
	int n = 10;

	foo(n);  // T=int&,  ������ �Լ�: foo(int& arg)
	foo(10); // T=int,	 ������ �Լ�: foo(int&& arg)
}




