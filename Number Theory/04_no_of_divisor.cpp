#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int fact[N] ;
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
    
    for(int i=0; i<5; i++)
    {
        int n,d; cin>>n;
    
        int cnt=0,no_of_div=1;
        while(n>1)
        {
            d=fact[n];
            cnt=0;

            while(n%d==0)
            {
                n/=d;
                cnt++;
            }
            no_of_div*=(cnt+1);
        }

        cout<<no_of_div<<"\n";
    }

    return 0;
}  