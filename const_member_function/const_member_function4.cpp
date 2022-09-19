#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] 연산자 재정의 : 객체를 배열 처럼 사용 가능하게 할때 필요
	// -> 대부분 참조를 반환하게 된다.
	// -> "v[0] = 10" 처럼 함수 호출을 lvalue 가 될수 있게 하기 위해
	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	vector<int> v(10);
	v[0] = 0; 
	int a = v[0];
}