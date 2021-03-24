//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 305
#define pb push_back
#define oo 1000000000000007
//#define int long long
#define DoNothing "BONUS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q, a[mn];
long long f[mn][mn][mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> q;
    forr(i, 1, n) cin>> a[i];

    forr(i, 1, n)
        forr(j, 1, n)
            forr(k, 0, q)
                f[i][j][k]= -oo;

    forr(i, 1, n)
    {
        f[i- 1][i][0]= 0;
        f[i][i][0]= 0;
    }

    forr(k, 1, q){
        for(int i= n; i> 0; i--)
        {
            forr(j, i+ 1, n)
                f[i][j][k]= max(f[i+ 2][j][k- 1]+ abs(a[i]- a[i+ 1]),
                            max(f[i][j- 2][k- 1]+ abs(a[j]- a[j- 1]),
                            max(f[i+ 1][j- 1][k- 1]+ abs(a[i]- a[j]),
                            max(f[i+ 1][j][k], f[i][j- 1][k]))));
        }
    }

    cout<< f[1][n][q];

    return 0;
}
