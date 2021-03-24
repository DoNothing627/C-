//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1096D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], f[mn][4], res= 1e18, u;
char s[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    cin>> s[i];
    forr(i, 1, n)
    cin>> a[i];

    forr(i, 1, n)
    {
        forr(j, 0, 3) f[i][j]= f[i- 1][j];
        if(s[i]== 'h') f[i][0]+= a[i];
        if(s[i]== 'a') f[i][1]+= a[i];
        if(s[i]== 'r') f[i][2]+= a[i];
        if(s[i]== 'd') f[i][3]+= a[i];
    }

    forr(i, 1, n)
    {
        if(s[i]== 'h') u= 0;
        if(s[i]== 'a') u= 1;
        if(s[i]== 'r') u= 2;
        if(s[i]== 'd') u= 3;

        forr(j, 0, u- 1)
        res= min(res, f[i][j]);
        forr(j, u+ 1, 3)
        res= min(res, f[n][j]- f[i][j]);
    }

    cout<< res;

    return 0;
}
