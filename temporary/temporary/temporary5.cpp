#include <iostream>

// F.44: Return a T & when copy is undesirable and "returning no object" isn't needed

//--------------------------------
// Temporary(�ӽð�ü) �� Ư¡
// �Լ� ��ȯ
//--------------------------------

class Counter
{
	int value{ 0 };
public:
	//�ӽð�ü ��ȯ
	//return by value
	Counter increment()
	{
		++value;
		return *this;
	}
	int get() const { return value; }

	~Counter() { std::cout << "~Counter" << std::endl; }

};

class Counter2
{
	int value{ 0 };
public:
	//*this�� ��ȯ�Ҷ��� ��κ� ���� ��ȯ�� ����ؾ� �Ѵ�.
	//*this�� increment() ȣ���� ����Ǿ �ı����� �ʴ´�.
	//return by reference
	Counter2& increment()
	{
		++value;
		return *this;
	}
	int get() const { return value; }

	~Counter2() { std::cout << "~Counter2" << std::endl; }

};

int main()
{
	Counter c;
	//	c.increment();5
	//	c.increment();
	//	c.increment(); //3�� ������ ���̴�. ->�����ϸ� 3����.

	std::cout << "----------------" << std::endl;
	c.increment().increment().increment();	//this�� �����Ͽ� �ٽ� increment() �Լ� ȣ���� �����ϵ���.. �Ͽ���.
											//3�� ��������?
											//-> increment�Լ��� ����ȯ�̴�. ��.. �ӽð�ü�̴�.
											//-> 3���� �ӽð�ü�� �����ǰ� �ı��ǰ��Ѵ�...����value 1,2,3
											//������ ����° �ӽð�ü�� value�� 3�� ��������..
											//�ᱹ c.get�� ���� 1�� 1�� ��µ�.
											//���ɿ��� ������ ������.. �ǵ����� ���� ������ �� ���ɼ��� �����Ѵ�.
	std::cout << "----------------" << std::endl;

	std::cout << c.get() << std::endl;


	Counter2 d;

	std::cout << "----------------" << std::endl;
	d.increment().increment().increment();	//this�� �����Ͽ� �ٽ� ȣ���� �����ϵ���.. �Ͽ���.
											//���� 3�� ���´�.
											//return by reference�� �ӽð�ü�� �������� �ʴ´�.
	std::cout << "----------------" << std::endl;

	std::cout << d.get() << std::endl;

}//<-- �̸��ִ� ��ü c, d �ı�(�Ҹ��� ȣ��)