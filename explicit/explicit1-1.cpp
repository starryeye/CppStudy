#include <vector>
#include <string>

void f1(std::vector<int> v) {}
void f2(std::string s) {}

int main()
{
	std::string s("aaa"); //이코드가 가능하다는것은..
							//string(const char*) 생성자가 있다는 것
							
	std::vector<int> v(10);//이코드가 가능하다는것은..
							//vector(int) 생성자가 있다는 것

	// 아래 두줄은 되는게 좋을까.. 안되는게 좋을까..
	f1(10);		//error가 좋다.
				//vector는 //explicit가 있다.
	f2("aaa");	//ok 가 좋다..
				//string은 //explicit가 없다.

	std::string s1 = "aaa"; //ok explicit 생성자 아님..
	std::vector<int> v1 = 10; //error. explicit 생성자 이다.
}