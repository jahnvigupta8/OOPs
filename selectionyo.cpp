#include<iostream>
#include<algorithm>
using namespace std;
static int a[20];

void selectionsort(int x)
{
	int largest = 0; 
	if(x==0)
	{
		return;
	}
	for(int i =0;i<x;i++)
	{
		if(a[i]>a[largest])
		{
			largest = i;
		}
	}
	swap(a[largest],a[x-1]);
	selectionsort(x-1);
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
	selectionsort(t);
	output(t);
}
