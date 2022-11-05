#include <memory>

class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	
	//explicit ���� ����
//	Point() = default;
//	Point(int x, int y) : x{ x }, y{ y } {}

	//���ڰ� ���ų� �������� explicit ��밡���ϴ�.
	explicit Point() = default;
	explicit Point(int x, int y) : x{ x }, y{ y } {}
};
void fn(Point pt) {} 

int main()
{
	// ���ڰ� ���ų� 2�� ¥���� �Ʒ�ó�� ��ü ��������
	Point p1;
	Point p2 = {};

	Point p3(1, 2);
	Point p4{ 1, 2 };
	Point p5 = { 1,2 };

	// �����ڰ� explicit �� �ƴϸ� �Ʒ� ǥ���ĵ� ����
	fn({});
	fn({ 1,2 });


	//STL ����Ʈ ������ ����
	std::shared_ptr<int> sp1(new int); //ok
	std::shared_ptr<int> sp2 = new int; //error
						// -> �ᱹ, shared_ptr �� �����ڴ� explicit ��� �ǹ�.
}


