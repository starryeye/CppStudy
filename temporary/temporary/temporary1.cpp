#include <iostream>

//--------------------------------
// Temporary(�ӽð�ü) ��?
//--------------------------------

class Point
{
public:
	int x, y;

	Point(int a, int b) { 
		std::cout << "Point()" << std::endl; 
	}
	~Point() {
		std::cout << "~Point()" << std::endl; 
	}
};
int main()
{
	Point pt(1, 2); //�̸� �ִ� ��ü (named object)
					//���� : �ڽ��� ������ ���� ����� �ı�.

	Point(1, 2);	//�̸� ���� ��ü (unnamed object)
					//���� : �ڽ��� ������ ������ ��
					//-> �ӽð�ü(temporary) �� �θ���.

	Point(1, 2), std::cout << "X" << std::endl; // C++������ �ĸ��� ���̰� ���� ������ ���� �� �ִ�. 
												//���� ����: ������ -> X -> �Ҹ���(X����� ���峡���� �Ҹ��� ȣ��)

	std::cout << "-------" << std::endl;
} //<-- pt �ı�

//C++ object lifetime.pdf "hurb shutter" ��� �ڷᵵ.. �����ϸ� ����, �Ҹ���