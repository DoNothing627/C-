//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 4005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1382D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, a[mn], c[mn], l[mn], r[mn], f[mn], COUNT;
//vector< int> v[2];

void RESET()
{
    f[0]= 1;
    forr(i, 1, n)
        f[i]= 0, l[i]= 0, c[i]= 0, r[i]= 0;
    a[0]= oo;
    COUNT= 0;

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n;
        n*= 2;

        RESET();
        forr(i, 1, n){
            cin>> a[i];
            l[i]= i- 1;
            while(a[i]> a[l[i]])
                l[i]= l[l[i]];
            if(!l[i]) r[i]= ++COUNT;

            else r[i]= r[l[i]];

            ++c[r[i]];

        }


        forr(j, 1, n)
            for(int i= n/ 2; i> 0; i--)
                if(i>= c[j]) f[i]= max(f[i], f[i- c[j]]);

        cout<< (f[n/ 2]? "YES": "NO")<< "\n";
    }

    return 0;
}
