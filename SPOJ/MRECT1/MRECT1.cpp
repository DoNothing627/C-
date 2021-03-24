//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 5000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "MRECT1"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, N, X[mn], Y[mn];
ii a[mn], u[100005], v[100005];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    //cin>> n;
    scanf("%ld", &n);
    forr(i, 1, n)
    {
        //cin>> a[i].x>> a[i].y;
        scanf("%ld%ld", & a[i].x, & a[i].y);
        X[i]= a[i].x, Y[i]= a[i].y;
    }

    //cin>> m;
    scanf("%ld", &m);
    forr(i, 1, m)
    {
        //cin>> u[i]>> v[i];
        scanf("%ld%ld%ld%ld", & u[i].x, & v[i].x, & u[i].y, & v[i].y);
        X[n+ i]= u[i].x, Y[n+ i]= v[i].x;
        X[m+ n+ i]= u[i].y, Y[m+ n+ i]= v[i].y;
    }

    int N= n+ 2* m;

    sort(X+ 1, X+ N+ 1);
    sort(Y+ 1, Y+ N+ 1);

    forr(i, 1, n)
    {
        a[i].x= lower_bound(X+ 1, X+ N+ 1, a[i].x)- X;
        a[i].y= lower_bound(Y+ 1, Y+ N+ 1, a[i].y)- Y;
        c[0][a[i].x].pb(a[i].y);
        c[1][a[i].y].pb(a[i].x);
    }

    forr(i, 1, n){
        c[0][i].sort(c[0][i].begin(), c[0][i].end());
        c[1][i].sort(c[1][i].begin(), c[1][i].end());
    }

    forr(i, 1, m)
    {
         l= up
    }

    return 0;
}
