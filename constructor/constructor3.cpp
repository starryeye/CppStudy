#include <iostream>

// C.47: Define and initialize member variables in the order of member declaration

// 아래 클래스는 어떤 문제가 있을까요 ?
struct vector
{
	int* buff;
	int size;
public:
	// 맴버 초기화 리스트는 "코드의 순서"가 아닌
	// 정해진 순서에 따라 초기화 된다.
	// 1. 기반 클래스 생성자 먼저 호출
	// 2. 맴버 데이터 초기화.
	// -> 순서는 맴버가 선언된 순서대로..
//	vector(int sz) : size(sz), buff(new int[size]) // buff가 먼저 수행
													//size가 초기화 되기 전에 쓰레기값인 size로 buff 할당이 이루어지고있다.. 
	vector(int sz) : buff(new int[size]), size(sz) //-> good
	{												
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector v(10);
}