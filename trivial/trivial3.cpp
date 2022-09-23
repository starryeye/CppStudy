#include <iostream>
#include <type_traits>

// SL.con.4: don��t use memset or memcpy for arguments that are 
//           not "trivially-copyable"

struct Point
{
	int x, y;

	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

	//����ڰ� ���� �����ڸ� ���� �����ϸ�,
	// ��������ڴ� trivial ���� �ʰ� �ȴ�.
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}
	Point(const Point& pt) = default; //�����Ϸ����� ��û(trivial)
};

template<typename T> 
void copy(T* dst, T* src, std::size_t size)
{
	if (std::is_trivially_copy_constructible_v<T>)
	{//trivial�ϰ� �����Ҽ� �ִ� Ÿ���̶��.. memcpy
		std::cout << "memcpy�� ����" << std::endl;

		memcpy(dst, src, sizeof(T) * size); //�׳� �������� ����.
	}
	else
	{
		std::cout << "��������ڰ� trivial ���� ����" << std::endl;
		std::cout << "��� ��Ҹ� ��������ڷ� ����" << std::endl;

		while (size--)
		{
			//���� ���縦 ����.
			new(dst) T(*src); //���� ������ ȣ�� (���� �н�)
			++dst, ++src;
		}
	}
	
}

int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];

	copy(pt2, pt1, 5);

}

//���� STL������ ���� ���� ������ ��ģ��..
//vector���� .. trivial���� ���θ� üũ�ϰ� �����ϰ� ��..