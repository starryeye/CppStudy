#include <iostream>
#include <vector>

template<typename T>
class view_interface
{
	const T& Cast() const //상수맴버함수 내부에서 부름 따라서 상수 맴버함수가 되어야한다.
	{
		//const 맴버 함수에서 this 는 const를 가리키는 포인터이다.
		//return static_cast<T&>(*this); 
		return static_cast<const T&>(*this);
	} 
public:
	bool empty() const
	{
		auto& derv = Cast();
		// derv는 const& 이다.

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

	auto begin() const { return range.begin(); }
	auto end() const { return range.begin() + count; }
};

template<typename T>
class reverse_view : public view_interface<reverse_view<T>>
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	auto begin() const { return range.rbegin(); }
	auto end() const { return range.rend(); }
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