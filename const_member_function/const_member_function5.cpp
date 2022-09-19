#include <iostream>
#include <vector>

template<typename T>
class take_view
{
	T&  range;
	int count;
public:
	take_view(T& r, int c) : range(r), count(c) {}

	auto begin() { return range.begin(); }
	auto end() { return range.begin() + count; } // <- 핵심
};

template<typename T>
class reverse_view
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	auto begin() { return range.rbegin(); }
	auto end() { return range.rend(); } // <- 핵심
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3); //C++17 부터는 클래스 template 타입 인자 생략 가능

	for (auto e : v) //원리 : 내부적으로 v.begin(), v.end() 를 사용
	{
		std::cout << e << ", ";
	}

	std::cout << "------------" << std::endl;
		
	for(auto e : tv)
	{
		std::cout << e << ", ";
	}

	std::cout << "------------" << std::endl;

	for (auto e : take_view(v, 3)) // 임시 객체로 전달
	{
		std::cout << e << ", ";
	}

	std::cout << "------------" << std::endl;

	for (auto e : reverse_view(v)) // 임시 객체로 전달
	{
		std::cout << e << ", ";
	}
}