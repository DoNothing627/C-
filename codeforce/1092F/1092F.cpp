//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 100000000000000007
#define int long long
#define DoNothing "1092F"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, c[mn], f[mn], F[mn], s[mn], res= 0;
vector< int> a[mn];

void dfs(int u, int o)
{
    s[u]= c[u];
    for(auto v: a[u])
    {
        if(v== o) continue;
        f[v]= f[u]+ 1;
        dfs(v, u);
        s[u]+= s[v];
    }
}

void DFS(int u, int o)
{
    res= max(res, F[u]);
    for(auto v: a[u])
    {
        if(v== o) continue;
        F[v]= F[u]- s[v]+ s[1]- s[v];
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

    forr(i, 1, n- 1){
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfs(1, 0);

    forr(i, 1, n)
    F[1]+= c[i]* f[i];
    DFS(1, 0);

    cout<< res;

    return 0;
}
