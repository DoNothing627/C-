//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1091C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a, c, d, m;
vector< int> v;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    //forr(i, 1, n) cin>> a[i];

    forr(i, 1, sqrt(n))
    {
        if(n% i== 0)
        {
            c= n+ 1- i, d= 1;
            m= (c- d)/ i+ 1;
            v.pb((d+ c)* m/ 2);
            a= n/ i;
            if(a!= i){
                c= n+ 1- a, d= 1;
                m= (c- d)/ a+ 1;
                v.pb((d+ c)* m/ 2);
            }
        }
    }

    sort(v.begin(), v.end());
    for(auto z: v) cout<< z<< " ";

    return 0;
}
