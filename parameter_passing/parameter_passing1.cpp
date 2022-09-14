// F16 ~ F20  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters

#include <iostream>
#include <string>

struct Rect
{
	int left, top, right, bottom;
};

// call by value�� ����.
// 1. ���纻 ������ �޸�(����) ����
// 2. ���� ������ ȣ�� <--- std::string ���� ���.. �̺κп��� 
//							������尡 ũ��.(���� �����ڿ��� �޸� ���� ����)
// 3. �Ҹ��� ȣ��

void f1(Rect rc) 
{
}
void f2(std::string s2) 
{
}

// call by non-cost reference
// -> ���ڰ��� �����Ҷ��� ���
// -> ���ڸ� �������� ������ �� const �ٿ����Ѵ�.(temporory ���� �����ϵ���)
void f3(Rect& rc) {}

void f4(const Rect& rc) {} // temporary(rvalue)�� ����������.


int main()
{
	Rect rc;
	f1(rc);

	f3(rc); //ok
	f3(Rect()); // error.. (temporary �Ұ���)
	f4(Rect()); //ok

	std::string s1 = "to be or not to be";
	f2(s1);
}
