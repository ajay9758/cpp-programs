#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,pair<int,int>>>  viii;
vector<int> parent;
int find(int v )
{
    if(parent[v] == -1 )
    return v;

    else
    return find(parent[v] );
}

void unioon(int f , int to )
{
    int p1 = find(f);
    int p2 = find(to);

    parent[p1] = p2;
}

viii kruskals( viii graph , int n)
{
    sort(graph.begin() , graph.end());
    parent.resize(n , -1);

    int s,d,w;
    viii res;

    for (int i = 0; i < graph.size(); i++)
    {
        s = graph[i].second.first;
        d = graph[i].second.second;
        w = graph[i].first;

        if(find(s ) != find(d ))
        {
            res.push_back(graph[i]);

            unioon(s , d );
        }
    }
    return res;
}

int main()
{
    viii graph , res;
    int n,m,s , d , wt;
    cin>>n>>m;

    for (int i = 0; i < m; i++)
    {
        cin>>wt>>s>>d;
        graph.push_back({wt,{s,d}});
    }
    
    res = kruskals(graph , n );
    int sum = 0;
    for(auto it : res)
    {
        cout<<"wt="<<it.first<<"  s = "<<it.second.first<<"  d = "<<it.second.second<<endl;
        sum = sum + it.first;
    }
    
    cout<<" ---------------"<<endl;
    cout<<sum;
}
/*
6 9
1 0 1
2 1 5
3 0 5
4 1 2
5 1 4
6 4 5
7 2 4
8 2 3
9 3 4
 ------------------------------------
9 14
1 7 6
2 8 2
2 6 5
4 0 1
4 2 5
6 8 6
7 2 3
7 7 8
8 0 7
8 1 2
9 3 4 
10 5 4
11 1 7
14 3 5


wt = 37
*/