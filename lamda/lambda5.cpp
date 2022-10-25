// F.53: Avoid capturing by reference in lambdas that will be used non - locally, 
//       including returned, stored on the heap, or passed to another thread

#include <vector>
#include <functional>

std::function<int(int, int)> f;

void foo()
{
	//핵심 1. 람다 표현식은 auto 뿐 아니라 std::function에도 담을수 있다.
	auto f1 = [](int a, int b) {return a + b; };

	std::function<int(int, int)> f2 = [](int a, int b) {return a + b; };
}

int main()
{
	//지역적으로만 사용하지 않는 람다표현식은
	//지역변수의 reference capture 하지 말자..
	int n = 0;

//	f = [n](int a, int b) {return a + b + n; }; //ok 항상 안전하다.
											//n이 아니라 n의 값 0을 보관

	f = [&n](int a, int b) {return a + b + n; };
								//reference capture.
								// n 자체를 참조(주소)로 캡쳐
}//<- 이순간 n의 파괴. 하지만.. f는 전역이므로 다른 곳에서 사용가능
	// f가 캡쳐한 n은 "Dangling reference" 이다.
	//-> 죽음

int main()
{
	foo();
	f(1, 2); //버그 .. f가 캡쳐한 n은 이미 파괴 되었음
}