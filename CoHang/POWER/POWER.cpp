//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "POWER"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, k, I[mn], res= 0, z, c, h[mn];
typedef pair< int, ii> iii;
iii p[mn];

void up(int x)
{
    while(x<= n)
    {
        ++I[x];
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0)
    {
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

bool cmp(iii A, iii B)
{
    return A.y.x> B.y.x;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;
    forr(i, 1, n)
        cin>> p[i].x>> p[i].y.x;

    sort(p+ 1, p+ n+ 1, cmp);
    forr(i, 1, n) h[i]= p[i].y.x;
    forr(i, 1, n)
        p[i].y.y= i;

    sort(p+ 1, p+ n+ 1);
    //--k;

    forr(i, 1, n)
    {
        int l= 0, r= n+ 1;
        c= k;
        if(p[i].y.y- get(p[i].y.y)>= c) --c;
        while(r- l> 1)
        {
            int m= (l+ r)/ 2;
            if(m- get(m)< c) l= m;
            else r= m;
        }
        if(r<= n){
            if(c== k) z= h[r];
            else z= p[i].y.x;
            res= max(res, p[i].x* z);
        }
        up(p[i].y.y);
    }

    cout<< res;

    return 0;
}
