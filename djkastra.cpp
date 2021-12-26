#include <bits/stdc++.h> 
#define siz 100004 
using namespace std; 
const int m =  2e9; 
vector<pair<int , int> > v[siz]; 
multiset<pair<long long,int> >s; 
multiset<pair<long long ,int > >:: iterator itr;
 long long dis[siz],w; 
bool visit[siz];

 int main() 
{     
int i,j,a,b,t,start,end,edge,node;     
cout<<"Enter the number of nodes and edges"<<endl;     
cin>>node>>edge;
    cout<<"Enter the start Vertex"<<endl;     
cin>>start;
          cout<<"Enter the edges and weights"<<endl;             
for( i = 0 ;i < edge ; i++)                 
{           
          cin>>a>>b>>w;  
                  v[a-1].push_back(make_pair(b-1,w));                          
v[b-1].push_back(make_pair(a-1,w));   
             }              
start--;
     dis[start] = 0;     
for(i = 0; i < node ; i++)         
    if( i != start)             
    dis[i] = m;             
for(i = 0 ;i<node;i++)         
    visit[i] = false;         
s.insert(make_pair(0,start));             
while(!s.empty())                 
{                 
itr = s.begin();       
      int x = (*itr).second;         
            long long y = (*itr).first;         
        s.erase(*itr);       
          if(visit[x]==false)    
         {                 
visit[x] = true;        
     for(i = 0 ;i < v[x].size();i++)
{     
                 long long int temp1 = v[x][i].first;     
                int temp2 = v[x][i].second;
                     if(dis[temp1] > dis[x]+temp2)
{           
                  dis[temp1]=dis[x]+temp2;            
                 s.insert(make_pair(dis[temp1],temp1));                  
           }               
  
    }         


        }     
}
 cout<<"shortest path to all other nodes"<<endl;   
  for(i=0;i<node;i++)        
 cout<<dis[i]<<" ";
    cout<<endl; 
 return 0;     
}

