#include<iostream>
#include<string.h>
using namespace std;
class String2;
class String3;
class String1
{
	private:
		int len;
		char *str;
	public:
		void getString();
		void setString();
		friend void concating(String1 , String2 ,String3);
};
class String2
{
	private:
		int len;
		char *str;
	public:
		void getString();
		void setString();
		friend void concating(String1 , String2 ,String3);
};
class String3
{
	private:
		int len;
		char *str;
	public:
		void getString();
		friend void concating(String1 , String2 ,String3);
};
void String1::setString()
{
	cout<<endl<<"**enter lenght**";
	cin>>len;
	str = new char[len+1];
	cout<<endl<<"**enter String**";
	cin.ignore();
	cin.getline(str,len+1);
}
void String1::getString()
{
	cout<<endl<<"String entered :"<<str;
}
void String2::setString()
{
	cout<<endl<<"**enter lenght**";
	cin>>len;
	str = new char[len+1];
	cout<<endl<<"**enter String**";
	cin.ignore();
	cin.getline(str,len+1);
}
void String2::getString()
{
	cout<<endl<<"String entered :"<<str;
}
void String3::getString()
{
	cout<<endl<<"String entered :"<<str;
}
void concating( String1 s1 , String2 s2 ,String3 s3)
{
	int i,j;
	s3.len=s1.len + s2.len;
	s3.str=new char[s3.len+1+1];
	for(i=0;s1.str[i] !=NULL;i++)
	{
		s3.str[i]=s1.str[i];
	}
	s3.str[i]=' ';
	i++;
	for(j=0;s2.str[j] !='\0';i++,j++)
	{
		s3.str[i]=s2.str[j];
	}
	s3.str[i]='\0';
	//s3.str[0] = toupper(str[0]);
	
}
main()
{
	String1 s1;
	String2 s2;
	String3 s3;
	s1.setString();
	s1.getString();
	s2.setString();
	s2.getString();
	concating(s1,s2,s3);
	s1.getString();
	s2.getString();
	s3.getString();
}
