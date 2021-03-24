//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 5005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "CHGLSTGT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, a[mn], b[mn], p[mn], f[mn];
string s;

int mod(int x)
{
    x%= oo;
    while(x< 0) x+= oo;
    return x;
}

int ga(int u, int v)
{
    int t= v- u+ 1;
    return mod(a[v]- a[u- 1]* p[t]);
}

int gb(int u, int v)
{
    int t= v- u+ 1;
    return mod(b[u]- b[v+ 1]* p[t]);
}

bool chek(int i, int j)
{
    return (ga(i, j)== gb(i, j));
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    p[0]= 1;
    forr(i, 1, 5005)
    p[i]= (p[i- 1]* 131)% oo;

    cin>> t;
    while(t--){
        memset(f, 40);
        cin>> n>> s;
        s= " "+ s;
        forr(i, 1, n) a[i]= (a[i- 1]* 131+ s[i])% oo;
        b[n+ 1]= 0;
        for(int i= n; i> 0; i--)
            b[i]= (b[i+ 1]* 131+ s[i])% oo;

        f[0]= 0;
        forr(i, 1, n)
            forr(j, i, n)
                if(chek(i, j))
                    f[j]= min(f[j], f[i- 1]+ 1);
        cout<< f[n]<< "\n";
    }

    return 0;
}
