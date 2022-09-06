//C.80 : Use  = default if you have to be explicit about using the default semantics
//C.81 : Use  = delete when you want to disable default behavior(without wanting an alternative)

#include <iostream>
#include <string>

//계열 : 생성자, 대입 연산자

// 규칙1. 사용자가 복사 계열, move 계열 함수를 모두 만들지 않으면
// -> 컴파일러가 모두 제공
// -> 컴파일러 제공 copy 계열은 모든 맴버를 copy
// -> 컴파일러 제공 move 계열은 모든 맴버를 move
/*
class Object
{
public:
	std::string name;
	Object(const std::string& n) : name(n) {}

};
*/

// 규칙2. 사용자가 복사 계열만 제공한 경우..
// -> 컴파일러는 디폴트 move 계열 함수를 자동생성하지 않는다.
// -> std::move() 사용시 "사용자가 만든 복사 계열" 함수 사용

// -> 복사 생성자를 만들었지만, move 생성자를 컴파일러에게 요청하려면
// "=default" 를 사용해라..
/*
class Object
{
public:
	std::string name;
	Object(const std::string& n) : name(n) {}

	Object(const Object& obj)
		: name(obj.name) { std::cout << "copy" << std::endl; }

	//복사를 만들었지만, move는 컴파일러에게 요청하려면 "=default" 사용하면됨
	//Object(Object&&) = default;

	//move 생성자만 요청하지 말고, 대입연산자도 요청할땐..
	//Object& operator=(const Object&) = default;
	//Object& operator=(Object&&) = default;

};
*/

//규칙 3. 사용자가 move 계열 함수만 제공하면
// -> 복사 계열 함수는 모두 삭제 "=delete" 된다.
// -> 복사 계열이 필요한 모든 곳에서 컴파일 에러.
// -> 복사 계열을 제공받으려면 "=default" 사용

// -> move 생성자를 만들었지만, 복사 생성자를 컴파일러에게 요청하려면
// "=default" 를 사용해라..
class Object
{
public:
	std::string name;
	Object(const std::string& n) : name(n) {}

	Object(Object&& obj) : name(std::move(obj.name)) {} //아래 main에서 error남.

};

//참고..
//소멸자만 사용자가 제공하면
//-> 컴파일러가 복사생성자는 제공하지만, move 생성자는 제공하지 않는다.
//-> 결론.. 아무것도 안만들면 최고의 클래스이다..

int main()
{
	Object obj1("obj1");
	Object obj2("obj2");
	Object obj3 = obj1;				//copy
	Object obj4 = std::move(obj2);	//move
	
	std::cout << obj1.name << std::endl;
	std::cout << obj2.name << std::endl;
}