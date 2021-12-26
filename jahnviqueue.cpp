#include<iostream>
using namespace std;
static int a[20];
static int top= 0;
static int bottom= 0;
static int e = 20;
void push(int x)
{
	if(top==19)
	{
		cout<<"stack owerflow";
	}
	else
	{
		a[top]=x;
		top++;
	}
}
void pop()
{
	if(bottom==top) 
	{
		cout<<"stack empty";
	}
	else
	{
	cout<<a[bottom]<<endl;
	bottom++;
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
