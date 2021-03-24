//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1245C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

string s;
int d, res= 1, f[mn], g[mn];

int power(int a, int b)
{
    int c= 1;
    for(; b> 0; a= (a* a)% oo)
    {
        if(b% 2) c= (c* a)% oo;
        b/= 2;
    }
    return c;
}

void init()
{
    f[0]= 1;
    forr(i, 1, mn)
    f[i]= (f[i- 1]* i)% oo;
    forr(i, 0, mn)
    g[i]= power(f[i], oo- 2);
}

int C(int K, int N)
{
    int ans= (f[N]* g[K])% oo;
    ans= (ans* g[N- K])% oo;
    return ans;
}

int calc(int x)
{
    int c= 0;
    forr(i, 0, x/ 2)
        c= (c+ C(i, x- i))% oo;

    return c;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    init();
    cin>> s;

    forr(i, 0, s.size()- 1)
    {
        if(s[i]== 'm'|| s[i]== 'w'){
            cout<< 0;
            return 0;
        }
        if(s[i]== 'n'|| s[i]== 'u') ++d;
        if(i){
            if(s[i]!= s[i- 1]&& d> 1)
            {
                res= (res* calc(d))% oo;
                d= 0;
            }
        }
    }

    if(d> 1) res= (res* calc(d))% oo;

    cout<< res;

    return 0;
}
