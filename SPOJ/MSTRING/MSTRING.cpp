//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "MSTRING"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, f[1005][1005];
string a, b;


int rcs(int x, int y)
{
    if(x== n) return oo;
    if(f[x][y]>= 0) return f[x][y];


    forr(i, y, m- 1)
    {
        if(a[x]== b[i])
        {
            f[x][y]= min(rcs(x+ 1, y), 1+ rcs(x+ 1, i+ 1));
            return f[x][y];
        }
    }
    return 1;
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> a>> b;

    n= a.size(), m= b.size();
    //a= " "+ a, b= " "+ b;

    memset(f, -1);

    cout<< rcs(0, 0);

    return 0;
}
