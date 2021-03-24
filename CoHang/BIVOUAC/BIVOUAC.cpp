//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "BIVOUAC"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int m, n, res, f[mn][mn][2];
ii a[mn], b[mn];


int d(ii A, ii B)
{
    return (A.x- B.x)* (A.x- B.x)+ (A.y- B.y)*(A.y- B.y);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> m>> n;
    forr(i, 1, m)
    cin>> a[i].x>> a[i].y;

    forr(i, 1, n)
    cin>> b[i].x>> b[i].y;

    memset(f, 40);
    f[1][0][0]= 0;

    forr(i, 1, m)
    forr(j, 0, n)
    {
        if(i== 1&& !j) continue;
        f[i][j][0]= min(f[i][j][0], f[i- 1][j][0]+ d(a[i- 1], a[i]));
        f[i][j][0]= min(f[i][j][0], f[i- 1][j][1]+ d(b[j], a[i]));
        f[i][j][1]= min(f[i][j][1], f[i][j- 1][0]+ d(a[i], b[j]));
        f[i][j][1]= min(f[i][j][1], f[i][j- 1][1]+ d(b[j- 1], b[j]));
    }

    res= min(f[m- 1][n][0]+ d(a[m- 1], a[m]), f[m- 1][n][1]+ d(a[m], b[n]));

    cout<< res;

    return 0;
}
