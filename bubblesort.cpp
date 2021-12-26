#include<iostream>
using namespace std;
void bsort(int);
void display(int);
static int a[20];
int main(){
	cout<<"Enter the number of element you want to add: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	bsort(n);
	display(n);
}
void bsort(int x){
	if(x==1){
		return ;
	}
	else{
		for(int i=0;i<(x-1);i++){
			if(a[i]>a[i+1]){
				int t;
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
			
			
		}
		bsort(x-1);
		
	}
	
	
}
void display(int y){
	for(int i=0;i<y;i++){
		cout<<a[i]<<endl;
		
	}
	
	
}
