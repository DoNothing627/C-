//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "C11SEQ"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, l, r, a[mn], I[3* mn], h[3* mn], res= 0;


void up(int x)
{
    while(x<= 3* n+ 1)
    {
        ++I[x];
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0)
    {
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> l>> r;
    forr(i, 1, n)
    {
        cin>> a[i];
        a[i]+= a[i- 1];
        h[i]= a[i], h[i+ n]= a[i]- l, h[i+ 2* n]= a[i]- r;
    }

    sort(h, h+ 3* n+ 1);

    int c= lower_bound(h, h+ 3* n+ 1, 0)- h+ 1;
    up(c);

    forr(i, 1, n)
    {
        c= lower_bound(h, h+ 3* n+ 1, a[i]- l)- h+ 1;
        res+= get(c);
        c= lower_bound(h, h+ 3* n+ 1, a[i]- r)- h+ 1;
        res-= get(c- 1);
        c= lower_bound(h, h+ 3* n+ 1, a[i])- h+ 1;
        up(c);
    }

    cout<< res;

    return 0;
}
