//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1496B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, k, a[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> k;
        //RESET();
        if(!k){
            cout<< n<< "\n";
            continue;
        }
        forr(i, 1, n) cin>> a[i];
        sort(a+ 1, a+ n+ 1);
        int j= 0, i= 1;
        while(j == a[i]) ++j, ++ i;
        int c= (j+ a[n])/ 2;
        if((j+ a[n])% 2) ++c;
        bool chek= binary_search(a+ 1, a+ n+ 1, c);
        if(j> a[n]) n+= k- 1;
        if(!chek) ++n;

        cout<< n<< "\n";
        //if()
    }

    return 0;
}
