#include<iostream>
using namespace std;
void heapify(int a[],int ,int);
void heapsort(int a[],int);
void display(int a[],int );
int main(){
	cout<<"Enter the elments ";
	int e;
	cin>>e;
	int a[e];
	for(int i=0;i<e;i++){
		cin>>a[i];
	}
	heapsort(a,e);
	display(a,e);
	
}
void heapsort(int a[],int n){
	for(int i=(n/2)-1;i>=0;i--){
		heapify(a,n,i);
	}
	for(int i=0;i<n;i++){
		int t=a[0];
		a[0]=a[n-i-1];
		a[n-i-1]=t;	
		heapify(a,n-i-1,0);
	}
}
void heapify(int a[],int n,int pos){
	int l=2*pos+1;
	int r=2*pos+2;
	int large=pos;
	if(a[large]>=a[l]&&l<n){
		large=l;
	}
		if(a[large]>=a[r]&&r<n){
		large=r;
	}
	
		if(large!=pos){
				int t;
		t=a[large];
		a[large]=a[pos];
		a[pos]=t;
		heapify(a,n,large);
		
	}
}
void display(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
}

