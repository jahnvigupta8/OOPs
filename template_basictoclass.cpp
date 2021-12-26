#include<iostream>
using namespace std;
template<class T>
class Data
{
	T x;
	T y;
	public:
	Data()
	{
	  x=0;
	  y=0;	
	}
	Data( T m)
    {
    	x = m;
    	y = m;
	}
	void show()
	{
    	cout<<endl<<x+y;
	}
};
main()
{
	Data<int> d;
	int i=1;
	d=1;
	d.show();
	Data<float> d1;
	float j=443.534;
	d1=j;
    d1.show();
}
