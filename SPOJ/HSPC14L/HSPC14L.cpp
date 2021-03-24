//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "HSPC14L"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))

using namespace std;

int n, c, d, A= 0, a[10], res;


void check()
{
    if(A<= n) return;
    res= min(A, res);
}

void rcs(int id)
{
    if(id> d) check();
    if(id> d+ 1) return;
    for(int i= 1; i<= 9; i++)
    {
        if(a[i]) continue;
        A= A* 10+ i;
        a[i]= 1;
        rcs(id+ 1);
        A/= 10;
        a[i]= 0;
    }
}

void RESET()
{
    d= 0;
    memset(a, 0);
    res= oo;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    while(cin>> n){
        int c= n;
        RESET();
        while(c> 0){
            ++d;
            c/= 10;
        }
        rcs(1);
        if(res== oo) cout<< 0<< "\n";
        else cout<< res<< "\n";
    }

    return 0;
}
