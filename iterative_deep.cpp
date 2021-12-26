#include<iostream>
using namespace std;
int count=0;
int v;int s;
int a[10][10];
int z[10];
void DFS(int s , int d)
{
	if(d==0)
	{
		return;
	}
	else 
	{
		cout<<s<<"\n";
		s=s-1;
		for(int i=0;i<v;i++)
		{
			if(a[s][i]==1 && z[i]!=1)
			{
				z[i]=1;	
				DFS(i+1,d-1);
			}
		}		
	}
}
int main()
{
	int x,y,k,d;
	cout<<"Enter the number of vertices ";
	cin>>v;
	cout<<"Enter the number of and edges ";
	cin>>x;
	cout<<"Enter the depth ";
	cin>>d;
		for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			a[i][j]=0;
		}
	}
		for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<x;i++)
	{
		cout<<"Enter the vertices ";
		cin>>y>>k;
		a[y-1][k-1]=1;
		a[k-1][y-1]=1;
	}
		for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<v;i++)
	{
		z[i]=0;
	}
	cout<<"Enter the source ";
	cin>>s;
	z[s-1]=1;
	DFS(s,d+1);
}

