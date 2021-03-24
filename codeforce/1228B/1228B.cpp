//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1228B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, c, d[mn][mn], ans;
long long res= 1;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    forr(i, 1, n)
        forr(j, 1, m)
            d[i][j]= -1;

    forr(i, 1, n){
        cin>> c;
        forr(j, 1, c) d[i][j]= 1;
        d[i][c+ 1]= 0;
    }

    /*forr(i, 1, n)
    {
        forr(j, 1, m)
            cout<< d[i][j]<< " ";
        cout<< "\n";
    }*/

    forr(i, 1, m){
        cin>> c;
        forr(j, 1, c)
        {
            if(d[j][i]== 0) ans= 1;
            d[j][i]= 1;
        }
        if(d[c+ 1][i]== 1) ans= 1;
        d[c+ 1][i]= 0;
    }

    if(ans){
        cout<< 0;
        return 0;
    }

    forr(i, 1, n)
        forr(j, 1, m)
            if(d[i][j]== -1) ++ans;

    forr(i, 1, ans)
        res= (res* 2)% oo;

    cout<< res;

    return 0;
}
