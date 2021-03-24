//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "LIQ"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;
int n, a[mn], f[mn], res= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
        cin>> a[i];
    forr(i, 1, n)
    {
        forr(j, 0, i- 1)
            if(a[i]> a[j]) f[i]= max(f[i], f[j]+ 1);
        res= max(res, f[i]);
    }

    cout<< res;

    return 0;
}
