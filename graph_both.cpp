#include<iostream>
#include<queue>
using namespace std;
int count=0;
queue<int>p;
int v;	int z[10];
int a[10][10];
int r[10];
void BFS( )
{
	while(!p.empty())
	{
		int h =p.front();
		p.pop();
		z[h]=1;
			for(int i=0;i<v;i++)
		{
			if(a[h][i]==1&&z[i]!=1)
			{	
					p.push(i);
					z[i]=1;
					r[count]=(i+1);
					count++;
			}			
		}
	}
}
void DFS(int s)
{
	cout<<s<<" ";
	s=s-1;
	for(int i=0;i<v;i++)
	{
		if(a[s][i]==1 && z[i]!=1)
		{
			z[i]=1;
			DFS(i+1);
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
		z[i]=0;
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
	int s;
	cout<<"Enter the source ";
	cin>>s;
	
	cout<<"to traverse using bfs press 1 and if you want to traverse using dfs press 2";
	int t=0;
	cin>>t;
	if(t==1)
	{
		r[count]=s;
		s=s-1;
	p.push(s);
	count++;
	BFS();
	cout<<endl;
	for(int i=0;i<v;i++)
		{
			cout<<r[i]<<" ";
		}
	}
	if(t==2)
	{
			z[s-1]=1;
			DFS(s);
	}
}
