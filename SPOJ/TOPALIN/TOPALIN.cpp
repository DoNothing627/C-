//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "TOPALIN"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, a[mn], f[62], res= 0, ans, z;
string s;
vector< int> c[62];
bool d[62];

void dfs(int u)
{
    d[u]= 1, ans+= f[u], z= max(z, f[u]);;
    for(auto v: c[u])
    {
        if(d[v]) continue;

        dfs(v);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s;
    n= s.size(), s= " "+ s;

    forr(i, 1, n)
    {
        if('a'<= s[i]&& s[i]<= 'z') a[i]= s[i]- 'a';
        if('A'<= s[i]&& s[i]<= 'Z') a[i]= s[i]- 'A'+ 26;
        if('0'<= s[i]&& s[i]<= '9') a[i]= s[i]- '0'+ 52;
        ++f[a[i]];
    }
    forr(i, 1, n/ 2)
    {
        if(a[i]!= a[n- i+ 1]){
            c[a[i]].pb(a[n- i+ 1]);
            c[a[n- i+ 1]].pb(a[i]);
        }
    }

    forr(i, 0, 61)
        if(!d[i]){
            ans= 0, z= 0;
            dfs(i);
            res+= ans- z;
        }

    cout<< res;

    return 0;
}
