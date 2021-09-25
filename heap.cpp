#include<iostream>
using namespace std;

void heapify(int a[],int s,int i)
{
    int largest=i;
    int left=2*i+1;
    int right= 2*i+2;

    if(left < s && a[left]> a[largest])
    largest=left;

    if(right < s && a[right] > a[largest])
    largest=right;

    if(largest !=i)
    {
        swap( a[i],a[largest] );
        heapify(a,s,largest);
    }
}

void heapsort(int a[],int s)
{
    int i;
    
    for(i=s/2-1;i>=0;i--)
    heapify(a,s,i);


    for(i=s-1;i>=0;i--)
    {
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
    
}


int main()
{
    int a[]={6,1,4,9,0,2,5,7,8,10};
    int s=*(&a+1)-a;

    heapsort(a,s);

    for (int i = 0; i < s; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}