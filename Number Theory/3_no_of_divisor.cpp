#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    int no_of_divisor=0;

    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            no_of_divisor++;
            if(i*i!=n)no_of_divisor++;
        }
    }
    cout<<no_of_divisor<<"\n";
    
    return 0;
}