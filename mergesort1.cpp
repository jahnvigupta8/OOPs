#include<iostream>
#include<algorithm>
using namespace std;
static int a[10];
void partition(int n, int start,int end)
{
	int pivot = end;
	int pos = start;
	for(int i=0;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(a[i],a[pos]);
		}
	}
	swap(a[pos],a[end]);
	partition(n,start,pos-1);
	partition(n,pos+1,end);
}
void output(int x)
{
	for(int i = 0;i<x;i++)
		cout<<a[i]<<endl;
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
	partition(t,0,t-1);
	output(t);
}
