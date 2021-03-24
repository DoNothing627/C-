//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "NUMTRANS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int a, b, c, res= 0, va[1500], vb[1500], m= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> a>> b>> c;

    int u= __gcd(a, b);

    a/= u, b/= u;

    forr(i, 1, sqrt(a))
        if(a% i== 0){
            if(i!= 1) va[++m]= i;
            if(i!= a/ i) va[++m]= a/ i;
        }

    sort(va+ 1, va+ m+ 1);

    while(a> 1){
        for(int i= m; i> 0; i--)
        {
            if(va[i]> c) continue;
            if(a% va[i]== 0){
                a/= va[i];
                m= i;
                goto over;
            }
        }
        cout<< -1;
        return 0;
        over:;
        ++res;
    }

    m= 0;
    forr(i, 1, sqrt(b))
        if(b% i== 0){
            if(i!= 1) vb[++m]= i;
            if(i!= b/ i) vb[++m]= b/ i;
        }

    sort(vb+ 1, vb+ m+ 1);

    while(b> 1){
        for(int i= m; i> 0; i--)
        {
            if(vb[i]> c) continue;
            if(b% vb[i]== 0){
                b/= vb[i];
                m= i;
                goto END;
            }
        }
        cout<< -1;
        return 0;
        END:;
        ++res;
    }

    cout<< res;

    return 0;
}
