#include<iostream>
using namespace std;
int a[9];
int X[5];
int O[5];
int mg[9] = {8,3,4,1,5,9,6,7,2};
int turn = 0;
int make2()
{
    if(a[4] == 2)
    {
        return 4;
    }
    else if(a[1] == 2)
	{
    	return 1;
    }
    else if(a[3] == 2)
    {
    	return 3;
    }	
    else if(a[5] == 2)
    {
    	return 5;
    }	
    else if(a[7] == 2)
    {
    	return 7;
    }
    else
    {
        for(int i=0;i<9;i++)
        {
            if(a[i] == 2)
            {
            	return i;
            } 
        }
    }
}
int posswin(int x)
{
    int ct = 0;
    int val;
    if(x == 1)
    {
        for(int i=0;i<9;i++)
        {
            if(a[i] == 3)
            {
                X[ct] = i;
                ct++;
            }
        }
        for(int i=0;i<ct;i++)
        {
            for(int j=i+1;j<ct;j++)
            {
                val = 15-(mg[X[i]]+mg[X[j]]);
                if(val>0 && val<9)
                {
                    for(int k=0;k<9;k++)
                    {
                        if(mg[k] == val && a[k] == 2)
                        {
                            return k;
                        }
                    }
                }
            }
        }
    }
    else if(x == 0)
    {
        for(int i=0;i<9;i++)
        {
            if(a[i] == 5)
            {
                O[ct] = i;
                ct++;
            }
        }
        for(int i=0;i<ct;i++)
        {
            for(int j=i+1;j<ct;j++)
            {
                val = 15-(mg[O[i]]+mg[O[j]]);
                if(val>0 && val<9)
                {
                    for(int k=0;k<9;k++)
                    {
                        if(mg[k] == val && a[k] == 2)
                        {
                            return k;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int check_win()
{
    for(int i=0;i<3;i++)
    {
        i*=3;
        if(a[i]*a[i+1]*a[i+2] == 27)
            return 1;
        else if(a[i]*a[i+1]*a[i+2] == 125)
            return 0;
        i=i/3;
    }
    for(int i=0;i<3;i++)
    {
        if(a[i]*a[i+3]*a[i+6] == 27)
            return 1;
        else if(a[i]*a[i+3]*a[i+6] == 125)
            return 0;
    }
    if(a[0]*a[4]*a[8] == 27)
        return 1;
    else if(a[0]*a[4]*a[8] == 125)
        return 0;
    else if(a[2]*a[4]*a[6] == 27)
        return 1;
    else if(a[2]*a[4]*a[6] == 125)
        return 0;
    else
        return -1;
}
int go(int d)
{
    a[d] = 5;
}
void display()
{
    for(int i=0;i<9;i++)
    {
        if(i % 3 == 0)
            cout<<endl;
        if(i % 3 == 1)
            cout<<"|";   
	    if(i % 3 == 2)
            cout<<"|";		 
        if(a[i] == 2)
            cout<<" ";
        else if(a[i] == 3)
            cout<<"X";
        else
            cout<<"O";
    }
}
int user_input(int val)
{
    if((val>9||val<1) || a[val-1]!=2)
    {
        cout<<"Enter a correct and empty place\n";
		return 0;
	}
	else
	{
	
    	a[val-1] = 3;
    	return 1;
	}
}
void comp_play(int d)
{
	int pos;
	switch(d)
	{
		case 1:
			go(0);
			break;
		case 2:
			go(make2());
			break;
		case 3:
			if (a[8] == 2)
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
            if(a[6] == 2)
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
                    if(a[i] == 2)
                        {
							go(i);
                        	break;
						}
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
                    if(a[i] == 2)
                        {
							go(i);
                        	break;
						}
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
                    if(a[i] == 2)
                        {
							go(i);
                        	break;
						}
                }
                break;
            }
	}
}
int main()
{
    int win,check=-1;
    cout<<"to play first enter 1 or else enter 0 ";
    int chance;
    cin>>chance;
    int pos;
    for(int i=0;i<9;i++)
    {
        a[i] = 2;   
    }
    if(chance == 1)
    {
        turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        turn++;
    	comp_play(turn);
        display();
        cout<<endl;
        turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        turn++;
    	comp_play(turn);
        display();
        cout<<endl;
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	comp_play(turn);
        display();
        cout<<endl;
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	comp_play(turn);
        display();
        cout<<endl;
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    }
    else if(chance == 0)
    {
        turn++;
        cout<<endl<<"Computer Turn";
    	comp_play(turn);
        display();
        cout<<endl;
    	turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
		cout<<endl<<"Computer Turn";
    	turn++;
    	comp_play(turn);
        display();
        cout<<endl;
    	turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	comp_play(turn);
        display();
        cout<<endl;
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	comp_play(turn);
        display();
        cout<<endl;
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	cout<<"Enter position : ";
    	cin>>pos;
    	while(user_input(pos)==0)
    	{
    		cout<<"Enter position : ";
    		cin>>pos;
    	}
        display();
        cout<<endl<<"Computer Turn";
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    	turn++;
    	comp_play(turn);
        display();
        cout<<endl;
        check = check_win();
        if(check != -1)
        {
            if(check == 1)
                cout<<"User Wins"<<endl;
            else
                cout<<"Computer Wins"<<endl;
            return 0;
        }
    }
    else
	{
    	cout<<"Enter correct number ";
		return 0;
	}
	cout<<"It's a tie"<<endl;
    return 0;
}

