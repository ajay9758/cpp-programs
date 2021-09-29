//Topological Sort of Directed Acyclic Graph
//Detailed video explanation: https://youtu.be/3HHlOG05qEo
//============================================

//C++:

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Graph{
    int v;
    vector<vector<int>> adj;
    void TS_rec(int s, vector<bool>& visited, stack<int>& S){
        visited[s] = true;
        
        for(int u: adj[s]){
            if(!visited[u])
                TS_rec(u, visited, S);
        }
        
        S.push(s);
    }
public:
    Graph(int v):v(v), adj(v){}
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    
    void Top_Sort(){
        vector<bool> visited(v, false);
        stack<int> S;
        for(int i = 0; i < v; ++i)
            if(!visited[i]) TS_rec(i, visited, S);
            
        while(!S.empty()){
            cout << S.top() << " ";
            S.pop();
        }
    }
};

int main(){
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(0,4);
    G.addEdge(1,2);
    G.addEdge(4,2);
    G.addEdge(3,4);
    G.Top_Sort();
   
   return 0;
}

/*


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void TS_rec(int s, vector<bool> &visited, stack<int> &S)
{
    visited[s] = true;

    for (int it : adj[s])
    {
        if (!visited[u])
            TS_rec(it, visited, S);
    }
    S.push(s);
}

void Top_Sort( int n )
{
    vector<bool> visited(n, false);
    stack<int> S;
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            TS_rec(i, visited, S);

    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    Top_Sort( n );

    return 0;
}
/*
5 6
0 1
0 3
0 4
1 2
4 2
3 4

*/