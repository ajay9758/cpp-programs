#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int s,d,wt;
};

struct node
{
    int parent,rank;
};

vector<node> dsuf;
vector<edge> mst;

int find(int v)
{
    if(dsuf[v].parent == -1)
    return v;

    return dsuf[v].parent = find(dsuf[v].parent);
}

void unioon(int p1 , int p2)
{
    if(dsuf[p1].rank > dsuf[p2].rank)    //p1 has higher rank
        dsuf[p2].parent = p1;
    else if(dsuf[p1].rank < dsuf[p2].rank)    //p2 has higher rank
        dsuf[p1].parent = p2;
    else
    {
        //Both have same rank and so anyone can be made as parent
        dsuf[p1].parent = p2;
        dsuf[p2].rank +=1;        //Increase rank of parent
    }
}

bool comparator(edge a,edge b)
{
    return a.wt < b.wt;
}
void kruskals(vector<edge> edgelist , int n , int m)
{
    sort(edgelist.begin() , edgelist.end() , comparator);

    int i=0,j=0;
    while (i< n-1 && j<m)
    {
        int p1 = find(edgelist[j].s);
        int p2 = find(edgelist[j].d);

        if(p1 == p2)
        {
            ++j;
            continue;
        }

        unioon(p1, p2);
        mst.push_back(edgelist[j]);
    }
}
void printmst( vector<edge> &mst)
{
    cout<<" MST \n";
    for(auto it : mst)
    {
        cout<<"s ="<<it.s<<" d = "<<it.d <<" wt = "<< it.wt<<endl;
    }
}
int main()
{
    int n,m,f,to ,wt;
    cin>>n>>m;
    dsuf.resize(n);
    
    for (int i = 0; i < n; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    vector<edge> edgelist;
    edge t;
    for (int i = 0; i < m; i++)
    {
        cin>>f>>to>>wt;
        t.s = f;
        t.d = to;
        t.wt = wt;

        edgelist.push_back(t);
    }

    kruskals(edgelist , n , m);
    printmst(mst); 

}
/*
6 10
0 1 1
1 3 1
2 4 1
0 2 2
2 3 2
3 4 2
1 2 3
1 4 3
4 5 3
3 5 4

9 14
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8
1 2 8
3 4  9
5 4 10
1 7 11
3 5 14
*/