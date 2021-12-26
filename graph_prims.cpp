#include<iostream>
using namespace std;

struct graph
{
	int adj[20][20];
	int v;
	int e;
};
void display(struct graph* G)
{
	for(int i=0;i<G->v;i++){
		for(int j=0;j<G->v;j++){
			
			cout<<G->adj[i][j] << " ";
		}
		cout<<endl;
	}
}
int main()
{
	struct graph *G = new graph();
	cout<<" ENTER THE NO OF VERTICES AND EDGES "<<endl;
	cin>>G->v>>G->e;
	int  x, y;
	for(int i=0;i<G->v;i++){
		for(int j=0;j<G->v;j++){
			
			G->adj[i][j]=999;
		}
	}
	cout<<"ENTER THE VERTICES IN BETWEEN EDGE NEEDED"<<endl;
		for(int j=0;j<G->e;j++)
		{
			int wt;
			cin>>x>>y;
			cout<<"enter the weight : ";
			cin>>wt;
			G->adj[x-1][y-1]=wt;
			G->adj[y-1][x-1]=wt;
		}
	display(G)	;
	int visited[20];
	int near[2][20];
	for(int i=0;i<G->v;i++)
	{
		visited[i]=0;
	}
	cost = 0;
	int p,q;
	c=999;
	for(int i=0;i<G->v;i++)
	{
		for(int j=0;j<G->v;j++)
		{
			if(G->adj[i][j]<=c)
			{
				c=G->adj[i][j];
				i=p;
				j=q;
			}
		}
	}
	visited[p]=visited[q]=1;
	cost +=c;
	int a,b
	for(int i =1;i<G->e;i++)	
	{
		for(int j =0;j<G->v;j++)
		{
			near[0][j]=G->adj[p][j];
			near[1][j]=G->adj[q][j];
		}
		int np = nq = 999;
		for(int j=0;j<G->v;j++)
		{
			if(G->adj[p][j]<nc && visited[j]!=1)
			{
				nc = G->adj[0][j];
				
				
			}
			if(G->adj[1][j]<nq && visited[j]!=1)
			{
				nq = G->adj[1][j]
			}
		}	
		if(nc>nq)
		{
			
		}
	}	
}
