//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1095C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, c= 0, f[35];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;

    forr(i, 0, 30)
    if((n>> i)& 1){
        ++f[i];
        ++c;
    }

    if(c> k){
        cout<< "NO";
        return 0;
    }

    while(c< k){
        forr(i, 1, 30)
        if(f[i]){
            --f[i];
            f[i- 1]+= 2;
            ++c;
            goto over;
        }
        cout<< "NO";
        return 0;
        over:;
    }

    cout<< "YES"<< "\n";
    forr(i, 0, 30)
    {
        while(f[i]--){
            cout<< (1<< i)<< " ";
        }
    }

    return 0;
}
