#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> parent;

int find(int x)
{
    if(parent[x] == -1)
    return x;

    else
    return find(parent[x]);
}

void unionn(int f , int t)
{
    int p1 = find(f);
    int p2 = find(t);

    parent[p1] = p2;

}

bool iscycle(vector<pair<int , int>> edgelist )
{
    for(auto p : edgelist)
    {
        int f = find(p.first);
        int t = find(p.second);

        if(f == t)
        return true;

        unionn(f , t);
    }
    return false;

}

int main()
{
    int n,m;
    cin>>n>>m;
    parent.resize(n , -1);
    vector<pair<int,int>> edgelist;

    for (int i = 0; i < m; i++)
    {
        int f,t;
        cin>>f>>t;

        edgelist.push_back({f , t});
    }

    if(iscycle(edgelist) == true)
    cout<<" Cycel Exists";

    else
    cout<<"No cycle";
    
}