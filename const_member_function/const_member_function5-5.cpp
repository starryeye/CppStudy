#include <iostream>
#include <vector>

template<typename T>
class view_interface
{
	const T& Cast() const //����ɹ��Լ� ���ο��� �θ� ���� ��� �ɹ��Լ��� �Ǿ���Ѵ�.
	{
		//const �ɹ� �Լ����� this �� const�� ����Ű�� �������̴�.
		//return static_cast<T&>(*this); 
		return static_cast<const T&>(*this);
	}
public:
	bool empty() const
	{
		auto& derv = Cast();
		// derv�� const& �̴�.

		return derv.begin() == derv.end();
	}
	unsigned int size() const
	{
		auto& derv = Cast();

		return derv.end() - derv.begin();
	}
};

template<typename T>
class take_view : public view_interface<take_view<T>>
{
	T& range;
	int count;
public:
	take_view(T& r, int c) : range(r), count(c) {}

	//��� begin(), end()������ cbegin()����.. ��� �ݺ��ڸ� ����Ѵ�.
	auto begin() const { return range.cbegin(); }
	auto end() const { return range.cbegin() + count; }

	auto begin() { return range.begin(); }
	auto end() { return range.begin() + count; }
};

template<typename T>
class reverse_view : public view_interface<reverse_view<T>>
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	//��� begin(), end()������ crbegin(), crend()��.. ��� �ݺ��ڸ� ����Ѵ�.
	auto begin() const { return range.crbegin(); }
	auto end() const { return range.crend(); }

	auto begin() { return range.rbegin(); }
	auto end() { return range.rend(); }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv1(v, 3);
	const take_view tv2(v, 3);

	auto p1 = tv1.begin(); //�� ��� view�� �ݺ���
	auto p2 = tv2.begin(); //��� view�� �ݺ���

	//�Ʒ� �ڵ带 �����غ���..
	*p1 = 10; //ok
	*p2 = 10; //error�� �Ǿ���Ѵ�.
	
}