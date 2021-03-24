//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 10005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "SPECONE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, k, s, m, d[mn], c;
bool chek[10001][10001], inq[mn];
string u, v, a[mn];
map< string, int> M;
vector< int> f[mn];
vector< string> V;
priority_queue< ii> q;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> k>> s>> m;

    forr(i, 1, s)
    {
        cin>> a[i];
        M[a[i]]= i;
        d[i]= k;
        q.push(ii(d[i], i));
    }

    c= s;

    forr(i, 1, m)
    {
        string u, v;
        int _u, _v;
        cin>> u>> v;
        if(M[u]) _u= M[u];
        else{
            M[u]= ++c;
            a[c]= u;
            _u= c;
        }
        if(M[v]) _v= M[v];
        else{
            M[v]= ++c;
            a[c]= v;
            _v= c;
        }
        if(chek[_u][_v]) continue;
        f[_u].pb(_v);
        f[_v].pb(_u);
        chek[_u][_v]= chek[_v][_u]= 1;
    }

    while(q.size())
    {
        int u= q.top().y;
        inq[u]= 0;
        q.pop();
        if(d[u]< k) break;
        for(auto v: f[u])
        {
            if(!inq[v]&& d[v]) continue;
            ++d[v];
            inq[v]= 1;
            q.push(ii(d[v], v));
        }
    }


    forr(i, 1, c)
    if(d[i]>= k|| i<= s) V.pb(a[i]);

    sort(V.begin(), V.end());

    cout<< V.size()<< "\n";
    for(auto z: V)
        cout<< z<< " ";

    return 0;
}
