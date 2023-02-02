#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� �����ϴ�.
//	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point ��ü�� ���� �Ѱ��� ����� ������
	Point* p1 = new Point(1, 2);

	// Point ��ü�� ���� 10�� ����� ������ (�޸𸮰� ��������..)
//	Point* p2 = new Point[10]; // ����Ʈ �����ڸ� 10�� ȣ���ϴ� ǥ���
								//�׷���, ����Ʈ �����ڰ� ����..
	
	//�޸� �Ҵ�� ������ ȣ���� �и��ϸ� ���� �����ϰ� �ڵ� �� �� �ִ�.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10)); //10���� �޸� �Ҵ�

	//10���� �޸� ������ 10���� ��ü�� ����(�����ڸ� ȣ���Ѵٴ� �ǹ�)
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0); //std::construct_at(&p2[i], 0, 0);
	}

	//.....
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point(); //std::destroy_at(&p2[i]);
	}

	operator delete(p2);
	
}