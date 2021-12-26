//X = 3   O = 5    Empty = 2

#include<bits/stdc++.h>
using namespace std;
int arr[9]={0};
int depth=0,level=0,c=0;
int user_input(int val)
{
    if((val>9||val<1) || arr[val-1]!=2)
    {
        cout<<"Enter a valid move\n";
        return -1;
    }
    else
    {
        arr[val-1] = 3;
        return 0;
    }
}
int go(int a)
{
//    cout<<a<<endl;
    arr[a] = 5;
}
int c_win()
{
    for(int i=0;i<3;i++)
    {
        i*=3;
        if(arr[i]*arr[i+1]*arr[i+2] == 27)
            return 1;
        else if(arr[i]*arr[i+1]*arr[i+2] == 125)
            return 0;
        i=i/3;
    }
    for(int i=0;i<3;i++)
    {
        if(arr[i]*arr[i+3]*arr[i+6] == 27)
            return 1;
        else if(arr[i]*arr[i+3]*arr[i+6] == 125)
            return 0;
    }
    if(arr[0]*arr[4]*arr[8] == 27)
        return 1;
    else if(arr[0]*arr[4]*arr[8] == 125)
        return 0;
    else if(arr[2]*arr[4]*arr[6] == 27)
        return 1;
    else if(arr[2]*arr[4]*arr[6] == 125)
        return 0;
    else
        return -1;
}
void display()
{
    for(int i=0;i<9;i++)
    {
        if(i % 3 == 0 && i != 0)
            cout<<endl<<"___|___|___"<<endl;
        if(arr[i] == 2)
            cout<<" _ |";
        else if(arr[i] == 3)
            cout<<" X |";
        else
            cout<<" O |";
    }
}
int static_eval(int turn)
{
    int X[9],O[9],val=0,cntO=0,cntX=0;
    for(int i=0;i<9;i++)
    {
        X[i] = -1;
        O[i] = -1;
    }
    for(int i=0;i<9;i++)
    {
        if(arr[i] == 5)
            O[cntO++] = i;
        else if(arr[i] == 3)
            X[cntX++] = i;
    }
    if(c_win() == 0)
    {
        if(turn == 1)
            return 100;
        else
            return -100;
    }
    else if(c_win() == 1)
    {
        if(turn == 1)
            return -100;
        else
            return 100;
    }
//    if(c_win() == 0)
//        return 100;
//    else if(c_win() == 1)
//        return -100;
    for(int i=0;i<cntO;i++)
    {
        
        if(O[i] == 4)
            val+=4;
        else if(O[i] == 0 || O[i] == 2 || O[i] == 6 || O[i] == 8)
            val+=3;
        else if(O[i] == 1 || O[i] == 3 || O[i] == 5 || O[i] == 7)
            val+=2;
    }
    for(int i=0;i<cntX;i++)
    {
        
        if(X[i] == 4)
            val-=4;
        else if(X[i] == 0 || X[i] == 2 || X[i] == 6 || X[i] == 8)
            val-=3;
        else if(X[i] == 1 || X[i] == 3 || X[i] == 5 || X[i] == 7)
            val-=2;
    }
    if(turn == 1)
        return val;
    else
        return -val;
}
int min_max(int depth,int turn)
{
    int MoveList[9];
	int MoveCount = 0;
	int bestScore = -9999999;
	int score = -9999999;
	int bestMove = -1;
	int Move;
	int index;
    
    if(depth < 1)
        return(static_eval(turn));
    
    for(index = 0; index < 9; ++index) {
		if( arr[index] == 2) {
            MoveList[MoveCount++] = index;
//            cout<<index<<endl;
		}
	}
    if(MoveCount == 0)
    {
        if(turn == 1)
        {
            if(c_win() == 0)
            {
				bestScore = 100;
				c++;
			}
            else if(c_win() == 1)
            {
				bestScore = -100;
				c++;
			}
        }
        else
        {
            if(c_win() == 0)
                {
					bestScore = -100;c++;
				}
            else if(c_win() == 1)
                {
					bestScore = 100;c++;
				}
        }
        if(c == 0)
            bestScore = 0;
    }
    for(index = 0; index < MoveCount; ++index) {
		Move = MoveList[index];
//        cout<<"Move: "<<Move<<endl;
        if(turn == 1)
		  arr[Move] = 5;
        else
            arr[Move] = 3;
		level++;
		score = -min_max(depth-1, !turn);
		if(score > bestScore) {			
			bestScore = score;	
			bestMove = Move;
		}
		arr[Move] = 2;
        level--;
//        cout<<"Best Move : "<<bestMove<<endl;
	}
    if(level!=0)
		return bestScore;	
	else 
		return bestMove;
}
int board_empty()
{
    for(int i=0;i<9;i++)
    {
        if(arr[i] == 2)			
            return 1;
    }
    return 0;
}
int main()
{
    int pos,z;
    cout<<endl<<"Press 1 to play first else Press 0 to play second : ";
    cin>>z;
	cout<<"Enter the depth : ";
    cin>>depth;
    for(int i=0;i<9;i++)
        arr[i] = 2;
    //Chance == 1 for computer and Chance == 0 for user   X for user O for computer
    int turn,test;
    if(z == 1)
        turn = 0;
    else
        turn = 1;
    int done=0;
    display();
    cout<<endl<<endl;
    while(done==0)
    {
        if(turn == 0)
        {
            cout<<"Enter position : ";
            cin>>pos;
            test=user_input(pos);
            while(test)
            {
                cout<<"Enter position : ";
                cin>>pos;
                test=user_input(pos);
            }
            display();
            cout<<endl<<endl;
            turn = 1;
        }
        else
        {
            go(min_max(depth,turn));
            display();
            cout<<endl<<endl;
            turn = 0;
        }
        
        if(c_win() == 0 || c_win() == 1)
        {
            done = 1;
            if(c_win() == 0)
                cout<<endl<<"Computer Won";
            else
               cout<<endl<<"User Won"; 
            break;
        }
        
        if(!board_empty())
        {
            done = 1;
            cout<<endl<<"It's a Draw";
        }
        
    }
    return 0;
}
