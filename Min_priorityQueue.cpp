#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int v)
    {
        val = v;
        prev = next = NULL;
    }
};

class Deque
{
private:
    int num;
    Node* head;
    Node* rear;

public:
    Deque()
    {
        num = 0;
        head = rear = NULL;
    }

	void Insert(int val)
	{
		while(num != 0 && get_rear() > val)
		{
			Delete_rear(); 
		}
		Insert_rear(val);
		
		return;
	}
	
    void Insert_front(int val)
    {
        Node* elem = new Node(val);
        if(num == 0)
        {
            head = rear = elem;
            num++;
            return;
        }

        elem->next = head;
        head->prev = elem;
        head = elem;
        num++;
        return;
    }

    void Insert_rear(int val)
    {
    	Node* elem = new Node(val);
        if(num == 0)
        {
            head = rear = elem;
            num++;
            return;
        }

        elem->prev = rear;
        rear->next = elem;
        rear = elem;
        num++;
        return;
    }

	

    void Delete_front()
    {
        if(num == 0)
        {
            cout<<"Empty List\n";
            return;
        }
        Node* ptr = head;
        if(num == 1)
        {
            head = rear = NULL;
            delete(ptr);
            num--;
            return;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            delete(ptr);
            num--;
            return;
        }
    }

	void Delete(int val)
	{
		if(val == get_head())
		{
			Delete_front();
		}
	}


    void Delete_rear()
    {
        if(num == 0)
        {
            cout<<"Empty List\n";
            return;
        }
        Node* ptr = rear;
        if(num == 1)
        {
            head = rear = NULL;
            delete(ptr);
            num--;
            return;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
            delete(ptr);
            num--;
            return;
        }
    }

    int get_head()
    {
        return head->val;
    }

    int get_rear()
    {
        return rear->val;
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

	int get_head()
	{
		return front->val;
	}
};

int main()
{
	int ch;
	long element;
	Queue num;
    Deque priority;
	
	do
	{
		cout<<"1. Insert 2. Delete 3. Show 4. Minimum 5. Exit Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value to be inserted: ";
				cin>>element;
				num.Insert(element);
                priority.Insert(element);
				break;
			}
			case 2:
			{
				cout<<"Value deleted\n";
				int c = num.get_head();
				num.Delete();
				priority.Delete(c);
				break;
			}
			case 3:
			{
				
				num.Show();
				break;
			}
            case 4:
            {
                cout<<"Minimum: "<<priority.get_head()<<endl;
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
