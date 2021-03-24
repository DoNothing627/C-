//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "FRIENDS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q, p[21][mn], h[mn], f[mn];
vector< ii> a[mn];

void dfs(int u)
{
    for(auto z: a[u])
    {
        int v= z.x, w= z.y;
        if(v== p[0][u]) continue;
        p[0][v]= u;
        h[v]= h[u]+ 1;
        f[v]= f[u]+ w;
        dfs(v);
    }
}

void rmq()
{
    forr(j, 1, 20)
    {
        forr(i, 1, n)
            p[j][i]= p[j- 1][p[j- 1][i]];
    }
}

int lca(int u, int v)
{
    if(h[u]< h[v]) swap(u, v);
    int del= h[u]- h[v];
    forr(i, 0, 20)
        if((del>> i)& 1) u= p[i][u];
    if(u== v) return u;
    for(int i= 20; i>= 0; i--)
    {
        if(p[i][u]!= p[i][v])
        {
            u= p[i][u];
            v= p[i][v];
        }
    }
    return p[0][u];
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 2, n)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(ii(i, v));
    }

    dfs(1), rmq();

    cin>> q;
    while(q--)
    {
        int u, v, w;
        long long res;
        cin>> u>> v>> w;
        int d= lca(u, v);
        res= min((long long) f[u]+ w, min((long long) 2ll* f[u]+ f[v]- 2ll* f[d], (long long) f[v]+ 2ll* w));
        cout<< res<< "\n";
    }

    return 0;
}
