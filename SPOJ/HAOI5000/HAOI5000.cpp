//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 2000005
#define pb push_back
#define oo 100000000007
#define int long long
#define DoNothing "HAOI5000"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, k, a[mn], f[mn], r, d[mn];
vector< int> v;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;
    forr(i, 1, k){
        int u;
        cin>> u;
        ++a[u];
    }
    if(n% 2) r= n/ 2;
    else r= n/ 2- 1;


    forr(i, 1, n)
        a[i+ n]= a[i];

    forr(i, 1, 2* n)
    f[i]= f[i- 1]+ a[i];

    forr(i, 1, n)
    d[n/ 2+ 1]+= abs(i- n/ 2- 1)* a[i];
    int res= d[n/ 2+ 1];

    forr(i, n/ 2+ 2, n+ n/ 2)
    {
        d[i]= d[i- 1]+ f[i- 1]- f[i- n/ 2- 1]- a[i- n/ 2- 1]* (n/ 2);
        d[i]= d[i]+ f[i- 1]- f[i+ r- 1]+ a[i+ r]* r;
        if(d[i]< res) res= d[i];
    }

    forr(i, n/ 2+ 1, n+ n/ 2)
    {
        if(d[i]== res){
            if(i> n) v.pb(i- n);
            else v.pb(i);
        }
    }

    cout<< res<< "\n"<< v.size()<< "\n";
    for(auto u: v) cout<< u<< " ";

    return 0;
}
