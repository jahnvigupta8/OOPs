#include<iostream>
using namespace std;
void mergesort(int a[],int);
void merge(int left[],int,int right[],int,int a[]);
void display(int a[] , int);
int main()
{
	int a[20],n;
	cout<<"ENTER THE NO OF ELEMENTS YOU WANT TO ADD \n";
	cin>>n;
	cout<<"ENTER THE ELEMENTS \n";
	for (int i =0;i<n;i++)
	{
		cout<<"element"<<i+1<<endl;
		cin>>a[i];
	}
	mergesort(a,n);
	display (a,n);
}
void mergesort(int a[],int n)
{
	if(n==1)
	{
		return;
	}
int	mid = n/2;
	int left[mid],right[n-mid];
	for(int i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(int i=mid;i<n;i++)
	{
		right[i-mid]=a[i];
	}	
	mergesort(left,mid);
	mergesort(right,n-mid);
	merge(left,mid,right,n-mid,a);
}
void merge(int *left,int nl , int *right,int nr,int *a)
{
			int i=0,j=0,k=0;

	while(i<nl && j<nr)
	{
		if(left[i]>right[j])
		a[k++]=right[j++];
		else
		a[k++]=left[i++];		
	}
	while(i<nl)
	a[k++]=left[i++];
	while(j<nr)
	a[k++]=right[j++];
}
void display(int a[],int n)
{
	for(int i =0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
