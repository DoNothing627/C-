//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1208D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], I[mn];
vector< int> v;


void up(int x)
{
    int val= x;
    while(x<= n){
        I[x]+= val;
        x+= (x& (- x));
    }
}

int get(int x)
{
    int res= 0;
    while(x> 0){
        res+= I[x];
        x-= (x& (- x));
    }
    return res;
}

int fid(int x)
{
    int l= 1, r= n+ 1;
    while(r- l> 1)
    {
        int m= (l+ r)/ 2;
        if(2* x+ m+ 2* get(m- 1)< m* m) r= m;
        else l= m;
    }
    return l;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> a[i];

    for(int i= n; i> 0; --i)
    {
        int x= fid(a[i]);
        v.pb(x), up(x);
    }

    reverse(v.begin(), v.end());

    for(auto c: v) cout<< c<< " ";

    return 0;
}
