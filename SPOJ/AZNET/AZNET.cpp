//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "AZNET"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, m, a[mn], b[mn], MAX, MIN, r[mn], d[2][mn], k;
vector< ii> V[2];
vector< int> res, s;

int fs(int u)
{
    return !r[u]? u: r[u]= fs(r[u]);
}

void lm()
{
    res.clear();
    MAX= 0, MIN= n- 1;
    //int res= oo;

    memset(r, 0);
    for(auto z: V[0])
    {
        int u= z.x, v= z.y;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv)
        {
            r[fu]= fv;
            ++MAX;
        }
    }

    memset(r, 0);
    for(auto z: V[1])
    {
        int u= z.x, v= z.y;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv)
        {
            r[fu]= fv;
            --MIN;
        }
    }

    k= MIN;
    forr(i, MIN+ 1, MAX)
        //res= min(res, a[i]+ b[n- i- 1]);
        if(a[i]+ b[n- 1- i]< a[k]+ b[n- 1- k]) k= i;
    //cout<< res<< "\n";

    memset(r, 0);
    for(auto z: V[1])
    {
        int u= z.x, v= z.y;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv) r[fu]= fv;
    }

    s.clear();

    forr(i, 0, V[0].size()- 1)
    {
        int u= V[0][i].x, v= V[0][i].y;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv){
            r[fu]= fv;
            s.pb(i);
            res.pb(d[0][i]);
        }
    }

    memset(r, 0);

    for(auto i: s)
    {
        int u= V[0][i].x, v= V[0][i].y;
        int fu= fs(u), fv= fs(v);
        r[fu]= fv;
    }

    forr(i, 0, V[0].size()- 1)
    {
        if(MIN== k) break;
        int u= V[0][i].x, v= V[0][i].y;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv){
            r[fu]= fv;
            res.pb(d[0][i]);
            ++MIN;
        }
    }

    forr(i, 0, V[1].size()- 1)
    {
        int u= V[1][i].x, v= V[1][i].y;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv){
            r[fu]= fv;
            res.pb(d[1][i]);
        }
    }

    sort(res.begin(), res.end());

    for(auto z: res) cout<< z<< " ";

    cout<< "\n";

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    while(t--){
        cin>> n>> m;
        forr(i, 1, n- 1) cin>> a[i];
        forr(i, 1, n- 1) cin>> b[i];
        V[0].clear(), V[1].clear();
        forr(i, 1, m)
        {
            int u, v, c;
            cin>> u>> v>> c;
            if(c== 1){
                V[0].pb(ii(u, v));
                d[0][V[0].size()- 1]= i;
            }
            if(c== 2){
                V[1].pb(ii(u, v));
                d[1][V[1].size()- 1]= i;
            }
        }
        lm();
    }

    return 0;
}
