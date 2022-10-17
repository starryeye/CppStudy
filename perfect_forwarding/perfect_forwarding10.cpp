#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// �Ʒ� �����ڴ� move ������ �ȵȴ�.
	// -> T&& �� ������ �Ѵ�. Ŭ���� �Ʒ� �κ� ����
//	People(const std::string& name, const std::string& addr) : name(name), addr(addr)
//	{
//	}

	//���ڰ� 2���� setter
	//-> �Ʒ�ó���� ����� move ���� �ȵȴ�.
	//-> ���ڰ� 2���� setter�� move�� �����Ϸ��� 4���� �Լ��� �����ؾ� �Ѵ�.
//	void set(const std::string& n, const std::string& a)
//	{
//		name = n;
//		addr = a;
//	}

	//���ڰ� 2�� �̻��� setter�� move�� �����Ϸ���
	//	T&&�� ����ϴ� ���� ����.
	//����.. ���ڰ� 1���ΰ��� ���� 2���� �Լ��� �����ϴ� ���̰�..
	//���ڰ� 2���̻��̸� T&& �������..
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		addr = std::forward<T2>(a);
	}

	//move �����ϴ� ������..
	template<typename T1, typename T2>
	People(T1&& n, T2&& a)
		: name(std::forward<T1>(n)), addr(std::forward<T2>(a))
	{
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2); 
	People p2(std::move(s1), s2); 
	People p3(s1, std::move(s2)); 
								  
	People p4(std::move(s1), std::move(s2));

}
//�ٽ� 1. move�� �����ϴ� setter/������ �����.
// ���ڰ� 1�����.. : 2��(const&, && ����)�� setter ������ (9��.cpp ����)
// ���ڰ� 2�� �̻��̶��.. : T&& �� �������.. (���ڵ� ����)

//�ٽ� 2. T&& �� �ֵ� �뵵
// �Ϻ��� ���� ��� : ���޹��� ���ڸ� �ٸ� �Լ��� ������ (chronometry ����)
// move ���� setter �Ǵ� ������ ���鶧 (�� ����)

