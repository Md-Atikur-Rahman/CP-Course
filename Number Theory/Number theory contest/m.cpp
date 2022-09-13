#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);

const int N=1e6;
int fact[N] ;
void Sieve(){
    for (int i = 2 ; i<N ; i+=2) fact[i] = 2 ;
    for (long long i = 3 ; i<N ; i+=2){
        if(fact[i]!=0)continue;
        fact[i]=i;
        for (long long j = i*i ; j<N ; j+=i){
            if (fact[j] == 0) fact[j] = i ;
        }
    }
}

void Engine(int tc)
{
    int a,b; cin>>a>>b;
    int d,cnt,ans=1,g=__gcd(a,b);
    while(g>1)
    {
        d=fact[g];
        cnt=0;
        while(g%d==0)
        {
            g/=d;
            cnt++;
        }
        ans*=(cnt+1);
    }
    cout<<ans<<'\n';
}

int main()
{
    FastIO
    Sieve();

    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  