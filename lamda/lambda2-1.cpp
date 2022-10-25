#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

bool foo(int n) { return n % 3 == 0; }

struct IsDivide
{
	int value; // <-- 핵심, main 함수 안에 있는 지역 변수 k의 값을 보관(캡쳐)

	IsDivide(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };


	int k = 3;

	IsDivide f(k);
	bool b = f(10); // f는 단항 함수(객체)이다.
					// 결국 "10 % k == 0" 이므로 false
					// 즉, "k 의 값을 캡쳐"한 단항함수

//	auto ret1 = std::find_if(v.begin(), v.end(), f); //f는 k값을 캡쳐한 클로져이다.
	
	//한번만 사용한다면, 아래처럼 임시객체 형태로 보내면 된다.
	auto ret1 = std::find_if(v.begin(), v.end(), IsDivide(k));

	//IsDivide(k) : k 값은 캡쳐한 단항함수(객체),
	//					즉, Closure 이다.

	std::cout << *ret1 << std::endl;
}
