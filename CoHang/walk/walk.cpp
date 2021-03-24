//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 2893606913523066920
#define int long long
#define DoNothing "walk"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;


int n, m, s, f, chek[2* mn], d[mn], p[mn], trace[mn], res= 0;
vector< int> a[mn], X, Y;
typedef pair< int, ii> iii;
vector< iii> c;

void djk()
{
    memset(d, 40);
    d[s]= 0;

    priority_queue< ii> pq;
    pq.push(ii(0, s));

    while(pq.size())
    {
        int u= pq.top().y, du= - pq.top().x;
        pq.pop();
        if(du!= d[u]) continue;
        for(auto id: a[u])
        {
            if(chek[id]) continue;
            //d[id]= 1;
            int v= c[id].y.x, w= c[id].y.y;
            w= w+ p[u]- p[v];
            if(d[v]> d[u]+ w)
            {
                d[v]= d[u]+ w;
                trace[v]= id;
                pq.push(ii(- d[v], v));
            }
        }
    }
}


void lm()
{
    djk();

    if(d[f]== oo){
        cout<< -1;
        return;
    }
    int v= f;
    X.pb(f);
    while(v!= s)
    {
        int id= trace[v];
        v= c[id].x;
        chek[id]= 1;
        c[id^ 1].y.y*= (- 1);
        X.pb(v);
        res+= c[id].y.y;
    }

    forr(i, 1, n) p[i]= d[i];

    djk();
    if(d[f]== oo){
        cout<< -1;
        return;
    }
    v= f;
    //Y.pb(f);
    while(v!= s)
    {
        int id= trace[v];
        v= c[id].x;
        Y.pb(v);
        res+= c[id].y.y;
    }

    cout<< res<< "\n";

    reverse(X.begin(), X.end());
    //cout<< X.size()<< " ";
    for(auto z: X) cout<< z<< " ";

    //reverse(Y.begin(), Y.end());
    //cout<< "\n"<< Y.size()<< " ";
    for(auto z: Y) cout<< z<< " ";

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    s= 1, f= n;

    forr(i, 1, m)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(c.size()), c.pb(iii(u, ii(v, w)));
        a[v].pb(c.size()), c.pb(iii(v, ii(u, w)));
    }

    lm();
    return 0;
}

