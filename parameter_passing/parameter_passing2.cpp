// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const

// 인자값을 읽기만 하려고 한다.
// 다음중 좋은 코드는 ?
void f1(int n) { int a = n; } //good
void f2(const int& n) { int a = n; } //bad
				//int* p		int a = *p;
				//참조는 결국 포인터처럼 주소를 보관했다가 접근하는 원리이다.

//사실 f2는 어셈블리 코드단에서 보자면.. 포인터 변수가 생성된다.


int main()
{
	int x = 10;
	f1(x);
	f2(x);
}