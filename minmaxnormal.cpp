#include<iostream>
using namespace std;
int a[8];
int n ;
int mini ;
int maxi ;
void MinMax()
{
	if(n==1)
	{
		maxi = a[0];
		mini = a[0];	
	}
	else
	{
		mini = a[0];
		maxi = a[0];
		for(int i=0;i<n;i++)
		{
			if(a[i]>maxi)
			maxi = a[i];
			if(a[i]<mini)
			mini =a[i];
		}
	}
}
int main()
{
	char ch;
	cout<<"Enter the number of elements u want to add: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	cout<<"Maximum and Mininum"<<endl;
	MinMax();
	cout<<" maximum number "<<maxi<<endl;	
	cout<<" minimum number "<<mini<<endl;
}
