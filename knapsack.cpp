#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
class knapsack{
public:
  double weight;
  double profit;
  double fraction;
  double check;
};
bool mycmp(knapsack a,knapsack b){
  return a.fraction>b.fraction;
}
void knap(knapsack nap[], double w,int i,int n){
  if(i==n||w==0){
    return;
  }
  else{
    if(nap[i].weight<=w){
      nap[i].check=1;
      w=w-nap[i].weight;
    }
    else{
      nap[i].check=w/nap[i].weight;
      w=0;
    }
    knap(nap,w,i+1,n);
  }
}
int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  knapsack nap[n];
  cout<<"Enter the weight & Profit:\n";
  for(int i=0;i<n;i++){
    cin>>nap[i].weight>>nap[i].profit;
    nap[i].fraction=(nap[i].profit/nap[i].weight);
    nap[i].check=0;
  }
  double sack;
  cout<<"Enter the weight of your sack: ";
  cin>>sack;
  sort(nap,nap+n,mycmp);
  knap(nap,sack,0,n);
cout<<"Weight"<<setw(15)<<"Profit"<<setw(15)<<"Fraction"<<setw(15)<<"Fraction_Used"<<endl;
    for(int i=0;i<n;i++){    cout<<nap[i].weight<<setw(15)<<nap[i].profit<<setw(15)<<nap[i].fraction<<setw(15)<<nap[i].check<<endl;
    }
  int i=0;
  cout<<endl;
  double prof;
  while(nap[i].check!=0){
    prof=prof+nap[i].check*nap[i].profit;
    i++;
  }
  cout<<"\nMaximum Profit: "<<prof<<endl;

}
