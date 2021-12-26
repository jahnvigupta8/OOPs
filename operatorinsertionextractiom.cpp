#include<iostream>
using namespace std;
class Complex
{
	private:
		int real;
		int imag;
	public:
		Complex( int real = 0 , int imag = 0)
		{
			this->real=real;
			this->imag=imag;
		}
		friend istream & operator>>(istream & , Complex &);
		friend ostream & operator<<(ostream & , Complex &);
};
istream & operator>>(istream & in, Complex & a)
{
	cout<<"Enter real";
	in>>a.real;
	cout<<"Enter Imag";
	in>>a.imag;
}
ostream & operator<<(ostream & out, Complex & a)
{
	cout<<" real";
	out<<a.real;
	cout<<"Imag";
	out<<a.imag;
}
main()
{
	Complex c , d ;
	cout<<endl<<" enter the two comples numbers ";
	cin>>c>>d;
	cout<<endl<<"the complex numbers are";
	cout<<c<<d;
}
