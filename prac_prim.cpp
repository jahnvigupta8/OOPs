#include<iostream>
using namespace std;
int a[10][10];
int min_mst(int key[],bool mst[] , int n)
{
	int value=999;
	int index;
	for(int i=0;i<n;i++)
	{
		if(key[i]<value && mst[i]==false)
		{
			value=key[i];
			index =i;
		}
	}
	return index;
}
void print(int parent[],int n)
{
	int cost=0;
	cout<<"edge weight \n";
	for(int i=1;i<n;i++)
	{
		cout<<parent[i]+1<<" - "<<i+1<<"-->"<<a[i][parent[i]]<<endl;
		cost = cost+a[i][parent[i]];
	}
	cout<<endl<<"cost is - "<<cost;
}
void prim(int n)
{
	int key[n],parent[n],u;
	bool mst[n];
	for(int i=0;i<n;i++)
	{
		mst[i]=false;
		key[i]=999;
	}
	key[0]=0;
	parent[0]=-1;
	for(int i=0;i<n-1;i++)
	{
		u=min_mst(key,mst,n);
		mst[u]=true;
		for(int j=0;j<n;j++)
		{
			if(a[u][j] && mst[j]==false && a[u][j]<key[j])
			{
				key[j]=a[u][j];
				parent[j]=u;
			}
		}
	}
	print(parent ,n);
}
int main()
{
	int n,x,y,w,e;
	cout<<"enter the number of vertex";
	cin>>n;
	cout<<"enter the number of edges";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cout<<"enter the vertices and weights";
		cin>>x>>y>>w;
		a[x-1][y-1]=a[y-1][x-1]=w;
	}
    prim(n);
}
