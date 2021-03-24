//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1263C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n;

vector< int> v;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n;
        v.clear();
        forr(i, 1, sqrt(n))
        {
            v.pb(i);
            if(n/ i!= i) v.pb(n/ i);
        }
        v.pb(0);
        sort(v.begin(), v.end());
        cout<< v.size()<< "\n";
        for(auto u: v)
            cout<< u<< " ";
        cout<< "\n";
    }

    return 0;
}
