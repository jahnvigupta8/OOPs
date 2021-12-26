#include<iostream>
using namespace std;
int max(int a , int b)
{
	return (a > b)? a : b ;
}
float Knapsack(float w[] , float v[],int n ,float buck,float r[])
{
	float profit  =0;
	float capacity =buck;
	float z[n];
	for(int i=0;i<n;i++)
	{
		z[i]=0.0;
	}
	if(buck==0)
	{
		return 0;
	}
	else
	{
		for(int i=0;i<n;i++)
			{
					if(capacity>0)
					{
						if(capacity>=w[i])
						{
							capacity = capacity-w[i];
							profit = profit + v[i];
							z[n]=w[i];
						}
						else 
						{
							float a = capacity/w[i];
							z[i]=a;
							profit = profit + (a*v[i]);
							return profit;
						}
					}
			}
	}
}
int main()
{
	int n ;
	float bucket;
	cout<<"Enter the number of products";
	cin>>n;
	float v[n],w[n];
	float r[n];
	for(int i=0;i<n;i++)
	{
		cout<<endl<<"Enter the value of "<<i+1<<" element"<<endl;
		cin>>v[i];
		cout<<endl<<"Enter the weight of "<<i+1<<" element"<<endl;
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		r[i]=v[i]/w[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(r[i]<r[j])
			{
				swap(r[i],r[j]);
				swap(v[i],v[j]);
				swap(w[i],w[j]);
			}
		}
	}
	cout<<"Enter the maximum weight of bucket";
	cin>>bucket;
	float pro =	Knapsack(w,v,n,bucket,r);
	cout<<endl<<"maximum profit earned is "<<pro;
	
	
}
