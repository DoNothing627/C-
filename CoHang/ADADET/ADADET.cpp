//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 500005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "ADADET"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, a[mn];
ii p[mn];

bool chek(int u, int v, int w)
{
    double c= p[v].x- p[u].x;
    c= (c* p[v].y)/ (p[u].y- p[v].y)+ c;
    return p[w].y* c>= p[u].y* (p[u].x+ c- p[w].x);
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

        stack< int> s;
        forr(i, 1, n)
            cin>> p[i].x>> p[i].y;

        forr(i, 1, n) a[i]= -1;
        for(int i= n; i> 0; i--)
        {
            while(s.size()&& p[i].y> p[s.top()].y)
            {
                a[i]= s.top();
                s.pop();
            }
            s.push(i);
            if(a[i]== -1) continue;
            while(a[a[i]]!= -1&& chek(i, a[i], a[a[i]]))
                a[i]= a[a[i]];
        }

        forr(i, 1, n) cout<< a[i]<< " ";
        cout<< "\n";
    }

    return 0;
}
