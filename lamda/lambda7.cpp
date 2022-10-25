// conversion function pointer

int main()
{
	int k = 0;

	//핵심 1. 람다 표현식은 함수 포인터로 변환 가능하다.
	int(*f1)(int, int) = [](int a, int b) { return a + b; };

	//핵심 2. 그러나.. 캡쳐한 람다 표현식은 함수 포인터 변환은 안된다.
	int(*f2)(int, int) = [k](int a, int b) { return a + b + k; }; //error
}