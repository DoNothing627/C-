//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "CHEFGIRL"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;


int n, m, d[mn][33][33], F[33][33];
typedef pair< int, ii> iii;
iii a[mn];
vector< iii> V;

void dfs(int u)
{
    int v= a[u].x;
    if(!v) return;
    dfs(v);
    forr(r, 1, 32)
        forr(l, 1, r)
            d[u][l][r]= d[v][l][r]+ max(0ll, a[u].y.x- l)+ max(0ll, r- a[u].y.y);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    forr(i, 1, m)
    {
        int u, v, l, r;
        cin>> u>> v>> l>> r;
        if(u== 1) V.pb(iii(v, ii(l, r)));
        else a[u]= iii(v, ii(l, r));
    }

    for(auto z: V)
        dfs(z.x);

    memset(F, 40);


    for(auto z: V)
    {
        int u= z.x;
        forr(r, 1, 32)
            forr(l, 1, r)
                F[l][r]= min(F[l][r], d[u][l][r]+ max(0ll, z.y.x- l)+ max(0ll, r- z.y.y));
    }

    forr(r, 1, 32)
        forr(l, 1, r)
            forr(m, l, r)
                F[l][r]= min(F[l][r], F[l][m]+ F[m+ 1][r]);

    cout<< F[1][32];
    return 0;
}
