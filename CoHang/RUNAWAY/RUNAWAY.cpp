//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 400005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "RUNAWAY"
#define ii pair< int, long long>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, p[mn][20], in[mn], out[mn], I[4* mn];
long long L, d[mn];
vector< ii> a[mn];

void dfs(int u)
{
    in[u]= ++n;
    if(a[u].size()!= 0)
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i].x;
        long long w= a[u][i].y;
        if(v== p[u][0]) continue;
        d[v]= d[u]+ w;
        dfs(v);
    }
    out[u]= ++n;
}

void rmq()
{
    forr(i, 1, 19)
        forr(j, 1, n)
            p[j][i]= p[p[j][i- 1]][i- 1];
}

void up(int k, int l, int r, int u, int val)
{
    if(l> u|| r< u) return;
    if(l== r){
        I[k]+= val;
        return;
    }
    int mid= (l+ r)/ 2;
    up(2* k, l, mid, u, val);
    up(2* k+ 1, mid+ 1, r, u, val);
    I[k]= I[2* k]+ I[2* k+ 1];
}

int get(int k, int l, int r, int u, int v)
{
    if(l> v|| r< u) return 0;
    if(l>= u&& r<= v)
        return I[k];
    int mid= (l+ r)/ 2;
    return get(2* k, l, mid, u, v)+ get(2* k+ 1, mid+ 1, r, u, v);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> L;
    forr(i, 2, n)
    {
        long long w;
        cin>> p[i][0]>> w;
        a[p[i][0]].pb(ii(i, w));
    }
    rmq();
    n= 0;
    dfs(1);

    forr(i, 1, n)
    {
        int l= -1, r= n, u;
        while(r- l> 1){
            int mid= (l+ r)/ 2;
            u= i;
            forr(j, 0, 19)
                if((mid>> j)& 1) u= p[u][j];
            if(!u) r= mid;
            else{
                if(d[i]- d[u]<= L) l= mid;
                else r= mid;
            }
        }
        u= i;
            forr(j, 0, 19)
                if((l>> j)& 1) u= p[u][j];
        up(1, 1, n, in[i], 1);
        if(p[u][0]) up(1, 1, n, in[p[u][0]], -1);
    }

    forr(i, 1, n/ 2)
    cout<< get(1, 1, n, in[i], out[i])<< "\n";

    return 0;
}
