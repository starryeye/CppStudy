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

	//lvalue, rvalue 모두 받을 수 있다.
	//깊은 복사, copy 생성자, 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		std::cout << "copy 생성자" << std::endl;
	}

	//임시객체로 인자를 넘기면 copy생성자도 가능하지만.. 우선순위로 인해 아래가 불림.
	//임시객체(rvalue)인 경우를 위한
	//복사 생성자를 추가로 제공
	//move 생성자, 이동 할당 생성자.
	Cat(Cat&& c) 
		: name(c.name), age(c.age)  //모든 맴버를 얕은 복사후
									//(포인터이더라도, 메모리 주소를 그대로 복사)
	{
		//임시객체가 파괴될때 자원을 삭제하지 못하도록
		//자원 포인터를 null reset
		//이 작업을 하려면 임시객체라도 상수성 없이 가리킬수 있어야한다.
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


	Cat c2 = c1; //c1은 lvalue, copy 생성자 호출

	Cat c3 = foo(); //foo()의 리턴은 임시객체이다.
					//임시객체와 c3 객체간의 깊은 복사가 이루어진다.
					//임시객체는 어차피 문장끝날때.. 파괴된다.
					//-> 힙메모리가 어차피 파괴 될거.. 굳이.. 깊은 복사가 필요할까? 힙메모리를 또만드는게.. 성능저하이다.
					//Cat(Cat&& c) 를 만들어 놓으면.. 불필요한 힙메모리 깊은복사가 이루어지지 않는다.
					//-> move 생성자 호출
					

}