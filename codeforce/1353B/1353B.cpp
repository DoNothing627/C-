//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1353B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a[35], b[35], n, k;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> k;
        forr(i, 1, n) cin>> a[i];
        forr(i, 1, n) cin>> b[i];

        sort(a+ 1, a+ n+ 1);
        sort(b+ 1, b+ n+ 1);

        int i= 1;
        while(a[i]< b[n- i+ 1]&& i<= k&& i<= n){
            swap(a[i], b[n- i+ 1]);
            ++i;
        }

        int res= 0;

        forr(i, 1, n) res+= a[i];
        cout<< res<< "\n";
    }

    return 0;
}
