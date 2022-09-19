//��� �ɹ� �Լ���
//������ �ƴ� �ʼ� �����̴�.

// "��ü�� ���¸� �������� �ʴ� ��� �ɹ��Լ��� �ݵ�� ��� �ɹ� �Լ��� ������ �Ѵ�."

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; } //const Ȯ��2
};

//void foo(Rect r)	// user type�� call by value�� �޴� ���� ���� �ʴ�.
void foo(const Rect& r) //const Ȯ��1
{
	int n = r.getArea(); 
}

int main()
{
	Rect r(1, 2, 3, 4);	//��� ��ü �ƴϴ�.
	int n = r.getArea();
	foo(r);
}