#include<iostream>
#include<algorithm>
using namespace std;
static int a[10];
int partition(int start,int end,int k)
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
	if(pos==k)
	return pivot;
	if(pos>k)
	{	
		partition(start,pos-1,k);
    }
    if(pos<k)
	{	
		partition(pos+1,end,k);
	}
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
		cout<<"element - "<<i+1<<"---";
		cin>>a[i];
	}
	int d;
	cout<<"to search kth larget .. give value of k"<<endl;
	cin>>d;
	d=d-1;
	cout<<"value "<<"------>>  "<<partition(0,t-1,d);
	
}
