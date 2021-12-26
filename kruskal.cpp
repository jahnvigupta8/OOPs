#include<iostream>
using namespace std;
int v[6];
struct graph
{
	int a,b;
	int w;
};
int parent(int v[] , int i)
{
	while(v[i]!=i)
	{
		v[i]= v[v[i]];
		i=v[i];
	}
	return i;
}
void join(int s , int t , int v[])
{
	int m = v[s];
	int n = v[t];
	v[n]=v[m];
}
int main()
{
	cout<<"enter the number of edges and vertices "<<endl;
	int edges,vertices,cost=0;;
	cin>>edges>>vertices;
	struct graph G[edges];
	for(int i=0;i<edges;i++)
	{
		cout<<endl<<"enter the 2 vertices "<<endl;
		cin>>G[i].a>>G[i].b;
		cout<<"enter the weight of the edge ";
		cin>>G[i].w;
	}
	for(int i=0;i<edges;i++)
	{
		for(int j=i+1;j<edges;j++)
		{
			if(G[i].w>G[j].w)
			swap(G[i],G[j]);
		}
		cout<<endl;
	}	
	cout<<"vertice 1"<<"\t"<<"vertice 2"<<"\t"<<"weight"<<endl;
	for(int i=0;i<edges;i++)
	{
		cout<<G[i].a<<"\t \t"<<G[i].b<<"\t \t"<<G[i].w<<endl;
	}

	for(int i=0;i<=vertices;i++)
	{
		v[i]=i;
	}
	for(int i=0;i<edges;i++)
	{
		if(parent(v , G[i].a)!=parent(v , G[i].b))
			cost += G[i].w;
			join(G[i].a,G[i].b , v);	
	}
	cout<<endl<<cost;
}

