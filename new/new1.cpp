#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	//1. sizeof(Point) ũ���� �޸� �Ҵ�
	//2. ������ ȣ��
//	Point* p1 = new Point(1, 2);

	//1. �Ҹ��� ȣ��
	//2. �޸� ����
//	delete p1;


	//------------------------
	//1.�޸𸮸� �Ҵ�
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));

	//2. �����ڸ� ȣ��
	new(p2) Point(1, 2); // �̹� �Ҵ�� p2 �޸𸮿� ���� ������ ȣ��
							// placement new ��� �θ��� ���
//	std::construct_at(p2, 1, 2); //C++20 ���� ����

	//3. �Ҹ��ڸ� ȣ��
	p2->~Point(); //C++17 ����
//	std::destroy_at(p2); //C++17 ���� ����

	//4. �޸𸮸� ����
	operator delete(p2);

}