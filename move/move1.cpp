struct Point
{
	int x;
	int y;
};

int main()
{
	Point pt;

	//& �� ���� reference ��� �ҷ�����.. �߸��� �θ��̴�.
	//lvalue reference�� �ҷ�����.
	//&& �� rvalue reference�� �Ҹ���.

	// ��Ģ 1. non const lvalue reference�δ� lvalue�� ����ų�� �ִ�.
	Point& r1 = pt;			//ok
	Point& r2 = Point();	//error, �ӽð�ü (rvalue)�� �ȵ�.

	// ��Ģ 2. const lvalue reference�δ� lvalue, rvalue ��� ����ų�� �ִ�.
	const Point& r3 = pt;		//ok
	const Point& r4 = Point();	//ok

	//��Ģ 1, 2 ������ C++98
	//==========================C++98=====================


	//==========================C++11=====================

	//C++ 11������ "����� ���� �ӽð�ü�� ����Ű�� ��" �� �ʿ� �ߴ�..

	// ��Ģ 3. C++11���� ���� "rvalue reference"�� rvalue�� ����ŵ�ϴ�.
	Point&& r5 = pt;		//error
	Point&& r6 = Point();	//ok, �ӽð�ü�� ����ų�� �ִ�. 


	//����. const rvalue reference�� rvalue�� ����Ű�µ�..
	//���� ������� �ʴ´�.
	//&& �� move ������ �ַ� ����ϴµ�, const�� move�� �� ����.
	const Point&& r7 = pt;		//error
	const Point&& r8 = Point();	//ok, �ӽð�ü�� ����ų�� �ִ�. 
}