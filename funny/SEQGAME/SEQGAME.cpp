//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000000
//#define int long long
#define DoNothing "SEQGAME"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, a[mn];

long long f(int x)
{
    long long res= 0;
    forr(i, 1, n)
        res+= abs(x+ (i- 1)* k- a[i]);
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;
    forr(i, 1, n) cin>> a[i];

    long long l= -oo- 1, r= oo+ 1, m1, m2;

    while(r- l> 2){
        m1= l+ (r- l)/ 3, m2= r- (r- l)/ 3;
        if(f(m1)< f(m2))
            r= m2;
        else l= m1;
    }

    cout<< min(f(m1), f(m2));

    return 0;
}
