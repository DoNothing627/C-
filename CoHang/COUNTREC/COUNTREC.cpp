//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "COUNTREC"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, I[4* mn], lazy[4* mn];
typedef pair< ii, ii> iii;
iii p[mn]

void up(int k, int l, int r, int u, int v, int val)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v){
        I[k]+= val;
        lazy[k]+= val;
        return;
    }
    int mid= (l+ r)/ 2;
    if(lazy[k])
    {
        up(2* k, l, mid, l, r, lazy[k]);
        up(2* k+ 1, mid+ 1, r, l, r, lazy[k]);
        lazy[k]= 0;
    }
    up(2* k, l, mid, u, v, val);
    up(2* k, mid+ 1, r, u, v, val);
    I[k]= max(I[2* k], I[2* k+ 1]);
}

int get(int k, int l, int r, int u, int v)
{
    if(l> v|| r< u) return 0;
    if(l>= u&& r<= v) return I[k];
    int mid= (l+ r)/ 2;
    if(lazy[k])
    {
        up(2* k, l, mid, l, r, lazy[k]);
        up(2* k+ 1, mid+ 1, r, l, r, lazy[k]);
        lazy[k]= 0;
    }
    return max(get(2* k, l, mid, u, v), get(2* k+ 1, mid+ 1, r, u, v));
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        int x1, y1, x2, y2;
        cin>> x1>> y1>> x2>> y2;
        p[i]= iii(ii(y1, 0), ii(x1, x2));
        p[n+ i]= iii(ii(y2, 1), ii(x1, x2));
        m= max(m, x2);
    }

    sort(p+ 1, p+ 2* n+ 1);

    forr(i, 1, 2* n)
    {
        if(!p[i].x.y){
            if(!get(1, 1, m, p[i].y.x, p[i].y.y)) ++res;
            up(1, 1, m, p[i].y.x, p[i].y.y, 1);
        }
        else up(1, 1, m, p[i].y.x, p[i].y.y, -1);
    }

    cout<< res;

    return 0;
}
