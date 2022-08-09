#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    int sum=0;

    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(i*i!=n)sum+=n/i;
        }
    }
    cout<<sum<<"\n";
    
    return 0;
}