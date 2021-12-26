#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct graph{
	int adj[20][20];
	int v;
	int e;
};
void dfs(struct graph* g,int vi,int visited[]){
	if(vi>=g->v){
		return;
	}
	else{
		cout<<vi<<endl;
		visited[vi]=1;
		for(int i=0;i<g->v;i++){
			if(g->adj[vi][i]==1&&visited[i]==0)
			{
				dfs(g,i,visited);
			}
		}		
	}
}
void bfs(struct graph* g,int vi,int visited[]){
	if(vi>=g->v){
		return;
	}
	else{
	visited[vi]=1;
	queue<int>q;
	q.push(vi);
	while(!q.empty()){
		cout<<q.front()<<endl;
	for(int i=0;i<g->v;i++){
			
				if(g->adj[q.front()][i]==1){
					if(visited[i]!=1){
					visited[i]=1;
					q.push(i);
				}
				}
			
			
		}
		q.pop();	
		
	}
}
	
}

int main(){
	struct graph *g=new graph();
	cin>>g->v;
	cin>>g->e;
//	g->adj=malloc(sizeof((g->v)*(g->v)));
	int x,y;

	for(int i=0;i<g->v;i++){
		for(int j=0;j<g->v;j++){
			
			g->adj[i][j]=0;
		}
	}
	for(int i=0;i<g->e;i++){
		cin>>x>>y;
		g->adj[y][x]=1;
		g->adj[x][y]=g->adj[y][x];
	}
	int visited[g->v];
	for(int i=0;i<g->v;i++){
		visited[i]=0;
	}
	int v=0;
	dfs(g,v,visited);
	for(int i=0;i<g->v;i++){
		visited[i]=0;
	}
	v=0;
	cout<<endl;
	bfs(g,v,visited);
}


