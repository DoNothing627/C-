//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1363E"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, p[mn][20], r[mn][20], z[mn], b[mn], c[mn], d[mn][2], f[mn];
vector< int> a[mn];

void dfs(int u)
{
    for(int v: a[u])
    {
        if(p[u][0]== v) continue;
        p[v][0]= u;
        dfs(v);
    }
}

void rmq()
{
    forr(k, 1, 18)
        forr(i, 0, n)
            p[i][k]= p[p[i][k- 1]][k- 1];
    z[0]= oo;
    forr(i, 0, n) r[i][0]= z[i];
    forr(k, 1, 18)
        forr(i, 0, n)
            r[i][k]= min(r[p[i][k- 1]][k- 1], r[i][k- 1]);
}

void doIt(int u)
{
    if(b[u]!= c[u]){
        if(!b[u]) ++d[u][0];
        if(!c[u]) ++d[u][1];
    }

    for(int v: a[u])
    {
        if(p[u][0]== v) continue;
        doIt(v);
        forr(i, 0, 1)
            d[u][i]+= d[v][i];
        f[u]+= f[v];
    }
    if(z[u]== r[u][18]){
        int ans= min(d[u][0], d[u][1]);
        f[u]+= 2* z[u]* ans;
        d[u][0]-= ans, d[u][1]-= ans;
    }
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
        cin>> z[i]>> b[i]>> c[i];

    forr(i, 1, n- 1){
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfs(1);
    rmq();
    doIt(1);

    if(d[1][0]|| d[1][1]) cout<< -1;
    else cout<< f[1];

    return 0;
}
