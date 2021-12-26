#include<iostream>
#include<algorithm>
using namespace std;
int f[10];
int s[10];
void ASort(int n)
{
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<(n-1);i++)
		{
			if(f[i]>f[i+1])
			{
				swap(f[i],f[i+1]);
				swap(s[i],s[i+1]);
			}
		}
	}
}
int ActivitySelection(int n)
{
	ASort(n);
	int count = 1;
	int finish = f[0];
	for(int i =1;i<n;i++)
	{
		if(finish<s[i])
		{
			finish = f[i];
			count++;
		}
	}
	return count;
}
int main()
{
	int a,n;
	cout<<"***ACTIVITY SELECTION***"<<endl;
	cout<<"ENTER THE NUMBER OF PROCESSES ";
	cin>>n;
	cout<<"enter the Start And Finish of the processes"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"process "<<i+1<<" START ";
		cin>>s[i];
		cout<<"process "<<i+1<<" FINISH ";
		cin>>f[i];
		cout<<endl	;
	}
	a = ActivitySelection(n);
	cout<<"NUMBER OF ACTIVITIES IS "<<a;	
}
