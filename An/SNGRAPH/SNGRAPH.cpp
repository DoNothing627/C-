//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "SNGRAPH"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, m, d[mn], COUNT= 0, u[mn], v[mn], r[mn];
vector< int> Q;
typedef pair< int, ii> iii;
iii p[mn];

void RESET()
{
    memset(d, 0);
    memset(r, 0);
    COUNT= 0;
    Q.clear();
}

int fs(int u)
{
    return !r[u]? u: r[u]= fs(r[u]);
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
        cin>> n>> m;
        RESET();
        //int COUNT= 0;
        forr(i, 1, m)
        {
            cin>> u[i]>> v[i];
            ++d[u[i]], ++d[v[i]];
        }

        forr(i, 1, m)
            p[i]= iii(min(d[u[i]], d[v[i]]), ii(u[i], v[i]));

        sort(p+ 1, p+ m+ 1);
        int j= m;
        for(int i= n- 1; i>= 0; i--)
        {
            while(p[j].x== i+ 1){
                int fu= fs(p[j].y.x), fv= fs(p[j].y.y);
                if(fu!= fv){
                    r[fu]= fv;
                    ++COUNT;
                }
                --j;
            }
            Q.pb(n- COUNT- 1);
        }
        reverse(Q.begin(), Q.end());
        for(auto z: Q)
            cout<< z<< " ";
        cout<< "\n";
    }

    return 0;
}
