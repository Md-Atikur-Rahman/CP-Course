#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
int fact[N] ; //fact[i] stored smallest prime divisor of i;
vector<int> primes;
void Sieve(){
    for (int i = 2 ; i<N ; i+=2) fact[i] = 2 ;
    primes.push_back(2);
    for (long long i = 3 ; i<N ; i+=2){
        if(fact[i]!=0)continue;
        primes.push_back(i);
        fact[i]=i;
        for (long long j = i*i ; j<N ; j+=i){
            if (fact[j] == 0) fact[j] = i ;
        }
    }
}

int main()
{
    Sieve();

    int n,testcase; cin>>testcase;

    for(int i=0; i<testcase; i++)
    {
        cin>>n;

        if(fact[n]==n)cout<<"number is prime\n";
        else cout<<"Number is not prime\n";
    }

    // all primes are stored in primes array, they can be print
    //for(int x:primes)cout<<x<<" ";

    return 0;
}