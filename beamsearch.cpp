#include<iostream>
#include<queue>
using namespace std;
int count=0;
queue<int>p;
int v;
int a[10][10];
int r[10];
void BFS(int v, int z[],int h,int d)
{
	while(!p.empty())
	{
		int h =p.front();
		p.pop();
		cout<<endl<<"next : "<<h+1<<endl;
		int ab=d;
		for(int i=0;i<v;i++)
		{
				if(a[h][i] == 1)
				{
				    if(z[i] != 1 && ab!=0)
					{
						cout<<endl<<"Push : "<<i+1<<endl;
						p.push(i);
						z[i]=1;
						r[count]=i+1;
						count++;
						ab--;
					}
				}		
		}
		
	}
}
int main()
{
	int x,y,k,d;
	cout<<"Enter the number of vertices";
	cin>>v;
	cout<<"Enter the number of and edges";
	cin>>x;
	cout<<"Enter the depth ";
	int z[v];
	cin>>d;
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
	
	int s;
	cout<<"Enter the source ";
	cin>>s;
	z[s-1]=1;
	p.push(s-1);
	r[count]=s;
	count++;
	cout<<"hello";
	BFS(v,z,s,d);
	cout<<endl;
	for(int i=0;i<v;i++)
		{
			cout<<r[i]<<" ";
		}
}

