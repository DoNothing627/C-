//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 500005
#define pb push_back
#define oo 100000000007
#define int long long
#define DoNothing "SWAPB"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, Im[mn], Is[mn], D, C, d[mn], type, cnt;
vector< int> v;
bool av[mn];

void ups(int x)
{
    while(x<= n* m)
    {
        ++Is[x];
        x+= (x& (- x));
    }
}

int gets(int x)
{
    int ans= 0;
    while(x> 0)
    {
        ans+= Is[x];
        x-= (x& (- x));
    }
    return ans;
}

void dfs(int u)
{
    ++cnt;
    av[u]= 1;
    if(av[d[u]]) return;
    dfs(d[u]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> m>> n>> type;

    forr(i, 1, n)
    forr(j, 1, m)
    v.pb((j- 1)* n+ i);

    //for(auto u: v) cout<< u<< " ";

    for(int i= v.size()- 1; i>= 0; i--)
    {
        int u= v[i];
        C+= gets(u);
        ups(u);
    }

    forr(i, 0, v.size()- 1)
        d[v[i]]= i+ 1;

    forr(i, 1, n* m)
    {
        if(!av[i]){
            cnt= 0;
            dfs(i);
            D+= cnt- 1;
        }
    }

    if(type== 1) cout<< D;
    else cout<< C;

    return 0;
}
