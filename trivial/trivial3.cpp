#include <iostream>
#include <type_traits>

// SL.con.4: don’t use memset or memcpy for arguments that are 
//           not "trivially-copyable"

struct Point
{
	int x, y;

	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

	//사용자가 복사 생성자를 직접 구현하면,
	// 복사생성자는 trivial 하지 않게 된다.
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}
	Point(const Point& pt) = default; //컴파일러에게 요청(trivial)
};

template<typename T> 
void copy(T* dst, T* src, std::size_t size)
{
	if (std::is_trivially_copy_constructible_v<T>)
	{//trivial하게 복사할수 있는 타입이라면.. memcpy
		std::cout << "memcpy로 복사" << std::endl;

		memcpy(dst, src, sizeof(T) * size); //그냥 얕은복사 때림.
	}
	else
	{
		std::cout << "복사생성자가 trivial 하지 않음" << std::endl;
		std::cout << "모든 요소를 복사생성자로 복사" << std::endl;

		while (size--)
		{
			//깊은 복사를 위함.
			new(dst) T(*src); //복사 생성자 호출 (내일 학습)
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

//참고 STL에서도 위와 같은 과정을 거친다..
//vector에서 .. trivial한지 여부를 체크하고 복사하고 함..