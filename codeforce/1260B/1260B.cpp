//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1260B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a, b;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> a>> b;
        //if(a< b) swap(a, b);
        int c= a- b;
        //if((a- 2* c== b- c)&& (a- 2* c)% 3== 0) cout<< "YES\n";
        if((a- 2* c)% 3){
            cout<< "NO\n";
            continue;
        }
        //else cout<< "NO\n";
        int B= (a- 2* c)/ 3, A= B+ c;
        if(A>= 0&& B>= 0) cout<< "YES\n";
        else cout<< "NO\n";
    }

    return 0;
}
