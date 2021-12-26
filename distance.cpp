#include<iostream>
using namespace std ;
class disFIN;
class disMCM
{
	 	int meter;
    	int centimeter;
	public: 
		void setDis(int,int);
	 	void getDis();
	 	friend int compare(disMCM , disFIN);
};
void disMCM :: setDis(int m,int cm)
{
	m = meter;
	cm = centimeter;	
}
void disMCM :: getDis()
{
	
	cout<<endl<<"distance in meter is : "<< meter;
	cout<<endl<<"distance in centimeter is : "<< centimeter;
}
class disFIN
{
	 	int feet ;
    	int inches;
	public: 
		void setDis(int,int);
	 	void getDis();
	 	friend int compare(disMCM , disFIN);
};
void disFIN :: setDis(int f,int in)
{
	f=feet;
	in=inches;	
}
void disFIN :: getDis()
{
	
	cout<<endl<<"distance in feet is : "<< feet;
	cout<<endl<<"distance in inches is : "<< inches;
}
main()
{
	float diff;
	int m,cm,f,in;
	disMCM dm;
	disFIN df;

	cout<<endl<<"Enter the distance in MCM : \n";
	cout<<endl<<"Enter meters are : ";
	cin>>m;
	cin.ignore();
	cout<<endl<<"Enter centimeters are : ";
	cin>>cm;
	cin.ignore();
	dm.setDis(m,cm);
	dm.getDis();

	cout<<endl<<"Enter feet are : ";
	cin>>f;
	cin.ignore();
	cout<<endl<<"Enter inches are : ";
	cin>>in;
	cin.ignore();
	df.setDis(f,in);
	df.getDis();
	
	float res;
	res = compare(dm,df);
	if(res>0)
			cout<<endl<<" **Distance in disMCM is greater than distance in disFIN **";
	else if(res<0)
			cout<<endl<<"** Distance in disFIN is greater than distance in disMCM **";	
	else
			cout<<endl<<"**Distance in disMCM is equal to distance in disFIN*";
}
int compare(disMCM dm, disFIN df)
{
		float diff;
		diff=(dm.meter)+(dm.centimeter*(0.01))-(df.feet*(0.3048))-(df.inches*(0.0254));
		if(diff>0)
		{
			cout<<endl<<" **Distance in disMCM is greater than distance in disFIN **";
			return 1;
		}
		else if(diff<0)
		{
			cout<<endl<<"** Distance in disFIN is greater than distance in disMCM **";
			return -1;	
		}
		else
		{
			cout<<endl<<"**Distance in disMCM is equal to distance in disFIN*";
			return 0;
		}
}
