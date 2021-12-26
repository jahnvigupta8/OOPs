#include<iostream>
#include<string.h>
using namespace std;
class Medical
{
	private:
		int rno;
		char name[20];
		int marks;
	public:
		void setRno(int);
		int getRno();
		void setName(char*);
		char* getName();
		void setMarks(int);
		int getMarks();
};
void Medical::setRno(int r)
{
	rno=r;
}
int Medical::getRno()
{
	return rno;
}
void Medical::setName(char *n)
{
	strcpy(name,n);
}
char* Medical::getName()
{
	return name;
}
void Medical::setMarks(int m)
{
	marks=m;
}
int Medical::getMarks()
{
	return marks;
}


class NonMedical
{
	private:
		int rno;
		char name[20];
		int marks;
	public:
		void setRno(int);
		int getRno();
		void setName(char*);
		char* getName();
		void setMarks(int);
		int getMarks();
};
void NonMedical::setRno(int r)
{
	rno=r;
}
int NonMedical::getRno()
{
	return rno;
}
void NonMedical::setName(char *n)
{
	strcpy(name,n);
}
char* NonMedical::getName()
{
	return name;
}
void NonMedical::setMarks(int m)
{
	marks=m;
}
int NonMedical::getMarks()
{
	return marks;
}


void compare(Medical,NonMedical);

main()
{
	Medical mObj;
	NonMedical nObj;
	int r,m;
	char name[20];
	cout<<"Enter Details of Medical Student :"<<endl;
	cout<<"Enter Name : ";
	cin>>name;
	mObj.setName(name);
	cout<<"Enter Roll No : ";
	cin>>r;
	mObj.setRno(r);
	cout<<"Enter Marks : ";
	cin>>m;
	mObj.setMarks(m);
	
	
	cout<<"Enter Details of NonMedical Student :"<<endl;
	cout<<"Enter Name : ";
	cin>>name;
	nObj.setName(name);
	cout<<"Enter Roll No : ";
	cin>>r;
	nObj.setRno(r);
	cout<<"Enter Marks : ";
	cin>>m;
	nObj.setMarks(m);
	compare(mObj,nObj);
}
void compare(Medical mObj,NonMedical nObj)
{
	if(mObj.getMarks()>nObj.getMarks())
	{
		cout<<mObj.getName()<<" secured "<<mObj.getMarks()-nObj.getMarks()<<" marks more than "<<nObj.getName(); 
	}
	else if(mObj.getMarks()<nObj.getMarks())
	{
		cout<<nObj.getName()<<" secured "<<nObj.getMarks()-mObj.getMarks()<<" marks more than "<<mObj.getName(); 
	}
	else
	{
		cout<<nObj.getName()<<" and "<<mObj.getName()<<" secured equal marks .";
	}
}
