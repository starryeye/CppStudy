#include <cstring>
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	//깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		// 포인터가 아닌 맴버는 그냥 복사
//		age = c.age; //->여기말고 위에 age(c.age)로 사용하는 편이 좋다.
					 //생성자 교육시간에 설명

		// 포인터는 메모리 자체를 복사
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
};
int main()
{
	Cat c1("nabi", 2);


	Cat c2 = c1; //깊은 복사 할당 연산자가 사용된다.

}