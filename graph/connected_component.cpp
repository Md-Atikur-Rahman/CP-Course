#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define PB push_back
#define All(x) (x).begin(),(x).end()
#define MP make_pair
#define nl "\n"
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VPII;
typedef vector<VI>VVI;
typedef vector<long long>VL;
typedef vector <VL>VVl;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
const long double PI = acos(-1.0);
const long double EPS=1e-9;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> comp;

void dfs(int v)
{
    comp.push_back(v);
    for(int x:adj[v])
    {
        if(vis[x])continue;
        vis[x]=true;
        dfs(x);
    }
}

void Engine(int tc)
{
    int n,m; cin>>n>>m;
    adj.clear();
    vis.clear();
    adj.resize(n+1);
    vis.resize(n+1);

    int u,v;

    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    vector<vector<int>> ans;

    for(int i=1; i<=n; i++)
    {
        if(vis[i])continue;

        vis[i]=true;
        comp.clear();
        dfs(i);
        ans.push_back(comp);
    }

    cout<<ans.size()<<nl;
    // for(vector<int>& x:ans)print(x);
}

int main()
{
    FastIO
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  