#include<iostream>
#include<queue>
using namespace std;
int count=0;
queue<int>p;
int v;
int a[10][10];
int r[10];
void BFS(int v, int z[],int h)
{
//	
//		
//		if(!p.empty())
//		{
//		p.pop();
//			h=p.front();
//		BFS(v,z,h);
//		
//	}
	while(!p.empty())
	{
		int h =p.front();
		p.pop();
		z[h-1]=1;
			for(int i=0;i<v;i++)
		{
			if(a[h-1][i]==1&&z[i]!=1)
			{	
					p.push(i);
					cout<<i<<" ";
					z[i]=1;
					r[count]=i+1;
					count++;
			}			
		}
	}
}
int main()
{
	int x,y,k;
	cout<<"Enter the number of vertices";
	cin>>v;
	cout<<"Enter the number of and edges";
	cin>>x;

		for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			a[i][j]=0;
		}
		r[i]=0;
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
	int z[v];
	for(int i=0;i<v;i++)
	{
		z[i]=0;
	}
	int s;
	cout<<"Enter the source ";
	cin>>s;
	z[s-1]=1;
	p.push(s);
	r[count]=s;
	count++;
	BFS(v,z,s);
	cout<<endl;
	for(int i=0;i<v;i++)
		{
			cout<<r[i]<<" ";
		}
}

