#include<bits/stdc++.h>
using namespace std;
int minmst(int key[],bool mst[],int n)
{
    int value = INT_MAX,ind;
    for(int i=0;i<n;i++)
    {
        if(key[i] < value && mst[i] == false)
        {
            value = key[i];
            ind = i;
        }
    }   
    return ind;
}
void print(int parent[],int n,int cadj[][5])
{
    cout<<"Edge Weight\n";
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]+1<<" - "<<i+1<<" "<<cadj[i][parent[i]]<<endl;
    }
}
void prims(int cadj[][5],int n)
{
    int key[n],parent[n],u;
    bool mst[n];
    for(int i=0;i<n;i++)
    {
        mst[i] = false;
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i=0;i<n-1;i++)
    {
        u = minmst(key,mst,n);
        mst[u] = true;
        for(int j=0;j<n;j++)
        {
            if(cadj[u][j] && mst[j] == false && cadj[u][j] < key[j])
            {
                key[j] = cadj[u][j];
                parent[j] = u;
            }
        }
    }
    print(parent,n,cadj);
}
int main()
{
    int cadj[][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    prims(cadj,5);
}
