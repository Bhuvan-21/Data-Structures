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
    Node* bottom;

public:
    Deque()
    {
        num = 0;
        head = bottom = NULL;
    }

    void Insert_front(int val)
    {
        Node* elem = new Node(val);
        if(num == 0)
        {
            head = bottom = elem;
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
            head = bottom = elem;
            num++;
            return;
        }

        elem->prev = bottom;
        bottom->next = elem;
        bottom = elem;
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
            head = bottom = NULL;
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

    void Delete_rear()
    {
        if(num == 0)
        {
            cout<<"Empty List\n";
            return;
        }
        Node* ptr = bottom;
        if(num == 1)
        {
            head = bottom = NULL;
            delete(ptr);
            num--;
            return;
        }
        else
        {
            bottom = bottom->prev;
            bottom->next = NULL;
            delete(ptr);
            num--;
            return;
        }
    }

    void Show()
    {
        if(!num)
        {
            cout<<"Empty List\n";
            return;
        }
        Node* ptr = head;
        cout<<"List: ";
        do
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        } while (ptr != NULL);
        cout<<endl;
    }



};

int main()
{
    int ch, element;
    Deque num;

    do
	{
		cout<<"1. Insert to the front  2. Delete from the front  3. Insert at the end  4. Delete from the end  5. Show  6. Exit\nEnter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value to be inserted\n";
				cin>>element;
				num.Insert_front(element);
				break;
			}
			case 2:
			{
				num.Delete_front();
				break;
			}
			case 3:
			{
				cout<<"Enter the value to be inserted\n";
				cin>>element;
				num.Insert_rear(element);
				break;
			}
			case 4:
			{
				num.Delete_rear();
				break;
			}
            case 5:
            {
				num.Show();
				break;
            }
            case 6:
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
	
	}	while(ch != 6);
    return 0;
}
