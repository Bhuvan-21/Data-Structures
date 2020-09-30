#include <iostream>
#include <string>



using namespace std;

class Node
{
public:
	long val;
	Node* next;
	
	Node(long value)
	{
		val = value;
	}
};



class Queue
{
private:
	Node* front,  rear;
	
public:
	
	Queue()
	{
		front = nullptr; 
		rear = nullptr;
	}
	
	void Insert(long num)
	{
		Node* elem = new Node(num);
		
		
		
	}
	
	void Delete()
	{
		
	}
	
	void Show()
	{
		
	}
	
	
	
};

int main()
{
	int ch;
	long element;
	Queue num;
	
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
