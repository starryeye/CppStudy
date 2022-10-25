#include <iostream>

// C170. 람다표현식이 오버로딩이 필요 하면 generic 람다를 사용해라. - C++14

int main()
{
	auto add = [](int a, int b) { return a + b; };

	std::cout << add(1,   2) << std::endl;	//3
	std::cout << add(1.1, 2.2) << std::endl;//3
	std::cout << add(1,   2.2) << std::endl;//3
	std::cout << add(1.1, 2) << std::endl;	//3

	//C++14 부터 지원되는 generic lambda
	//-> 람다의 인자로 auto 사용
	auto add1 = [](auto a, auto b) { return a + b; };

	std::cout << add1(1, 2) << std::endl;		//3
	std::cout << add1(1.1, 2.2) << std::endl;	//3.3
	std::cout << add1(1, 2.2) << std::endl;		//3.2
	std::cout << add1(1.1, 2) << std::endl;		//3.1

	//generic 람다의 단점
	auto swap = [](auto& a, auto& b) {auto t = a; a = b; b = tmp; };

	int n1 = 10;
	double d1 = 3.4;

	swap(n1, d1); //되는게 좋을까.. 에러가 좋을까..
					//-> 된다... 단점을 극복하기 위해.. C++20

	//C++20 부터 template lambda 문법이 도입되었다.
	// -> 람다 표현식에서도 템플릿이 가능하다는 것이다.
	auto swap2 = []<typename T>(T & a, T & b) {};

	swap2(n1, d1); //error. 2개의 인자가 같은 타입이어야 한다.
}

//generic 람다 원리
class CompilerGeneratedName
{
public:
	//핵심. 2개의 인자가 서로 다른 템플릿
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b)
	{
		return a + b;
	}
};

//C++11 : C++에서 함수 인자로 auto 를 사용할 수 없다.
//C++14 : 람다표현식에서 인자로 auto 를 사용가능하다.
//C++20 : 일반 함수(템플릿)도 auto 인자 가능하다.

void foo(auto a)//ok.. C++20 부터..
{
}
// 위 foo는 결국 템플릿입니다.
//template<typename T> void foo(T a) {} // 이 코드와 완전히 동일

auto add(auto a, auto b)
{
	return a + b;
}


