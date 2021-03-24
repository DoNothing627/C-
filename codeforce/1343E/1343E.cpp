//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000000000000007
#define int long long
#define DoNothing "1343E"
#define ii pair< int, int>
#define iii pair< ii, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int q, n, m, s[3], p[mn], res, d[3][mn];
vector< int> a[mn];
ii V[mn];

void reSet()
{
    res= oo;
    forr(i, 1, n)
       forr(j, 0, 2)
           d[j][i]= oo;
    forr(i, 0, 2)
       d[i][s[i]]= 0;

    forr(i, 1, n) a[i].clear();
    //forr(i, 1, m) V[i].clear();
}

void djk(int type)
{
    priority_queue< ii> p;
    p.push(ii(0, s[type]));
    while(p.size()){
        int u= p.top().y, du= -p.top().x;
        p.pop();
        if(d[type][u]!= du) continue;
        for(int v: a[u]){
            //int v= i.x.x, dv= i.x.y;
            if(d[type][v]> du+ 1){
                d[type][v]= du+ 1;
                p.push(ii(-d[type][v], v));
            }
        }
    }
}

void doIt()
{
    sort(p+ 1, p+ m+ 1);
    forr(i, 1, m) p[i]+= p[i- 1];
    forr(i, 1, n){
        int ans= d[0][i]+ d[1][i]+ d[2][i];
        if(ans> m) continue;
        res= min(res, p[ans]+ p[d[1][i]]);
    }
    cout<< res<< "\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> q;
    while(q--){
        cin>> n>> m>> s[0]>> s[1]>> s[2];
        reSet();
        forr(i, 1, m) cin>> p[i];
        forr(i, 1, m){
            int u, v;
            cin>> u>> v;
            a[u].pb(v), a[v].pb(u);
        }
        forr(i, 0, 2)
            djk(i);
        doIt();
    }

    return 0;
}
