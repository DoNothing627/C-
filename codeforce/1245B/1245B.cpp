//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1245B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, a, b, c, e;
string v[105];
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> a>> b>> c>> s;
        int ans= 0;
        //memset(v, 0);
        forr(i, 0, 100) v[i]= " ";
        for(int i= 0; i< s.size(); i++)
        {
            if(s[i]== 'R'&& b> 0) --b, ++ ans, v[i]= "P";
            if(s[i]== 'P'&& c> 0) --c, ++ ans, v[i]= "S";
            if(s[i]== 'S'&& a> 0) --a, ++ ans, v[i]= "R";
        }
        if(n% 2) e= n/ 2+ 1;
        else e= n/ 2;
        if(ans< e) cout<< "NO"<< "\n";
        else{
            cout<< "YES\n";
            for(int i= 0; i< s.size(); i++)
            {
                if(v[i]!= " ") cout<< v[i];
                else{
                    if(a> 0){
                        cout<< "R", --a;
                        continue;
                    }
                    if(b> 0){
                        cout<< "P", --b;
                        continue;
                    }
                    if(c> 0){
                        cout<< "S", --c;
                        continue;
                    }
                }
            }
            cout<< "\n";
        }
    }

    return 0;
}
