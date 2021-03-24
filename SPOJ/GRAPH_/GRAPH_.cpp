//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "GRAPH_"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, num[mn], low[mn], khop, cau, cnt, COUNT, dad[mn], root;
bool d[mn], chek[mn];
vector< int> a[mn], s;
vector< ii> V;
stack< int> S;

void visit(int u)
{
    num[u]= low[u]= ++cnt;
    S.push(u);

    int dem= 0;
    for(auto id: a[u])
    {
        if(d[id]) continue;
        d[id]= d[id^ 1]= 1;
        int v= s[id];
        ++dem;
        if(num[v])
            low[u]= min(low[u], num[v]);
        else{
            visit(v);
            low[u]= min(low[u], low[v]);
        }
        if(u== root){
            if(dem>= 2) chek[u]= 1;
        }
        else if(low[v]>= num[u]) chek[u]= 1;
    }

    if(num[u]== low[u]){
        int v;
        ++COUNT;
        while(v!= u){
            v= S.top(), S.pop();
            dad[v]= COUNT;
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, m)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(s.size());
        s.pb(v);
        a[v].pb(s.size());
        s.pb(u);
        V.pb(ii(u, v));
    }

    forr(i, 1, n)
    if(!num[i]){
        root= i;
        visit(i);
    }

    forr(i, 1, n)
    if(chek[i]) ++khop;

    for(auto z: V)
    {
        int u= dad[z.x], v= dad[z.y];
        if(u!= v) ++cau;
    }

    cout<< khop<< " "<< cau;

    return 0;
}
