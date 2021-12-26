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
	diff=(y*360)+(m*30)+(d);
	return diff;
}
main()
{
	Date d1,d2;
	int n,i;
	
	
	do
	{
		cout<<"\nEnter 1 to set current and past dates.";
		cout<<"\nEnter 2 to get current and past dates.";
		cout<<"\nEnter 3 to get difference between the dates.";
		cout<<"\nEnter 4 to exit.";
		cout<<"\nEnter choice : ";
		cin>>i;
		switch(i)
		{
			case 1:
				cout<<"\nEnter current date :\n";
				d1.setDate();
				cout<<"\nEnter past date :\n";
				d2.setDate();
				break;
			case 2:
				cout<<"\nCurrent ";
				d1.getDate();
				cout<<"\nPast ";
				d2.getDate();
				break;
			case 3:
				n=d1.dateDiff(d2);
				cout<<"\nDifference between the two dates = "<<n;
				break;
			case 4:
				cout<<"\nExiting.....";
				break;
			default :
				cout<<"\nEnter correct choice."	;
		}
	}while(i!=4);
}
