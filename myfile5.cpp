#include<fstream>
#include<iostream>
using namespace std;
class Student
{
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
int main()
{
	Student s[3];
	Student t[3];
	fstream out;
	out.open("students.txt",ios::in|ios::out|ios::trunc);
	
	cout<<"\nEnter following info:\n";
	for(int i=0; i<3; i++)
	{
		s[i].setData();
		out.write((char*) &s[i], sizeof(s[i]));
	}
	out.seekg(0);
	cout<<"\nEntered info:\n";
	cout<<"Name\tAge\tHeight";
	for(int i=0; i<3;i++)
	{
		out.read((char*)&t[i],sizeof(t[i]));
		t[i].getData();
	}
	out.close();
}
