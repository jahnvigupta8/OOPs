#include<iostream>
using namespace std;
static int a[20];
void selectionsort(int x)
{
	int largest = 0;
	if(x==1)
	{
		return;
	}
	for(int i =0;i<x;i++)
	{
		if(a[i]>largest)
		{
			largest = i;
		}
    }
    int temp;
    temp=a[largest];
    a[largest]=a[x-1];
    a[x-1]=temp;
	selectionsort(x-1);    
}
void display(int x)
{
	for(int i=0;i<x;i++)
	{
		cout<<a[i]<<endl;
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements u want to add: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
		selectionsort(n);
	display(n);
}
