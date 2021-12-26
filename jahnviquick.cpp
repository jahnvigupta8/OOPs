#include<iostream>
#include<algorithm>
using namespace std;
void partition(int a[] , int start , int end )
{

	if(start<end)
	{
		int pivot = a[end];
		int pos=start;
		for(int i =start;i<end;i++)
		{
			if(a[i]<=pivot)
			{
				swap(a[i],a[pos]);
				pos++;
			}
		}	
		swap(a[pos],a[end]);
		partition(a,start,pos-1);
		partition(a,pos+1,end);
	}	
}
void display(int x ,int a[])
{
	for(int i = 0;i<x;i++)
	{
		cout<<a[i]<<endl;
	}
}
int main()
{
	int n;
	int a[10];
	cout<<"Enter the number of elements u want to add: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	partition(a,0,n-1);
	display(n,a);
	
}
