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
	meter=m;
	centimeter=cm;	
}
void disMCM :: getDis()
{
	
	cout<<endl<<"distance in meter is : "<<meter;
	cout<<endl<<"distance in centimeter is : "<<centimeter;
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
	feet=f;
	inches=in;	
}
void disFIN :: getDis()
{
	
	cout<<endl<<"distance in feet is : "<<feet;
	cout<<endl<<"distance in inches is : "<<inches;
}
int compare(disMCM dm, disFIN df)
{
		float diff;
		diff=(dm.meter)+(dm.centimeter*(0.01))-(df.feet*(0.3048))-(df.inches*(0.0254));
		if(diff>0)
		{
			return 1;
		}
		else if(diff<0)
		{
			return -1;	
		}
		else
		{
			return 0;
		}
}
main()
{
	float diff;
	int m,cm,f,in;
	disMCM dm;
	disFIN df;

	cout<<endl<<"Enter the distance in MCM : \n";
	cout<<endl<<"Distance in meters are : ";
	cin>>m;
	cout<<endl<<"Distance in centimeters are : ";
	cin>>cm;
	dm.setDis(m,cm);
	cout<<"Enter the distance in FIN : \n";
	cout<<endl<<"Enter feet are : ";
	cin>>f;
	cout<<endl<<"Enter inches are : ";
	cin>>in;
	df.setDis(f,in);
	dm.getDis();
	df.getDis();
	
	float res;
	res = compare(dm,df);
	if(res>0)
		{
			cout<<endl<<" **Distance in disMCM is greater than distance in disFIN **";
		}
		else if(res<0)
		{
			cout<<endl<<"** Distance in disFIN is greater than distance in disMCM **";	
		}
		else
		{
			cout<<endl<<"**Distance in disMCM is equal to distance in disFIN*";
		}

}

