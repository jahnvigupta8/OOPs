#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
class Student
{	public:
		char name[20];
		int rno;
		float age;

		void setData()
		{
			cout<<endl;
	
			cout<<"Name : "; 	cin>>name;
			cout<<"RNO: ";		cin>>rno;
			cout<<"Age: ";		cin>>age;
		}
		void updateData()
		{
			cout<<endl;
			cout<<"Name : "; 	cin>>name;
			cout<<"Age: ";		cin>>age;
		}
		void getData()
		{
			cout<<"\n"<<setw(15)<<name<<setw(10)<<rno<<setw(10)<<age;
		}
};
void add();
void show();
void update(int);
void del(int);
void delfile();
void search(int);
int main()
{
	int ch;
	do
	{
		cout<<"\n";
		cout<<"\nEnter 1 to add";
		cout<<"\nEnter 2 to view";
		cout<<"\nEnter 3 to update";
		cout<<"\nEnter 4 to delete";
		cout<<"\nEnter 5 to search";
		cout<<"\nEnter 6 to exit";
		cout<<"\n\nEnter choice: ";
		cin>>ch;
		int r;
		switch(ch)
		{
			case 1:
				add();
				break;
			case 2:
				show();
				break;
			case 3:
				cout<<"Enter R.No of the student to update: ";
				cin>>r;
				update(r);
				break;
			case 4:
				cout<<"Enter R.No of the student to delete: ";
				cin>>r;
				del(r);
				break;
			case 5:
				cout<<"Enter R.No of the student to search: ";
				cin>>r;
				search(r);
				break;
			case 6:
				exit(0);
			default:
				cout<<"\nIncorrect choice";
		}
	} while(ch != 6);
}
void add()
{
	ofstream out("stu.txt",ios::app);
	cout<<"\nEnter data:\n";
	Student s;
	s.setData();
	out.write((char*)&s, sizeof(s));
	cout<<"\nRecord saved successfully!";
	out.close();
}
void show()
{
	ifstream in("stu.txt");
	Student s;
	if(in.is_open())
	{
		int cnt = 0;
		while(in.read((char*)&s,sizeof(s)))
		{
			cnt++;
			if(cnt == 1)
				cout<<"\n"<<setw(15)<<"Name"<<setw(10)<<"R.No."<<setw(10)<<"Age";
			s.getData();		
		}	
		if(cnt == 0)
		{
			cout<<"\nNo records found!";
		}
		in.close();	
	} 
	else
	{
		cout<<"\nNo records found!";	
	}	
}
void update(int r)
{
	fstream file("stu.txt", ios::in|ios::out);
	fstream temp ("temp.txt", ios::out) ;
	Student s;
	
	int cnt=0;
	
	while(file.read((char*)&s,sizeof(s)))
	{
		if(s.rno==r)
		{
			cnt++;
			s.updateData();				
			temp.write((char*)&s, sizeof(s));		
		}
		else
		{
			temp.write((char*)&s,sizeof(s));
		}
	}
		temp.close();
		file.close();
	if(cnt>0)	
		delfile();
	else
	{
		cout<<"\nNo matching record found!";
		remove( "temp.txt" );
	}	
}
void del(int r)
{
	fstream file("stu.txt", ios::in|ios::out);
	fstream temp ("temp.txt", ios::out) ;
	Student s;
	
	int cnt=0;
	
	while(file.read((char*)&s,sizeof(s)))
	{
		if(s.rno==r)
		{
			cnt++;	
		}
		else
		{
			temp.write((char*)&s,sizeof(s));
		}
	}
		temp.close();
		file.close();
	if(cnt>0)	
		delfile();
	else
	{
		cout<<"\nNo matching record found!";
		remove( "temp.txt" );
	}
}
void search(int r)
{
	ifstream in("stu.txt");
	Student s;
	if(in.is_open())
	{
		int cnt = 0;
		while(in.read((char*)&s,sizeof(s)))
		{
			if(s.rno == r)
			{
				cout<<"\n"<<setw(15)<<"Name"<<setw(10)<<"R.No."<<setw(10)<<"Age";
				cnt++;
				s.getData();
				break;		
			}
		}	
		if(cnt == 0)
		{
			cout<<"\nNo records found!";
		}
		in.close();	
	} 
	else
	{
		cout<<"\nNo records found!";	
	}	
}
void delfile()
{
	if(remove( "stu.txt" ) == 0)
	{	
		int result;
	  	char oldname[] ="temp.txt";
	  	char newname[] ="stu.txt";
		result= rename( oldname , newname );
	  	if ( result == 0 )
	   		cout<<"Record updated successfully!";
	  	else
	   		cout<<"Error updating record!" ;
	}
	else
	    cout<<"\nError updating record!" ;
}
