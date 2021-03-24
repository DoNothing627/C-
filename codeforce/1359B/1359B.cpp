//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1359B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, m, x, y, ans, res;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> m>> x>> y;
        res= 0;
        while(n--){
            cin>> s;
            ans= 0;
            forr(i, 0, s.length()- 1)
            {
                if(s[i]== '*'){
                    res+= min(y* (ans/ 2)+ x* (ans% 2), x* ans);
                    ans= 0;
                }
                else ++ans;
            }
            res+= min(y* (ans/ 2)+ x* (ans% 2), x* ans);
        }
        cout<< res<< "\n";
    }

    return 0;
}
