#include<iostream>
#include<algorithm>
using namespace std;
static int a[20];
static int j =1;
static int m;
void display(int x)
{
	for(int i=0;i<x;i++)
	{
		cout<<a[i]<<" ";
	}
}
void display1(int x)
{
	for(int i=(x-1);i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
}
void bubblesort(int x)
{
	if(x==1)
	{
		return ;
	}
	for(int i=0;i<x;i++)
	{
		if(a[i]<a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
		cout<<endl<<" "<<j<<" -- ";
	display(m);
	j++;
	bubblesort(x-1);
}
int main()
{
	char ch;
	cout<<"BUBBLE SORT"<<endl;
	do{
	j=1;
	int n;
	cout<<"Enter the number of elements u want to add: ";
	cin>>n;
	m = n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	bubblesort(n);
	cout<<endl<<" "<<j<<" -- ";
	display(n);
	cout<<endl<<"desscending order"<<endl;
	display(n);
	cout<<endl<<"ascending order"<<endl;
	display1(n);
	cout<<endl<<"if you want to continue then press y else press any character ";
	cin>>ch;
	}while(ch=='y');
}
