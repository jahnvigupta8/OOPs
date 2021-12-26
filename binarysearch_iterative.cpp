#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the number of elements: ";
cin>>n;
int a[n];
cout<<"Enter the elements: ";
for(int i=0;i<n;i++){
  cout<<"Elements "<<i+1<<" : ";
  cin>>a[i];
}
int nm;
char another;
do{
cout<<"Enter the number you want to search: ";
cin>>nm;
int index,low=0,high=n;
while(low<high){
  int mid=(low+high)/2;
  if(a[mid]<nm){
    low=mid+1;
  }
  else if(a[mid]>nm){
    high=mid;
  }
  else{
      cout<<"Number is found at "<<mid+1<<" position.\n";
      break;
  }
}
if(low>=high){
    cout<<"Number is not found. \n";

}
cout<<"Do u want to continue: ";
cin>>another;}while(another=='y');
}

