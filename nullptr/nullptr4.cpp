// nullptr �� ����

void f1(int*  p) {}
void f2(char* p) {}

// nullptr�� ���� ������.. 
struct mynullptr_t
{
	//mynullptr_t Ÿ�� -> int* �� ��ȯ�Ǳ� ���� ��ȯ ������ �Լ�
//	operator int* () const { return 0; }
//	operator char*() const { return 0; }

	//��� ������ Ÿ������ ��ȯ�����ؾ� �Ѵ�.
	template<typename T>
	constexpr operator T* () const { return 0; } //������Ÿ�ӿ� ������ Ű���� : constexpr
};

mynullptr_t mynullptr; //mynullptr�� nullptr�̴�..

int main()
{
	f1(mynullptr);	// mynullptr -> int* ���� �Ͻ��� ����ȯ�� �ʿ�
					// "mynullptr.operator int*()" ��� �ɹ��Լ��� ã�Եȴ�.
	f2(mynullptr);
}

//nullptr �� ����
// 1. boost ���̺귯��(boost.org)���� ��ó�� ���� ����ߴ� ����
// 2. C++11 �� ����鼭, "nullptr"�� ��ü�� �ƴ� "Ű����"�� ���Ե� ��.