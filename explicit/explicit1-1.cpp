#include <vector>
#include <string>

void f1(std::vector<int> v) {}
void f2(std::string s) {}

int main()
{
	std::string s("aaa"); //���ڵ尡 �����ϴٴ°���..
							//string(const char*) �����ڰ� �ִٴ� ��
							
	std::vector<int> v(10);//���ڵ尡 �����ϴٴ°���..
							//vector(int) �����ڰ� �ִٴ� ��

	// �Ʒ� ������ �Ǵ°� ������.. �ȵǴ°� ������..
	f1(10);		//error�� ����.
				//vector�� //explicit�� �ִ�.
	f2("aaa");	//ok �� ����..
				//string�� //explicit�� ����.

	std::string s1 = "aaa"; //ok explicit ������ �ƴ�..
	std::vector<int> v1 = 10; //error. explicit ������ �̴�.
}