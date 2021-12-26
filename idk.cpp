#include<iostream>
using namespace std;
class student 
{
   private:
    int rno;
   	char name[20];
   	int marks[5];	
   	int total;
   	float avg;
   	void calctotal();
   public:
   	void setdata();
   	void getdata();
   	int gettotal();
   	float getavg();
} ;

void student :: calctotal()
{
		total=0;
		int i;
		for(int i=0;i<5;i++)
			{
	   			total+=marks[i];
	   		}
	
}
void student :: setdata()
{
	cout<<"enter roll number";
	cin>>rno;
	cout<<"enter name ";
	cin>>name;
	int i;
	for(int i=0;i<5;i++)
	{
		cout<<"enter marks in "<<i+1<<"subject = ";
		cin>>marks[i];
	}
}
void student :: getdata()
{
cout<<endl<<"*****DATA*****";
cout<<endl<<"roll number "<<rno;
cout<<endl<<"Name "<<name;
int i;
for(int i=0;i<5;i++)
	{
		cout<<endl<<"marks in "<<i+1<<"subject = "<<marks[i];
	}	
}
int student :: gettotal()
{
	calctotal();
	return total;
}
float student :: getavg()
{
	avg = gettotal()/5.0;
	return avg;
}
main()
{
int i;
int temp;
student s[5];
for(int i=0;i<5;i++)
	{
	    s[i].setdata();
	}
  for(i=0;i<5;i++)
	 { 
	   	for(int j=i+1;j<5;j++)
		{
			if(s[i].gettotal()<s[j].gettotal())
			{
				s.temp=s[i];
				s[i]=s[j];
				s[j]=s.temp;
			}
		}
	  } 
    						s[i].getdata();
	    	cout<<"the total marks obtained = "<<s[i].gettotal();
	    	cout<<"the average marks obtained ="<<s[i].getavg();	
}
