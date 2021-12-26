#include<iostream>
using namespace std;
#include<string.h>
class String
{
	private:
		int len;
		char* str;
	public:
		String()
		{	
			len = 0;
			str = new char[len+1];
			strcpy(str,"");
		}
		String(const char* str)
		{		
			this->len = strlen(str);
			this->str = new char[len+1];
			strcpy(this->str,str);
			cout<<"a";		    	
		}
		String(const String& obj)
		{
			this->len = strlen(obj.str);
			this->str = new char[len+1];
			strcpy(this->str,obj.str);
			cout<<endl<<"b";
		}
		char* getString()
		{
			cout<<endl<<str;
		}		

		String operator++()
		{
			for(int i = 0;i<len;i++)
			{
				if(str[i] >= 'a' && str[i] <= 'z')
				  {
				  	if(str[i]=='z')
				  	 str[i]='a';
				  	else
					 str[i]=str[i]+1;  
				  }
			    else if(str[i] >= 'A' && str[i] <= 'Z')
			        {
				  	  if(str[i]=='Z')
				  	   str[i]='A';
				  	  else
					   str[i]=str[i]+1;  
				    }
			}
			return *this;
		}
        String operator++(int)
		{
			String temp(*this);
			for(int i = 0;i<len;i++)
			{
				if(str[i] >= 'a' && str[i] <= 'z')
				  {
				  	if(str[i]=='.z')
				  	 str[i]='a';
				  	else
					 str[i]=str[i]+1;  
				  }
			    else if(str[i] >= 'A' && str[i] <= 'Z')
			        {
				  	  if(str[i]=='Z')
				  	   str[i]='A';
				  	  else
					   str[i]=str[i]+1;  
				    }
			}
		  return temp;
		}	
};
main()
{
	String s("abc");
	String s1;
	cout<<endl<<"pre increment";
	s1=++s;
	s.getString();
	s1.getString();
	cout<<endl<<"post increment";
	s1=s++;
	s.getString();
	s1.getString();

	
}

