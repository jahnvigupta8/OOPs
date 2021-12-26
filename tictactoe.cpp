#include<iostream>
using namespace std;
int board[9];
int display()
{
	for(int i==0;i<10;i++)
	{
		if(i==3 || i==6)
		{
			cout<<endl
		}
		if(a[i]==2)
		{
			cout<<" "<<" ";
		}
		if(a[i]==3)
		{
			cout<<"X"<<" ";
		}
		if(a[i]==5)
		{
			cout<<"O"<<" ";
		}
	}
}
int Make2()
{
	if(a[4]==2)
	{
		return 4;
	}
	else
	{
		for(int i==1;i<7;i++)
		{
				if(a[i]==2)
				{
					return i;
				}
				i++;
		}				
	}
}
int Posswin(char p)
{
	if(p=='X')
	{
			if(a[0]*a[1]*a[2]==18)
			{
				if(a[0]!=3)
				return 0;
				else if(a[1]!=3)
				return 1;
				else 
				return 2;
			}
			if(a[3]*a[4]*a[5]==18)
			{
				if(a[3]!=3)
				return 3;
				else if(a[4]!=3)
				return 4;
				else 
				return 5;
			}
			if(a[6]*a[7]*a[8]==18)
			{
				if(a[6]!=3)
				return 6;
				else if(a[7]!=3)
				return 7;
				else 
				return 8;
			}
			if(a[0]*a[3]*a[6]==18)
			{
				if(a[0]!=3)
				return 0;
				else if(a[3]!=3)
				return 3;
				else 
				return 6;
			}
			if(a[4]*a[1]*a[7]==18)
			{
				if(a[1]!=3)
				return 1;
				else if(a[4]!=3)
				return 4;
				else 
				return 7;
			}
			if(a[2]*a[5]*a[8]==18)
			{
				if(a[2]!=3)
				return 2;
				else if(a[5]!=3)
				return 5;
				else 
				return 8;
			}
			if(a[0]*a[4]*a[8]==18)
			{
				if(a[0]!=3)
				return 0;
				else if(a[4]!=3)
				return 4;
				else 
				return 8;
			}
			if(a[2]*a[4]*a[6]==18)
			{
				if(a[2]!=3)
				return 2;
				else if(a[4]!=3)
				return 4;
				else 
				return 6;
			}
	}
	if(p=='O')
	{
		if(a[0]*a[1]*a[2]==50)
			{
				if(a[0]!=5)
				return 0;
				else if(a[1]!=5)
				return 1;
				else 
				return 2;
			}
			if(a[3]*a[4]*a[5]==50)
			{
				if(a[3]!=5)
				return 3;
				else if(a[4]!=5)
				return 4;
				else 
				return 5;
			}
			if(a[6]*a[7]*a[8]==50)
			{
				if(a[6]!=5)
				return 6;
				else if(a[7]!=5)
				return 7;
				else 
				return 8;
			}
			if(a[0]*a[3]*a[6]==50)
			{
				if(a[0]!=5)
				return 0;
				else if(a[3]!=5)
				return 3;
				else 
				return 6;
			}
			if(a[4]*a[1]*a[7]==50)
			{
				if(a[1]!=5)
				return 1;
				else if(a[4]!=5)
				return 4;
				else 
				return 7;
			}
			if(a[2]*a[5]*a[8]==50)
			{
				if(a[2]!=5)
				return 2;
				else if(a[5]!=5)
				return 5;
				else 
				return 8;
			}
			if(a[0]*a[4]*a[8]==50)
			{
				if(a[0]!=5)
				return 0;
				else if(a[4]!=5)
				return 4;
				else 
				return 8;
			}
			if(a[2]*a[4]*a[6]==50)
			{
				if(a[2]!=5)
				return 2;
				else if(a[4]!=5)
				return 4;
				else 
				return 6;
			}		
	}
}

