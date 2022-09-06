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
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }
};
int main()
{
	Cat c1("nabi", 2);


	Cat c2 = c1; //얘때메 runtime에 죽는다.
				 //얕은 복사 현상 발생( 컴파일러가 제공하는 얕은복사 생성자를 사용하기때문에..)
				 //반드시 개발자는 복사 생성자를 제공해야한다. (깊은 복사 생성해야함)
				
}