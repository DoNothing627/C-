//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 405
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "BGBOARD"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, a[mn][mn], F[mn][mn][mn], d[1000005], e[1000005], c, res= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> m>> n;

    forr(i, 1, m)
    forr(j, 1, n)

    cin>> a[i][j];

    forr(i, 1, m)
    {
        forr(j, 1, n){
           F[i][i][j]= d[a[i][j]];
           res= max(res, j- d[a[i][j]]);
           d[a[i][j]]= j;
        }
        forr(j, 1, n) d[a[i][j]]= 0;
    }

    forr(j, 2, m)
    {
        forr(i, 1, m)
        {
            c= i+ j- 1;
            if(c> m) break;
            forr(k, 1, n)
            {
                F[i][c][k]= max(F[i][c- 1][k], max(F[i+ 1][c][k], F[i][c][k- 1]));
                if(a[i][k]!= a[c][k]) F[i][c][k]= max(F[i][c][k], max(d[a[i][k]], e[a[c][k]]));
                else F[i][c][k]= k;
                res= max(res, j* (k- F[i][c][k]));
                d[a[i][k]]= k;
                e[a[c][k]]= k;
            }
            forr(k, 1, n) d[a[i][k]]= e[a[c][k]]= 0;
        }
    }

    cout<< res;
    return 0;
}
