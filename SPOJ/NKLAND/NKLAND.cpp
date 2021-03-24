//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "NKLAND"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;


int t, n, m, d[mn][mn], bet;
ii p[mn], c, a[mn];
bool in, out, fake;

double ccw(ii O, ii A, ii B)
{
    A.x-= O.x, A.y-= O.y;
    B.x-= O.x, B.y-= O.y;
    return A.x* B.y- A.y* B.x;
}


void RESET()
{
    memset(d, 0);
    in=out= 0;
}


void lm()
{
    cin>> n;
    forr(i, 1, n) cin>> p[i].x>> p[i].y;
    p[n+ 1]= p[1];

    RESET();
    cin>> m;
    forr(i, 1, m)
    {
        cin>> c.x>> c.y;
        a[i]= ii(c.x, c.y);
        bet= 0, fake= 0;
        forr(i, 1, n)
        {
            double ans= ccw(c, p[i], p[i+ 1]);
            if(ans== 0&& !d[i][i+ 1])
            {
                ++bet;
                d[i][i+ 1]= 1;
            }
            if(ans< 0)
                fake= 1;
        }
        if(!fake)
            in= 1;
        else
            out= 1;
    }

    a[m+ 1]= a[1];

    if(bet> 1&& out){
        cout<< "YES\n";
        return;
    }

    if(!bet&& in && out){
        cout<< "YES\n";
        return;
    }

    RESET();
    forr(i, 1, n)
    {
        bet= 0, fake= 0;
        forr(j, 1, m)
        {
            double ans= ccw(p[i], a[j], a[j+ 1]);
            if(ans== 0&& !d[j][j+ 1])
            {
                ++bet;
                d[j][j+ 1]= 1;
            }
            if(ans< 0)
                fake= 1;
        }
        if(!fake)
            in= 1;
        else
            out= 1;
    }

    if(bet> 1)
    {
        if(in)
            cout<< "NO\n";
        else
            cout<< "YES\n";
    }
    else
    {
        if(in && out)
            cout<< "YES\n";
        else
            cout<< "NO\n";
    }

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    while(t--) lm();

    return 0;
}
