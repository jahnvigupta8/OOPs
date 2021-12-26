#include<bits/stdc++.h>
using namespace std;
int mindist(bool sp[],int dist[],int n)
{
    int val = INT_MAX,in;
    for(int i=0;i<n;i++)
    {
        if(sp[i] == false && dist[i] < val)
        {
            val = dist[i];
            in = i;
        }
    }
    return in;
}
void print(int dist[],int n)
{
    cout<<"Vertex  Distance from source\n";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<dist[i]<<endl;
    }
}
void sssp(int graph[][9],int n,int v)
{
    int dist[n];
    bool sp[n];
    for(int i=0;i<n;i++)
    {
        sp[i] = false;
        dist[i] = INT_MAX;
    }
    dist[v] = 0;
    for(int i=0;i<n-1;i++)
    {
        int u = mindist(sp,dist,n);
        sp[u] = true;
        for(int j=0;j<n;j++)
        {
            if(graph[u][j] && sp[j] == false && dist[u]+graph[u][j] < dist[j])
            {
                dist[j] = dist[u]+graph[u][j];
            }
        }
    }
    print(dist,n);
}
int main()
{
    int graph[][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    sssp(graph,9,0);
}
