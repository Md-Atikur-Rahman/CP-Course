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

vector<bool> visited;
vector<int> tin, low;
int timer;

VPII res;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], low[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                res.push_back({v,to});
            }
        }
    }
}

void Engine(int tc)
{
    int n,m,u,v; cin>>n>>m;

    visited.clear();
    visited.resize(n);
    adj.clear();
    adj.resize(n);
    tin.assign(n,-1);
    low.assign(n,-1);
    res.clear();

    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer=0;

    for(int i=0; i<n; i++)
    {
        if(visited[i])continue;
        dfs(i);
    }
    cout<<res.size()<<nl;
    for(auto x:res)cout<<x.first<<" "<<x.second<<nl;
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