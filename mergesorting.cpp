/*#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(int l,int mid ,int r, int a[]){

    int l_sz = mid - l + 1; // 0 1 2 3 4 5 6  m=3;
    int r_sz = r - mid;

    int L[l_sz + 1];
    int R[r_sz + 1];

    for(int i=0;i< l_sz ; ++i)
       {
            L[i] = a[i + l];
       }
    for(int i=0; i< r_sz; ++i)
      {
           R[i] = a[i + mid + 1];
      }

    L[l_sz] = R[r_sz] = INT_MAX - 1;

    int l_i=0,r_i=0;

    for (int  i = l; i <= r; i++)
    {
        if(L[l_i] <= R[r_i])
        {
            a[i] = L[l_i];
            l_i++;
        }
        else{
            a[i]= R[r_i];
            r_i++;
        }
    }   
    
}

void mergeSort( int l ,int r,int a[])
{
    if (l<r){
        
    int mid = (l+r)/2;
    mergeSort( l, mid, a);
    mergeSort(mid+1,r , a);
    merge(l,mid ,r, a);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n ;i++)
    {
        cin>>a[i];
    }
    
    mergeSort(0, n-1 ,a);

    for (int i = 0; i < n; i++)
    {
    cout<<a[i]<<" ";
    }  
}
   */

// Merge sort in C++

#include <iostream>
using namespace std;

void merge(int a[], int lb, int mid, int up)
{
    int lsz = mid - lb + 1; //  0,1,2,3,4,5  m = 2
    int rsz = up - mid;

    int L[lsz], R[rsz];

    for (int i = 0; i < lsz; i++)
        L[i] = a[i + lb];

    for (int j = 0; j < rsz; j++)
        R[j] = a[j + mid + 1];


    int i = 0, j = 0, k = lb;
    while (i < lsz && j < rsz)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < lsz)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < rsz)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int lb, int up)
{
    if (lb < up)
    {
        int mid = lb + (up - lb) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, up);
        merge(a, lb, mid, up);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; ++i)
        cout << a[i] <<" ";
}