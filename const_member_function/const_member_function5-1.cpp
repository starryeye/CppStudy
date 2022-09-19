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

//������..
//��� ���ø��� empty, size, ���� ��� ������ֱ�� �����..
//c++20���� �̷��� �� ���� ���ø��� ���ʰ����̴�..
//C++ ǥ�ؿ��� ��� �ϴ��� �˾ƺ���..
//5-2..

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3);
	reverse_view rv(v);

	bool b1 = tv.empty();
	bool b2 = rv.empty();


}