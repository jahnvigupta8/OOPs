#include<iostream>
using namespace std;
void intsort(int,int);
void display(int);
static int a[20],b[20];
int main(){
	int n;
	cout<<"Enter the elements u want to add: ";
	cin>>n; 
	for(int i=0;i<n;i++){
		cout<<"Element "<<i+1<<" : ";
		cin>>a[i];
	}
	intsort(n,0);
	display(n);
	
}
void intsort(int x,int y){
if(x==0){
	return;
}
else{
	int j;
	for( j=0;j<y;j++){
		if(b[j]<a[x-1]){
			continue;
		}
		else{
			int i;
			for(i=y;i>j;i--){
				b[i]=b[i-1];
			}
			b[i]=a[x-1];
			break;
		}	
	}
	if(j==y){
		b[y]=a[x-1];
	}	
	intsort(x-1,y+1);	
}	
}
void display(int y){
	for(int j=0;j<y;j++){
		cout<<b[j]<<endl;
	}	
}
