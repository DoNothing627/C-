//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "COCKROACH"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, res= 0, p[mn], c[mn];
vector< int> a[mn];
ii f[mn];

void dfs(int u)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i];
        if(v== p[u]) continue;
        p[v]= u;
        f[v].x= f[u].x+ 1;
        dfs(v);
    }
}

void loang(int u, int o)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i];
        if(v== o) continue;
        if(c[v]>= c[u]- 1) continue;
        c[v]= c[u]- 1;
        loang(v, u);
    }
}

void COW()
{
    dfs(1);
    forr(i, 1, n){
        f[i].y= i;
        c[i]= -1;
    }
    sort(f+ 1, f+ n+ 1);

    for(int i= n; i> 0; i--)
    {
        int u= f[i].y;
        if(c[u]> -1) continue;
        forr(j, 1, k) u= p[u];
        if(c[u]!= k){
            c[u]= k;
            loang(u, 0);
        }
    }

    forr(i, 1, n) if(c[i]== k) ++res;
    cout<< res;
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;
    forr(i, 1, n- 1)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    if(n== 1){
        cout<< 1;
        return 0;
    }

    COW();

    return 0;
}
