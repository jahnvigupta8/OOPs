#include<iostream>
#include<algorithm>
using namespace std;
int cost[10][10];
int a[10][10];
int min(int a , int b)
{
	return (a < b)? a : b ;
}
void display(int x)
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<x;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}
int allpair(int x)
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<x;j++)
		{
			a[i][j]=cost[i][j];
		}
	}
	display(x);
	for(int k=0;k<x;k++)
	{
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<x;j++)
			{
				a[i][j]= min(a[i][j] , a[i][k]+a[k][j]);
			}
		}
		cout<<endl<<"from intermediate vertice "<<k<<endl;
		display(x);
	}
}
int main()
{
	int n,m,c,b,w;
	cout<<"Enter the number vertices "<<endl;
	cin>>n;
	cout<<endl<<"Enter the number of edges"<<endl;
	cin>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cost[i][j]=99;
			a[i][j]=99;
		}
	}
	for(int i=0;i<n;i++)
	{
		cost[i][i]=0;
		a[i][i]=0;
	}
	for(int j=0;j<m;j++)
	{
		cout<<endl<<"Enter the two vertices between an edge is required ";
		cin>>c>>b;
		cout<<endl<<"Enter the weight of the edge ";
		cin>>w;
		cost[c-1][b-1]=w;
		a[c-1][b-1]=w;
	}
	display(n);
	allpair(n);
}
