//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1228A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int l, r;
bool d[20];

bool chek(int x)
{
    memset(d, 0);
    while(x){
        if(d[x% 10]) return 0;
        d[x% 10]= 1;
        x/= 10;
    }
    return 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> l>> r;

    forr(i, l, r)
    if(chek(i)){
        cout<< i;
        return 0;
    }

    cout<< -1;

    return 0;
}
