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

	//상수 begin(), end()에서는 cbegin()으로.. 상수 반복자를 사용한다.
	auto begin() const { return range.cbegin(); }
	auto end() const { return range.cbegin() + count; }

	auto begin() { return range.begin(); }
	auto end() { return range.begin() + count; }
};

template<typename T>
class reverse_view : public view_interface<reverse_view<T>>
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	//상수 begin(), end()에서는 crbegin(), crend()로.. 상수 반복자를 사용한다.
	auto begin() const { return range.crbegin(); }
	auto end() const { return range.crend(); }

	auto begin() { return range.rbegin(); }
	auto end() { return range.rend(); }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv1(v, 3);
	const take_view tv2(v, 3);

	auto p1 = tv1.begin(); //비 상수 view의 반복자
	auto p2 = tv2.begin(); //상수 view의 반복자

	//아래 코드를 생각해보자..
	*p1 = 10; //ok
	*p2 = 10; //error가 되어야한다.
	
}