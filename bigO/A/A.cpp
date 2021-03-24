//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, a[mn][3], f[mn], ans, res, cnt;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    forr(i, 1, m){
        int x, y;
        cin>> x>> y;
        ++a[x][y];
    }

    forr(i, 1, n){
        ans= 0, cnt= 0;
        forr(j, 1, 3) ans= max(ans, a[i][j]);
        forr(j, 1, 3)
        if(a[i][j]== ans){
            res= j;
            ++cnt;
        }
        if(cnt== 1) ++f[res];
    }

    cnt= 0, ans= 0;
    forr(i, 1, 3) ans= max(ans, f[i]);
    forr(i, 1, 3)
    if(f[i]== ans) res= i, ++cnt;

    if(cnt== 1) cout<< res;
    else cout<< 0;

    return 0;
}
