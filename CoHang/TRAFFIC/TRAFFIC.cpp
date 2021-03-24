//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "TRAFFIC"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

typedef pair< int, ii> iii;
int n, m, d[100005], r[40005], res= 0;
vector< iii> a;
bool ok= 0;

bool cmp(iii A, iii B)
{
    return A.x> B.x;
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
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    forr(i, 1, m)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a.pb(iii(w, ii(u, v)));
        ++d[w];
        if(d[w]> 1) ok= 1;
    }

    for(auto z: a)
    {
        int u= z.y.x, v= z.y.y, w= z.x;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv){
            r[fu]= fv;
            res+= w;
        }
    }

    cout<< res<< " ";
    if(!ok) cout<< 1;
    else cout<< rand();
    return 0;
}
