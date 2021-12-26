#include<iostream>
using namespace std;
int binarysearch(int num,int low,int high,int a[]){
  if(low>=high){
    return -1;
  }
  else{
    int mid=(low+high)/2;
    if(a[mid]<num){
      return binarysearch(num,mid+1,high,a);
    }
    else if(a[mid]>num){
      return binarysearch(num,0,mid,a);
    }
    else{
      return mid;
    }
  }
}
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
int index;
index=binarysearch(nm,0,n,a);
if(index!=-1)
  cout<<"Number is found at "<<index+1<<" position.\n";
else{
    cout<<"Number is not found. \n";

}
cout<<"Do u want to continue: ";
cin>>another;}while(another=='y');
}

