#include<iostream>
#include<math.h>
using namespace std;
void add(int (&a)[20],int &n)
{
	int x,y;
	cout<<"Enter the position and the element you want to add :\n";
	cin>>x>>y;
	if(x<n)
	{
		a[x-1]=y;
		n++;
	}
	else
		cout<<"Enter a valid position...\n";
}
void del(int(&a)[20],int &n)
{
	int y;
	int j=0;
	cout<<"Enter the position of element you want to delete :\n";
	cin>>y;
	if(y<=n)
	{
		for(int i=y-1;i<n;i++)
		{
			a[i]=a[i+1];
		}
	n=n-1;
	}
	else
		cout<<"Enter a valid position...\n";
}
void lsearch(int (&a)[20],int n,int z)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==z)
			j=i+1;
	}
	if(j>0)
	{
		cout<<"Element found at "<<j<<" index.\n";
	}
	else
		cout<<"Element not found...\n";
}
int* sort(int a[20],int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;	
			}
		}
	}
	return a;
}
void binsearch(int a[20],int l,int h,int q)
{
	a = sort(a,h);
	int x;
	x = (h+l)/2;
	floor(x);
	if(a[x]==q)
		cout<<"Element found \n";
	else if(q>a[x])
	{
		l=x+1;
		binsearch(a,l,h,q);
	}
	else if(q<a[x])
	{
		h=x-1;
		binsearch(a,l,h,q);
	}
	else
		cout<<"Element not found...\n";
}
main()
{
	int a[20],x,l=0;
	char z;
	cout<<"Enter the number of elements :\n";
	cin>>x;
	for(int i=0;i<x;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>a[i];
	}
	int c;
		do
	{
		cout<<"if you want to ADD an element PRESS 1 :"<<endl<<"if you want to DELETE an element PRESS 2 :"<<endl<<"if you want to search an element using LINEAR SEARCH an element PRESS 3 :"<<endl<<"if you want to search an element using BINARY SEARCH an element PRESS 4 :\n";
		cout<<"if you want to view the array PRESS 5 : \n";
		cin>>c;
		switch(c)
			{
				case 1:
					add(a,x);
					break;
				case 2:
					del(a,x);
					break;
				case 3:
					cout<<"Enter element to be searched : \n";
					int z;
					cin>>z;
		    		lsearch(a,x,z);
		    		break;
				case 4:
					cout<<"Enter element to be searched : \n";
					int q;
					cin>>q;
		    		binsearch(a,l,x,q);
					break;
				case 5:
					for(int i=0;i<x;i++)
					{
						cout<<a[i]<<endl;
					}
				default:
				break;	    
			}
		cout<<"if you want to continue press y";
		cin>>z;
		}while(z=='y');
}

