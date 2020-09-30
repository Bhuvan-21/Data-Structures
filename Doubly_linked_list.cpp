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

class D_L_List
{
private:
    int num;
    Node* head;
    Node* bottom;

public:
    D_L_List()
    {
        num = 0;
        head = bottom = NULL;
    }

    void Insert(int v, int p)
    {
        if(p < 0 || p > num || num == 0)
        {
            cout<<"Invalid Position. Please enter a position between 0 and "<<num<<endl;
            return;
        }
        Node* elem = new Node(v);

        if(num == 0)
        {
            num++;
            head = elem;
            bottom = elem;
        }
        else if(p == 0)
        {   
            num++;
            elem->next = head;
            head->prev = elem;
            head = elem;
        }
        else if(p == num)
        {
            num++;
            elem->prev = bottom;
            bottom->next = elem;
            bottom = elem;
        }
        else
        {
            num++;
            Node* ptr = head;
            while(p > 1)
            {
                ptr = ptr->next;
                p--;
            }
            elem->prev = ptr;
            elem->next = ptr->next;
            ptr->next = ptr->next->prev = elem;
        }
        

    }

    void Delete(int p)
    {
        if(num == 0)
        {
            cout<<"Empty List\n";
            return;
        }
        if(p < 0 || p >= num)
        {
            cout<<"invalid Position. Please enter a number between 0 and "<<num-1<<endl;
            return;
        }
        if(p == 0)
        {
            Node* ptr = head;
            head->next->prev = NULL;
            head = head->next;
            delete(ptr);
            num--;
            return;
        }
        if(p == num-1)
        {
            Node*ptr = bottom;
            bottom->prev->next = NULL;
            bottom = bottom->prev;
            delete(ptr);
            num--;
            return;
        }
        Node *before = head, *after, *ptr;
        while(p>1)
        {
            before = before->next;
            p--;
        }
        after = before->next->next;
        ptr = before->next;

        before->next = after;
        after->prev = before;
        delete(ptr);
        num--;
        return;
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
    int ch;
	long element, pos;
	D_L_List num;
	
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
	
    return 0;
}

