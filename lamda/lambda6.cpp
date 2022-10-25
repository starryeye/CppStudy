#include <iostream>

// C170. ����ǥ������ �����ε��� �ʿ� �ϸ� generic ���ٸ� ����ض�. - C++14

int main()
{
	auto add = [](int a, int b) { return a + b; };

	std::cout << add(1,   2) << std::endl;	//3
	std::cout << add(1.1, 2.2) << std::endl;//3
	std::cout << add(1,   2.2) << std::endl;//3
	std::cout << add(1.1, 2) << std::endl;	//3

	//C++14 ���� �����Ǵ� generic lambda
	//-> ������ ���ڷ� auto ���
	auto add1 = [](auto a, auto b) { return a + b; };

	std::cout << add1(1, 2) << std::endl;		//3
	std::cout << add1(1.1, 2.2) << std::endl;	//3.3
	std::cout << add1(1, 2.2) << std::endl;		//3.2
	std::cout << add1(1.1, 2) << std::endl;		//3.1

	//generic ������ ����
	auto swap = [](auto& a, auto& b) {auto t = a; a = b; b = tmp; };

	int n1 = 10;
	double d1 = 3.4;

	swap(n1, d1); //�Ǵ°� ������.. ������ ������..
					//-> �ȴ�... ������ �غ��ϱ� ����.. C++20

	//C++20 ���� template lambda ������ ���ԵǾ���.
	// -> ���� ǥ���Ŀ����� ���ø��� �����ϴٴ� ���̴�.
	auto swap2 = []<typename T>(T & a, T & b) {};

	swap2(n1, d1); //error. 2���� ���ڰ� ���� Ÿ���̾�� �Ѵ�.
}

//generic ���� ����
class CompilerGeneratedName
{
public:
	//�ٽ�. 2���� ���ڰ� ���� �ٸ� ���ø�
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b)
	{
		return a + b;
	}
};

//C++11 : C++���� �Լ� ���ڷ� auto �� ����� �� ����.
//C++14 : ����ǥ���Ŀ��� ���ڷ� auto �� ��밡���ϴ�.
//C++20 : �Ϲ� �Լ�(���ø�)�� auto ���� �����ϴ�.

void foo(auto a)//ok.. C++20 ����..
{
}
// �� foo�� �ᱹ ���ø��Դϴ�.
//template<typename T> void foo(T a) {} // �� �ڵ�� ������ ����

auto add(auto a, auto b)
{
	return a + b;
}


