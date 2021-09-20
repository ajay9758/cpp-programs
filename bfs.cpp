#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    queue<int> q;
    bool vis[n];
    memset(vis,0, sizeof vis);

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    
    q.push(1);
    vis[1] = 1;

    while(!q.empty())
    {
        int node = q.front();
        cout<<node<<" ";
        q.pop();

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }    
}