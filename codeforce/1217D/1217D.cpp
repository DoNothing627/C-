//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1217D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;


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
        s.pb(v), a[u].pb(s.size());
        s.pb(u), a[v].pb(s.size());
    }

    forr(i, 1, n)
    {
        dfs(i);
    }

    return 0;
}
