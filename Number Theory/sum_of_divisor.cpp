#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int fact[N] ;
vector<int> primes;
void Sieve(){
    for (int i = 2 ; i<N ; i+=2) fact[i] = 2 ;
    primes.push_back(2);
    for (int i = 3 ; i<N ; i+=2){
        if(fact[i]!=0)continue;
        primes.push_back(i);
        for (int j = i ; j<N ; j+=i){
            if (fact[j] == 0) fact[j] = i ;
        }
    }
}

long long powr(long long  n, long long p)
{
    long long res=1;
    while(p)
    {
        res=res*n;
        p--;
    }
    return res;
}

int main()
{
    Sieve();
    
    for(int i=0; i<5; i++)
    {
        int n,p; cin>>n;
    
        int e=0,sum_of_div=1;

        while(n>1)
        {
            p=fact[n];
            e=0;

            while(n%p==0)
            {
                n/=p;
                e++;
            }
            
            sum_of_div*=(powr(p,e+1)-1)/(p-1);

        }
        cout<<sum_of_div<<"\n";
    }

    return 0;
}  