//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1230B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k>> s;

    if(n== 1){
        if(k== 1) cout<< 0;
        else cout<< s;
    }

    else{
        int i= 0;
        while(i< n){
            if(!k){
                cout<< s[i];
                ++i;
                continue;
            }
            if(!i){
                //if(s[i]== '1') continue;
                if(s[i]!= '1') s[i]= '1', --k;
            }
            else{
                if(s[i]!= '0') s[i]= '0', --k;
            }
            cout<< s[i];
            ++i;
        }
    }

    return 0;
}
