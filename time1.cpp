#include<iostream>
#include<stdlib.h>
using namespace std;
class T24;
class T12
{
	int hr;
	int min; 
    char session;
 public:
    void setTime (int ,int,char);
	void getTime()	;
	friend int Compare(T12,T24);
	
};
void T12 :: setTime (int h1,int m1,char ses)
{
	hr=h1;
	min=m1;
	session=ses;	
}
void T12 ::getTime()
{		
	cout<<"Time : "<<hr<<"/"<<min<<"" <<session;
}

class T24
{
	int hr;
	int min; 
	int second;
 public:
    void setTime(int ,int ,int);
	void getTime();
	friend int Compare(T12,T24);
};
void T24 :: setTime(int h2,int m2,int s2)
{
	hr=h2;
	min=m2;
	second=s2;
}
void T24 :: getTime()
{
	cout<<"Time : "<<hr<<"/"<<min<<" "<<second;
}

main()
{
	int h1,h2,m1,m2,s2,diff;
	char ses;
	T12 t1;
	T24 t2;
	
cout<<endl<<"Enter the time in 12 hours format : ";
cout<<endl<<"Enter hours : ";
cin>>h1;
cout<<endl<<"Enter minutes : ";
cin>>m1;
cout<<endl<<"Enter session : ";
cout<<endl<<"enter a for before noon"<<endl<<"enter p for after noon"<<endl;
cin>>ses;
t1.setTime(h1,m1,ses);

cout<<endl<<"Enter time in 24 hours format : ";
cout<<endl<<"Enter hours : ";
cin>>h2;
cout<<endl<<"Enter minutes : ";
cin>>m2;
cout<<endl<<" enter seconds : ";
cin>>s2;
t2.setTime(h2,m2,s2);

diff=Compare(t1,t2);

cout<<" ****  Difference between the two time is : "<<diff<<" minutes  ****.";

}
int Compare(T12 t1,T24 t2)
{
	 int diff;
	 if(t1.session=='a')
	 {
	 	if(t1.hr!=12)
	 	{
			diff=t2.hr*60-t1.hr*60+t2.min-t1.min;
		}
		else
	 	{
	 		t1.hr=0;
	 		diff=t2.hr*60-t1.hr*60+t2.min-t1.min;
		}	
	 }
	 else if(t1.session=='p')
	 {
	 	if(t1.hr>=1 && t1.hr<12)
	 	{
	 		t1.hr=t1.hr+12;
	 		diff=t2.hr*60-t1.hr*60+t2.min-t1.min;
		}
	 }
	 return abs(diff);
}

