#include<iostream>
#include<cstdlib>
using namespace std;
void push(int );
void pop();
void display();
class node{
	public:
		int data;
		node* next;
	
};
node* head;
static int k=0;
int main(){
	 head=NULL;
	 int op;
	 char another;
	 cout<<"Press 1 for insertion"<<endl<<"Press 2 for deletion"<<endl;
	 do{
	 cout<<"Enter your option!!!!!"<<endl;
	 cin>>op;
	 switch(op){
	 	case 1:{
	 		int el;
	 		cout<<"Enter the element u want to add: ";
	 		cin>>el;
	 		push(el);
	 		display();
			break;
		 }
		 case 2:{
		 	pop();
		 	display();
			break;
		 }
	 }
	 cout<<"Do u want to continue: ";
	 cin>>another;
}while(another=='y');
	 display();

}
void push(int x){
	node* newnode=new node();
	newnode->data=x;
	if(k==0){
		newnode->next=head;
		head=newnode;
	}
	else{
	newnode->next=head;
	head=newnode;
	}
	k++;
	
}
void pop(){
	node* temp=head;
	if(k==0){
	cout<<"No element is present in this: "<<endl; 
	}
	else{
	node* prev;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;	
	k--;
	/*head=temp->next;
	free(temp);*/
}
}
void display(){
	node* temp=head;
	while(temp->next!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}
