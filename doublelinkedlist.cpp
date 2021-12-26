#include<iostream>
#include<cstdlib>
using namespace std;
void insertlist(int);
void add(int,int);
void output();
int search(int);
void deleteel(int);
class node{
	public:
		int data;
		node* next;
		node* prev;
};
node* head;
static int k=0;
void insertlist(int x){
node* newnode=new node();
if(head==NULL){
newnode->data=x;
newnode->next=head;
	head=newnode;
}
else{
	node* temp=head;
while(temp->next!=NULL){
	temp=temp->next;	
}		
newnode->data=x;
newnode->prev=temp;
temp->next=newnode;
newnode->next=NULL;
}
k++;
}
void output(){
	node* temp=head;
	int i=1;
	while(temp->next!=NULL){
		cout<<"Element "<<i<<" : "<<temp->data<<endl;
		temp=temp->next;
		i++;
	}
	cout<<"Element "<<i<<" : "<<temp->data<<endl;	
}
void add(int x,int p){
	node* temp=head;
	node* newnode=new node();	
	if(p==1){
		newnode->data=x;
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		k++;
	}
	else if(p<=k){
		int i=1;
		while(temp->next!=NULL){
			if(p==i){
		newnode->data=x;
		newnode->next=temp;
		temp->prev->next=newnode;
		newnode->prev=temp->prev;
		temp->prev=newnode;
		k++;
		return;
	}
	else{
		temp=temp->next;
	}
		i++;	
	}
		if(p==i){
		newnode->data=x;
		newnode->next=temp;
		temp->prev->next=newnode;
		newnode->prev=temp->prev;
		temp->prev=newnode;
		k++;
		return;		
}
}
else{
	while(temp->next!=NULL){
	temp=temp->next;	
	}
			newnode->data=x;
newnode->prev=temp;
temp->next=newnode;
newnode->next=NULL;	
}

}
void deleteel(int x){
node* temp=head;
node* pre;
int l=1;
while(temp->next!=NULL){
	if((temp->data==x)&&(l==1)){
		pre=temp;
		head=temp->next;
		free(pre);
		return;
	}
	else if(temp->data==x){
		pre->next=temp->next;
		temp->next->prev=pre;
		free(temp);
		return;
	}
	else{		
	pre=temp;
	temp=temp->next;
	l++;
	}
	}
	if(temp->data==x){
		pre->next=NULL;
		free(temp);	
		return;	
	}
	else{
		cout<<"Element doesn't find in this list!!!"<<endl;
	}
}
int search(int x){
	node* temp=head;
	int i=1;
	while(temp->next!=NULL){
		if(temp->data==x){
			return i;
		}
		else{
			temp=temp->next;
		}
		i++;
	}
	if(temp->data==x){
		return i;
	}
	else{
		cout<<"Element does not found"<<endl;
	}
}
int main(){
	int n;
	int op;
	head=NULL;
	char another;
		cout<<"Enter the number of elements: ";
cin>>n;
int i=1;
	while(n!=0){
		int x;
		cout<<"Enter the value "<<i<<" : ";
		cin>>x;
		insertlist(x);
		n--;
		i++;
	}
	cout<<"Press 1: For inserting the elenemt"<<endl<<"Press 2: For deleting the element"<<endl<<"Press 3: For searching"<<endl;
	do{
	cout<<"Enter your option: ";
	cin>>op;
	switch(op){
		case 1:{
			int po,el;
			cout<<"Enter the element you want to add: ";
			cin>>el;
			cout<<"Enter the position where u want to add: ";
			cin>>po;
			add(el,po);
				break;
		}
		case 2:{
			int e;
			cout<<"Enter the element you want to delete: ";
			cin>>e;
			deleteel(e);	
			break;
		}
		case 3:{
		int el;
		int po;
		cout<<"Enter the element you want to search: ";
		cin>>el;
		po=search(el);	
		if(po<=k){
		cout<<"Element is at "<<po<<" postion"<<endl;	
		}
			break;
		}
}
	output();
	cout<<"Do u want to continue: ";
	cin>>another;
}while(another=='y');
}
