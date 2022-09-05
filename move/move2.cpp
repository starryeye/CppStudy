#include <iostream>

struct Point
{
	int x;
	int y;
};

//�Լ� �����ε� ��Ģ - �� ����� ��.
//�Ʒ� error�ƴ�.. 3�� �����ε� �����ϴ�.
//lvalue reference
//const lvalue reference
//rvalue reference
void foo(Point& pt) { std::cout << "Point&" << std::endl; } //1���Լ�
void foo(const Point& pt) { std::cout << "const Point&" << std::endl; }//2���Լ�
void foo(Point&& pt) { std::cout << "Point&&" << std::endl; }//3���Լ�

//�Ʒ��ڵ嵵 �����ϴ�.. ������ ������� �ʴ´�.
void foo(const Point&& pt) { std::cout << "const Point&&" << std::endl; }//4���Լ�

int main()
{
	Point pt;
	foo(pt);		//pt�� lvalue�̴�.
					//1�� ȣ��, ������ 2��ȣ�� (����� �ƴϹǷ�..) ->�켱����

	foo(Point());	//�ӽð�ü�̹Ƿ� rvalue�̴�.
					//3�� ȣ��, ������ 2��ȣ�� (����� �ƴϹǷ�..) ->�켱����

	foo(static_cast<const Point&&>(Point())); // 4�� ȣ��

	//���
	//lvalue, rvalue �� �Ѱ��� �Լ����� ��� �޾Ƽ� ó���ϰ� �ʹ�.
	// -> const lvalue reference ���.
}