#include<fstream>
#include<iostream>
using namespace std;
class Student
{
	public:
		char name[20];
		int age;
		float height;
	public:
		void setData()
		{
			cout<<endl;
			cout<<"Name : "; 	cin>>name;
			cout<<"Age: ";		cin>>age;
			cout<<"Height: ";	cin>>height;
		}
		void getData()
		{
			cout<<"\n"<<name<<"\t"<<age<<"\t"<<height;
		}
};
main()
{
	Student s[3];
	Student t[3];
	fstream out;
	out.open("stud.txt");
	cout<<"\nEnter following info:\n";
	for(int i=0; i<3; i++)
	{
		s[i].setData();
//		out<<s[i].setData();
	out<<s[i].name<<"\t"<<s[i].age<<"\t"<<s[i].height;
	}
	out.close();
		fstream in;
	in.open("stud.txt");
	cout<<"\nEntered info:\n";
	cout<<"Name\tAge\tHeight";
	char uname[20];
	int uage,uheight;
	for(int i=0; i<3;i++)
	{
		in>>uname;	in>>uage;	in>>uheight;
	}
	in.close();
}
