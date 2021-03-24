//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 400005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "MINIONS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, res= 0, f[mn], h[mn], c[mn];
double ans, TU, MAU;
ii p[mn], I[mn];



void up(int u, int val)
{
    while(u<= n)
    {
        I[u].x+= val;
        ++I[u].y;
        u+= (u& (- u));
    }
}

ii get(int u)
{
    ii A;
    while(u> 0)
    {
        A.x+= I[u].x;
        A.y+= I[u].y;
        u-= (u& (- u));
    }
    return A;
}

bool cmp(ii A, ii B)
{
    return A.y< B.y;
}

void RESET()
{
    forr(i, 1, n){
        I[i].x= I[i].y= 0;
        int d= lower_bound(h+ 1, h+ n+ 1, p[i].y)- h;
        c[d]= 0;
    }
    res= 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    while(t--)
    {
        cin>> n;
        forr(i, 1, n)
            cin>> p[i].x>> p[i].y;
        sort(p+ 1, p+ n+ 1, cmp);
        forr(i, 1, n){
            f[i]= f[i- 1]+ p[i].y;
            h[i]= p[i].y;
        }

        sort(p+ 1, p+ n+ 1);
        forr(i, 1, n)
        {
            int d= lower_bound(h+ 1, h+ n+ 1, p[i].y)- h;
            ++c[d];
            d= d- 1+ c[d];
            TU= f[d]- get(d).x, MAU= d- get(d).y;
            ans= TU/ MAU;
            if(ans> p[i].x){
                up(d, p[i].y);
                continue;
            }
            int l= d, r= n+ 1;
            while(r- l> 1)
            {
                int m= (l+ r)/ 2;
                TU= f[m]- get(m).x, MAU= m- get(m).y;
                ans= TU/ MAU;
                if(ans> p[i].x) r= m;
                else l= m;
            }
            res= max(res, l- get(l).y);
            up(d, p[i].y);
        }

        cout<< res<< "\n";

        RESET();
    }

    return 0;
}
