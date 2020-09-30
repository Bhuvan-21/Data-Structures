#include <iostream>
#include <string>

#define Max_size 1000

using namespace std;

class Queue
{
private:
	long arr[Max_size];
	long front, rear;
	
public:
	
	Queue()
	{
		front = 0; 
		rear = 0;
	}
	
	void Insert(long num)
	{
		if(rear == Max_size)
			cout<<"Queue is full\n";
		else
		{
			
			arr[rear] = num;
			rear++;	
		}
	}
	
	void Delete()
	{
		if(rear == front)
			cout<<"Queue is empty\n";
		else
		{
			front++;
		}
	}
	
	void Show()
	{
		cout<<"Queue has "<<rear-front<<" element(s).\n";
		if(rear > front)
		{
			for(long i = front; i < rear; i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	}
	
	
	
};

int main()
{
	int ch;
	long element;
	Queue num;
	cout<<"Bhuvan Sachdeva 2K19/CO/102\n";
	do
	{
		cout<<"1. Insert 2. Delete 3. Show 4. Exit Enter choice:\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value to be inserted\n";
				cin>>element;
				num.Insert(element);
				break;
			}
			case 2:
			{
				cout<<"Value deleted\n";
				num.Delete();
				break;
			}
			case 3:
			{
				
				num.Show();
				break;
			}
			case 4:
			{
				cout<<"Exiting\n";
				break;
			}
			default:
			{
				cout<<"Invalid choice\n";
				break;
			}
		}
	
	}	while(ch != 4);
	
}
