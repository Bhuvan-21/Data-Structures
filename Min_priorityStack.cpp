#include <iostream>



using namespace std;

class Node
{
public:
	long val;
    long min_so_far;
	Node* next;
	
	Node(long value, long m)
	{
		val = value;
        min_so_far = m;
        next = NULL;
	}
};





class Stack
{
private:
	
	
	Node* top;
	
public:
	Stack()
	{
		top = NULL;
	}
	
	void push(long element)
	{
        long m;
        if(top == NULL)
        {
            m = element;
        }
        else
        {
            m = get_min() < element ? get_min() : element;
        }
        
		Node* elem = new Node(element, m);
		
		
		elem->next = top;
		top = elem;
	}
		
	void pop()	
	{
		if(top == NULL)
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
		if(top == NULL)
			cout<<"Empty stack\n";
		else
		{
			Node* ptr = top;
            cout<<"Stack: ";		
			while(ptr)
			{
				cout<<ptr->val<<" ";
				ptr = ptr->next;
			}
			cout<<endl;
		}	
	}

    long get_min()
    {
        return top->min_so_far;
    }
};

int main()
{
	int ch;
	long element;
	Stack num;
	
	do
	{
		cout<<"1. Push 2. Pop 3. Show 4. Minimum 5. Exit Enter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value to be pushed: ";
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
				num.show();
				break;
			}
            case 4:
            {
                cout<<"Minimum: "<<num.get_min()<<endl;
                break;
            }
			case 5:
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
	
	}	while(ch != 5);
	
}
