#include<iostream>
using namespace std;

class SelfRef
{
	int num;
public:
	SelfRef(int n) :num(n)
	{
		cout << "��ü����" << endl;
	}
	SelfRef& Adder(int n)	//��ȯ���� ��ü �ڽ�. �����ڸ� �ٿ��� �ڽ��� �����Ѵ�.
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
	SelfRef& ref = obj.Adder(2);	//obj�� Adder�� ������ ��, �̸� �����Ѵ�. ���� num���� ����.

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	//���� �̸��������� �̷� ȣ�����°� �����ϴ�.
	return 0;
}