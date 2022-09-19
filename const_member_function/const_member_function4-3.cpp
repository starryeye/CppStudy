#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// 1. non-const 버전은 함수 호출을 lvalue 가 되게 해야한다.
	// -> reference 반환
	T& operator[](int idx) { return buff[idx]; }
	
	// 2. const 버전은 함수 호출을 등호의 왼쪽에 올수 없게 해야한다.
	// 방법 1. value 반환
	// -> temporary(rvalue)를 반환
	// -> 주소 연산자를 사용 할 수 없기 때문에 "&v2[0]" 같은 코드를 사용못함.
	// -> 임시객체는 lvalue reference로 주소를 못구한다.
	//T operator[](int idx) const { return buff[idx]; } //const 잘못된 방법
	
	// 방법 2. const reference 반환
	// -> lvalue 반환, "&v2[0]" 사용 가능
	// -> 단, const reference 이므로 등호 왼쪽에는 올수 없다. "v2[0] = 10" error
	const T& operator[](int idx) const { return buff[idx]; } //const
};

int main()
{
	int n;
	vector<int> v1(10);
	const vector<int> v2(10);

	//				//의도한 것		//현재 동작
	v1[0] = 10;		//ok			//ok
	n = v1[0];		//ok			//ok

	v2[0] = 10;		//error			//error
	n = v2[0];		//ok			//ok

	auto p = &v2[0]; // 되어야 한다.
						//상수 vector의 첫번째 요소의 주소 구하기
						//따라서, [] 의 const 버전의 반환 값은
						//lvalue이어야 한다.
						//단, 등호의 왼쪽에는 올 수 없어야 하므로
						//"const lvalue"
}