#include<iostream>
#include<algorithm>
using namespace std;
static int a[10];
void partition(int start,int end)
{
	if(start<end){
	int pivot = a[end];
	int pos = start;
	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(a[i],a[pos]);
			pos++;
		}
	}
	swap(a[pos],a[end]);
	partition(start,pos-1);
	partition(pos+1,end);
}
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
	partition(0,t-1);
	output(t);
}
