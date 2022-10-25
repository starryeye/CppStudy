#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

//������(predicator) : bool�� ��ȯ�ϴ� �Լ�
//���� ������ : ���ڰ� �Ѱ��� ������
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	//�־��� �������� ù��°�� ������ "3" ã��
	auto ret1 = std::find(v.begin(), v.end(), 3);

	//�־��� �������� ù��°�� ������ "3�� ���" ã��
	// std::find	: �� �˻�
	// std::find_if	: ���� �˻�, 3��° ���ڷ� ���� �Լ� ����
	auto ret2 = std::find_if(v.begin(), v.end(), foo);
	std::cout << *ret2 << std::endl; //6


	int k;
	std::cin >> k;

	// �־��� �������� ù��°�� ������ k�� ����� ã�� �ʹ�.
	auto ret3 = std::find_if(v.begin(), v.end(), "�����Լ� + ��������k");
}

//�ϱ� ��ü(first class object)
// -> �Լ� ���ڷ� ���ް����� ��ü
// -> C/C++ ������ "�Լ�"�� �ϱް�ü �̴�.(�Լ��� �ٸ� �Լ��� ���ڷ� ���ް����ϴٴ� ��)
//find_if�� foo�� ����

//Ŭ����(Closure)
// -> ���ƿ� ���Ե� ���������� ĸ���� �� �ִ� "�ϱް�ü"
// -> ��, �Լ� ���ڷ� "�Լ� + ��������"�� ���� ������ �� �ִ� ���� "Closure" ��� �Ѵ�.

// �Ϲ� �Լ� : �ϱ� ��ü ������ Ŭ������ �ƴϴ�..
// �Լ� ��ü : �ϱ� ��ü �̰� Ŭ���� �̴�.