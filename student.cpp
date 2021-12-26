#include<iostream>
#include<iomanip>
using namespace std;
class Student
{
	private:
		int rno;
		char name[10];
		int total;
		float avg;
		int marks[5];
		int calMarks();
	public:
		void getData();
		void setData();
		int getTotal();
		void getAvg();
};
int Student::calMarks()
{
	total=0;
	for(int i=0;i<5;i++)
	{
		total+=marks[i];
	}
	return total;
}
void Student::setData()
{
	cout<<"Enter name : ";
	cin>>name;
	cout<<"Enter Roll No. : ";
	cin>>rno;
	for(int i=0;i<5;i++)
	{
	cout<<"Enter marks in subject "<<i+1<<" :";
	cin>>marks[i];
	}
}
void Student::getData()
{
	cout<<setw(10)<<"\n~~~~~DATA~~~~\n";
	cout<<"\nName : "<<name;
	cout<<"\nRoll No : "<<rno;
	for(int i=0;i<5;i++)
	{
	cout<<"\nMarks in subject "<<i+1<<" : "<<marks[i];
	}
}
int Student::getTotal()
{
	calMarks();
	return total;
}
void Student::getAvg()
{
	float i;
	i=calMarks();
	cout<<"\nAverage Marks : "<<i/5.0;
}
main()
{
	Student s[3];
	for(int i=0;i<3;i++)
	{
		cout<<"Enter detalis of student "<<i+1<<endl;
		s[i].setData();
	}
	for(int i=0;i<3;i++)
	{
		for(int j=i+1;j<3;j++)
		{
			if(s[i].getTotal()<s[j].getTotal())
			{
				Student temp;
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		s[i].getData();
		cout<<"\nTotal Marks : "<<s[i].getTotal();
		s[i].getAvg();
	}
}

