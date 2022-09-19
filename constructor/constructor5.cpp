#include <iostream>

class Point
{
	int x, y;
public:
	//Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};
//Point p; //error. Point �� ����Ʈ �����ڰ� ����..

class Rect
{
	Point ptFrom;
	Point ptTo;
public:
				//�����Ϸ��� ������ �ڵ�
//	Rect() {}	//Rect() : ptFrom(), ptTo()

	//�ٽ� : �ɹ������Ͱ� ����Ʈ �����ڰ� ���� Ÿ���̸� �ݵ��
	//		����ڰ� ��������� �����ڸ� ȣ���ϴ� �ڵ带 �����ؾ� �Ѵ�.

	// ���1. �ɹ� �ʱ�ȭ ����Ʈ���� ȣ��
	Rect() : ptFrom(0, 0), ptTo(0, 0) {} // ptTo{0,0} ó�� {}�� ����(����, ���� ����)

};

class Rect2
{
	//��� 2. C++ 11 ���ʹ� �ɹ������� ���鶧 ���� ���� ����
	Point ptFrom{ 0,0 };
	Point ptTo{ 0,0 };

//	Point ptTo(0, 0); //error, ���⼭�� {}�� �����ϴ�.
						//ptTo��� �Լ��� �ν��ع�������.
						//���� ���޿� �׳� 0�� �־���� ����
};

int main()
{
	Rect r;
}




