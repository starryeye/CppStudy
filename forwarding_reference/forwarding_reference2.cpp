// forwarding_reference2 - ���� ���� �߿�!!

void f1(int&  r) {}
void f2(int&& r) {}

int n1 = 10;
f1(n1); //ok		n1�� lvalue
f1(10); //error		10�� rvalue

//�Լ� ���ڷ�
//int&	: int Ÿ���� lvalue�� �ްڴٴ� �ǹ� (lvalue reference �� �θ�)
//int&&	: int Ÿ���� rvalue�� �ްڴٴ� �ǹ� (rvalue reference �� �θ�)


//�Ʒ��� ���Ȳ�̶�.. T �ڿ� &�� �Ѱ��� �����Ƿ� &�� �Ͱ�
// T& : ������ Ÿ���� lvalue�� �ްڴٴ� �ǹ� (lvalue reference �� �θ�)
// T&& : ������ Ÿ���� lvalue, rvalue�� ��� ���� �� �ִ�. (universal reference �� �θ�)
//			"���� �� �ִ�"�� ���� "�ش� �Լ��� ����" �Ѵٴ� ��
//				������ �Լ��� "call by value" �� �ƴ� "call by reference"

// f4(n1) : T = int&, T&& = int& && => int&		�������Լ� : f4(int&)
// f4(n1) : T = int,  T&& = int&&				�������Լ� : f4(int&&)

// "universal reference" - effective-c++�� ���ڰ� ������ �̸�
// ������.. C++ ǥ������ȸ������ "forwarding reference" �� ������

template<typename T> void f3(T& a)
{
}

int main()
{
	int n1 = 10;

	//1. Ÿ�����ڸ� ��������� �������� �� ������ �Լ��� ���
	//�Ʒ����� ������ �Լ��� ��� lvalueŸ���̹Ƿ� rvalue�� ������ ����.
	f3<int>(n1);	// T=int		T&=int&		�������Լ� : f3(int& a)
	f3<int&>(n1);	// T=int&		T&=int& &	�������Լ� : f3(int& a)
	f3<int&&>(n1);	// T=int&&		T&=int&& &	�������Լ� : f3(int& a)

	//2. Ÿ�����ڸ� �����ϸ� "�Լ� ���ڸ� ����" Ÿ���� �����մϴ�.
	f3(10); // T�� int, int&, int&& �� � ������ �ص�, 10�� �޴� �Լ��� ����� ����.
			//������ ����
	f3(n1); // T�� int�� ����(������ int), ������ �Լ� f3(int&)
}

// �ᱹ �Ʒ� ���ø��� �ǹ̸� �ľ��ϴ� ���� �ٽ�.
//-> ��� Ÿ���� ��� ���¸� �� ���� �� �ְ�.. ��
template<typename T> void f4(T&& a)
{
}

int main()
{
	int n1 = 10;

	//1. Ÿ���� �����ϴ� ���
	f4<int>(10);	//T=int			T&&=int&&		�������Լ�:f4(int&& a)
	f4<int&>(n1);	//T=int&		T&&=int& &&		�������Լ�:f4(int& a)
	f4<int&&>(10);	//T=int&&		T&&=int&& &&	�������Լ�:f4(int&& a)

	//2. Ÿ���� �������� �ʴ� ���(T�� Ÿ���� ��� �����Ǵ����� �߿�
	f4(n1);	//1. "int n1" �̹Ƿ� "T=int" �� �����ϸ� "f4(int&&)" �̹Ƿ� ����
			//2. n1�� �������� "T=int&"�� ��������. "f4(int&)"
			//C++ǥ���� 2������ ����
	f4(10); //T=int, int&& ��� ����, �׷��� ǥ���� T=int�� ����
			//������ �Լ��� f4(int&&)
}

