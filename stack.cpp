#include <iostream>

#define msize 1000

using namespace std;

class Stack
{
private:
	
	long arr[msize];
	long top;
	
public:
	Stack()
	{
		top = -1;
	}
	
	void push(long element)
	{
		
		if(top == msize-1)
		{
			cout<<"Size overflow\n";
		}
		else
		{	
			arr[top+1] = element;
			top++;
		}
	}
		
	void pop()	
	{
		if(top == -1)
		{
			cout<<"Empty stack\n";	
		}	
		else
		{
			top--;
		}
	}
		
	void show()
	{
		if(top == -1)
			cout<<"Empty stack\n";
		else
		{
					
			for(long i = 0; i <= top; i++)
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
	Stack num;
	cout<<"Bhuvan Sachdeva 2K19/CO/102\n";
	do
	{
		cout<<"1. Push 2. Pop 3. Show 4. Exit Enter choice:\n";
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





