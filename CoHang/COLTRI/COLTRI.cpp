//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "COLTRI"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, root, c[mn], h[mn], in[mn], out[mn], color[2* mn], ans[mn], COUNT[mn], cnt= 0, res= 0;
vector< int> a[mn];
typedef pair< ii, int> iii;
iii p[mn];

bool cmp(iii A, iii B)
{
    return A.x.y< B.x.y;
}

void dfs(int u, int o)
{
    in[u]= ++cnt;
    color[cnt]= c[u];
    for(auto v: a[u])
    {
        if(v== o) continue;
        dfs(v, u);
    }
    out[u]= ++cnt;
    color[cnt]= c[u];
}

void up(int l, int r)
{
    int u= p[l].x.x;
    if(u< p[r].x.x)
    while(u< p[r].x.x){
        --COUNT[color[u]];
        if(COUNT[color[u]]== 0) --res;
        ++u;
    }
    else{
        while(u> p[r].x.x){
            --u;
            if(COUNT[color[u]]== 0) ++res;
            ++COUNT[color[u]];

        }
    }
    u= p[l].x.y;
    if(u< p[r].x.y)
    while(u< p[r].x.y){
        ++u;
        if(COUNT[color[u]]== 0) ++res;
        ++COUNT[color[u]];

    }
    else{
        while(u> p[r].x.x){
            --COUNT[color[u]];
            if(COUNT[color[u]== 0]) --res;
            --u;
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> root;

    forr(i, 1, n- 1)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    forr(i, 1, n){
        cin>> c[i];
        h[i]= c[i];
    }
    sort(h+ 1, h+ n+ 1);
    forr(i, 1, n)
    c[i]= lower_bound(h+ 1, h+ n+ 1, c[i])- h;

    dfs(root, 0);

    forr(i, 1, m)
    {
        int u;
        cin>> u;
        p[i]= iii(ii(in[u], out[u]), i);
    }

    sort(p+ 1, p+ m+ 1);

    p[m+ 1].x.x= oo;
    int step= sqrt(2* n);

    int l, r= 1, dem= 1;
    while(r<= m)
    {
         l= r;
         while(r<= n&& p[r].x.x<= step* dem) ++r;
         sort(p+ l, p+ r, cmp);
         forr(i, l, r- 1)
         {
             up(i- 1, i);
             ans[p[i].y]= res;
         }
         ++dem;
    }

    forr(i, 1, m)
    cout<< ans[i]<< "\n";

    return 0;
}
