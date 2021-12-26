#include<iostream>
#include<cstdlib>
using namespace std;
void insert(int);
void output();
void insertin(int,int);
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
		node* temp=head;
	if(temp==NULL){
		newnode->next=head;
		head=newnode;
		head->next=head;
	}
	else{
	while(temp->next!=head){
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
k++;
}
void deletee(int x){
node* temp=head;
node* prev;
	prev=temp;
	temp=temp->next;
while(prev->next!=head){
	if(temp->data==x){
		prev->next=temp->next;
		free(temp);
		return;
	}
	else{
			prev=temp;
	temp=temp->next;
	}
}
	if(temp->data==x){
		prev->next=temp->next;
		head=temp->next;
		free(temp);
		return;
	}
	else{
		cout<<"Element does not exist: "<<endl;
	}	
}
void insertin(int x,int y){
	node* temp=head;
	node* newnode=new node();
	newnode->data=x;
	int l=0;
	while(temp->next!=head){
		l++;
		if(temp->data==y){
		newnode->next=temp->next;
		temp->next=newnode;
		return;			
		}
		else{
			temp=temp->next;
		}
			}
if(temp->data==y){
	newnode->next=temp->next;
	temp->next=newnode;
}
else{
	cout<<"NO such element is found: "<<endl;
}		
}
void output(){
	node* temp=head;
	while(temp->next!=head){
					cout<<temp->data<<endl;
							temp=temp->next;
	}
			cout<<temp->data<<endl;
}
void search(int x){
	node* temp=head;
	int l=0;
	while(temp->next!=head){
		l++;
		if(temp->data==x){
			cout<<"Element is at "<<l<<" position"<<endl;
			return;
		}
		else{
			temp=temp->next;
		}
			}
		l++;
		if(temp->data==x){
			cout<<"Element is at "<<l<<" position"<<endl;
			return;
		}
		else{
cout<<"No element exist "<<endl;
		}		
}
int main(){
	head=NULL;
	int n;
	char another;
	int op;
	cout<<"Enter the number of element you want to add: ";
	cin>>n;
	while(n!=0){
		int x;
		cin>>x;
		insert(x);
		n--;
	}
	do{
	cout<<"Enter your option: ";
	cin>>op;
	switch(op){
		case 1:{
			int el,po;
			cout<<"Enter the number you want to add: ";
			cin>>el;
			cout<<"Enter the element after which you want to add: ";
			cin>>po;
			insertin(el,po);
			break;
		}
		case 2:{
			int el;
			cout<<"Enter the element you want to delete: ";
			cin>>el;
			deletee(el);
			break;
		}
		case 3:{
			cout<<"Enter the element: ";
			int el;
			cin>>el;
			search(el);
			
			break;
		}		
	}
	cout<<endl<<"Output: "<<endl;
	output();
	cout<<"Do u want to continue: ";
	cin>>another;
}while(another=='y');	
}
