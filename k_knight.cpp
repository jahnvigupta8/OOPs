#include<bits/stdc++.h>
using namespace std;
int c,r;
int cnt=0;
int board[20][20] ;//,new_board[200][200];
int check(int i,int j)
{
    if(board[i][j] == 0)
        return 1;
    else
        return 0;
}
void unplace(int i,int j)
{ 
     board[i][j] = 0;
	  if(i+1 < r && j+2 < c)
                   board[i+1][j+2] = 0;
                if(i+2 < r && j+1 < c)
                    board[i+2][j+1] = 0;
                if(i+1 < r && j-2 >= 0)
                    board[i+1][j-2] = 0;
                if(i+2 < r && j-1 >= 0)
                    board[i+2][j-1] = 0;
                if(i-1 >= 0 && j+2 < c)
                    board[i-1][j+2] = 0;
                if(i-2 >= 0 && j+1 < c)
                    board[i-2][j+1] = 0;
                if(i-1 >= 0 && j-2 >= 0)
                   board[i-1][j-2] = 0;
                if(i-2 >= 0 && j-1 >= 0)
                   board[i-2][j-1] = 0;
                for(int i=0;i<r;i++)
			    {
			        for(int j=0;j<c;j++)
			        {
			            if(board[i][j] == 1)
			            {
			                if(i+1 < r && j+2 < c && board[i+1][j+2]==0)
			                   board[i+1][j+2] = 2;
			                if(i+2 < r && j+1 < c && board[i+2][j+1]==0)
			                    board[i+2][j+1] = 2;
			                if(i+1 < r && j-2 >= 0 && board[i+1][j-2]==0)
			                    board[i+1][j-2] = 2;
			                if(i+2 < r && j-1 >= 0 && board[i+2][j-1]==0)
			                    board[i+2][j-1] = 2;
			                if(i-1 >= 0 && j+2 < c && board[i-1][j+2]==0)
			                    board[i-1][j+2] = 2;
			                if(i-2 >= 0 && j+1 < c && board[i-2][j+1]==0)
			                    board[i-2][j+1] = 2;
			                if(i-1 >= 0 && j-2 >= 0 && board[i-1][j-2]==0)
			                   board[i-1][j-2] = 2;
			                if(i-2 >= 0 && j-1 >= 0 && board[i-2][j-1]==0)
			                   board[i-2][j-1] = 2;
			            }
			        }
			    }
}
void knight(int s,int f,int k)
{
    if(k == 0)
    {
        cnt++;
        cout<<" board "<<cnt<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j] == 0 || board[i][j] == 2)
                    cout<<" - ";
                else if(board[i][j] == 1)
                    cout<<" K ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return;
    }
    for(int i=s;i<r;i++)
    {
        for(int j=f;j<c;j++)
        {
            if(check(i,j))
            {
                board[i][j] = 1;
                if(i+1 < r && j+2 < c)
                   board[i+1][j+2] = 2;
                if(i+2 < r && j+1 < c)
                    board[i+2][j+1] = 2;
                if(i+1 < r && j-2 >= 0)
                    board[i+1][j-2] = 2;
                if(i+2 < r && j-1 >= 0)
                    board[i+2][j-1] = 2;
                if(i-1 >= 0 && j+2 < c)
                    board[i-1][j+2] = 2;
                if(i-2 >= 0 && j+1 < c)
                    board[i-2][j+1] = 2;
                if(i-1 >= 0 && j-2 >= 0)
                   board[i-1][j-2] = 2;
                if(i-2 >= 0 && j-1 >= 0)
                   board[i-2][j-1] = 2;
                knight(i,j,k-1);
                unplace(i,j);
            }
        }
        f = 0;
    }
}
int main()
{
    int k;
    cout<<"Enter column and row of board : ";
    cin>>c>>r;
    cout<<"Enter number of knights : ";
    cin>>k;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
		{
			board[i][j] = 0;
		}
    }
    knight(0,0,k);
    return 0;
}
