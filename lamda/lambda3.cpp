#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	//핵심 1. 람다 표현식의 최종 결과는 임시 객체이다.
	[](int a, int b) {return a + b; };
	//컴파일러가 클래스하나를 만든다. () 연산자 있는..
	// class xxx{ operator()(){...}}; 
	// xxx();

	//auto 변수에 담아서 함수 처럼 사용가능하다.
	auto f1 = [](int a, int b) {return a + b; };

	int n1 = f1(1, 2);

//	auto& f2 = [](int a, int b) {return a + b; }; //error, 임시 객체이므로 lvalue reference에 담지 못함
	const auto& f3 = [](int a, int b) {return a + b; }; //ok
	//대부분 f1 처럼 value로 담아서 사용한다.


	//핵심 2. 람다표현식과 타입
	// -> 모든 람다 표현식은 다른 타입이다.
	// -> 컴파일러가 실제 사용하는 이름은 "컴파일러 종류, 버전"에 따라 다르다.
	auto f4 = [](int a, int b) {return a + b; };
					// class yyy{}; yyy();
	auto f5 = [](int a, int b) {return a + b; };
					// class xxx{}; xxx();

	std::cout << typeid(f4).name() << std::endl;
	std::cout << typeid(f5).name() << std::endl;

}