#include <iostream>
#include <string>



using namespace std;

class Node
{
public:
	long val;
	Node *next;
	
	Node(long value)
	{
		val = value;
		next = NULL;
		
	}
};



class Queue
{
private:
	int num;
	Node *front,  *rear;
	
public:
	
	Queue()
	{
		num = 0;
		front = NULL; 
		rear = NULL;
	}
	
	void Insert(long val)
	{
		Node* elem = new Node(val);
		if(num == 0)
		{
			front = rear = elem;
			num++;
			return;
		}
		else
		{
			rear->next = elem;
			rear = elem;
			num++;
		}
	}
	
	void Delete()
	{
		if(num == 0)
		{
			cout<<"Empty Queue\n";
			return;
		}
		else
		{
			if(num == 1)
			{
				Node* ptr = front;
				front = rear = NULL;
				delete(ptr);
				num--;
				return;
			}
			else
			{
				Node* ptr = front;
				front = front->next;
				delete(ptr);
				num--;
				return;
			}
		}
	}
	
	void Show()
	{
		if(num == 0)
		{
			cout<<"Empty Queue\n";
			return;
		}	
		else
		{
			Node* ptr = front;
			cout<<"Queue: ";
			for(int i = 0; i < num; i++)
			{
				cout<<ptr->val<<" ";
				ptr = ptr->next;
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
