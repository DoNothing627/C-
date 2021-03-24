//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 500005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "ANCESTOR"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, topo[mn], m= 0, I[mn], q[mn];
vector< int> a[mn], c[mn];
bool chek[mn];

void RESET()
{
    m= 0;
    forr(i, 1, n)
    {
        a[i].clear(), c[i].clear();
        chek[i]= 0;
    }
}

void up(int x, int val)
{
    while(x<= n){
        I[x]+= val;
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0){
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

void dfs(int u)
{
    topo[u]= ++m;
    for(auto v: a[u])
    {
        if(topo[v]) continue;
        dfs(v);
    }
}

void DFS(int u)
{
    chek[u]= 1;
    q[u]= get(topo[u]);
    up(topo[u], 1);
    for(auto v: c[u])
    {
        if(chek[v]) continue;
        DFS(v);
    }
    up(topo[u], -1);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n;
        RESET();
        forr(i, 1, n- 1)
        {
            int u, v;
            cin>> u>> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        forr(i, 1, n- 1)
        {
            int u, v;
            cin>> u>> v;
            c[u].pb(v);
            c[v].pb(u);
        }
        dfs(1);
        DFS(1);
        forr(i, 1, n)
            cout<< q[i]<< " ";
        cout<< "\n";
    }

    return 0;
}
