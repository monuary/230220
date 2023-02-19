#include<iostream>
using namespace std;

class SelfRef
{
	int num;
public:
	SelfRef(int n) :num(n)
	{
		cout << "객체생성" << endl;
	}
	SelfRef& Adder(int n)	//반환형이 객체 자신. 참조자를 붙여서 자신을 참조한다.
	{
		num += n;
		return*this;
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return*this;
	}
};

int main()
{
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);	//obj에 Adder를 실행한 후, 이를 참조한다. 따라서 num값이 같다.

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	//같은 이름공간에서 이런 호출형태가 가능하다.
	return 0;
}