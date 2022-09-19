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
	auto end() { return range.begin() + count; } // <- �ٽ�
};

template<typename T>
class reverse_view
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	auto begin() { return range.rbegin(); }
	auto end() { return range.rend(); } // <- �ٽ�
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3); //C++17 ���ʹ� Ŭ���� template Ÿ�� ���� ���� ����

	for (auto e : v) //���� : ���������� v.begin(), v.end() �� ���
	{
		std::cout << e << ", ";
	}

	std::cout << "------------" << std::endl;
		
	for(auto e : tv)
	{
		std::cout << e << ", ";
	}

	std::cout << "------------" << std::endl;

	for (auto e : take_view(v, 3)) // �ӽ� ��ü�� ����
	{
		std::cout << e << ", ";
	}

	std::cout << "------------" << std::endl;

	for (auto e : reverse_view(v)) // �ӽ� ��ü�� ����
	{
		std::cout << e << ", ";
	}
}