#include<iostream>
using namespace std;
void selsort(int);
void display(int);
static int a[20];
int main(){
	int n;
	cout<<"Enter the number of elements u want to add: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	selsort(n);
	display(n);
}
void selsort(int x){
	if(x==1){
		return;
	}
	else{
		int large=0;
		for(int i=0;i<x;i++){
			if(a[large]<a[i]){
				large=i;
			}
			
		}
		int t;
		t=a[large];
		a[large]=a[x-1];
		a[x-1]=t;
		selsort(x-1);
		
	}
	
}
void display(int y){
	for(int i=0;i<y;i++){
		cout<<a[i]<<endl;
		
	}
	
}
