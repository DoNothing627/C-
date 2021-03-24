//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1946D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], f[mn], g[mn], res, ans= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    forr(i, 1, n){
        cin>> a[i];
        if(a[i]> a[i- 1]&& i> 1) f[i]= f[i- 1]+ 1;
    }

    res= f[n];
    for(int i= n- 1; i> 0; i--)
    {
        if(a[i]> a[i+ 1]) g[i]= g[i+ 1]+ 1;
        res= max(res, max(g[i], f[i]));
    }

    forr(i, 1, n){
        if(f[i]<= g[i]) swap(f[i], g[i]);
        if(f[i]== res&& g[i]<= f[i]&& res% 2) ++ ans;
    }

    if(ans> 1|| res== 0|| res% 2) ans= 0;
    //ans= 1;

    cout<< ans;

    return 0;
}
