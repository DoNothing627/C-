//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 110005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "PAINTBOX"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, w, q, a[mn], MIN, MAX, h[mn], c[mn], d[mn];
ii T[4* mn], lazy[4* mn];

void upmax(int k, int l, int r, int u, int v, int val)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v){
        I[k].x= val;
        lazy[k].x= val;
        return;
    }
    int mid= (l+ r)/ 2;
    if(lazy[k].x)
    {
        upmax(2* k, l, mid, l, r, lazy[k].x);
        upmax(2* k+ 1, mid+ 1, r, l, r, lazy[k].x);
        lazy[k].x= 0;
    }
    upmax(2* k, l, mid, u, v, val);
    upmax(2* k+ 1, mid+ 1, r, u, v, val);
}

void upmin(int k, int l, int r, int u, int v, int val)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v){
        I[k].y= val;
        lazy[k].y= val;
        return;
    }
    int mid= (l+ r)/ 2;
    if(lazy[k].y)
    {
        upmin(2* k, l, mid, l, r, lazy[k].y);
        upmin(2* k+ 1, mid+ 1, r, l, r, lazy[k].y);
        lazy[k].y= 0;
    }
    upmin(2* k, l, mid, u, v, val);
    upmin(2* k+ 1, mid+ 1, r, u, v, val);
}

void getmax(int k, int l, int r, int u)
{
    if(l> u|| r< u) return;
    if(l== r) return MAX= I[k].x;
    int mid= (l+ r)/ 2;
    if(lazy[k].x)
    {
        upmax(2* k, l, mid, l, r, lazy[k].x);
        upmax(2* k+ 1, mid+ 1, r, l, r, lazy[k].x);
        lazy[k].x= 0;
    }
    getmax(2* k, l, mid, u);
    getmax(2* k+ 1, mid+ 1, r, u);
}


void getmin(int k, int l, int r, int u)
{
    if(l> u|| r< u) return;
    if(l== r) return MIN= I[k].y;
    int mid= (l+ r)/ 2;
    if(lazy[k].y)
    {
        upmin(2* k, l, mid, l, r, lazy[k].y);
        upmin(2* k+ 1, mid+ 1, r, l, r, lazy[k].y);
        lazy[k].y= 0;
    }
    getmin(2* k, l, mid, u);
    getmin(2* k+ 1, mid+ 1, r, u);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        RESET();
        cin>> n>> w;
        forr(i, 1, n){
            cin>> a[i];
            h[i]= a[i];
        }
        cin>> q;
        forr(i, 1, q)
        {
            cin>> d[i]>> c[i];
            h[i+ n]= c[i];
        }
        sort(h+ 1, h+ q+ n+ 1);
        forr(i, 1, n)
        {
            a[i]= lower_bound(h+ 1, h+ n+ q+ 1, a[i])- h;
            if(a[i]!= a[i- 1]){
                if(save){
                    upmin(1, 1, n, save, i- 1, save);
                    upmax(1, 1, n, save, i- 1, i- 1);
                    res+= max(0, (i- save- w+ 1));
                }
                save= i;
            }

        forr(i, 1, q)
        {
            c[i]= lower_bound(h+ 1, h+ n+ q+ 1, c[i])- h;
            if(c[i]== a[d[i]]){
                cout<< res<< "\n";
                continue;
            }

            if(a[d[i]]== a[d[i]+ 1]&& a[d[i]]== a[d[i]- 1]){
                getmin(1, 1, n, d[i]);
                getmax(1, 1, n, d[i]);
                res-= max(0, MAX- MIN+ 1- w+ 1);
                res+= max(0, d[i]- MIN- w+ 1);
                res+= max(0, MAX- d[i]- w+ 1);
                upmin(1, 1, n, d[i]+ 1, MAX, d[i]+ 1);
                upmax(1, 1, n, MIN, d[i]- 1, MIN);
                a[d[i]]= c[i];
                upmin(1, 1, n, d[i], d[i], d[i]);
                upmax(1, 1, n, d[i], d[i], d[i]);
            }
            else{
                if(c[i]== a[d[i]+ 1]&& c[i]== a[d[i]- 1]){
                    getmin(1, 1, n, d[i]- 1);
                    getmax(1, 1, n, d[i]+ 1);
                    res-= max(0, d[i]- MIN- w+ 1);
                    res-= max(0, MAX- d[i]- w+ 1);
                    res-= max(0, MAX- MIN+ 1- w+ 1);
                    upmin(1, 1, n, d[i], d[i], MIN);
                    upmax(1, 1, n, d[i], d[i], MAX);
                    a[d[i]]= c[i];
                    if(w== 1) --res;
                }
                else{
                    if(a[d[i]]== a[d[i]- 1])

                }
            }

        }
    }

    return 0;
}
