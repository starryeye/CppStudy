class Point
{
	int x = 0; //C++11 ���� ������ �ʱ�ȭ ����
	int y = 0;
public:
	Point() {}
	Point(int a) : x(a) {}
	Point(int a, int b) : x(a), y(b) {}
};
//�� �ڵ�� �����Ϸ��� �Ʒ�ó�� �����Ѵ�.
class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int a) : x(a), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};