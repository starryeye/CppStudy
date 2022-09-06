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

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		std::cout << "copy 생성자" << std::endl;
	}

	Cat(Cat&& c)
		: name(c.name), age(c.age)
	{
		c.name = nullptr;

		std::cout << "move 생성자" << std::endl;
	}
};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	//c1은 lvalue, 복사 생성자 호출

	Cat c3 = foo();	//temporary, rvalue, move 생성자 호출

	Cat c4 = static_cast<Cat&&>(c2);	//move 생성자 호출, 더이상 c2는 안쓸거다라는 의도가 포함
										//이름있는 lvalue라더라도.. move하고 싶다면..

	Cat c5 = std::move(c3); //위와 같은 캐스팅(static_cast<Cat&&>)을 수행한다.


	//결론
	//1. std::move() 자체가 객체의 자원을 이동하는 것은 아니다.
	//2. 단지, 객체를 rvalue 로 캐스팅하는 것이다.
	//3. 캐스팅의 결과로 move 생성자 호출.
	//4. 결국, 자원을 이동하는 것은 클래스 안에 있는 move 생성자가 한다.

	//참고
	//어떤 객체에 std::move() 했는데, 해당 타입에 move 생성자가 없다면..
	//-> 그냥 복사 생성자를 사용하게 된다.(const Cat& c)
	//-> 즉, 성능향상은 없지만, 에러는 아니다.


}