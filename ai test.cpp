#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
queue <int> p;
int close[10];
int open[10];
int adj[10][10];
int arr[10][3],dis[10]={0,0,0,0,0,0,0,0,0,0};
int z[10];
int dest=0,count_display=0;
int cnto =0,cntp=0,value;
void pro()
{
		int h =p.front();
		p.pop();
		z[h]=1;
		int move = h;
		while(dest!=1)
		{
			h=close[cntp-1];
			move=h;
			for(int i=0;i<10;i++)
			{
				if(adj[move][i]==1&&z[i]!=1)
				{	
					open[cnto]=i;
					cnto++;
					z[i]=1;
				}
			}
			int min = 999;
			for(int i=0;i<cnto;i++)
			{
				int c=open[i] , calx;
				calx=abs(arr[c][0]-2) + abs(arr[c][1]-0) ;
				if(calx<min)
				{
					min=calx;
					move=c;	
				}
			}
			close[cntp]=move;
			cntp++;
			if(min==0)
			{
				dest=1;
			//	return;

			}
			int x[cnto-1], p=0;
			for(int k=0;k<cnto;k++)
			{
				if(open[k]==move)
				{
				}
				else
				{
					x[p]=open[k];
					p++;	
				}
			}
			cnto--;
			for(int k=0;k<cnto;k++)
			{
				open[k]=x[k];
			}

		}
}

//int present(int a)
//{
//	for(int i=0;i<cntp;i++)
//	{
//		if(a==close[i])
//		return 1;
//	}
//	return 0;
//}

int present(int a)
{
	for(int i=0;i<cntp;i++)
	{
		if(a==close[i])
		{
			value =i;
			return 1;
		}
		
	}
	return 0;
}

void display()
{
	int qr,reach=0;
	int cn=cntp-1;
	
	while(reach!=1)
	{
		int qr;
		if(present(arr[close[cn]][2]))
		{
			qr= value;
			dis[count_display]=close[cn];
			count_display++;
		}
		cn=qr;
		if(cn==0)
		{
			dis[count_display]=0;
			reach=1;
		}
		
	}
}

//void display()
//{
//	for(int i=(cntp-1);i>=0;i--)
//	{
//		if(arr[close[i]][2]==close[i-1] )
//		{
//			dis[count_display]=close[i];
//			count_display++;
//			
//		}
//		else if (present(arr[close[i]][2]))
//		{
//			dis[count_display]=close[i];
//			count_display++;			
//		}
//		for(int j=0;j<count_display;j++)
//		{
//			if(arr[arr[dis[j]][2]][0]==0 && arr[arr[dis[j]][2]][1]==0 && present(arr[dis[j]][2]))
//			{
//				dis[count_display]=arr[dis[j]][2];
//				return;
//			}
//		}
//		
//	}
//}

int main()
{
	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[0][2] = 0;
	arr[1][0] = 0;
	arr[1][1] = 3;
	arr[1][2] = 0;
	arr[2][0] = 4;
	arr[2][1] = 0;
	arr[2][2] = 0;
	arr[3][0] = 1;
	arr[3][1] = 3;
	arr[3][2] = 2;
	arr[4][0] = 4;
	arr[4][1] = 3;
	arr[4][2] = 2;
	arr[5][0] = 3;
	arr[5][1] = 0;
	arr[5][2] = 1;
	arr[6][0] = 3;
	arr[6][1] = 3;
	arr[6][2] = 5;
	arr[7][0] = 4;
	arr[7][1] = 2;
	arr[7][2] = 6;
	arr[8][0] = 0;
	arr[8][1] = 2;
	arr[8][2] = 7;
	arr[9][0] = 2;
	arr[9][1] = 0;
	arr[9][2] = 8;
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		adj[i][j] = 0;
		close[i]=0;
		open[i]=0;
		z[i]=0;
	}
	adj[5][6] = 1;
	adj[5][6] = 1;
	adj[5][1] = 1;
	adj[1][5] = 1;
	adj[1][4] = 1;
	adj[4][1] = 1;
	adj[3][1] = 1;
	adj[4][2] = 1;
	adj[2][4] = 1;
	adj[7][2] = 1;
	adj[2][3] = 1;
	adj[3][2] = 1;
	adj[2][0] = 1;
	adj[0][2] = 1;
	adj[1][0] = 1;
	adj[0][1] = 1;
	adj[6][7] = 1;
	adj[7][6] = 1;
	adj[7][8] = 1;
	adj[8][7] = 1;
	adj[8][9] = 1;
	adj[7][4] = 1;
	p.push(0);
	close[cntp]=0;
	cntp++;
	pro();
	for (int i=0;i<cntp;i++)
	{
		cout<<endl<<close[i]+1;
	}
	display();cout<<endl;
	for (int i=count_display;i>=0;i--)
	{
		cout<<" Step "<<abs(count_display-i+1)<<" - ";
		cout<<"( "<<arr[dis[i]][0]<<" , "<<arr[dis[i]][1]<<" ) ";
		cout<<endl;
	}
}

