//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1095D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, u, Next[mn], c= 0, a[mn][2];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    cin>> a[i][0]>> a[i][1];

    forr(i, 1, n)
    {
        u= a[i][0];
        if(a[u][0]== a[i][1]|| a[u][1]== a[i][1])
            Next[u]= a[i][1];
        else Next[a[i][1]]= u;
    }

    while(c< n){
        cout<< u<< " ";
        u= Next[u];
        ++c;
    }
    return 0;
}
