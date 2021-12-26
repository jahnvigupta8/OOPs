#include<iostream>
#include<cstdlib>
using namespace std;
void push(int);
void pop();
void display();
class node
{
	public:
		int data ;
		node* next;
};
node* head;
static int l = 1;
void push(int x)
{
	node* newnode = new node();
	newnode->data=x;
	newnode->next=head;
	head=newnode;
	l++;
}
void pop()
{
	if(l==1)
	{
		return;
	}
	else
	{
		node* temp = head;
		head=temp->next;
		free(temp);
		l--;
		return;		
	}
}
void display()
{
	node* temp = head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}
main()
{
	head=NULL;
	int  op;
	char another;
	cout<<"press 1 for inserting into stack : "<<endl<<"pree 2 for deleting the element in a stack : "<<endl;
	do
	{
		cout<<"enter your option : ";
		cin>>op;
		switch(op)
		{
			case 1:
				{
					int el;
					cout<<"enter the element you want to insert : ";
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
		cout<<"do you want to continue : ";
		cin>>another;
	}
	while(another=='y');
	display();
}
