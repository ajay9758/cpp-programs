#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> adj[] , vector<bool> vis , int curr)
{
    if(vis[curr] == true)
    return true;

    vis[curr] = true;
    bool flag = false;

    for (int i = 0; i < adj[curr].size(); i++)
    {
        flag = isCyclicUtil( adj , vis , adj[curr][i]);
        if(flag == true)
        return true;
    }
    return false;
}

bool isCyclic(int n , vector<int> adj[])
{
    vector<bool> vis(n , false);
    bool flag = false;

    for (int  i = 0; i < n; i++)
    {
        vis[i]= true;
        for (int j = 0; j < adj[i].size(); j++)
        {
            flag = isCyclicUtil( adj , vis , adj[i][j]);
            if(flag == true)
            return true;
        }
        vis[i] = false;        
    }
    return false;
}


int main()
{
    int n,m,f,t;
    cin>>n>>m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        cin>>f>>t;
        adj[f].push_back(t);
    }

    bool res = isCyclic(n , adj);

    if(res == true)
    cout<<"Cycle exist";

    else
    cout<<"NO cycle";
    return 0;
    
}
/* 
5 6
0 1
2 1
4 0    
4 2
2 3
3 4 cycle exist;

*/