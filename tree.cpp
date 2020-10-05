#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node* right;
    Node* left;     

    Node(int v)
    {
        val = v;
        right = left = NULL;
    }
};

class Tree
{
private:
    Node* root;

public:
    Tree()
    {
        root = NULL;
    }

    void Insert(int v)
    {
        Node* elem = new Node(v);
        if(root == NULL)
        {
            root = elem;
            return;
        }
        Node* ptr = root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            ptr = q.front();
            q.pop();
            if(ptr->left == NULL)
            {
                ptr->left = elem;
                return;
            }
            else
            {
                q.push(ptr->left);
            }

            if(ptr->right == NULL)
            {
                ptr->right = elem;
                return;
            }
            else
            {
                q.push(ptr->right);
            }
            

        }
    }

    void Traversal()
    {
        if(root == NULL)
        {
            cout<<"Empty Tree\n";
            return;
        }
        
        Node* ptr;
        queue<Node*> q;
        q.push(root);

        cout<<"Tree: ";
        while(!q.empty())
        {
            ptr = q.front();
            q.pop();
            cout<<ptr->val<<" ";
            if(ptr->left != NULL)
            {
                q.push(ptr->left);
            }
            if(ptr->right != NULL)
            {
                q.push(ptr->right);
            }
        }
        cout<<endl;
        return;
    }

    void Delete(int v)
    {
        Node *ptr1, *ptr2; 
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            ptr1 = q.front();
            q.pop();
            if(ptr1->left != NULL)
            {
                q.push(ptr1->left);
            }
            if(ptr1->right != NULL)
            {
                q.push(ptr1->right);
            }
            if(ptr1->val == v)
            {
                ptr2 = ptr1;
            }
        }
        //cout<<"*"<<ptr1<<endl;
        ptr2->val = ptr1->val;
        Node* ptr = ptr1;
        q.push(root);
        if(ptr1 == root)
        {
            root =  NULL;
            return;
        }
        while(!q.empty())
        {
            ptr1 = q.front();
            q.pop();
            
            if(ptr1->left == ptr)
            {
            	//cout<<"#"<<ptr1->left<<endl;
            	
                delete(ptr);
                ptr1->left = NULL;
                return;
            }
            if(ptr1->right == ptr)
            {
            	//cout<<"#"<<ptr1->right<<endl;
                delete(ptr);
                ptr1->right = NULL;
                return;
            }
            if(ptr1->left != NULL)
            {
                q.push(ptr1->left);
            }
            if(ptr1->right != NULL)
            {
                q.push(ptr1->right);
            }
            
        }
        

    }


};

int main()
{
    Tree tree;

    int ch, element;

    do
	{
		cout<<"1. Insert 2. Delete 3. In-order Traversal 4. Exit Enter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value to be inserted\n";
				cin>>element;
				tree.Insert(element);
				break;
			}
			case 2:
			{
				cout<<"Enter the element to be deleted\n";
				cin>>element;
				tree.Delete(element);
				break;
			}
			case 3:
			{
				tree.Traversal();
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
