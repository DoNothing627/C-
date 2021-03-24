//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1505
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "CAKECUT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, f[mn][mn], c, d, res= 0;
bitset< mn> bit[mn], a;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, n)
    {
        forr(j, 1, m)
        {
            char u;
            cin>> u;
            int v= u- '0';
            f[i][j]= (f[i- 1][j]+ f[i][j- 1]- f[i- 1][j- 1]+ v)% 2;
            while(f[i][j]< 0) f[i][j]+= 2;
            if(f[i][j]) bit[i].set(j, 1);
        }
    }

    forr(i, 0, n)
    {
        forr(j, i+ 1, n)
        {
            a= bit[i]^ bit[j];
            c= a.count();
            d= m- c;
            res+= c* (c- 1)/ 2+ d* (d+ 1)/ 2;
        }
    }

    cout<< res;

    return 0;
}
