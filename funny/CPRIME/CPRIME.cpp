//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "CPRIME"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a, b, c[mn], f[mn], d[mn];
vector< int> v;

void snt()
{
    forr(i, 2, 100000)
    {
        if(c[i]) continue;
        c[i]= i;
        for(long long j= 1ll* i* i; j<= 100000; j+= i)
            c[j]= i;
    }
}

void work()
{
    forr(i, 2, 100000)
    {
        f[i]= f[i- 1];
        int x= i, ans= 1;
        while(x> 1){
            ++d[c[x]];
            if(d[c[x]]== 1) v.pb(c[x]);
            x/= c[x];
        }
        for(auto j: v){
            ans= ans* (d[j]+ 1);
            d[j]= 0;
        }
        if(c[ans]== ans) ++f[i];
        while(v.size()) v.pop_back();
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    snt();
    work();

    cin>> n;
    forr(i, 1, n)
    {
        cin>> a>> b;
        cout<< f[b]- f[a- 1]<< "\n";
    }

    return 0;
}
