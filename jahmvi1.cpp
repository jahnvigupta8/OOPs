#include<iostream>
#include<stdio.h>
using namespace std;
void add(int a[20],int n)
{
	int x,y,b[20];
	int i, j =0;
	cout<<"Enter the position and the element you want to add";
	cin>>x>>y;
	for(i=0;i<n+1;i++)
	{
		if(i==(x-1))
		{
			b[i]= y;
		}
		else 
		{
			b[i]=a[j];
			j++;
		}
	}
	n=n+1;
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<endl;
	}
}
void del(int a[] ,int n)
{
	int y,b[20];
	int j=0;
	cout<<"Enter the element you want to delete"<<endl;
	cin>>y;
	for(int i=0;i<n;i++)
	{
		if(a[i]==y)
		{
			continue;
		}
		else 
		{
			b[j]=a[i];
			j++;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<b[i]<<endl;
	}
}
void lsearch(int a[] ,int n)
{
	int y;
	int j=0;
	cout<<"Enter the element you want to search"<<endl;
	cin>>y;
	for(int i=0;i<n;i++)
	{
		if(a[i]==y)
		{
		 cout<<"the position of element is "<<i+1<<endl;
		 }
	}
}
void bsearch(int a[] ,int n,int k,int low,int high)
{
	for(int j=0;j<n;j++)
	{
	for(int i=j+1;i<n;i++)
	{
		if(a[i]<a[j])
		{
			int t;
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	}
	int mid=0;
	mid=(low+high)/2;
	if(a[mid]==k)
	{
		cout<<"position of element is "<<mid<<endl;
	}
	else if(a[mid]>k)
	return bsearch(a,n,k,0,mid-1);
	else 
	return bsearch(a,n,k,mid+1,high);
}
main()
{
	int a[20],x,n;
	int c;
	cout<<"Enter the no elements in array"<<endl;
	cin>>x;
	char z;
	for(int i=0;i<x;i++)
	{
			cout<<"Enter the element"<<i+1;
			cin>>a[i];
	}
	do
{
	cout<<"if you want to ADD an element PRESS 1"<<endl<<"if you want to DELETE an element PRESS 2"<<endl<<"if you want to search an element using LINEAR SEARCH an element PRESS 3"<<endl<<"if you want to search an element using BINARY SEARCH an element PRESS 4";
	cin>>c;
	switch(c)
	{
		case 1:{
			add(a,x);
			break;
		}
		case 2:
			del(a,x);
			break;
		case 3:
		    lsearch(a,n);
		    break;
		case 4:
			int k;
			cout<<"enter the element you want to search";
			cin>>k;
		    bsearch(a,n,k,0,n-1);
			break;
		default:
		break;	    
	}
	cout<<"if you want to continue press y";
	cin>>z;
}while(z=='y');
}

