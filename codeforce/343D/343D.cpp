//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "343D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, in[mn], out[mn], p[mn];
vector< int> a[mn];
set< int> s;

void dfs(int u)
{
    in[u]= ++n;
    for(auto v: a[u])
    {
        if(v== p[u]) continue;
        p[v]= u;
        dfs(v);
    }
    out[u]= ++n;
    if(in[u]== out[u]- 1) s.insert(in[u]);
}

bool chek(int u)
{
    auto it= s.lower_bound(in[u]);
    if(it!= s.end()&& *it<= out[u]) return 0;
    return 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n- 1)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    n= 0;
    dfs(1);
    out[0]= n+ 1;

    cin>> m;
    while(m--){
        int u, type;
        cin>> type>> u;
        if(type== 1){
            if(!chek(p[u])){
               s.erase(s.lower_bound(in[u]), s.lower_bound(out[u]));
               s.insert(in[p[u]]);
            }
        }
        else{
            if(type== 2) s.insert(in[u]);
            else{
                if(chek(u)) cout<< 1<< "\n";
                else cout<< 0<< "\n";
            }
        }
    }

    return 0;
}
