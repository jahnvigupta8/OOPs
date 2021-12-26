#include<iostream>
using namespace std;
void max_min(int s ,int e,int a[],int &max,int &min)
{
	int max1 , min1,mid;
	mid=(s+e)/2;
	if(s==e)
	{
		max=min=a[s];
	}
	if(s==(e-1))
	{
		if(a[s]>a[e])
		{
			max=a[s];
			min=a[e];
		}
		else
		{
			max=a[e];
			min=a[s];
		}
	}
	else
	{
		max_min(s,mid,a,max,min);
		max_min(mid,e,a,max1,min1);
		if(max1>max)
		{
			max=max1;
		}
		if(min>min1)
		{
			min=min1;
		}
	}
}
int main()
{
	int n;
	int max,min;
	cout<<"enter the number of elements in array";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	max_min(0,n-1,a,max,min);
	cout<<"max is "<<max<<endl;
	cout<<"min is "<<min;	
}
