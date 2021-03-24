//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 100000000000007
#define int long long
#define DoNothing "JTREE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, q, I[4* mn], f[mn];
vector< int> a[mn];
vector< ii> c[mn];

void up(int k, int l, int r, int u, int val)
{
    if(l> u|| r< u) return;
    if(l== r){
        I[k]= val;
        return;
    }
    int m= (l+ r)/ 2;
    up(2* k, l, m, u, val);
    up(2* k+ 1, m+ 1, r, u, val);
    I[k]= min(I[2* k], I[2* k+ 1]);
}

int get(int k, int l, int r, int u, int v)
{
    if(l> v|| r< u) return oo;
    if(l>= u&& r<= v) return I[k];
    int m= (l+ r)/ 2;
    return min(get(2* k, l, m, u, v), get(2* k+ 1, m+ 1, r, u, v));
}

void dfs(int u, int o, int h)
{
    //int ans= 0;
    if(u!= 1)
    {
        f[u]= oo;
        for(auto z: c[u])
        {
            int k= z.x, w= z.y;
            f[u]= min(f[u], get(1, 1, n, max(1ll, h- k), h- 1)+ w);
        }
        up(1, 1, n, h, f[u]);
    }
    else up(1, 1, n, 1, 0);

    for(auto v: a[u])
    {
        if(v== o) continue;
        dfs(v, u, h+ 1);
    }

    up(1, 1, n, h, oo);
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    forr(i, 1, n- 1)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    forr(i, 1, m)
    {
        int v, k, w;
        cin>> v>> k>> w;
        c[v].pb(ii(k, w));
    }

    memset(I, 40);
    dfs(1, 0, 1);

    cin>> q;
    while(q--){
        int u;
        cin>> u;
        cout<< f[u]<< "\n";
    }

    return 0;
}
