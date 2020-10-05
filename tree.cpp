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

    void BFS_Traversal()
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

    void display(Node* ptr, int ch)
    {
        if(ptr != NULL)
        {
            switch (ch)
            {
                case -1:
                {
                    display(ptr->left, ch);
                    cout<<ptr->val<<" ";
                    display(ptr->right, ch);
                    break;
                }
                case 0:
                {
                    cout<<ptr->val<<" ";
                    display(ptr->left, ch);
                    display(ptr->right, ch);
                    break;
                }
                case 1:
                {
                    display(ptr->right, ch);
                    cout<<ptr->val<<" ";
                    display(ptr->left, ch);
                    break;
                }
                default:
                    cout<<"Invaid input\n";
            }
        }
    }

    void DFS_2(int ch)
    {
        if(root == NULL)
        {
            cout<<"Empty tree\n";
            return;
        }
        else
        {
            cout<<"Tree: ";
            display(root, ch);
            cout<<"\n";
        }
        
    }


    void DFS_Traversal()
    {
        if(root == NULL)
        {
            cout<<"Empty Tree\n";
            return;
        }
        
        Node* ptr;
        stack<Node*> s;
        s.push(root);
        
        cout<<"Tree: ";
        while(!s.empty())
        {
            ptr = s.top();
            s.pop();
            cout<<ptr->val<<" ";
            if(ptr->right != NULL)
            {
                s.push(ptr->right);
            }
            if(ptr->left != NULL)
            {
                s.push(ptr->left);
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
                delete(ptr);
                ptr1->left = NULL;
                return;
            }
            if(ptr1->right == ptr)
            {
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
		cout<<"1. Insert 2. Delete 3. BFS 4. DFS 5. Exit Enter choice:";
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
				tree.BFS_Traversal();
				break;
			}
            case 4:
            {
                int ord;
                cout<<"-1: Pre-order traversal 0: In-order traversal 1: Post-order traversal \nEnter choice: ";
                cin>>ord;
                tree.DFS_2(ord);
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
    



    return 0;
}
