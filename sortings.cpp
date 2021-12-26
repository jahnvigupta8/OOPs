#include<iostream>
#include<stdlib.h>
using namespace std;
void Linear(int* arr,int& x,int& n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			cout<<"\nElement Found at "<<i+1<<" position ";
			return;
		}
	}
	if(i==n)
		cout<<"\nNo Element found ";
}
void Recursive(int* arr,int& x,int n)
{
	if(n<0)
		{
			cout<<"\nNo Element found ";
			return;
		}
		
	else if(arr[n-1]==x)
		cout<<"\nElement Found at "<<n<<" position ";
	else 
		Recursive(arr,x,n-1);
}
void BS(int low,int high,int& x)
{
	int mid;
	mid=((low+high)/2);
	if(mid==x)
		cout<<"\nElement Found at "<<mid+1<<" position ";	
	else if(x<mid)
		BS(low,mid-1,x);
	else if (x>mid)
		BS(mid+1,high,x);
	
}
void Binary(int* arr,int& x,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
			int temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			}
			
		}
		
	}
	cout<<"\nElements After Sorting: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	BS(0,x,n);
}
void Bubble(int* arr,int& x,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i);j++)
		{
			if(arr[j]>arr[j+1])
			{
			int temp;
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;	
			}
		}
	}
	
}

void Selection(int* arr,int& x,int n)
{
	int smallest;
	for(int i=0;i<n;i++)
	{
		smallest=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[smallest]>arr[j])
				smallest=j;
		}
			int temp;
			temp=arr[i];
			arr[i]=arr[smallest];
			arr[smallest]=temp;	
	}
}
void Insertion(int* arr,int& n)
{
	int key;
	for(int i=1;i<n;i++)
	{
		int k=i;
		key=arr[i];
		for(int j=0;j<i;j++)
		{
			if(key<arr[j])
				{
					while(i>j)
					{
						arr[i]=arr[i-1];
						i--;
					}
					arr[i]=key;
				}
		}

	}	
}
int partition(int* arr,int first,int last)
{
	int pivot;
	pivot=arr[first];
	
	int leftmost,rightmost;
	leftmost=first+1;
	rightmost=last;
	
	char ch='y';
	while(ch=='y')
	{
		while((leftmost<=rightmost)&& (arr[leftmost]<=pivot))
			leftmost++;
			
		while((rightmost>=leftmost)&& (arr[rightmost]>=pivot) )
			rightmost--;
		
		if(rightmost<leftmost)
			ch='n';
		
		else
			{
			int temp;
			temp=arr[leftmost];
			arr[leftmost]=arr[rightmost];
			arr[rightmost]=temp;
			}
	}
			int temp;
			temp=arr[first];
			arr[first]=arr[rightmost];
			arr[rightmost]=temp;
	
	return rightmost;
}
void Quick(int* arr,int first,int last)
{
	int splitpoint;
	if(first<last)
		{
		splitpoint=partition(arr,first,last);
		Quick(arr,first,splitpoint-1);
		Quick(arr,splitpoint+1,last);
		}
	
}

/*void Merge(int& arr,int p,int r)
{
	if(p <r)
	{
	int q=(p+r)/2;
	Merge(arr,0,q);
	Merge(arr,q+1,r);	
			
			{
				int g=q+1;
			int numElements=r-p+1;
			int narr[numElements];
			int k=0;
		
					while((p < q )&& (g < r))
					{
						if(arr[p ]<arr[q])
							narr[k++]=arr[p ++];
						else
							narr[k++]=arr[g ++];
					}
			
			while(p <q)
					narr[k++]=arr[p++];
			
			while(q <r)
					narr[k++]=arr[q++];
					
			for(int i=0;i<numElements;i++)
					arr[i]=narr[i];
			}
	}

}*/
main()
{
	cout<<"Enter the number of elements you want to insert in a Array : ";
	int n,x; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter value : ";
		cin>>arr[i];
	}
	cout<<"\n\n WELCOME  to SORTINGS Section  ";
	int ch;
	do{
		cout<<"\nPress : \n1-Linear Search \n2-Recursive Linear Search\n3-Binary Search\n4-Bubble Sort\n5-Selection Sort\n6-Insertion sort\n7-Quick Sort\n8-Merge Sorting \n9-Exit\nEnter ur choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					cout<<"\nEnter the element u want to searcxh : ";
					cin>>x;
					cout<<"\nLinear Search : " ;
					Linear(arr,x,n);
					break;
			case 2:
					cout<<"\nEnter the element u want to searcxh : ";
					cin>>x;
					cout<<"\nRecursive Linear Search : ";
					Recursive(arr,x,n);
					break;
			case 3:
					cout<<"\nEnter the element u want to searcxh : ";
					cin>>x;
					cout<<"\nBinary Search : ";
					Binary(arr,x,n);
					break;
			case 4:
					cout<<"\nBubble Sort : ";
					Bubble(arr,x,n);
					cout<<"\nElements After Sorting: ";
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					break;
			case 5:
					cout<<"\nSelection Sort: ";
					Selection(arr,x,n);
					cout<<"\nElements After Sorting: ";
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					break;
			case 6:
					cout<<"\nInsertion Sort : ";
					Insertion(arr,n);
					cout<<"\nElements After Sorting: ";
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					break;
			case 7:
					cout<<"\nQuick Sort :  ";
					Quick(arr,0,n-1);
					cout<<"\nElements After Sorting: ";
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					break;
			case 8:
					cout<<"\nMerge Sorting : ";
					//Merge(arr,0,n-1);
					cout<<"\nElements After Sorting: ";
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<" ";
					}
					break;
			case 9:	
					exit(0);
		
		}
		
					
	}while(ch!=9);
}

