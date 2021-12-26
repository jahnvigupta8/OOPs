#include<iostream>
#include<algorithm>
using namespace std;

void mergesort(int a[],int l[] ,int nl,int r[],int nr)
{
	int i , k ,j;
	i=j=k=0;
	while(i<nl&&i<nr)
	{
		if(l[i]<=r[i])
		{
			a[i]=l[j]; 
			i++;
			j++;
		}
		else /*if(l[i]>r[i])*/
		{
			a[i]=r[k];
			k++;
			i++;
		}
	}
	while(i<nl)
	{
		a[i]=l[j];i++;j++;
	}
		while(j<nr)
	{
		a[i]=r[k];i++;k++;
	}
}
void merge(int a[],int x)
{
	if(x<=0)
	{
		return;
	}
	int mid = x/2;
	int left[x/2];
	int right[x-(x/2)];
	for(int i =0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(int i =mid;i<x;i++)
	{
		right[i-mid]=a[i];
	}
	
	merge(left,mid);
	merge(right , x-mid);
	mergesort(a , left , mid , right ,x-mid);
	
}
void output(int a[], int t)
{
	for(int i=0;i<t;i++)
	cout<<"element "<<i+1<<"---"<<a[i]<<endl;
}
int main()
{
	int t;
	int a[20];
	cout<<"enter the no of elements to sort ";
	cin>>t;
	for(int i =0 ;i<t;i++)
	{
		cout<<"element "<<i+1;
		cin>>a[i];
	}
	output(a,t);
	merge(a,t);
	output(a,t);
}
