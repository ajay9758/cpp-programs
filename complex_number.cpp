#include<iostream>
using namespace std;

/*class complex
{
private:
    int a,b;
public:

    void set(int x,int y)
    {
        a=x;
        b=y;
    }
    void show()
    {
        cout<<"a="<<a<<" b="<<b;
    }
    int r=90;
    void v()
    {
        cout<<"\n"<<r;
    }
    complex add(complex c)
    {
        complex t;
        t.a= a + c.a;
        t.b= b+ c.b;
        return t;
    }
    protected:
    
};


int main()
{
    int x,y;
    complex c1,c2,c3;
    c1.set(6,9);
    c2.set(3,4);
    c3=c1.add(c2);
    c3.show();
    c1.r;
    c1.v();
}*/

struct comp{
    float real;
    float imaginary;
}t,n1,n2;

struct comp add(struct comp n1,struct comp n2)
{
    
    t.real = n1.real + n2.real;
    t.imaginary = n1.imaginary + n2.imaginary;

    
    return t;
}

int main()
{
    struct comp s;

    cout<<"r  "<<" c"<<endl;
    cin>>n1.real;
    cin>>n1.imaginary;

    cout<<"r2  "<<" I2"<<endl;
    cin>>n2.real>>n2.imaginary;

    s=add(n1,n2);
    cout<<endl;
    cout<<s.real<<" + "<<s.imaginary;
}