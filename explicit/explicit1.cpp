// C46.인자가 한개인 생성자는 explicit 로 하는 것이 좋다.

class Vector
{
public:
	//explicit 생성자 : 직접 초기화만 가능하고 복사초기화는 사용할 수 없다.
	//인자가 한개인 생성자는 "explicit"로 설계하는 것이 항상 안전하다.
	explicit Vector(int sz) {}
};

void fn(Vector v) {}

int main()
{
	//핵심 1. 생성자로 int 한개를 받으면 아래처럼 4가지 형태로 객체 생성이 가능
	Vector v1(10);		//direct initialization : "="이 없는 것
	Vector v2 = 10;		//direct initialization : "="이 있는 것
	Vector v3{ 10 };	//C++11, direct
	Vector v4 = { 10 }; //C++11, copy

	//핵심 2. 함수의 인자 전달은 "복사 초기화" 이다.
	fn(10); // -> fn에 인자는..
			// Vector v = 10 의 원리로 전달됨.
			//Vector를 줘야하는데.. 10을 줘도 되는건..
			//의도하지 않은 코드일 경우가 많다..
			//-> explicit 키워드 추가하자..
}