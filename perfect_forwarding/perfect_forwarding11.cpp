#include <iostream>

void f0() { } //인자 0개
void f1(int a1) { } //인자 1개
void f2(int a1, double d) {  } //인자 2개
int& f3(int a1, double d, int& r) { r = 200; return r; } //인자 3개

// 완벽한 전달의 실전 코드.
// 1. 가변인자 템플릿 사용해서 인자 갯수의 제한을 없애야 한다.
// 2. 리턴값도 완벽하게 받으려면 "decltype(auto)" 사용
template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	//StopWatch sw; //생성자에서 시간 기록하자..
					//소멸자에서 다시 시간 구해서 기록된 시간과의 차이를 출력

	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 10;

	chronometry(f0);
	chronometry(f1, 10);
	chronometry(f2, 10, 3.4);
	int& ret = chronometry(f3, 10, 3.4, n);
	
	ret = 300; // 결국 n을 가리키는 참조 이므로 n = 300

	std::cout << n << std::endl; //200
}