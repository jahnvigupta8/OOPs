// conversion of basic type to class type
#include<iostream>
using namespace std;
class Data
{
	int x;
	float y;
	char z;
	public:
	Data()
	{
		x = 0;
		y = 0;
		z = '0';	
	}	
	Data(int a)
	{
		x = a;
		y = 0;
		z = '0';
	}
	Data(float b)
	{
		x = 0;
		y = b;
		z = '0';
	}
	Data (char ch)
	{
		x = 0; 
		y = 0;
		z = ch;
	}
	void show()
	{
		cout<<endl<<x<<endl<<y<<endl<<z;
	}
};
main()
{
	int i=2;
	Data d1;
	d1 = i;
	d1.show();
	float j=3.567;
	Data d2;
	d2 = j;
	d2.show();
	char k = 'a';
	Data d3;
	d3 = k;
	d3.show();	
}
