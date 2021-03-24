//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "BUILDING"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n;
vector< ii> v[2][mn];

struct data
{
    int x, y, p, q, id;
}c[mn];

void init()
{
    sort(X+ 1, X+ n+ 1);
    sort(Y+ 1, Y+ n+ 1);

    forr(i, 1, n){
        c[i].x= lower_bound(X+ 1, X+ n+ 1, c[i].x)- X;
        c[i].p= lower_bound(X+ 1, X+ n+ 1, c[i].p)- X;
        c[i].y= lower_bound(Y+ 1, Y+ n+ 1, c[i].y)- Y;
        c[i].q= lower_bound(Y+ 1, Y+ n+ 1, c[i].q)- Y;
    }

    forr(i, 1, n)
    {
        v[c[0].x].pb(ii(c[i].y, i));
        v[c[0].p].pb(ii(c[i].q, i));
    }

    forr(i, 1, n)
    {
        v[c[1].y].pb(ii(c[i].x, i));
        v[c[1].q].pb(ii(c[i].p, i));
    }

    forr(i, 1, n){
        sort(v[0][i].begin(), v[0][i].end());
        sort(v[1][i].begin(), v[1][i].end());
    }

    forr(i, 1, n)
    {
        for(ii pr: v[0][i]){
            int u= pr.first, id= pr.second;
            int st= lower_bound(v[0][i].begin(), v[0][i].end(), {c[id].q, id});
            int en= lower_bound(v[0][i].begin(), v[0][i].end(), {c[id].q, 0});
            forr(j, st, en){
                a[id].pb(v[0][i][j].second);
                a[v[0][i][j].second].pb(id);
            }
        }
    }

    forr(i, 1, n)
    {
        for(ii pr: v[1][i]){
            int u= pr.first, id= pr.second;
            int st= lower_bound(v[1][i].begin(), v[1][i].end(), {c[id].p, id});
            int en= lower_bound(v[1][i].begin(), v[1][i].end(), {c[id].p, 0});
            forr(j, st, en){
                a[id].pb(v[1][i][j].second);
                a[v[1][i][j].second].pb(id);
            }
        }
    }

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n){
        cin>> c[i].x>> c[i].y>> c[i].p>> c[i].q;
        X[i]= c[i].x, X[n+ i]= c[i].p;
        Y[i]= c[i].y, Y[n+ i]= c[i].q;
        c[i].id= i;
    }

    init();

    return 0;
}
