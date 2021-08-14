#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10];
    int i,j,k,n;
    cin>>n;
    int flag[n];
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for ( i = 0; i <n; i++)
    {
        int c=0;
        if(flag[i]!=1)
        {
            for ( j = 0; j < n; j++)
            {
                if(a[i]==a[j])
                {
                    c++;
                    flag[j]=1;
                }
            }
            if(c>1 || c==1)
            {
                cout<<'\n'<<a[i]<<" occurs"<<c<<" times";
            }   
        }
    }
    return 0;
}
