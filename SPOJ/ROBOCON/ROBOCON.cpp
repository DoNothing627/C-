//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 505
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "ROBOCON"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, a[mn][mn], c[mn][mn][755], d[mn][mn][755], f[mn][mn], res= oo;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    /*freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;
    forr(i, 1, k)
    {
        int u, v;
        cin>> u>> v;
        f[u][v]= 1;
    }

    c[1][1][0]= d[1][n][0]= 1;

    forr(i, 1, n)
        forr(j, 1, n)
            if(!f[i][j]&& (i!= 1|| j!= 1))
                    forr(o, 0, (3* n)/ 2)
                        if(c[i- 1][j][o]|| c[i][j- 1][o]|| c[i- 1][j- 1][o]) c[i][j][o+ 1]= 1;

    forr(i, 1, n)
        for(int j= n; j> 0; j--)
            if(!f[i][j]&& (i!= 1|| j!= n))
                    forr(o, 0, (3* n)/ 2)
                        if(d[i- 1][j][o]|| d[i][j+ 1][o]|| d[i- 1][j+ 1][o]) d[i][j][o+ 1]= 1;

    forr(i, 1, n)
        forr(j, 1, n)
            if(!f[i][j])
                    forr(o, 0, (3* n)/ 2)
                        if(c[i][j][o]&& d[i][j][o]){
                            res= min(res, o);
                            break;
                        }

    cout<< res;*/

    int a= 7 ^ 2, b= 5| 1;

    cout<< a+ b;

    return 0;
}
