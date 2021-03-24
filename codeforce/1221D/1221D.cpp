//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 300005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1221D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q;
ii a[mn];
priority_queue< int> pq;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> q;
    while(q--){

        int res= 0;

        cin>> n;
        forr(i, 1, n)
        {
            cin>> a[i].x>> a[i].y;
            //res-= a[i].x* a[i].y;
        }



        cout<< res<< "\n";

    }

    return 0;
}
