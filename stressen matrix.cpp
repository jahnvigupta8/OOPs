#include<iostream>
using namespace std;
int main()
{
	int p1,p2,p3,p4,p5,p6,p7,a[2][2],b[2][2],c[2][2];
	cout<<"enter the elements in matrix 1";
	for(int i=0;i<2;i++)
	{
		cout<<endl<<"enter the element in matrix 1 ";
		cin>>a[i][0];
		cout<<endl<<"enter the element in matrix 1 ";
		cin>>a[i][1];
	}
	cout<<endl<<"enter the elements in matrix 2";
	for(int i=0;i<2;i++)
	{
		cout<<endl<<"enter the element in matrix 2 ";
		cin>>b[i][0];
		cout<<endl<<"enter the element in matrix 2 ";
		cin>>b[i][1];
	}
	p1=a[0][0]*(b[0][1]-b[1][1]);
	p2=b[1][1]*(a[0][0]+a[0][1]);
	p3=b[0][0]*(a[1][0]+a[1][1]);
	p4=a[1][1]*(b[1][0]-b[0][0]);
	p5=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	p6=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
	p7=(a[0][0]-a[1][0])*(b[0][0]+b[0][1]);
	c[0][0]=(p4+p5+p6)-p2;
	c[0][1]=p1+p2;
	c[1][0]=p3+p4;
	c[1][1]=(p1+p5)-(p3+p7)	;
	cout<<endl;
	for(int i=0;i<2;i++)
	{
	for(int j=0;j<2;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
}
