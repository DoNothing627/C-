//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1048580
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "SOPENP"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, l, r, z[mn], d[mn], c= 0, j= 0;
long long res= 0, h[mn], a[mn];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> l>> r;

    forr(i, 1, n)
    {
        cin>> a[i];
        h[i]= a[i];
    }

    sort(h+ 1, h+ n+ 1);

    forr(i, 1, n)
        a[i]= lower_bound(h+ 1, h+ n+ 1, a[i])- h;


    forr(i, 1, n)
    {
         --d[a[i- 1]];
         if(d[a[i- 1]]== 0) --c;
         while(j<= n&& c< l){
             ++d[a[++j]];
             if(d[a[j]]== 1) ++c;
         }
         z[i]= j- 1;
    }

    //forr(i, 1, n) cout<< z[i]<< " ";
    memset(d, 0);
    c= 0, j= 0;

    forr(i, 1, n)
    {
         --d[a[i- 1]];
         if(d[a[i- 1]]== 0) --c;
         while(j<= n&& c<= r){
             ++d[a[++j]];
             if(d[a[j]]== 1) ++c;
         }
         res+= j- z[i]- 1;
    }

    cout<< res;

    return 0;
}
