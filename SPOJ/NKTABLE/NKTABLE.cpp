//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "NKTABLE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int m, n;
char a[505][505];
string f[505][505], s;

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

    f[1][1]= f[1][1]+ a[1][1];

    forr(i, 1, m)
        forr(j, 1, n)
        {
            if(a[i][j]== '2') continue;
            s= f[i][j];
            if(f[i- 1][j].size()) s= f[i- 1][j]+ a[i][j];
            if(f[i][j- 1].size()) s= max(s, f[i][j- 1]+ a[i][j]);
            f[i][j]= s;
        }

    cout<< f[m][n];
    return 0;
}
