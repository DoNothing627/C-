//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 500005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "C11CAVE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, h, a[mn], b[mn], m, z, ans, res= oo;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> h;

    forr(i, 1, n)
    {
        int c;
        cin>> c;
        if(i% 2) a[++m]= c;
        else b[++z]= h- c+ 1;
    }

    sort(a+ 1, a+ m+ 1);
    sort(b+ 1, b+ z+ 1);

    forr(i, 1, h)
    {
        int c, d;
        c= lower_bound(a+ 1, a+ m+ 1, i)- a;
        d= upper_bound(b+ 1, b+ z+ 1, i)- b;
        int C= m- c+ d;
        if(C== res) ++ans;
        else if(C< res){
            res= C;
            ans= 1;
        }
    }

    cout<< res<< " "<< ans;

    return 0;
}
