// T44. Use function templates 
// to deduce class template argument types

template<typename T> T square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};

// C++17 �������� Ŭ���� ���ø��� ���� �߷��� ����
// �Լ� ���ø��� ����Ѵ�..
template<typename T>
List<T> make_list(int sz, T value)
{
	return List<T>(sz, value);
}

int main()
{
	// ������ ���� ���̴� ���� ?
	square<int>(3); //Ÿ���� ���� - ������ ����.
	square(3);      //Ÿ���� ���� - ���� ����.(�Լ� ���ڷ� Ÿ�� �߷�)

	List<int> s1(10, 0); //Ÿ�� ����
	List s2(10, 0); //Ÿ�� ����
					// Ŭ���� ���ø� ������ �ι�° ���ڷ� T�� �߷�?
					// C++17 ���ʹ� Ŭ���� ���ø� �����ڷ� Ÿ�� �߷� ���� - ok
					// C++17 �������� Ŭ���� ���ø� �����ڷ� Ÿ�� �߷� ���� ����..

//	auto s3 = make_list<int>(10, 0); //��Ȯ�� ǥ���- Ÿ������
	auto s4 = make_list(10, 0);	//�Լ� ���ø��� C++98 ���� Ÿ�Ի��� ����
}







