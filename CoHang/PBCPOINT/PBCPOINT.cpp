//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "PBCPOINT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, res= 0, d[2005];
ii p[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n){
        cin>> p[i].x>> p[i].y;
        p[i].x+= 1001;
        p[i].y+= 1001;
    }

    sort(p+ 1, p+ n+ 1);

    int i= 1, j= 1;

    while(i<= n)
    {
        if(!d[p[i].y]) ++res;
        else res+= p[i].x- d[p[i].y];
        d[p[i].y]= p[i].x;
        while(i<= n&& p[i].x== p[i+ 1].x){
            forr(j, p[i].x+ 1, p[i+ 1].x)
            {
                if(!d[j]) ++res;
                else res+= p[i].x- d[j];
                d[j]= p[i].x;
                ++i;
            }
        }
        ++i;
    }

    cout<< res;

    return 0;
}
