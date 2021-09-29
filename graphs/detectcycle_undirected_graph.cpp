#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> adj[] , vector<int> vis , int curr)
{
    if(vis[curr] == 2)
    return true;

    bool flag = false;

    vis[curr] = 1;
    for (int i = 0; i < adj[curr].size(); i++)
    {
        if(vis[adj[curr][i]] == 1)
        vis[adj[curr][i]] = 2;

        else
        {
            flag = isCyclicUtil(adj , vis , adj[curr][i]);
            if(flag == true)
            return true;
        }
    }
    return false;
}


bool isCyclic(int n , vector<int> adj[])
{
    vector<int> vis(n , 0);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 1;
        for (int j = 0; j < adj[i].size(); j++)
        {
            flag = isCyclicUtil( adj , vis , adj[i][j]);
            if(flag == true)
            return true;
        }
        vis[i] = 0;
    }
    return false;  
}



int main()
{
    int n,m,x,y;
    cin>>n>>m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool res = isCyclic(n , adj);

    if(res == true)
    cout<<"Cycle Exist";

    else
    cout<<"No Cycle";
    return 0;
    
}