#include<iostream>
using namespace std;
int main(){
	int a[1100];
	int in,out;
	char another;
	in=0;
	int count=0;
	out=0;
	int op;
	int n;
	cout<<"Enter the size of queue : ";
	cin>>n;
	cout<<"Press 1 for insert: "<<endl<<"Press 2 for delete: "<<endl;
	do{
		cout<<"Enter your option: "<<endl;
		cin>>op;
		switch(op){
			case 1:{
				cout<<"Enter the element : ";
				int el;
				cin>>el;
				if(in==n){
					if(out==0){
					cout<<"Queue is full: "<<endl;
				}
					
				else{
					in=0;
					a[in]=el;
					in++;
					count++;
				}
			}

				else{
				if(in==out&&count>0){
				cout<<"Queue is full: "<<endl;
			}
			else{
				a[in]=el;
				in++;
				}
			}
				break;
			}
			case 2:{
				if(in==out+1){
					cout<<"Queue is empty: ";
				}else{
				out++;
			}
				break;
			}
		}
		cout<<"Do u want to continue: ";
		cin>>another;
		
	}while(another=='y');
	if(count>0){
		for(int i=out;i<n;i++){
			cout<<a[i]<<endl;
		}
		for(int i=0;i<in;i++){
			cout<<a[i]<<endl;
		}
	}
	else{
		for(int i=out;i<in;i++){
			cout<<a[i]<<endl;
		}
	}	
	
}
