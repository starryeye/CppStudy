// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const

// ���ڰ��� �б⸸ �Ϸ��� �Ѵ�.
// ������ ���� �ڵ�� ?
void f1(int n) { int a = n; } //good
void f2(const int& n) { int a = n; } //bad
				//int* p		int a = *p;
				//������ �ᱹ ������ó�� �ּҸ� �����ߴٰ� �����ϴ� �����̴�.

//��� f2�� ����� �ڵ�ܿ��� ���ڸ�.. ������ ������ �����ȴ�.


int main()
{
	int x = 10;
	f1(x);
	f2(x);
}