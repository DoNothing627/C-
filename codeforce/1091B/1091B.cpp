//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1091B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n;
ii a[mn], p[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    cin>> a[i].x>> a[i].y;

    forr(i, 1, n)
    cin>> p[i].x>> p[i].y;

    sort(a+ 1, a+ n+ 1);
    sort(p+ 1, p+ n+ 1);

    cout<< a[1].x+ p[n].x<< " "<< a[1].y+ p[n].y;

    return 0;
}
