//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1353E"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, k, a[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    while(t--){
        cin>> n>> k;
        char x;
        int ans= 0, res= oo;
        ++k;
        forr(i, 1, k) a[i]= 0;
        forr(i, 1, n){
            cin>> x;
            if(x== '1'){
                ++a[i% k];
                ++ans;
            }
        }


        forr(i, 1, k)
        {
            int c= n/ k;
            if(i<= n% k) ++c;
            res= min(res, ans+ c- 2* a[i]);
        }

        cout<< res<< "\n";
    }

    return 0;
}
