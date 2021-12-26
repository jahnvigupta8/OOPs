#include<iostream>
using namespace std;
int arr[9];
int turn = 0;
int make2()
{
    if(arr[4] == 2)
        return 4;
    else if(arr[1] == 2)
    	return 1;
    else if(arr[3] == 2)
    	return 3;
    else if(arr[5] == 2)
    	return 5;
    else if(arr[7] == 2)
    	return 7;
    else
    {
        for(int i=0;i<9;i++)
        {
            if(arr[i] == 2)
                return i;
        }
    }
}
int posswin(int x)
{
    if(x == 1)
    {
        for(int i=0;i<3;i++)
        {
            i*=3;
            if(arr[i]+arr[i+1]+arr[i+2] == 8)
            {
                for(int j=0;j<3;j++)
                {
                    if(arr[i+j] == 2)
                    {
                        return i+j;
                    }
                }
            }
            i=i/3;
        }
        for(int i=0;i<3;i++)
        {
            if(arr[i]+arr[i+3]+arr[i+6] == 8)
            {
                for(int j=0;j<3;j++)
                {
                    if(arr[i+j*3] == 2)
                     {
                        return i+j*3;
                    }
                }
            }
        }
        if(arr[0]+arr[4]+arr[8] == 8)
        {
            for(int j=0;j<3;j++)
                {
                    if(arr[j*4] == 2)
                     {
                        return j*4;
                    }
                }
        }
        else if(arr[2]+arr[4]+arr[6] == 8)
        {
            if(arr[2] == 2)
                return 2;
            else if(arr[4] == 2)
                return 4;
            else
                return 6;
        }
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            i*=3;
            if(arr[i]+arr[i+1]+arr[i+2] == 12)
            {
                for(int j=0;j<3;j++)
                {
                    if(arr[i+j] == 2)
                        return i+j;
                }
            }
            i=i/3;
        }
        for(int i=0;i<3;i++)
        {
            if(arr[i]+arr[i+3]+arr[i+6] == 12)
            {
                for(int j=0;j<3;j++)
                {
                    if(arr[i+j*3] == 2)
                     {
                        return i+j*3;
                    }
                }
            }
        }
        if(arr[0]+arr[4]+arr[8] == 12)
        {
            for(int j=0;j<3;j++)
                {
                    if(arr[j*4] == 2)
                        return j*4;
                }
        }
        else if(arr[2]+arr[4]+arr[6] == 12)
        {
            if(arr[2] == 2)
                return 2;
            else if(arr[4] == 2)
                return 4;
            else
                return 6;
        }
    }
    return -1;
}
int check_win()
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
int go(int a)
{
    arr[a] = 5;
}
void display()
{
    for(int i=0;i<9;i++)
    {
        if(i % 3 == 0)
            cout<<endl;
        if(arr[i] == 2)
            cout<<" ";
        else if(arr[i] == 3)
            cout<<"X";
        else
            cout<<"O";
    }
}
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
void comp_play(int a)
{
	int pos;
	switch(a)
	{
		case 1:
			go(0);
			break;
		case 2:
			go(make2());
			break;
		case 3:
			if (arr[8] == 2)
                go(8);
            else
                go(2);
            break;
        case 4:
            pos = posswin(1);
            if(pos == -1)
            {
                go(make2());
            }
            else
            {
                go(pos);
            }
            break;
        case 5:
            pos = posswin(1);
            if(pos!= -1)
            {
                go(pos);
                break;
            }
            pos = posswin(0);
			if(pos!=-1)
            {  
                go(pos);
                break;
            }
            if(arr[6] == 2)
            {
                go(6);
                break;
            }
            else
                {go(2);
                break;}
        case 6:
            pos = posswin(0);
            if(pos!=-1)
            {  
                go(pos);
                break;
            }
            pos = posswin(1);
            if(pos!= -1)
            {
                go(pos);
                break;
            }
            else
               { go(make2());
                break;}
        case 7:
            pos = posswin(0);
			if(pos!=-1)
            {  
                go(pos);
                break;
            }
            pos = posswin(1);
            if(pos!= -1)
            {
                go(pos);
                break;
            }
            else
            {
                for(int i=0;i<9;i++)
                {
                    if(arr[i] == 2)
                        {go(i);
                        break;}
                }
                break;
            }
        case 8:
            pos = posswin(0);
            if(pos!=-1)
            {  
                go(pos);
                break;
            }
            pos = posswin(1);
            if(pos!= -1)
            {
                go(pos);
                break;
            }
            else
            {
                for(int i=0;i<9;i++)
                {
                    if(arr[i] == 2)
                        {go(i);
                        break;}
                }
                break;
            }
        case 9:
            pos = posswin(0);
			if(pos!=-1)
            {  
                go(pos);
                break;
            }
            pos = posswin(1);
            if(pos!= -1)
            {
                go(pos);
                break;
            }
            else
            {
                for(int i=0;i<9;i++)
                {
                    if(arr[i] == 2)
                        {go(i);
                        break;}
                }
                break;
            }
	}
}
int main()
{
    int win,check=-1;
    cout<<"Enter 1 to play first or 0 to play second: ";
    int a,test;
    cin>>a;
    int pos;
    for(int i=0;i<9;i++)
    {
        arr[i] = 2;   
    }
    if(a == 1)
    {
        while(turn != 4)
        {
            turn++;
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
            turn++;
            comp_play(turn);
            display();
            cout<<endl<<endl;
        }
        while(turn != 9)
        {
            turn++;
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
            check = check_win();
            if(check != -1)
            {
                if(check == 1)
                    cout<<"User Wins!!!!\n";
                else
                    cout<<"Computer Wins!!!!\n";
                return 0;
            }
            turn++;
            comp_play(turn);
            display();
            cout<<endl<<endl;
            check = check_win();
            if(check != -1)
            {
                if(check == 1)
                    cout<<"User Wins!!!!\n";
                else
                    cout<<"Computer Wins!!!!\n";
                return 0;
            }
        }
    }
    else if(a == 0)
    {
        while(turn != 4)
        {
            turn++;
            comp_play(turn);
            display();
            cout<<endl<<endl;
            turn++;
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
        }
        while(turn != 9)
        {
            turn++;
            comp_play(turn);
            display();
            cout<<endl<<endl;
            check = check_win();
            if(check != -1)
            {
                if(check == 1)
                    cout<<"User Wins!!!!\n";
                else
                    cout<<"Computer Wins!!!!\n";
                return 0;
            }
            turn++;
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
            check = check_win();
            if(check != -1)
            {
                if(check == 1)
                    cout<<"User Wins!!!!\n";
                else
                    cout<<"Computer Wins!!!!\n";
                return 0;
            }
        }
    }
    cout<<"It's a tie!!!!\n";
    return 0;
}
