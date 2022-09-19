#include <iostream>
#include <vector>

// empty(), size()를 const 맴버 함수로 수정한 순간
// -> 에러가 많이 발생
// -> 이 에러들을 모두 해결해야함.
// -> empty(), size() 는 반드시 const 함수 로 해야함.

template<typename T>
class view_interface
{
	T& Cast() { return static_cast<T&>(*this); } //다운캐스팅..?
public:
	bool empty() const
	{
		auto& derv = Cast();

		return derv.begin() == derv.end();
	}
	unsigned int size() const
	{
		auto& derv = Cast();

		return derv.end() - derv.begin();
	}
};

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

	const take_view tv(v, 3);
	reverse_view rv(v);

	bool b1 = tv.empty(); // empty(), size() 등은 반드시 상수 멤버 함수로 해야함.
	bool b2 = rv.empty();
	//


}