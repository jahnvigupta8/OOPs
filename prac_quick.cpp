#include<iostream>
#include<algorithm>
using namespace std;
int z=0;
int n;
void partition(int start , int end,int a[])
{
	if(start<end)
	{
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
	cout<<z<<" - ";
	z++;
	for(int k=0;k<n;k++)
	cout<<a[k]<<" ";
	cout<<endl;
	partition(start,pos-1,a);
	partition(pos+1,end,a);
	}
}
int main()
{
	cout<<"enter the number of elements in array";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	partition(0,n-1,a);	
	cout<<endl<<"sorted array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}

