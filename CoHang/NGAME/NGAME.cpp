//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 5000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "NGAME"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a, b, d[mn], f[mn];


void snt()
{
    forr(i, 2, 5e6)
        if(!d[i]){
            d[i]= i;
            for(long long j= 1ll* i* i; j<= 5e6; j+= i)
                d[j]= i;
        }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> t;

    snt();

    forr(i, 2, 5e6)
    {
        int x= i;
        f[i]= f[i- 1];
        while(x> 1){
            ++f[i];
            x/= d[x];
        }
    }

    while(t--)
    {
        cin>> a>> b;
        cout<< f[a]- f[b]<< "\n";
    }

    return 0;
}
