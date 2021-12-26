#include<iostream>
#include<algorithm>
using namespace std;

void display(int x,int a[])
{
	for(int i=0;i<x;i++)
	{
		cout<<a[i]<<endl;
	}
}
void mergesort(int l[],int r[],int a[],int nl , int nr)
{
	int i ,j,k;
	i=j=k=0;
	while(i<nl&&i<nr)
	{
		if(l[i]<=r[j])
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=l[i];
		i++;k++;
	}
	while(j<nr)
	{
		a[k]=r[j];
		j++;k++;
	}	
	 
}
void merge(int a[] ,int x)
{
	if(x<=1){
		return;
	}
	else{
	int mid = x/2;
	int left[x/2];
	int right[x-(x/2)];	
	for(int i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(int i=mid;i<=x-1;i++)
	{
		right[i-mid]=a[i];
	}
	merge(left , mid-1);
	merge(right , x-mid);
mergesort(left,right,a,mid,x-mid);
}
}

int main()
{
	int n;
	int a[20];
	cout<<"Enter the number of elements u want to add: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	merge(a,n);
	display(n,a);
	
}
