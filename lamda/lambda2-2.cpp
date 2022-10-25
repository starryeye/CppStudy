#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)


int main()
{
//	int add(int a, int b) {} //error �Լ� �ȿ� �Լ� �ȵȴ�.
								//�׷��� �Լ� �ȿ� Ŭ����(�Լ���ü) �ȴ�.
								//�������� ĸ�� �ɷ��� �������� �Լ��ȿ� �Լ��� ���� �� �־�� �Ѵ�.

	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };


	int k = 3;


	auto ret = std::find_if(v.begin(), v.end(), [k](int n) {return n % k == 0; });

	//���� ǥ������ ����.
	//�� �ڵ带 ���� �����Ϸ��� �Ʒ� �ڵ带 �����Ѵ�..
	class CompilerGeneratedName
	{
		int k; //���� ǥ������ ĸ���� ���� ���� ������ �ɹ� ������
	public:
		CompilerGeneratedName(int n) : k(n) {}

		bool operator()(int n) const
		{
			return n % k == 0;
		}
	};
	//�׸���, ����ǥ������ �ִ� ��ġ�� �����Ϸ��� ���� Ŭ������ �ӽð�ü�� �����ϴ� �ڵ�� ����
	auto ret2 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k));
}
