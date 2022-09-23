// F.19: For ��forward�� parameters, pass by TP&& and only std::forward the parameter

template<typename T> void foo(T a)
{
	T& r = a; //T�� Ÿ���� int& �̹Ƿ�.. 
				//���������� int& &r = a;
				//reference collapsing ��Ģ�� ���Ͽ�..
				//int& r = a; �� �ȴ�.
}


int main()
{
	int n = 10;

	int&  r1 = n ; //lvalue reference (�̸� �ִ� ��ü)
	int&& r2 = 10 ; //rvalue reference (�̸� ���� ��ü, literal)

	int* *p; // �������� �����ʹ� ����� �ִ�.
			//�� �������ε�(*p) ���󰡸� ������(int*)�־�
//	int& &r3 = ?; //���۷����� ���۷����� ����� ����. error 

	//�ٽ� : ���۷����� ���۷����� ���� �ڵ����� ����� ������
	//		Ÿ���߷а������� �߻��ϴ� ���۷��� �浹��
	//		reference collapsing ��Ģ�� ����ȴ�.
	//		�Ʒ��� ���� ������..

	//LREF : lvalue reference
	//RREF : rvalue reference

	using LREF = int&; // typedef int& LREF;
	using RREF = int&&;

	LREF r4 = n;
	RREF r5 = 10;

	// reference collapsing ��Ģ
	LREF& r6 = n;	// int& &	=> int&
	RREF& r7 = n;	// int&& &	=> int&
	LREF&& r8 = n;	// int& &&  => int&
	RREF&& r9 = 10;	// int&& && => int&&
					//���ʸ�� �ΰ��� ��� �ΰ�

	foo<int&>(n); //foo �ȿ��� r�� Ÿ���� �����غ���..
}





