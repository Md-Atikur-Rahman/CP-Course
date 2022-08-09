#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n; // input a number for check , prime or not?

    if(n<2)
    {
        cout<<n<<" is not prime\n";
        return 0;
    }
    
    for(int i=2; i*i<=n; i++) // every composite number has a divisor <= sqrt(n)
    {
        if(n%i==0) // n is divisible by i
        {
            cout<<n<<" is not prime\n";
            return 0;
        }
    }

    // no divisor found
    cout<<n<<" is prime\n";

    return 0;
}