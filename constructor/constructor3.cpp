#include <iostream>

// C.47: Define and initialize member variables in the order of member declaration

// �Ʒ� Ŭ������ � ������ ������� ?
struct vector
{
	int* buff;
	int size;
public:
	// �ɹ� �ʱ�ȭ ����Ʈ�� "�ڵ��� ����"�� �ƴ�
	// ������ ������ ���� �ʱ�ȭ �ȴ�.
	// 1. ��� Ŭ���� ������ ���� ȣ��
	// 2. �ɹ� ������ �ʱ�ȭ.
	// -> ������ �ɹ��� ����� �������..
//	vector(int sz) : size(sz), buff(new int[size]) // buff�� ���� ����
													//size�� �ʱ�ȭ �Ǳ� ���� �����Ⱚ�� size�� buff �Ҵ��� �̷�������ִ�.. 
	vector(int sz) : buff(new int[size]), size(sz) //-> good
	{												
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector v(10);
}