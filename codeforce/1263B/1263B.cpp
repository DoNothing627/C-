//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1263B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;
int t, ans, dd[100];
string s[11];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin >> t;
    while (t--)
    {
        int n;
        ans=0;
        memset(dd, 0);
        cin >> n;
        forr(i, 1, n)
        {
            cin>> s[i];
            dd[s[i][0]-'0']=1;
        }
        int cur= 0; ans= 0;
        forr(i, 2, n)
        {
            forr(j, 1, i- 1)
            {
                if(s[i]== s[j])
                {
                    while(dd[cur]== 1) ++cur;
                    dd[cur]= 1;
                    s[i][0]= (char) (cur+ '0');
                    ++ans;
                }
            }
        }
        cout << ans<< "\n";
        forr(i, 1, n) cout << s[i]<< "\n";
    }
    return 0;
}
