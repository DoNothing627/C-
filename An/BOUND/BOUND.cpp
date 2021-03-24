//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "BOUND"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], l[mn], r[mn], I[3* mn], m, M, res= 0;

vector< int> h;

void up(int x)
{
    while(x<= 3* n){
        ++I[x];
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x){
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

    cin>> n>> m>> M;

    h.pb(0);

    forr(i, 1, n){
        cin>> a[i];
        a[i]+= a[i- 1];
        l[i]= a[i]- M, r[i]= a[i]- m;
        //h[i]= a[i], h[n+ i]= l[i], h[2* n+ i]= r[i];
        h.pb(a[i]), h.pb(l[i]), h.pb(r[i]);
    }

    sort(h.begin(), h.end());

    int c= lower_bound(h.begin(), h.end(), 0)- h.begin();
    up(++c);

    forr(i, 1, n){
        a[i]= lower_bound(h.begin(), h.end(), a[i])- h.begin();
        up(++a[i]);
        l[i]= lower_bound(h.begin(), h.end(), l[i])- h.begin();
        r[i]= lower_bound(h.begin(), h.end(), r[i])- h.begin();
        res+= (get(++r[i])- get(l[i]));
    }

    cout<< res;

    return 0;
}
