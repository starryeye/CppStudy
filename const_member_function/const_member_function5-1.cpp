#include <iostream>
#include <vector>

template<typename T>
class take_view
{
	T& range;
	int count;
public:
	take_view(T& r, int c) : range(r), count(c) {}

	auto begin() { return range.begin(); }
	auto end() { return range.begin() + count; }

	bool empty() { return count == 0; }
	int size() { return count; }
};

template<typename T>
class reverse_view
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	auto begin() { return range.rbegin(); }
	auto end() { return range.rend(); }

	bool empty() { return range.empty(); }
	int size() { return range.size(); }
};

//문제점..
//모든 템플릿에 empty, size, 등을 계속 만들어주기는 힘들다..
//c++20에는 이러한 뷰 관련 템플릿은 수십가지이다..
//C++ 표준에서 어떻게 하는지 알아보자..
//5-2..

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3);
	reverse_view rv(v);

	bool b1 = tv.empty();
	bool b2 = rv.empty();


}