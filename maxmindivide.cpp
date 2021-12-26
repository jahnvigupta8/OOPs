#include<iostream>
using namespace std;
int a[8];
int n;
int mini=0;
int maxi=0;
int mini1=0;
int maxi1=0;
void MaxMin(int x ,int y,int &max ,int &min)
{
	if(x==y)
	{
		min = max = a[x];
	}
    else if (x == (y-1))
	{
			if(a[x]>a[y])
			{
				max = a[x];
				min =a[y];
		    }
			if(a[x]<a[y])
			{
				max = a[y];
				min =a[x];
		    }
	}
	else
	{
			int mid = ((x+y)/2);
			MaxMin(x,mid,maxi,mini);
			MaxMin(mid+1,y,maxi1,mini1);
			if(maxi<maxi1)
				maxi = maxi1;
			if(mini1<mini)
				mini = mini1;
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
//	maxi = mini = a[0];
	cout<<"Maximum and Mininum"<<endl;
	MaxMin(0,n-1,maxi,mini);
	cout<<" maximum number "<<maxi<<endl;	
	cout<<" minimum number "<<mini<<endl;
}
