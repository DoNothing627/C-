//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 300005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "COMNET"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, mid;
vector< int> a[mn], c[mn];
bool d[mn];

void dfs(int u)
{
    d[u]= 1;
    for(auto z: a[u])
    {
        if(z> mid) continue;
        for(auto v: c[z])
        {
            if(d[v]) continue;
            dfs(v);
        }
    }
}

bool chek()
{
    memset(d, 0);
    dfs(1);
    return (d[n]== 1);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, m)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(i);
        c[i].pb(v);
    }

    int l= 0, r= n+ 1;
    while(r- l> 1)
    {
        mid= (l+ r)/ 2;
        if(chek()) r= mid;
        else l= mid;
    }

    if(r== n+ 1) cout<< -1;
    cout<< r;

    return 0;
}
