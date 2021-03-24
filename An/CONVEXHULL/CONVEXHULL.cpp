//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "CONVEXHULL"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int S[mn], top= 2, n, h[mn], t;
ii p[mn];


double gd(int u, int v)
{
    return (p[v].y- p[u].y)/ (p[u].x- p[v].x);
}

bool cmp(ii A, ii B)
{
    return A.x> B.x;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;

    forr(i, 1, n)
    cin>> p[i].x>> p[i].y;

    sort(p+ 1, p+ n+ 1, cmp);

    S[1]= 1, S[2]= 2;
    forr(i, 3, n)
    {
        while(top> 2&& gd(S[top- 1], i)< gd(S[top], i)) --top;
        S[top++]= i;
    }

    h[0]= -oo;
    cin>> t;

    while(t--){
        int u;
        cin>> u;
        int id= lower_bound(h, h+ top+ 1, u)- h;
        id= S[id];
        double res= p[id].x* u+ p[id].y;
        cout<< res<< "\n";
    }

    return 0;
}
