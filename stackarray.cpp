#include<iostream>
using namespace std;
static int a[20];
static int k =0;
void push(int x)
{
	if(k==19)
	{
		cout<<"stack owerflow";
	}
	else
		{
			a[k]=x;
			k++;
		}
}
void pop()
{
	if(k==0)
	cout<<"stack is empty";
	else
	{
		k--;
		cout<<a[k];
    }
}
void display()
{
	for(int i =0;i<k;i++)
	{
		cout<<a[i]<<endl;
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
	 					cout<<"Enter the element u want to add: "<<endl;
	 					cin>>el;
	 					push(el);
	 					display();
						break;
						
					 }
				 case 2:
					 {
		 				pop();
		 				display();
						break;
					 }

			 }
			cout<<"do u want to continue .... if yes press y "<<endl;	 
	 		cin>>z;
	 
	}while(z=='y');
}
