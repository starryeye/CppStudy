#include <iostream>
#include <vector>

//��� view �� ������ �ɹ��Լ��� �����ϱ� ���� ��� Ŭ����
// - > ���� C++ ǥ��(C++20)�� �� Ŭ������ �ֽ��ϴ�.

//CRTP ��� : Curiosly Recurring Template Pattern
// -> �ڽ��� �Ļ� Ŭ���� Ÿ������ ĳ�����ؼ� �Ļ� Ŭ������ �ִ� �Լ��� ȣ���ϴ� ���.
template<typename T>
class view_interface
{
	T& Cast() { return static_cast<T&>(*this); } //�ٿ�ĳ����..?
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

//���� STL�� ���� ����ȭ�� ���� �켱�� �ǹǷ�..
//virtual function ����� ���Ѵ�..

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