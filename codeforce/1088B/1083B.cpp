//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1083B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, t, a[mn], ans= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> t;

    forr(i, 1, n) cin>> a[i];

    sort(a+ 1, a+ n+ 1);

    int c= 1;
    while(!a[c]) ++c;

    while(t--){
        if(a[c]== ans){
            while(c<= n&& a[c]== ans) ++c;
            if(c== n+ 1){
                cout<< 0<< "\n";
                --c;
                continue;
            }
        }
        int d= a[c];
        cout<< a[c]- ans<< "\n";
        ans= d;
        if(c< n) ++c;
    }

    return 0;
}
