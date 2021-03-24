//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000009
//#define int long long
#define DoNothing "TEAM"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, k, a[mn], b[mn], f[mn][mn][11];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> k;

    forr(i, 1, n) cin>> a[i];
    forr(j, 1, m) cin>> b[j];

    sort(a+ 1, a+ n+ 1);
    sort(b+ 1, b+ m+ 1);

    //f[0][0][0]= 1;
    forr(i, 0, n)
    forr(j, 0, m)
    f[i][j][0]= 1;

    forr(i, 1, n)
    {
        forr(j, 1, m)
        {
            forr(c, 1, k)
            {
                f[i][j][c]= (f[i][j- 1][c]+ f[i- 1][j][c]- f[i- 1][j- 1][c])% oo;
                if(a[i]> b[j]&& c) f[i][j][c]= (f[i][j][c]+ f[i- 1][j- 1][c- 1])% oo;
            }
        }
    }

    cout<< f[n][m][k];

    return 0;
}
