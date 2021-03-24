//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 50005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "QUEUE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;


int t, n, m, q, res= 0, lit[mn], match[mn], u[mn], v[mn], r[mn], ans;
bool av[mn], found, ok= true;
vector< int> a[mn];

void dfs(int u)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i];
        if(av[v]) continue;
        av[v]= 1;
        if(!match[v]) found= 1;
        else dfs(match[v]);
        if(found== 1){
            match[v]= u;
            return;
        }
    }
}

void RESET()
{
    forr(i, 1, n) a[i].clear();
    res= 0;
    memset(match, 0);
    ok= 1;
}

bool chek(int mid)
{
    RESET();
    forr(i, 1, mid)
        forr(j, u[i], v[i])
            a[i].pb(j);
    long nlist= n;
    forr(i, 1, n) lit[i]= i;
    while(ok){
        ok= false;
        memset(av, 0);
        forr(i, 1, nlist)
        {
            found= 0;
            dfs(lit[i]);
            if(found== 1){
                lit[i]= lit[nlist];
                nlist--;
                ok= true;
            }
        }
    }
    forr(i, 1, m) if(match[i]) ++res;
    return (res== mid);
}

int fs(int u)
{
    if(r[u]== u) return u;
    return r[u]= fs(r[u]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--)
    {
        cin>> m>> n;
        if(n<= 300&& m<= 300)
        {
            forr(i, 1, n)
            cin>> u[i]>> v[i];
            int l= 1, r= n+ 1;
            while(r- l> 1)
            {
                int mid= (l+ r)/ 2;
                if(chek(mid))
                    l= mid;
                else
                    r= mid;
            }
            cout<< l<< "\n";
        }
        else{
            ok= 1, ans= n;
            //memset(r, 0);
            forr(i, 1, n) r[i]= i;
            forr(i, 1, n)
            {
                int c, d;
                cin>> c>> d;
                int an= fs(d);
                if(!an&& ok){
                    ans= i- 1;
                    ok= 0;
                }
                r[d]= fs(an- 1);
            }
            cout<< ans<< "\n";
        }
    }

    return 0;
}
