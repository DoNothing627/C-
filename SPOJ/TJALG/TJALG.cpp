//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 10005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "TJALG"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, num[mn], low[mn], COUNT;
vector< int> a[mn];
stack< int> S;

void dfs(int u)
{
    num[u]= low[u]= ++m;
    S.push(u);
    for(auto v: a[u])
    {
        if(num[v])
            low[u]= min(low[u], num[v]);
        else{
            dfs(v);
            low[u]= min(low[u], low[v]);
        }
    }

    if(num[u]== low[u]){
        int v;
        ++COUNT;
        while(v!= u){
            v= S.top(), S.pop();
            //++COUNT;
            num[u]= low[u]= oo;
        }
    }
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
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
    }
    m= 0;

    forr(i, 1, n)
    if(!num[i]) dfs(i);

    cout<< COUNT;

    return 0;
}
