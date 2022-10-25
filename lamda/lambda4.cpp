// T.141: Use an unnamed lambda 
//		  if you need a simple function object in one place only

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,2,4,6 };

	//������ ���� ǥ������ ������ ����Ѵٸ�
	//�Ʒ� ó������ ����..
	//��� �ٸ� ����Ÿ���̹Ƿ�..
	//�Ʒ� �ڵ�� �ᱹ 3���� sort() �Լ��� �����ȴ�..
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	//�ذ�
	auto cmp = [](int a, int b) { return a < b; };
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
}