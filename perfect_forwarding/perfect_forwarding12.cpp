#include <iostream>
#include <vector>

struct Point
{
	int x, y;

	Point(int a, int b) :x(a), y(b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//�Ʒ� ��� 1, 2, 3 �� ���� ���� �غ��� �˾ƺ���..
int main()
{
	std::vector<Point> v;

	// vector �� Point ��ü�� �ִ� ���

	// ��� 1. ��ü�� �������� �ֱ�
	// ���� ���� �Ҹ��� 2ȸ ȣ���.. �� 2ȸ�ΰ� ����(�����ڴ� ��..?)
//	Point pt(0, 0);
//	v.push_back(pt);	//pt�� �����ؼ� vector�� �ִ´�.
						//pt ��ü�� �����ϴ� ���� �ƴ϶�..
						//����(vector)�� pt�� ���纻�� ����� ����
	

	// ��� 2. �ӽð�ü ���·� ����
	// �Ҹ��� �������� 1ȸ ȣ���(�ӽð�ü �ı�), ���� ���� 1ȸ ȣ���.
//	v.push_back(Point(0, 0)); //���� �ӽð�ü�� ���纻�� �����Ѵ�..

	// ��� 3. �ٽ�
	// -> ��ü�� �������� ����, ��ü�� ����� ���� ������ ���ڸ� ��������..
	v.emplace_back(0, 0); // emplace_back �� 0,0 �� �޾Ƽ�
							//���������� new Point(0,0) ���� ��ü ����
							//�ӽð�ü�� �������� �ʴ´�..
							//��� 1, 2�� ���纻 ������ ������ ��ü�� 1ȸ ������.
							//emplace_back�� ���ڸ� �޾Ƽ�.. 0,0�� �����ڷ� �Ϻ��� ������ �Ѵ�.(foward)
							//stl ���Ǻθ� ����..
	std::cout << "------------" << std::endl;
}

//STL �����̳ʿ� �����
//1. primitive Ÿ���̳� �����͸� �����Ҷ���
//	push_xxx() �迭 �Լ��� ����ϰų� emplace_xxx() �Լ��� ����ϸ� �ȴ�.
//2. user define Ÿ���� ������ �����Ҷ���
//  push_xxx() ������� ���� �ǵ��� emplace_xxx() �������

//push_front() -> emplace_front()
//push_back() -> emplace_back()
//insert() -> emplace()

// emplace�� �ӽð�ü�� ������..?
// v.emplace_back(0,0) -> new Point(0,0)
// v.emplace_back(Point(0,0)) -> new Point(���޵� ����)
//							  -> new Point(�ӽð�ü)
//��, 1. �ӽð�ü ���鶧 ������ ȣ��
//   2. new Point(�ӽð�ü) ���� move ������ ȣ��

// std::shared_ptr<Point> sp = std::make_share<Point>(0,0)
// -> make_shared �� 0, 0 �� �޾Ƽ� "new Point(0,0)" �ϰ� �ȴ�.
// -> ��, make_shared �� �Ϻ��� ���� ��� �̴�.

// v.emplace_back(std::move(Point(0,0)); // �Ʒ��� �����ϴ�.
// v.emplace_back(Point(0,0));