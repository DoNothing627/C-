//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "INTERSEQ"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, s= 0, a[mn], f[mn], g[mn];
ii I[4* mn];

void BUFF()
{
    forr(i, 1, n)
        f[i]= f[i- 1]+ a[i];

    forr(i, 1, n)
    {
        int res= 0;
        forr(j, i+ 1, n)
        {
            if(f[j- 1]- f[i- 1]<= m&& f[2* j- i- 1]- f[j- 1]<= m&& 2* j- i- 1<= n) res= max(res, 2* (j- i));
        }
        cout<< res<< "\n";
    }
}

void up(int k, int l, int r, int u, int v, int val)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v){
        I[k].x= max(I[k].x, val);
        I[k].y= max(I[k].y, val);
        return;
    }
    int mid= (l+ r)/ 2;
    if(I[k].y){
        up(2* k, l, mid, l, r, I[k].y);
        up(2* k+ 1, mid+ 1, r, l, r, I[k].y);
        I[k].y= 0;
    }
    up(2* k, l, mid, u, v, val);
    up(2* k+ 1, mid+ 1, r, u, v, val);
    I[k].x= max(I[2* k].x, I[2* k+ 1].x);
}

int get(int k, int l, int r, int u)
{
    if(l> u|| r< u) return 0;
    if(l== r) return I[k].x;
    int mid= (l+ r)/ 2;
    if(I[k].y){
        up(2* k, l, mid, l, r, I[k].y);
        up(2* k+ 1, mid+ 1, r, l, r, I[k].y);
        I[k].y= 0;
    }
    return max(get(2* k, l, mid, u), get(2* k+ 1, mid+ 1, r, u));
}

void COW()
{

    forr(i, 1, 4* n)
        I[i].x= I[i].y= 0;

    int r= 0;
    forr(i, 1, n)
    {
        while(r<= n&& s<= m)
        {
            ++r;
            s+= a[r];
        }
        f[i]= r- 1;
        s-= a[i];
    }

    s= 0, r= n+ 1;

    for(int i= n; i> 0; i--)
    {
        while(r> 0&& s<= m)
        {
            --r;
            s+= a[r];
        }
        g[i]= r+ 1;
        s-= a[i];
    }

    //forr(i, 1, n) cout<< f[i]<< " ";

    forr(i, 1, n- 1)
    {
        int u= g[i], v= f[i+ 1];
        if(v- i< i+ 1- u) u= i+ 1- v+ i;
        up(1, 1, n, u, i, i);
    }

    forr(i, 1, n- 1)
    {
        int ans= get(1, 1, n, i);
        cout<< 2* (ans- i+ 1)<< "\n";
    }
    cout<< 0;

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, n) cin>> a[i];

    if(n<= 1000) BUFF();
    else COW();

    return 0;
}
