/*#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    //preorder

    vis[node] = 1;
    cout << node << " ";

    //inorder
    for (auto it : adj[node])
    {
        if (vis[it]);
        else
        {
            dfs(it);
        }
    }
    //postorder
}
int main()
{
    cout << "nodes and edges\n";
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> v;
    void solve(int node, vector<int> &vis,vector<int> adj[])
    {
        vis[node]= 1;
        v.push_back(node);
        for(auto it: adj[node])
        {
            if(!vis[it]){
                solve(it,vis, adj);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
    vector<int> vis(V);
    solve(0,vis,adj);
    return v;
    }
};

int main()
{
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    Solution obj;
    vector<int> ans = obj.dfsOfGraph(n,adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i]<<" ";
    }
   
    return 0;

}
/*
7 7
1 2
1 3
2 4
2 5
2 6
2 7 
3 7
*/