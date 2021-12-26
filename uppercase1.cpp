#include<iostream>
#include<string.h>
using namespace std;
class String
{
	private:
		int len;
		char *str;
	public:
		void getString();
		void setString();
		String concating(String);
};
void String::setString()
{
	cout<<endl<<"**enter lenght**";
	cin>>len;
	str = new char[len+1];
	
	
	cout<<endl<<"**enter String**";
	cin.ignore();
	cin.getline(str,len+1);
}
void String::getString()
{
	cout<<endl<<"String entered :"<<str;
}
String String::concating( String s2 )
{ 
	String s3;
	int i,j;
	s3.len=len + s2.len;
	s3.str=new char[s3.len+1+1];
	for(i=0;str[i] !='\0';i++)
	{
		str[0] = toupper(str[0]);
		s3.str[i]=str[i];
	}
	s3.str[i]=' ';
	i++;
	for(j=0;s2.str[j] !='\0';i++,j++)
	{
		s2.str[0] = toupper(s2.str[0]);
		s3.str[i]=s2.str[j];
	}
	s3.str[i]='\0';
	//s3.str[0] = toupper(str[0]);
	return s3;
}
main()
{
	String s1,s2,s3;
	s1.setString();
	s1.getString();
	s2.setString();
	s2.getString();
	s3=s1.concating(s2);
	s1.getString();
	s2.getString();
	s3.getString();
}

