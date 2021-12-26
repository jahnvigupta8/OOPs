#include<iostream>
using namespace std;
static int a[5];
static int rear= 0;
static int front= 0;
static int flag = 0;
static int e = 5;
void push(int x)
{
	if(rear==front&&flag==1)
	{
		cout<<"Queue is full"<<endl;
	}
	else
	{
		a[rear]=x;
		rear = (rear+1)%(e);
		if(rear==front)
		{
			flag=1;
		}
	}
}
void pop()
{
	if(flag==0&&rear==front) 
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		front =(front+1)%(e);
		if(front==0){
			flag = 0;
		}
	}
		
}
int main()
{
	int op;		char z;
	do
	{
		cout<<"Press 1 for insertion"<<endl<<"Press 2 for deletion"<<endl;
		cout<<"Enter your option!!!!!"<<endl;
		cin>>op;
		switch(op)
			 {
	 			case 1:
					 {
	 					int el;
	 					cout<<"Enter the element u want to add: ";
	 					cin>>el;
	 					push(el);
						break;
					 }
				 case 2:
					 {
		 				pop();
						break;
					 }

			 }
			cout<<"do u want to continue .... if yes press y "<<endl;	 
	 		cin>>z;
	 
	}while(z=='y');
}
