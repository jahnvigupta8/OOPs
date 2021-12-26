#include<iostream>
using namespace std;
int max(int a , int b)
{
	return (a > b)? a : b ;
}
int Knapsack(int w[] , int v[],int n ,int buck)
{
	int c[n+1][buck+1];
	int cost;
	if(n==0 || buck==0)
	return 0;
	for(int i=0;i<=n;i++)
		{
			for(int j =0;j<=buck;j++)
			{
				if(i==0 || j==0)
				c[i][j]=0;
				else if(j>=w[i-1])
				{
					c[i][j] = max(v[i-1] + c[i-1][j-w[i-1]] ,c[i-1][j]);
				}
				else
					c[i][j] = c[i-1][j];		
			}
		}
			for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=buck;j++)
			{
				cout<<c[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<"maximum profit is "<<c[n][buck];			
}
int main()
{
	int n , v[10] , w[10] , knap_cost , bucket;
	cout<<"Enter the number of products";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<endl<<"Enter the value of "<<i+1<<" element"<<endl;
		cin>>v[i];
		cout<<endl<<"Enter the weight of "<<i+1<<" element"<<endl;
		cin>>w[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(w[i]>w[j])
			{
				swap(v[i],v[j]);
				swap(w[i],w[j]);
			}
		}
	}
	cout<<"Enter the maximum weight of bucket";
	cin>>bucket;
	Knapsack(w,v,n,bucket);
	
	
}
