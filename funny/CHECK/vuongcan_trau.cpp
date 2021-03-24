//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 5005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "vuongcan"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, f[mn][mn], c, res= 0;

main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".ans", "w", stdout);

    cin>> n;
    forr(i, 1, n)
        forr(j, 1, n)
        {
            cin>> c;
            if(c== 1) f[i][j]= min(f[i][j- 1], f[i- 1][j])+ 1;
            res= max(res, f[i][j]);
        }

    cout<< res;

    return 0;
}
