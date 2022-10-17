#include <iostream>

int main()
{
	// 1. 프로그램에서 사용되는 "값" 들을 리터럴(literal)이라고 합니다.
	// 2. 모든 리터럴은 타입이 있습니다.
	10;			//int
	3.4;		//double
	3.4f;		//float
	"hello";	//const char[6]

	true;		//"참"을 나타내는 리터럴이고, 약속된 단어(키워드)
				//bool
	nullptr;	//std::nullptr_t 라는 타입이다. 타입이름 기억

	// std::nullptr_t 타입은 "모든 종류의 포인터로 암시적 형변환된다"는
	// 문법이 있다.
	std::nullptr_t x = nullptr;

	// 이제 x를 nullptr 처럼 포인터 초기화에 사용가능하다.
	int* p1 = x;
	char* p2 = x;

}