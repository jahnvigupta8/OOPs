#include<iostream>
using namespace std;
int main()
{
    int num,factorial=1;
    cout<<" Enter Number To Find Its Factorial:  ";
    cin>>num;
    if(num==0)
    {
    	factorial = 1;
	}
	else  	{
    for(int a=2;a<=num;a++)
    {
		factorial=factorial*a;
    }
		}
cout<<"Factorial of Given Number is ="<<factorial<<endl;
return 0;
}
