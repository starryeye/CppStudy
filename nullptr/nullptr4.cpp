// nullptr 의 원리

void f1(int*  p) {}
void f2(char* p) {}

// nullptr을 직접 만들어보자.. 
struct mynullptr_t
{
	//mynullptr_t 타입 -> int* 로 변환되기 위한 변환 연산자 함수
//	operator int* () const { return 0; }
//	operator char*() const { return 0; }

	//모든 포인터 타입으로 변환가능해야 한다.
	template<typename T>
	constexpr operator T* () const { return 0; } //컴파일타임에 해줘라는 키워드 : constexpr
};

mynullptr_t mynullptr; //mynullptr이 nullptr이다..

int main()
{
	f1(mynullptr);	// mynullptr -> int* 로의 암시적 형변환이 필요
					// "mynullptr.operator int*()" 라는 맴버함수를 찾게된다.
	f2(mynullptr);
}

//nullptr 의 역사
// 1. boost 라이브러리(boost.org)에서 위처럼 만들어서 사용했던 것을
// 2. C++11 을 만들면서, "nullptr"이 객체가 아닌 "키워드"로 도입된 것.