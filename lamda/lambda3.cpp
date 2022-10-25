#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	//�ٽ� 1. ���� ǥ������ ���� ����� �ӽ� ��ü�̴�.
	[](int a, int b) {return a + b; };
	//�����Ϸ��� Ŭ�����ϳ��� �����. () ������ �ִ�..
	// class xxx{ operator()(){...}}; 
	// xxx();

	//auto ������ ��Ƽ� �Լ� ó�� ��밡���ϴ�.
	auto f1 = [](int a, int b) {return a + b; };

	int n1 = f1(1, 2);

//	auto& f2 = [](int a, int b) {return a + b; }; //error, �ӽ� ��ü�̹Ƿ� lvalue reference�� ���� ����
	const auto& f3 = [](int a, int b) {return a + b; }; //ok
	//��κ� f1 ó�� value�� ��Ƽ� ����Ѵ�.


	//�ٽ� 2. ����ǥ���İ� Ÿ��
	// -> ��� ���� ǥ������ �ٸ� Ÿ���̴�.
	// -> �����Ϸ��� ���� ����ϴ� �̸��� "�����Ϸ� ����, ����"�� ���� �ٸ���.
	auto f4 = [](int a, int b) {return a + b; };
					// class yyy{}; yyy();
	auto f5 = [](int a, int b) {return a + b; };
					// class xxx{}; xxx();

	std::cout << typeid(f4).name() << std::endl;
	std::cout << typeid(f5).name() << std::endl;

}