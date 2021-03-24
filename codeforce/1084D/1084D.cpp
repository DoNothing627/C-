//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 300005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1084D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, c[mn], d[mn], res= 0;
vector< ii> a[mn];
vector< int> f[mn];




void dfs(int u, int o)
{
    //if(a[u].size()== 1&& u!= 1) f[u].pb(c[u]);
    f[u].pb(c[u]);
    for(auto z: a[u])
    {
        int v= z.x, w= z.y;
        if(v== o) continue;
        dfs(v, u);
        if(f[v][0]>= w){
            int cost= f[v][0]- w+ c[u];
            f[u].pb(cost);
        }
    }
    sort(f[u].begin(), f[u].end());
    reverse(f[u].begin(), f[u].end());
}


void DFS(int u, int o)
{
    d[u]= max(c[u], d[u]);
    for(auto z: a[u])
    {
        int v= z.x, w= z.y, pos= 0;
        if(v== o) continue;
        if(f[v][0]>= w&& f[v][0]- w+ c[u]== f[u][0]) pos= 1;
        if(pos< f[u].size()&& f[u][pos]>= w) d[v]= max(d[v], f[u][pos]- w+ c[v]);
        if(d[u]>= w) d[v]= max(d[v], d[u]- w+ c[v]);
        DFS(v, u);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> c[i];

    forr(i, 1, n- 1)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(ii(v, w));
        a[v].pb(ii(u, w));
    }

    dfs(1, 0);
    DFS(1, 0);

    forr(u, 1, n)
    {
        res= max(res, d[u]);
        if(f[u].size()) res= max(res, f[u][0]);
        //cout<< f[u][0]<< " "<< d[u]<< "\n";
    }

    cout<< res;

    return 0;
}
