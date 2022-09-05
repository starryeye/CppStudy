// F.43: Never(directly or indirectly) return a pointer or a reference to a local object
// F.44 : Return a T & when copy is undesirable and "returning no object" isn't needed

//--------------------------------
// Temporary(�ӽð�ü) �� Ư¡
// �Լ� ��ȯ
//--------------------------------

int x = 10;

//primitive type������ .... �׷��ϴ�..
int f1() { return x; }	//x�� �ƴ� x�� ��(10)�� ��ȯ�Ѵ�.
int& f2() { return x; } //x�� ������ ��ȯ

int main()
{
	int ret = f1();

	f1() = 20; //error, 10 = 20�� ������.
	f2() = 20; //ok, x=20�� �ǹ��̴�.

	//�ᱹ. �Լ��� ������ ��ȯ�ϸ�....
	//1. �ӽð�ü�� �������� �ʴ´�.
	//2. �Լ� ȣ���� ��ȣ�� ���ʿ� ���� �� �ִ�.(lvalue�� �� �� �ִٴ� ���̴�.)
}