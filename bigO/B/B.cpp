//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 2000019
#define int long long
#define DoNothing "B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, y, a[30], g[20], res= 0, ans;
string s;

void init()
{
    g[0]= 1;
    forr(i, 1, 15)
    {
        g[i]= g[i- 1]* i;
    }
}

int POW(int c, int d)
{
    if(d== 1) return c;
    int ANS= (POW(c, d/ 2)* POW(c, d/ 2))% oo;
    if(d% 2) ANS= (ANS* c)% oo;
    return ANS;
}

void doIt(string S, int Y)
{
    memset(a, 0);
    //forr(i, 0, 28) a[i]= 1;
    int m= S.length();

    for(int i= 0; i< m; i++){
        a[S[i]- 65]++;
    }

    ans= g[m];

    forr(i, 0, 26)
    ans/= g[a[i]];

    ans= POW(Y, ans);
    res= (res+ ans)% 50000003;

    //cout<< g[m]<< "\n";

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    init();

    forr(i, 1, n){
        cin>> s>> y;
        //cout<< s[0]- 65<< " ";
        doIt(s, y);
    }

    cout<< res;

    return 0;
}
