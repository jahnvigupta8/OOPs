#include<iostream>
using namespace std;
int mcm(int p[] , int n)
{
	int m[n+1][n+1];
	int s[n+1][n+1];
	for(int x=0;x<=n;x++)
	{
		for(int y=0;y<=n;y++)
		{
			m[x][y]=0;
			s[x][y]=0;
		}
	}
	for(int l=2;l<(n+1);l++)
	{
		for(int i=1;i<=(n-l+1);i++)
		{
			int j;
			j=i+l-1;
			m[i][j]=9999;
			for(int k=i;k<j;k++)
			{
				int q;
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<m[i][j]<<"\t";
			}
			cout<<endl;
		}	
		cout<<endl<<endl<<endl;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<s[i][j]<<"\t";
			}
			cout<<endl;
		}			
}

int main()
{
	int n , nm ;
	cout<<"enter the number of matrix";
	cin>>n;
	nm = n+1;
	int p[nm];
	for(int i =0;i<nm;i++)
	{
		cout<<endl<<"enter the number of rows in matrix : "<<i+1<<endl;
		cin>>p[i];
	}
	mcm(p,n);
}
