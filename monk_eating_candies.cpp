#include<iostream>
#include<set>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int n,k;
        cin>>n>>k;

        multiset <long long> bags;
        for(int i=0;i<n;++i)
        {
            int candy_ct;
            cin>>candy_ct;
            bags.insert(candy_ct);
        }

        long long total_candies = 0;
        for(int i=0;i<k; ++i)
        {
            auto last_it = (--bags.end());
            
            int candy_ct = (*last_it);

            bags.insert(candy_ct /2);

            total_candies += candy_ct;        
            bags.erase(last_it);
        }
        cout<<total_candies<<endl;
    }
}