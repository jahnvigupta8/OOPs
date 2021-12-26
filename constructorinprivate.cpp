#include<iostream>
using namespace std;
class Test
{
   int x;
   int y;
   public:
   ~Test()
   {
   	cout<<"Destructor";
   }
    Test(int x , int y )
   {
   	 cout<< "constructor"<<x<<y;
	   }	
};
main()
{
	Test t2(4,5);
}
