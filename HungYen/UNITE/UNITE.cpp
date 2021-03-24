//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define LL unsigned long long
#define DoNothing "UNITE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, a, b, c;
LL ans, MOD= 1<< 64;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> a>> b>> c;

    forr(i, 1, m)
    {
        cin>> a[i].x>> a[i].y;
        if(a[i].x> a[i].y) swap(a[i].x, a[i].y);
    }

    forr(i, 1, n)
    {
        if(m== 0){
            ans= (ans+ 1LL* c* (i- 1)* i/ 2+ 1LL * b* (i- 1)* (n- i)/ 2+ 1LL* c* (n- i)* (n- i+ 1)/ 2)% MOD;
        }
        if(m== 1){
            if(a[i].y< i&& i> 2){
                ans= (ans+ 1LL* c* (i- 3)* (i- 2)/ 2+ 1LL * b* (i- 1)* (n- i)/ 2+ 1LL* c* (n- i)* (n- i+ 1)/ 2)% MOD;
                continue;
            }


        }
    }

    return 0;
}
