#include<iostream>
using namespace std;
static int a[20];
static int k =0;
static int l=0;
void enqueue(int x)
{
	if(k==19)
	{
		cout<<"queue overflow";
	}
	else
		{
			a[k]=x;
			k++;
		}
}
void dequeue()
{
	if(k==0)
	cout<<"queue is empty";
	else
	{
		cout<<a[l];
		l++;
    }
}
void display()
{
	for(int i =l;i<k;i++)
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
	 					enqueue(el);
	 					display();
						break;
						
					 }
				 case 2:
					 {
		 				dequeue();
		 				display();
						break;
					 }

			 }
			cout<<"do u want to continue .... if yes press y "<<endl;	 
	 		cin>>z;
	 
	}while(z=='y');
}
