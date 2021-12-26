#include<iostream>
using namespace std;
void Th(int,char,char,char);
static int z=0;
main()
{
	int k;
	char another;
	do
	{
		z=0;
		cout<<"enter the element you want to sort : ";
		cin>>k;
		Th(k,'F','U','T');
		cout<<"total number of steps are "<<z<<endl;
		cout<<"do you want to continue...";
		cin>>another;
	}
	while(another=='y');
}
void Th(int x , char F , char U , char T)
{
	if(x==1)
	{
		cout<<"move disk from "<<F<<"to"<<T<<endl;
		z++;
		return;
	}
	else
	{
		Th(x-1,F,T,U);
		Th(1,F,U,T);
		Th(x-1,U,F,T);
	}
}
