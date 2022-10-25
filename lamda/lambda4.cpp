// T.141: Use an unnamed lambda 
//		  if you need a simple function object in one place only

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,2,4,6 };

	//동일한 람다 표현식을 여러번 사용한다면
	//아래 처럼하지 말자..
	//모두 다른 람다타입이므로..
	//아래 코드는 결국 3개의 sort() 함수가 생성된다..
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	//해결
	auto cmp = [](int a, int b) { return a < b; };
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
}