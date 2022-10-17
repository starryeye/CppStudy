#include <iostream>

void f0() { } //���� 0��
void f1(int a1) { } //���� 1��
void f2(int a1, double d) {  } //���� 2��
int& f3(int a1, double d, int& r) { r = 200; return r; } //���� 3��

// �Ϻ��� ������ ���� �ڵ�.
// 1. �������� ���ø� ����ؼ� ���� ������ ������ ���־� �Ѵ�.
// 2. ���ϰ��� �Ϻ��ϰ� �������� "decltype(auto)" ���
template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	//StopWatch sw; //�����ڿ��� �ð� �������..
					//�Ҹ��ڿ��� �ٽ� �ð� ���ؼ� ��ϵ� �ð����� ���̸� ���

	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 10;

	chronometry(f0);
	chronometry(f1, 10);
	chronometry(f2, 10, 3.4);
	int& ret = chronometry(f3, 10, 3.4, n);
	
	ret = 300; // �ᱹ n�� ����Ű�� ���� �̹Ƿ� n = 300

	std::cout << n << std::endl; //200
}