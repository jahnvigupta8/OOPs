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
		void concatString(string);
};
void String::setString()
{
	cout<<endl<<"**enter lenght**";
	cin>>len;
	str = new char[len+1];
	cout<<endl<<"**enter string**";
	cin.ignore();
	cin.getline(str,len+1);
}
void String::getString()
{
	cout<<endl<<"string entered :"<<str;
}
void String::concatString(string s2)
{
	int length;
	char s3;
	lenght = len+s2.len+2;
	for(int i=0;i<lenght;i++)
	{
		if(i<len);
		s3[i]=s1[i];
		else
		s3[i]=s2[i]
	}
	cout<<"The concatinated string is : "<<s3;
	return s3;
}
main
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

