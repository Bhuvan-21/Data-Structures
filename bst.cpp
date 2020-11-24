#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int x)
    {
        val = x;
        right = left = NULL;
    }

};

class BST
{
private:
    Node* root;

public:
    BST()
    {
        root = NULL;
    }

    void Insert(int x)
    {
    	if(root == NULL)
        {
            root = new Node(x);
            return; 
        }
        Node* ptr = new Node(x);
        Node* elem = root;
        while(elem != NULL)
        {
            if(x > elem->val)
            {
                if(elem->right == NULL)
                {
                    elem->right = ptr;
                    break;
                }
                else
                {
                    elem = elem->right;
                }
            }
            else if(x < elem->val)
            {
                if(elem->left == NULL)
                {
                    elem->left = ptr;
                    break;
                }
                else
                {
                    elem = elem->left;
                }
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

        cout<<"BST: ";
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
    	//cout<<"Delete"<<v;
        Node* ptr = root;
        Node* prev = NULL;
        int m = 0;
        while(ptr != NULL)
        {
            if(v == ptr->val)
            {
            	//cout<<"=="<<v;
                break;
        	}
			else if(v > ptr->val)
            {
                //cout<<"R";
                prev = ptr;
                m = 1;
                ptr = ptr->right;
            } 
            else if(v < ptr->val)
            {   
                //cout<<"L";
                prev = ptr;
                m = -1; 
                ptr = ptr->left;
            }
        
        }
        if(ptr != NULL)
        {
            if(ptr->right == NULL)
            {
                if(ptr != root)
                {
                    if(m == 1)
                        prev->right = ptr->left;
                    else if(m == -1)
                        prev->left = ptr->left;
                }
                delete(ptr);
                return;
            }
            else if(ptr->left == NULL)
            {
                if(ptr != root)
                {
                    if(m == 1)
                        prev->right = ptr->right;
                    else if(m == -1)
                        prev->left = ptr->right;
                }
                delete(ptr);
                return;
            }
            else
            {
                int v = Get_Min(ptr->right)->val;
                Delete(v);
                cout<<"@";
                ptr->val = v;
            }
            

        }
    }

    Node* Get_Max(Node* ptr)
    {
        while(ptr->right != NULL)
            ptr = ptr->right;
        return ptr;
    }

    Node* Get_Min(Node* ptr)
    {
        while(ptr->left != NULL)
            ptr = ptr->left;
        return ptr;
    }

    void display(Node* ptr, int ch)
    {
        if(ptr != NULL)
        {
            switch (ch)
            {
                case -1: //Pre order
                {
                	cout<<ptr->val<<" ";
                    display(ptr->left, ch);
                    display(ptr->right, ch);
                    break;
                }
                case 0: // In order
                {
                    display(ptr->left, ch);
                    cout<<ptr->val<<" ";
                    display(ptr->right, ch);
					break;
                }
                case 1: // Post order
                {
                	display(ptr->left, ch);
                    display(ptr->right, ch);
                    cout<<ptr->val<<" ";
                    break;
                }
                default:
                    cout<<"Invaid input\n";
            }
        }
    }

    void DFS_Traversal(int ch)
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

};




int main()
{
    BST b;
    b.Insert(12);
    b.Insert(35);
	b.Insert(5);
	b.Insert(123);
	b.Insert(1);
    b.Insert(6);
    b.Insert(73);
    b.Insert(42);
    
    //b.DFS_Traversal(1);
    cout<<"PRE ORDER\n";
    b.DFS_Traversal(-1);
    cout<<"IN ORDER\n";
    b.DFS_Traversal(0);
    cout<<"POST ORDER\n";
    b.DFS_Traversal(1);
    return 0;
}
