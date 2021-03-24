//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "QUEENS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, res;
bool a[15][15];
bool d[15], l[50], r[50];

void reSet()
{
    for(int i= 1; i<= n; ++i)
        for(int j= 1; j<= n; ++j)
            a[i][j]= false;
    res= 0;
}
void rcs(int x)
{
    if(x== n)
    {
        ++res;
        return;
    }
    ++x;
    for(int i= 1; i<= n; i++)
    {
        if(a[x][i]|| d[i]|| l[i- x+ 15]|| r[i+ x]) continue;
        d[i]= true, l[i- x+ 15]= true, r[i+ x]= true;
        rcs(x);
        d[i]= false, l[i- x+ 15]= false, r[i+ x]= false;
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    while(cin>> n>> k)
    {
        if(!n) break;
        reSet();
        for(int i= 1; i<= k; ++i)
        {
            int u, v;
            cin>> u>> v;
            a[u][v]= true;
        }
        rcs(0);
        cout<< res<< "\n";
    }

    return 0;
}
