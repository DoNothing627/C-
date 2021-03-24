//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 505
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "BONUS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, k, r, p, a[mn][mn], f[mn][mn], res= 0, ans;
ii c[mn];

int get(int u, int v, int x, int y)
{
    return f[x][y]- f[x][v- 1]- f[u- 1][y]+ f[u- 1][v- 1];
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k>> r>> p;

    forr(i, 1, n)
        forr(j, 1, n)
        {
            cin>> a[i][j];
            f[i][j]= f[i- 1][j]+ f[i][j- 1]- f[i- 1][j- 1]+ a[i][j];
        }

    while(k--)
    {
        ans= 0;
        forr(i, 0, p- 1)
        {
            int u, v;
            cin>> u>> v;
            c[i]= ii(u, v);
        }
        forr(x, 0, (1<< p)- 1)
        {
            int d= 0, u= 0, v= 0, _u= n+ 1, _v= n+ 1;
            forr(i, 0, p- 1)
                if((x>> i)& 1){
                    ++d;
                    u= max(u, c[i].x), _u= min(_u, c[i].x+ r- 1);
                    v= max(v, c[i].y), _v= min(_v, c[i].y+ r- 1);
                }
            if(u> _u|| v> _v) continue;
            d= d% 2;
            if(!d) --d;
            ans+= d* get(u, v, _u, _v);
        }
        res= max(ans, res);
    }

    cout<< res;
    return 0;
}
