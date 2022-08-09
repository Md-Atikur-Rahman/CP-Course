#include<bits/stdc++.h>
using namespace std;

/*  function can be made for binary exponentiation

int binary_exp(int n, int p)
{
    int res=1;

    while(p>0)
    {
        if(p%2==1)res*=n;

        n*=n;
        p/=2;
    }

    return res;
}
*/

int main()
{
    int n,p; cin>>n>>p; // n is base, p is power

    int res=1;

    while(p>0)
    {
        if(p%2==1)res*=n; // if p is odd then res is multiplied by n;
        
        n=n*n; // make n to n^2;
        p=p/2; // power is divided by 2;
    }

    cout<<res<<"\n";
    
}