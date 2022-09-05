// F.43: Never(directly or indirectly) return a pointer or a reference to a local object
// F.44 : Return a T & when copy is undesirable and "returning no object" isn't needed

//--------------------------------
// Temporary(임시객체) 의 특징
// 함수 반환
//--------------------------------

int x = 10;

//primitive type에서도 .... 그러하다..
int f1() { return x; }	//x가 아닌 x의 값(10)을 반환한다.
int& f2() { return x; } //x의 별명을 반환

int main()
{
	int ret = f1();

	f1() = 20; //error, 10 = 20과 동일함.
	f2() = 20; //ok, x=20의 의미이다.

	//결국. 함수가 참조를 반환하면....
	//1. 임시객체가 생성되지 않는다.
	//2. 함수 호출을 등호의 왼쪽에 놓을 수 있다.(lvalue가 될 수 있다는 말이다.)
}