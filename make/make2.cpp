#include <iostream>
#include <tuple>
#include <vector>

int main()
{
	std::pair<int, double> p1(3, 3.4); //C++98
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4); //C++11

	auto t2 = std::make_tuple(3, 3.4, 3, 3.4); //t1�� ����
	auto p2 = std::make_pair(3, 3.4); //p1�� ����

	//�׷���.. C++17 ���ʹ� �׳� �Ʒ�ó�� �ϸ��.
	std::tuple t3(3, 3.4, 3, 3.4);


	std::vector<int> v1 = { 1,2,3 };
	std::vector v2 = { 1,2,3 }; //C++17
}