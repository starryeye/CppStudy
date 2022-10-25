#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

bool foo(int n) { return n % 3 == 0; }

struct IsDivide
{
	int value; // <-- �ٽ�, main �Լ� �ȿ� �ִ� ���� ���� k�� ���� ����(ĸ��)

	IsDivide(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };


	int k = 3;

	IsDivide f(k);
	bool b = f(10); // f�� ���� �Լ�(��ü)�̴�.
					// �ᱹ "10 % k == 0" �̹Ƿ� false
					// ��, "k �� ���� ĸ��"�� �����Լ�

//	auto ret1 = std::find_if(v.begin(), v.end(), f); //f�� k���� ĸ���� Ŭ�����̴�.
	
	//�ѹ��� ����Ѵٸ�, �Ʒ�ó�� �ӽð�ü ���·� ������ �ȴ�.
	auto ret1 = std::find_if(v.begin(), v.end(), IsDivide(k));

	//IsDivide(k) : k ���� ĸ���� �����Լ�(��ü),
	//					��, Closure �̴�.

	std::cout << *ret1 << std::endl;
}
