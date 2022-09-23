// F.19: For “forward” parameters, pass by TP&& and only std::forward the parameter

template<typename T> void foo(T a)
{
	T& r = a; //T의 타입은 int& 이므로.. 
				//최종적으로 int& &r = a;
				//reference collapsing 규칙에 의하여..
				//int& r = a; 가 된다.
}


int main()
{
	int n = 10;

	int&  r1 = n ; //lvalue reference (이름 있는 객체)
	int&& r2 = 10 ; //rvalue reference (이름 없는 객체, literal)

	int* *p; // 포인터의 포인터는 만들수 있다.
			//나 포인터인데(*p) 따라가면 포인터(int*)있어
//	int& &r3 = ?; //레퍼런스의 레퍼런스는 만들수 없다. error 

	//핵심 : 레퍼런스의 레퍼런스를 직접 코딩으로 만들수 없지만
	//		타입추론과정에서 발생하는 레퍼런스 충돌은
	//		reference collapsing 규칙이 적용된다.
	//		아래와 같이 가능함..

	//LREF : lvalue reference
	//RREF : rvalue reference

	using LREF = int&; // typedef int& LREF;
	using RREF = int&&;

	LREF r4 = n;
	RREF r5 = 10;

	// reference collapsing 규칙
	LREF& r6 = n;	// int& &	=> int&
	RREF& r7 = n;	// int&& &	=> int&
	LREF&& r8 = n;	// int& &&  => int&
	RREF&& r9 = 10;	// int&& && => int&&
					//양쪽모두 두개일 경우 두개

	foo<int&>(n); //foo 안에서 r의 타입을 생각해보자..
}





