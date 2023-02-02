// C.100: Follow the STL when defining a container
// => Generic container idioms

#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz) : size(sz), capacity(sz)
	{
//		buff = new T; //�̷��� �����ϸ� T�� �ݵ�� ����Ʈ �����ڰ� �־�� �Ѵ�.
		
		//�׷��� ���� STL�� �Ʒ�ó�� ���� �Ǿ� �ִ�.
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) Point; //��.. ����Ʈ �����ڰ� �ʿ�..
		}
	}

	//����Ʈ ������ �ʿ����..
	vector(int sz, const T& obj) : size(sz), capacity(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) Point(obj); //���� ������ �ʿ�
		}
	}
	~vector()
	{
		for (int i = 0; i < 10; i++)
		{
			buff[i].~T();
		}
		operator delete(buff);
	}
	//����.. ���� STL ���δ� ���ʹ� �ٸ��� allocator ��� ���� ����Ѵ�.
	//�׷��� �޸� �Ҵ�� ������ ȣ���� �и��ϴ� ������ ���� ���� �ϴ�.
};

int main()
{
	Point pt(0, 0);
	vector<Point> v(10, pt); //pt�� ����ؼ� 10���� �ʱ�ȭ �ش޶�..
							//��, ���� ������ ����� �޶�..

}

//���� : smkang@codenuri.co.kr