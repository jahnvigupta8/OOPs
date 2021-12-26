#include<iostream>
#include<algorithm>
using namespace std;
void partition(int a[],int start,int end)
{
	if(start<end)
	{
		int pivot = end;
		int pos = start;
		for(int i=start;i<end;i++)
		{
			if(a[i]<=a[pivot])
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
void output(int a[] , int t)
{
	for(int i=0;i<t;i++)
		cout<<"element "<<i+1<<"---"<<a[i]<<endl;
}
int main()
{
	int n;
	int a[20];
	cout<<"enter the no of elements to sort ";
	cin>>n;
	for(int i =0 ;i<n;i++)
	{
		cout<<"element "<<i+1<<"--";
		cin>>a[i];
	}cout<<"when array is not sorted"<<endl;
	output(a,n);
	partition(a,0,n-1); cout<<"when array is sorted"<<endl;
	output(a,n);
}
