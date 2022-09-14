#include <iostream>
#include <vector>
#include <algorithm>

struct Rect
{
	int left, top, right, bottom;
};

// ��Ģ 1. �Լ��� ���� ���� �����ٸ�
// -> ��ȯ �� ���
Rect f() { }

// ��Ģ 2. ���޵� ���ڸ� �����Ѵٸ�
// -> ���� �Ǵ� ������
// -> ������ ���� ����
// -> �׷���, "no object, no argument"���� ����ϰ� ������ ������ ��밡��
void f1(Rect& r) {}
void f2(Rect* r = nullptr) {}

f1(0); // error, ������ �ݵ�� ��ȿ�� ��ü�� �����ؾ� �Ѵ�.
f2(nullptr); //ok, �����ʹ� 0 �Ǵ� nullptr ����.

// ��Ģ 3. ���޵� ���ڸ� �б⸸ �Ѵٸ�(in parameter)
// ���� ������ ����� ���� �� : call by balue    ex) foo(int n)
// -> int ���� primitive type,
// -> unique_ptr ���� ����Ʈ ������
// -> �ݺ���(iterator)

// ���� ������ ��� Ÿ�� : call by const reference
// -> ��κ��� user define type


// ���ڷ� �ݺ��ڸ� �������� �Ѵ�.
// 1,2,3 �� ���ڴ� ��� in parameter
template<typename IT, typename T>
IT find(IT first, IT last, const T& value) //�Ķ���� Ÿ���� ����..
{
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	std::find(v.begin(), v.end(), 3);
}
