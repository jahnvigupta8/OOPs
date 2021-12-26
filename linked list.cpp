#include<iostream>
using namespace std;
void insert(int);
void output();
void insertin(int ,int );
void deletee(int);
void search(int);
class node{
	public:
		int data;
		node* next;
};
node* head;
static int k=0;
void insert(int x){
	node* newnode=new node();
	newnode->data=x;
	newnode->next=head;
	head=newnode;
	k++;
	
}
void output(){
	node *temp=head;
	while(temp->next!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<temp->data<<endl;
	
}
void insertin(int x,int y){
if(y==1){
	node* newnode=new node();
	newnode->data=x;
	newnode->next=head;
	head=newnode;
	k++;	
}
else if(y<=k){
	int i=0;
	node* temp=head;
	node* prev;
while(temp->next!=0){
	if(i+1==y){
	node* newnode=new node();
	newnode->data=x;
	newnode->next=prev->next;
	prev->next=newnode;
	}
	prev=temp;
	temp=temp->next;
	i++;
}		
}
else{
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;	
	}
	node* newnode=new node();
	newnode->data=x;
	temp->next=newnode;
	newnode->next=NULL;
	
}
	
}

void deletee(int x){
	node* temp=head;
	node* prev;
	while(temp->next!=0){
		if(temp->data==x){
		prev->next=temp->next;	
		}
		prev=temp;
		temp=temp->next;
	}
}
void search(int x){
	node* temp=head;
	int t=0;
	while(temp->next!=NULL){
		t++;
		if(temp->data==x){
			cout<<"It is at "<<t<<" position."<<endl;
		}
		temp=temp->next;
	}
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
