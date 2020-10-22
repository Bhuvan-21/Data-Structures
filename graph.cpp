#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int num;
    vector<vector<int>> adj;
public:
    Graph(int n)
    {
        num = n;
        for(int i = 0; i < num; i++)
        {
            vector<int> p;
            adj.push_back(p);
        }
        
    }

    void AddEdge(int u, int v)
    {
    	
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void Display()
    {
        for(int v = 0; v < num; v++)
        {
            cout<<"Adjacency list of vertex "<<v<<": ";
            for(int u : adj[v])
                cout<<u<<" ";
            cout<<"\n";
        }
    }

    void BFS_traversal(int s)
    {
        queue<int> q;
        int arr[num] = {0};
        q.push(s);
        int cur;
        arr[s] = 1;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            for(int v : adj[cur])
            {
                if(!arr[v])
                {
                    q.push(v);
                    arr[v] = 1;
                }
            }
            cout<<cur<<" ";
            

        }
        cout<<"\n";

    }

    void DFS_traversal(int s)
    {
        stack<int> st;
        int arr[num] = {0};
        st.push(s);
        int cur;
        arr[s] = 1;
        while(!st.empty())
        {
            cur = st.top();
            st.pop();
            for(int v : adj[cur])
            {
                if(!arr[v])
                {
                    st.push(v);
                    arr[v] = 1;
                }
            }
            cout<<cur<<" ";
        }
        cout<<"\n";
    }

};


int main()
{
    Graph num(6);
    num.AddEdge(1, 2);
    num.AddEdge(0, 4);
    num.AddEdge(2, 4);
    num.AddEdge(1, 5);
    num.AddEdge(0, 3);
    num.AddEdge(2, 3);
    num.AddEdge(2, 5);

    num.Display();
    num.BFS_traversal(0);
    num.DFS_traversal(1);
    

}
