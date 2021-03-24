//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1081C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, d[mn];
vector< int> v[mn];


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    forr(i, 1, n)
    {
        int s, r;
        cin>> s>> r;
        v[s].pb(r);
    }

    memset(d, 0);

    forr(i, 1, m)
    {
        sort(v[i].begin(), v[i].end());
        int c= v[i].size(), ans= 0;
        for(int j= c- 1; j>= 0; j--)
        {
            int z= c- j;
            ans+= v[i][j];
            if(ans> 0) d[z]+= ans;
        }
    }


    int res= 0;

    forr(i, 1, n)
    res= max(res, d[i]);

    cout<< res;

    return 0;
}
