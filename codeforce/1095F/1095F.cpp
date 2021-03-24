//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 400005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1095F"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, c[mn], res= 0, r[mn], N= 0;
typedef pair< int, ii> iii;
iii a[mn];

int fs(int u)
{
    return !r[u]? u: r[u]= fs(r[u]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    int o= 0;
    c[0]= 1e13;

    forr(i, 1, n){
        cin>> c[i];
        if(c[o]> c[i]) o= i;
    }

    forr(i, 1, m)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[++N]= iii(w, ii(u, v));
    }

    forr(i, 1, n)
    {
        if(i== o) continue;
        a[++N]= iii(c[o]+ c[i], ii(o, i));
        //cout<< c[o]+ c[i]<< " "<< i<< "\n";
    }


    m= N;
    sort(a+ 1, a+ m+ 1);

    forr(i, 1, m)
    {
        int fu= fs(a[i].y.x), fv= fs(a[i].y.y);
        if(fu!= fv)
        {
            r[fu]= fv;
            res+= a[i].x;
        }
    }

    cout<< res;

    return 0;
}
