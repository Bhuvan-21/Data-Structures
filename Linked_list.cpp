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
		next = NULL;
	}
};





class L_list
{
private:

	Node* top;
	int num;
	
public:
	L_list()
	{
		top = NULL;
		num = 0;
	}
	
	void Insert(long element, int pos)
	{
		Node *elem, *ptr = new Node(element);
		
		if(num == 0)
		{
			top = ptr;
			num++;
		}
		else
		{
			elem = top;
			if(pos == 1)
			{
				ptr->next = top->next;
				top->next = ptr;
				num++;
				return;				
			}
			
			while(pos>1)
			{
				//cout<<"##\n";
				elem = elem->next;
				pos--;
			}
			ptr->next = elem->next;
			
			elem->next = ptr;
			num++;
		}
		
		
	}
		
	void Delete(int pos)	
	{
		
		if(top == NULL)
		{
			cout<<"Empty List\n";	
		}
		else if(pos < 0 || pos >= num)
		{
			cout<<"Invalid Position, enter between 0 and "<<num-1<<"\n";	
		}	
		else
		{
			Node *elem = top, *ptr;
			
			if(pos == 0)
			{
				Node *ptr = top;
				top = top->next;
				delete(ptr);
				num--;
				return;
			}
			while(pos>1)
			{
				//cout<<"**\n";
				elem = elem->next;
				pos--;
			}
			ptr = elem->next;
			//cout<<elem->next->val<<endl;
			elem->next = elem->next->next;
			//cout<<elem->val<<endl;
			delete(ptr);
			num--;
		}
	}
		
	void show()
	{
		if(top == NULL)
			cout<<"Empty List\n";
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
	long element, pos;
	L_list num;
	
	do
	{
		cout<<"1. Insert 2. Delete 3. Show 4. Exit Enter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value to be inserted\n";
				cin>>element;
				cout<<"Enter the position\n";
				cin>>pos;
				num.Insert(element, pos);
				break;
			}
			case 2:
			{
				cout<<"Enter the position of the value to be deleted\n";
				cin>>pos;
				num.Delete(pos);
				break;
			}
			case 3:
			{
				cout<<"List: ";
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





