//creating max heap using class and this is also known as max priority queue
#include <iostream>
using namespace std;
class heap
{
	private:
		int arr[10];
		int size = 0;
	public:
		void insert(int val)
		{
			if(size<10)
			{
				arr[size] = val;
				heapifyUp();
				size++;
			}
			else
				cout<<"Heap is full.\n";
		}
		int getMin()
		{
			return (arr[0]);
		}
		int extractMin()
		{
			int min = arr[0];
			arr[0] = arr[size-1];
			size--;
			heapifyDown();
		}
		void heapifyUp()
		{
			int currsize = size;
			while(currsize > 0 && arr[(currsize-1)/2] > arr[currsize])
			{
				int temp = arr[currsize];
				arr[currsize] = arr[(currsize-1)/2];
				arr[(currsize-1)/2] = temp;
				currsize = (currsize-1)/2;
			}
		}
		void heapifyDown()
		{
			int index = 0;
			while((arr[index] > arr[2*index+1] || arr[index] > arr[2*index+2]) && index < size)
			{
				if(arr[2*index+1] < arr[2*index+2])
				{
					int temp = arr[index];
					arr[index] = arr[2*index+1];
					arr[2*index+1] = temp;
					index = 2*index+1;
				}
				else
				{
					int temp = arr[index];
					arr[index] = arr[2*index+2];
					arr[2*index+2] = temp;
					index = 2*index+2;	
				}
			}
		}
		void print()
		{
			for(int i =0;i<size;i++)
			cout<<arr[i]<<endl;
		}
};
int main() {
	// your code goes here
	heap h;
	h.insert(9);
	h.insert(0);
	h.insert(8);
	h.insert(2);
	h.insert(1);
	h.insert(7);
	h.print();
	cout<<"Min element : "<<h.getMin()<<endl;
	cout<<"Min element : "<<h.extractMin()<<endl;
	h.print();
	return 0;
}

