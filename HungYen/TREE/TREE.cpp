//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "TREE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, q, p[20][mn], f[mn], H[mn], h[mn];
vector< int> a[mn];

void dfs(int u)
{
    for(auto v: a[u])
    {
        if(v== p[0][u]) continue;
        p[0][v]= u;
        h[v]= h[u]+ 1;
        dfs(v);
    }
}

void DFS(int u)
{
    for(auto v: a[u])
    {
        if(v== p[0][u]) continue;
        DFS(v);
        f[u]+= f[v];
    }
}

void C(int u)
{
    for(auto v: a[u])
    {
        if(v== p[0][u]) continue;
        H[v]= H[u]+ f[v];
        C(v);
    }
}

void rmq()
{
    forr(j, 1, 19)
        forr(i, 1, n)
            p[j][i]= p[j- 1][p[j- 1][i]];
}

int lca(int u, int v)
{
    if(h[u]< h[v]) swap(u, v);
    int del= h[u]- h[v];
    forr(i, 0, 19)
    if((del>> i)& 1) u= p[i][u];
    if(u== v) return u;
    for(int i= 19; i>= 0; i--)
    if(p[i][u]!= p[i][v]){
        u= p[i][u];
        v= p[i][v];
    }
    return p[0][u];
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> q;
    forr(i, 1, n- 1)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfs(1);
    rmq();

    while(m--){
        int u, v, w;
        cin>> u>> v>> w;
        int c= lca(u, v);
        f[u]+= w;
        f[v]+= w;
        f[p[0][c]]-= w;
        f[c]-= w;
    }

    DFS(1);
    H[1]= f[1], C(1);

    while(q--){
        int u, v, c;
        cin>> u>> v;
        c= lca(u, v);
        cout<< H[u]+ H[v]- 2* H[c]+ f[c]<< "\n";
    }

    return 0;
}
