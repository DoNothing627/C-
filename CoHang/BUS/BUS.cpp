//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "BUS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

typedef pair< int, ii> iii;

int n, m, s, t, res= oo;

int fs(int u)
{
    if(!r[u]) return u;
    return r[u]= fs(r[u]);
}

bool chek(int mid, int c)
{
    memset(r, 0);
    for(int i= 0; i<= c; i++)
    {
        int u= a[i].y.x, v= a[i].y.y;
        if(fs(u)== fs(v)) continue;
        r[u]= fs(v);
    }
    for(int i= 0; i< mid; i++)
    {
        int u= b[i].y.x, v= b[i].y.y;
        if(fs(u)== fs(v)) continue;
        r[u]= fs(v);
    }

    return fs(s)== fs(t);
}

void buff()
{
    for(int i= 0; i< a.size(); i++)
    {
        int w= a[i].x, u= a[i].y.x, v= a[i].y.y, l= 0, b.size()+ 1;
        while(r- l> 1){
            int mid= (r+ l)/ 2;
            if(chek(mid, i)) r= mid;
            else mid= l;
        }

        res= min(res, w+ b[mid].x);
    }
}

void cow()
{
    int i= 0, j= b.size()- 1;
    while(i< a.size()){

    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> s>> t;

    forr(i, 1, m){
        int c, u, v, w;
        cin>> c>> u>> v>> w;
        if(c== 1)
            a.pb(iii(w, ii(u, v)));
        else
            b.pb(iii(w, ii(u, v)));
    }

    a.pb(iii(0, ii(n+ 1, n+ 1)));
    b.pb(iii(0, ii(n+ 1, n+ 1)));

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a.size()<= 5000&& b.size()<= 5000) buff();

    else cow();

    cout<< res;

    return 0;
}
