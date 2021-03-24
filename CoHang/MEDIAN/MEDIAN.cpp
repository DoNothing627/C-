//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "MEDIAN"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, a[mn], N, I[2* mn], c[mn], d[mn], h[2* mn];


void up(int x, int val)
{
    while(x<= N){
        I[x]+= val;
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0){
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
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    n= 2* n+ 1;
    forr(i, 1, n){
        cin>> a[i];
        h[i]= a[i];
    }

    forr(i, 1, m)
    {
        cin>> c[i]>> d[i];
        h[i+ n]= d[i];
        ++c[i];
    }

    N= n+ m;

    sort(h+ 1, h+ N+ 1);

    forr(i, 1, n)
    {
        a[i]= lower_bound(h+ 1, h+ N+ 1, a[i])- h;
        up(a[i], 1);
    }

    forr(i, 1, m)
    {
        up(a[c[i]], -1);
        a[c[i]]= lower_bound(h+ 1, h+ N+ 1, d[i])- h;
        up(a[c[i]], 1);
        int l= 0, r= N;
        while(r- l> 1){
            int mid= (l+ r)/ 2;
            if(2* get(mid)> n) r= mid;
            else l= mid;
        }
        cout<< h[r]<< "\n";
    }
    return 0;
}
