#include<iostream>
#include<algorithm>
using namespace std;
static int a[10];
void insertion(int t)
{
	if(t==0)
	{
		return ;
	}
	else
	{
		for(int i=0;i<t;i++)
		{
			int hole = i;
			int value = a[i];
			while(hole>0&a[hole-1]>value)
			{
				a[hole]=a[hole-1];
				hole--;
			 } 
			 a[hole]=value;
		}
	}
}
void output(int t)
{
	for(int i=0;i<t;i++)
	cout<<"element "<<i+1<<"---"<<a[i]<<endl;
}
int main()
{
	int t;
	cout<<"enter the no of elements to sort ";
	cin>>t;
	for(int i =0 ;i<t;i++)
	{
		cout<<"element --  "<<i+1;
		cin>>a[i];
	}
	output(t);
	insertion(t);
	output(t);
}
