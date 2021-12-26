#include<iostream>
using namespace std;
class Date
{
	private:
		int dd;
		int mm;
		int yy;
	public:
		void setDate();
		void getDate();
		int Diff(Date);
};
void Date::setDate()
{
	cout<<"\n  Enter Day : ";
	cin>>dd;
	cout<<" \nEnter Month : ";
	cin>>mm;
	cout<<" \n Enter Year : ";
	cin>>yy;
}
void Date::getDate()
{
	cout<<" Date :  "<<dd<<":"<<mm<<":"<<yy;
}
int Date::Diff(Date d2)
{
	int y,m,d,diff;
	y=yy-d2.yy;
	m=mm-d2.mm;
	d=dd-d2.dd;
	diff=d+(m*30)+(y*360);
	return diff;
}
main()
{
	Date d1,d2;
	int n;
	cout<<"\n  Enter the current date : \n";
		d1.setDate();
	cout<<"\n Enter the past date :\n";
		d2.setDate();
	cout<<"\n The Current date is :";
		d1.getDate();
	cout<<"\n The Past date is : ";
		d2.getDate();	
	n=d1.Diff(d2);
	cout<<"\n The Difference between the two dates in terms of days are = "<<n;
}
				
