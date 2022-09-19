#include <iostream>
#include <vector>

//모든 view 의 공통의 맴버함수를 제공하기 위한 기반 클래스
// - > 실제 C++ 표준(C++20)에 이 클래스가 있습니다.

//CRTP 기법 : Curiosly Recurring Template Pattern
// -> 자신을 파생 클래스 타입으로 캐스팅해서 파생 클래스에 있는 함수를 호출하는 기술.
template<typename T>
class view_interface
{
	T& Cast() { return static_cast<T&>(*this); } //다운캐스팅..?
public:
	bool empty() 
	{
		auto& derv = Cast();

		return derv.begin() == derv.end();
	}
	unsigned int size() 
	{
		auto& derv = Cast(); 

		return derv.end() - derv.begin();
	}
};

//참고 STL은 성능 최적화가 가장 우선시 되므로..
//virtual function 사용은 피한다..

template<typename T>
class take_view : public view_interface<take_view<T>>
{
	T& range;
	int count;
public:
	take_view(T& r, int c) : range(r), count(c) {}

	auto begin() { return range.begin(); }
	auto end() { return range.begin() + count; }
};

template<typename T>
class reverse_view : public view_interface<reverse_view<T>>
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	auto begin() { return range.rbegin(); }
	auto end() { return range.rend(); }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3);
	reverse_view rv(v);

	bool b1 = tv.empty();
	bool b2 = rv.empty();


}