//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "PW"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, k, lazy[4* mn], X, Y, res= 0, I[4* mn], save;
//ii I[4* mn];

struct data
{
    int funk, up, down, type;
    data(){};
    data(int _funk, int _up, int _down, int _type){
        funk= _funk, up= _up, down= _down, type= _type;
    }
}p[2* mn];

bool cmp(data A, data B)
{
    return A.funk== B.funk? A.type< B.type: A.funk< B.funk;
}

void up(int k, int l, int r, int u, int v, int val)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v)
    {
        I[k]+= val;
        lazy[k]+= val;
        return;
    }
    int mid= (l+ r)/ 2;
    if(lazy[k]!= 0){
        up(2* k, l, mid, l, r, lazy[k]);
        up(2* k+ 1, mid+ 1, r, l, r, lazy[k]);
        lazy[k]= 0;
    }
    up(2* k, l, mid, u, v, val);
    up(2* k+ 1, mid+ 1, r, u, v, val);
    I[k]= max(I[2* k], I[2* k+ 1]);
}

int get(int k, int l, int r, int u)
{
    if(l> u|| r< u) return 0;
    if(l== r) return I[k];
    int mid= (l+ r)/ 2;
    if(lazy[k]!= 0){
        up(2* k, l, mid, l, r, lazy[k]);
        up(2* k+ 1, mid+ 1, r, l, r, lazy[k]);
        lazy[k]= 0;
    }
    return max(get(2* k, l, mid, u), get(2* k+ 1, mid+ 1, r, u));
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> k;
    forr(i, 1, m)
    {
        int x1, y1, x2, y2;
        cin>> x1>> y1>> x2>> y2;
        x1= max(1, x1- k+ 1);
        y1= max(1, y1- k+ 1);
        p[i]= data(x1, y1, y2, 0);
        p[i+ m]= data(x2, y1, y2, 1);
    }

    m*= 2;
    sort(p+ 1, p+ m+ 1, cmp);

    forr(i, 1, m)
    {
        if(!p[i].type)
            up(1, 1, n, p[i].up, p[i].down, 1);
        else
            up(1, 1, n, p[i].up, p[i].down, -1);
        if(res< I[1]){
            res= I[1];
            X= p[i].funk;
            save= i;
        }
    }

    cout<< res<< "\n"<< X<< " ";
    memset(I, 0), memset(lazy, 0);
    res= 0;
    forr(i, 1, save)
    {
        if(!p[i].type)
            up(1, 1, n, p[i].up, p[i].down, 1);
        else
            up(1, 1, n, p[i].up, p[i].down, -1);
    }


    forr(i, 1, n)
    {
        int ans= get(1, 1, n, i);
        if(res< ans) res= ans, Y= i;
    }

    cout<< Y;

    return 0;
}
