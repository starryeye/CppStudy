// C.100: Follow the STL when defining a container
// => Generic container idioms

#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point 는 디폴트 생성자가 없습니다.
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
//		buff = new T; //이렇게 설계하면 T는 반드시 디폴트 생성자가 있어야 한다.
		
		//그래서 실제 STL은 아래처럼 설계 되어 있다.
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) Point; //또.. 디폴트 생성자가 필요..
		}
	}

	//디폴트 생성자 필요없음..
	vector(int sz, const T& obj) : size(sz), capacity(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) Point(obj); //복사 생성자 필요
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
	//참고.. 실제 STL 내부는 위와는 다르게 allocator 라는 것을 사용한다.
	//그런데 메모리 할당과 생성자 호출을 분리하는 개념은 위와 동일 하다.
};

int main()
{
	Point pt(0, 0);
	vector<Point> v(10, pt); //pt를 사용해서 10개를 초기화 해달라..
							//즉, 복사 생성자 사용해 달라..

}

//질문 : smkang@codenuri.co.kr