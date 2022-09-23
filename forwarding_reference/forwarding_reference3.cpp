class X {};

// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
// ���1. call by value
// -> Ư¡ : ���纻 ����
//void foo(X arg) {}

// ���2.call by const lvalue reference
// -> ���纻�� �������� ������
// -> const �Ӽ��� �߰���.. (move���X)
//void foo(const X& arg) {}

// ���3. 2���� foo() �Լ� - C++11 ���� ����
//-> ���纻�� ����, const �Ӽ��� �߰����� ����
//void foo(X& arg) {} //lvalue�ϰ��
//void foo(X&& arg) {}//rvalue�ϰ��

// ���4. forwarding reference�� ����ϸ� "���3"�� 2�� �Լ��� �ڵ� ����
// -> X Ÿ�� �� �ƴ϶�.. "��� Ÿ��"�� ���� ��밡��
template<typename T> void foo(T&& arg) {}

int main()
{
	X x;

	// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
	foo(x);
	foo(X());
}
