#include <memory>

class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	
	//explicit 없는 버전
//	Point() = default;
//	Point(int x, int y) : x{ x }, y{ y } {}

	//인자가 없거나 여러개라도 explicit 사용가능하다.
	explicit Point() = default;
	explicit Point(int x, int y) : x{ x }, y{ y } {}
};
void fn(Point pt) {} 

int main()
{
	// 인자가 없거나 2개 짜리도 아래처럼 객체 생성가능
	Point p1;
	Point p2 = {};

	Point p3(1, 2);
	Point p4{ 1, 2 };
	Point p5 = { 1,2 };

	// 생성자가 explicit 가 아니면 아래 표현식도 가능
	fn({});
	fn({ 1,2 });


	//STL 스마트 포인터 사용시
	std::shared_ptr<int> sp1(new int); //ok
	std::shared_ptr<int> sp2 = new int; //error
						// -> 결국, shared_ptr 의 생성자는 explicit 라는 의미.
}


