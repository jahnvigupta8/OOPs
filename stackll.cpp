#include<iostream>
#include<cstdlib>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
};
Node* head;
static int k =0;
void push(int x)
{
	if(k==0)
	{
		Node* newnode = new Node;
		newnode->data =x;
		newnode->next =NULL;
		k++;
		head = newnode;
	}
	else
	{
		Node* temp = head;
		Node* newnode = new Node;
		newnode->data =x;
		newnode->next =NULL;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		k++;
	}
}
void pop()
{
	Node* temp =head;
	Node* temp1;
	while(temp->next->next!=NULL)
	{
		temp= temp->next;
	}
	cout<<"delete"<<temp->next->data<<endl;
	k--;
	temp1 = temp->next;
	temp->next=NULL;
	delete(temp1);
}
void display()
{
	Node* temp = head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
	cout<<temp->data<<endl;
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
