#include <iostream>



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





class Stack
{
private:
	
	
	Node* top;
	
public:
	Stack()
	{
		top = nullptr;
	}
	
	void push(long element)
	{
		Node* elem = new Node(element);
		
		
		elem->next = top;
		top = elem;
	}
		
	void pop()	
	{
		if(top == nullptr)
		{
			cout<<"Empty stack\n";	
		}	
		else
		{
			Node* ptr = top;
			top = ptr->next;
			delete(ptr); 
		}
	}
		
	void show()
	{
		if(top == nullptr)
			cout<<"Empty stack\n";
		else
		{
			Node* ptr = top;		
			while(ptr)
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
	Stack num;
	
	do
	{
		cout<<"1. Push 2. Pop 3. Show 4. Exit Enter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value to be pushed\n";
				cin>>element;
				num.push(element);
				break;
			}
			case 2:
			{
				cout<<"Value popped\n";
				num.pop();
				break;
			}
			case 3:
			{
				cout<<"Stack: ";
				num.show();
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





