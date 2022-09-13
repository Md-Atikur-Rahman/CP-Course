#include<bits/stdc++.h>
using namespace std;

int extend_euclid(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extend_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    int a,b; cin>>a>>b;

    int g,x,y;
    g=extend_euclid(a,b,x,y);

    cout<<"gcd "<<g<<"\n";
    cout<<"x= "<<x<<"\n";
    cout<<"y= "<<y<<"\n";

    return 0;
}