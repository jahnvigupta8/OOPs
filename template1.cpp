#include<iostream>
using namespace std;
template<class T, class S>
class Test
{
	T x;
	S y;
	public:
	Test(T a1 = 0, S a2 = '0')
	{
		x=a1;
		y=a2;
		cout<<x<<y<<endl;
	}
	void fun(T a1, S a2)
	{
		cout<<"data type 1"<<a1<<endl;
		cout<<"data type 2"<<a2<<endl;
	}
	S max(S a2)
	{
		return ++a2;
	}
	T alpha(T a1,T a3)
	{
		return a1+a3;
	}
};
main()
{
	Test<int,char> t1(45,'h');
	t1.fun(3,'g');
	cout<<endl;
	Test<int,char> t2;
	cout<<endl;
	Test<int,char> t3;
	cout<<endl<<t2.alpha(7,8);
	cout<<t3.max(5);
}
