//상수 맴버 함수는
//선택이 아닌 필수 문법이다.

// "객체의 상태를 변경하지 않는 모든 맴버함수는 반드시 상수 맴버 함수로 만들어야 한다."

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; } //const 확정2
};

//void foo(Rect r)	// user type을 call by value로 받는 것은 좋지 않다.
void foo(const Rect& r) //const 확정1
{
	int n = r.getArea(); 
}

int main()
{
	Rect r(1, 2, 3, 4);	//상수 객체 아니다.
	int n = r.getArea();
	foo(r);
}