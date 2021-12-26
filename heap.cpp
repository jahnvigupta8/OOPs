#include<iostream>
using namespace std;
void heapify(int a[],int ,int);
void heapsort(int a[],int);
void display(int a[],int );
void insert(int a[],int i,int data )
{ 
	a[i-1]=data;
		cout<<"yo"<<endl;
		i--;
	while(i > 0 && a[(i-1)/2] < data)
		{
			a[i]=a[(i-1)/2];
			i=((i-1)/2);
			cout<<"drgvrb"<<endl;

	}
a[i]=data;
}
void deleteEl(int a[],int i)
{ 
	i=i-1;
	swap(a[0],a[i]);
	heapify(a,i,0);
	
}

int main(){
	cout<<"\n Enter the elments ";
	int e;
	cin>>e;
	int a[50];
	for(int i=0;i<e;i++){
		cin>>a[i];
	}
	for(int i=(e/2)-1;i>=0;i--){
		heapify(a,e,i);
	}
	cout<<"\n Before insertion heap : ";
	display(a,e);
	e++;
	insert(a,e,44);
	cout<<"\n After insertion heap: ";
		display(a,e);
			cout<<" \n After deletion heap: ";
		deleteEl(a,e);
		e=e-1;
				display(a,e);

	
}

/*	for(int i=(n/2)-1;i>=0;i--){
		heapify(a,n,i);*/
void heapify(int a[],int n,int pos){
	int l=2*pos+1;
	int r=2*pos+2;
	int large=pos;
	if(a[large]<a[l]&&l<n){
		large=l;
	}
		if(a[large]<a[r]&&r<n){
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
