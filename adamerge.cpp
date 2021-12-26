#include<iostream>
#include<algorithm>
using namespace std;
static int m=1;
static int j = 1;
void display(int a[], int t)
{
	for(int i=0;i<t;i++)
	cout<<a[i]<<" ";
}
void display1(int a[],int x)
{
	for(int i=(x-1);i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
}
void mergesort(int a[], int left[],int l,int right[],int r)
{
	int i=0,j=0,k=0;
	int z=(i+j);
	while(i<l&&j<r)
	{
		
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			k++;i++;
		}
		else if(left[i]>right[j])
		{
			a[k]=right[j];
			k++;j++;
		}
	}
		while(i<l)
		{
			a[k]=left[i];
			k++;i++;
		}
		while(j<r)
		{
			a[k]=right[j];
			k++;j++;
		}	
		cout<<"pass: "<<m++<<endl;
		for(int i=0;i<l+r;i++)
			cout<<a[i]<<"  ";
		cout<<endl;		
}
void merge(int a[] ,int n)
{
	if(n==1)
	return;
	int mid ;
	mid = n/2;
	int left[mid];
	int right[n-mid];
	for(int i=0;i<mid;i++)
		left[i]=a[i];
	for(int i=mid;i<n;i++)
		right[i-mid]=a[i];
	merge(left , mid);
	merge(right ,n-mid);
	mergesort(a ,left ,mid,right,n-mid);
}

int main()
{
	char ch;
	int a[20];
	cout<<"MERGE SORT"<<endl;
	do{
		m=1;
	j=1;
	int n;
	cout<<"Enter the number of elements u want to add: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	merge(a,n);
	cout<<endl<<"ascending order"<<endl;
	display(a,n);
	cout<<endl<<"descending order"<<endl;
	display1(a,n);
	cout<<endl<<"if you want to continue then press y else press any character ";
	cin>>ch;
	}while(ch=='y');
}



