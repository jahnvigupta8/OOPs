#include<iostream>
#include<algorithm>
using namespace std;
static int a[20];

void bubblesort(int x)
{
	if(x==0)
	{
		return;
	}
	for(int i =0;i<x-1;i++)
	{
		if(a[i]>a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
	bubblesort(x-1);
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
		cout<<"element "<<i+1;
		cin>>a[i];
	}
	output(t);
	bubblesort(t);
	output(t);
}
