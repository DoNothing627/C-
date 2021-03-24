//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "TWOSAT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, a[mn], c[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, n)
    {
        int u, v;
        cin>> u>> v;
        if(u> 0) ++a[u];
        else ++c[-u];
        if(v> 0) ++c[u];
        else ++c[-u];
        d[i][2]= {u, v};
    }

    forr(i, -m, -1)
        q.push

    return 0;
}
