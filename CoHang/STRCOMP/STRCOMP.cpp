//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
#define DoNothing "STRCOMP"
//#define int long long
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, k, c, res, d[mn][26], r[mn], F[mn][105], cnt[mn];
string s, t;



void RESET()
{
    res= 0;
    memset(d, 0);
    memset(r, 0);
    memset(cnt, 0);
    memset(F, 0);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> m>> k>> s;

    n= s.size();
    s= " "+ s;

    while(m--){
        RESET();
        cin>> t;
        c= t.size();
        t= " "+ t;

        forr(j, 1, min(c, n))
        {
            int z= j;
            while(z<= n){
                ++d[j][s[z]- 'a'];
                ++cnt[j];
                if(s[z]!= t[j]) ++res;
                z+= c;
            }
        }

        forr(i, 1, min(c, n))
            forr(j, 0, 25){
                r[i]= max(r[i], -d[i][t[i]- 'a']+ d[i][j]);
            }

        F[0][0]= 0;
        forr(i, 1, min(c, n))
        {
            forr(j, 1, k)
            {
                F[i][j]= max(F[i- 1][j], F[i- 1][j- 1]+ r[i]);
            }
        }

        cout<< res- F[min(n, c)][k]<< "\n";

    }
    return 0;
}
