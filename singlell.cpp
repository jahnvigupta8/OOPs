#include<iostream>
using namespace std;
void insert(int);
void output();
void insertin(int ,int );
void deletee(int);
void search(int);
class Node{
	public:
		int data;
		Node* next;
};
Node* head;
static int k = 0;
void insert(int x)
{
	if(k==0)
	{
		Node* newnode = new Node();
		newnode->data = x;
		newnode->next = NULL;
		head = newnode;	
	}
	else
	{
		Node* newnode = new Node();
		newnode->data = x;
		newnode->next = head;
		head = newnode;
	}
	k++;
}
void insertin(int x,int y)
{
	Node* newnode = new Node;
	newnode->data = x;
	Node* temp = head;
	for(int i = 1;i<y-1;i++)
	temp = temp->next;
	newnode->next = temp->next;
	temp->next= newnode;
	k++;
	cout<<"yo";
}
void output()
{
	Node* temp = head;
	for(int i =0;i<k;i++)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
	cout<<"bye";
}
void search(int x)
{
	Node* temp = head;
	int t = 1;
	while(temp->data!= x)
	{
		t++;
		temp = temp->next;
	}
	cout<<"element found at "<<t<<"position";
}
void deletee(int x)
{
	Node* temp = head;
	Node* temp1 ;
	int t = k;
	while(temp->next->data!= x)
	{
		temp = temp->next;
	}
	temp1 = temp->next;
	temp->next=temp1->next;
	delete(temp1);
}
int main(){
	int n;
	int op;
	char another;
	cout<<"Insert the elements: ";
	cout<<"Enter the number of elements: ";
	cin>>n;
	while(n!=0){
		int x;
		cin>>x;
		insert(x);
		n--;
		
	}

	cout<<"Press 1:Insert new element"<<endl<<"Press 2:Delete the element"<<endl<<"Press 3:Search the element"<<endl;
do{
	cin>>op;
	switch(op){
		case 1:{
			int x,po;
			cout<<"Enter the element: ";
			cin>>x;
			cout<<"Enter the position: ";
			cin>>po;
			insertin(x,po);
			break;
		}
		case 2:{
			int del;
			cout<<"Enter the number u want to delete: ";
			cin>>del;
			deletee(del);
			
			break;
		}
		case 3:{
			int ser;
			cout<<"Enter the number u want to search: ";
			cin>>ser;
			search(ser);
			
			break;
		}
	}
		output();
		cout<<"DO U WANT TO CONTINUE: ";
		cin>>another;
	}while(another=='y');
	
}




