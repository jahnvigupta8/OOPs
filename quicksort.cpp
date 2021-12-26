#include<iostream>
#include<algorithm>
using namespace std;
static int n;
static int z=0;
void display1(int a[],int x)
{
	for(int i=(x-1);i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
}void partition(int a[],int start , int end) 
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
	partition(a,start,pos-1);
	partition(a,pos+1,end);
	}
}
void display(int a[],int n)
{
	for(int i =0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int a[20];
	char ch;
	cout<<"QUICK SORT"<<endl;
	do{
		z=1;
	cout<<"ENTER THE NO OF ELEMENTS YOU WANT TO ADD \n";
	cin>>n;
	cout<<"ENTER THE ELEMENTS "<<endl;
	for (int i =0;i<n;i++)
	{
		cout<<"element "<<i+1<<" ";
		cin>>a[i];
	}
	partition(a,0,n-1);
	cout<<endl;
	display(a,n);
	cout<<endl;
	cout<<endl<<"ascending order"<<endl;
	display(a,n);
	cout<<endl<<"descending order"<<endl;
	display1(a,n);
	cout<<endl<<"if you want to continue then press y else press any character ";
	cin>>ch;
	}while(ch=='y');
}
