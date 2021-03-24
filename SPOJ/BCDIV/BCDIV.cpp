//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "BCDIV"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, k;
unsigned long long C[26][26];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);


    C[0][0]= 1;

    forr(i, 1, 25)
        forr(j, 1, 25)
            C[i][j]= C[i- 1][j- 1]+ C[i- 1][j]* j;

    //cout<< C[2][4]<< "\n";

    cin>> t;
    while(t--)
    {
        cin>> n>> k;
        cout<< C[n][k]<< "\n";
    }

    return 0;
}
